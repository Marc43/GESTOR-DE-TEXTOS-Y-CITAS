#include "Frase.hh"

Frase::Frase() {
  num_palabras = 0;
}

Frase::Frase(list<string> &frase, int num_frase){
  this->frase = frase;
  num_palabras = frase.size();
  this->num_frase = num_frase;
}

int Frase::longitud_frase(){
  return num_palabras;
}

list<string> Frase::contenido_frase(){
  return frase;
}

void Frase::escribir_frase(){
  cout << num_frase << ' ';
  list<string>::iterator it = frase.begin();
  list<string>::iterator aux;
  while(it != frase.end()){ //No imprimia bien, lo he cambiado por un while y he añadido el numero de frase (y el final de linea)
    cout << *it;
    aux = it;
    if(++aux != frase.end()) cout << ' '; //Deja un espacio entre strings
    ++it;
  }
  cout << endl;
}

bool Frase::existe_palabra_frase(string palabra){
  bool match = false;
  list<string>::iterator it = frase.begin();
  while(it != frase.end() and not match){
    string p = *it; refina_signo(p);
    if(p == palabra) match = true;
    ++it;
  }
  return match;
}

bool Frase::eval_exp(istringstream &iss){
  stack<bool_exp> s;
  return i_eval_exp(iss, s);
}

bool Frase::i_eval_exp(istringstream &iss, stack<bool_exp> &s){
  string a_tratar; iss >> a_tratar;
  if(a_tratar.empty()){
    if(s.top().op == "&") return s.top().i and s.top().d;
    else if(s.top().op == "|") return s.top().i or s.top().d;
    else return s.top().i;
  }
  else{
    if(a_tratar[0] == '('){
      bool_exp aux;
      s.push(aux);
      iss.str(iss.str().substr(1, iss.str().size()-1));
    }
    else if(a_tratar[0] == '{'){
      a_tratar = a_tratar.substr(1, a_tratar.size()-1);
      bool value = true;
      while(a_tratar[a_tratar.size()-1] == ')') a_tratar = a_tratar.substr(0, a_tratar.size()-1);
      while(a_tratar[a_tratar.size()-1] != '}'){
        if(value){
          value = value and existe_palabra_frase(a_tratar);
        }
        recorta(iss); iss >> a_tratar;
        while(a_tratar[a_tratar.size()-1] == ')') a_tratar = a_tratar.substr(0, a_tratar.size()-1);
      }
      if(a_tratar[a_tratar.size()-1] == ')') a_tratar = a_tratar.substr(0, a_tratar.size()-1);
      else a_tratar = a_tratar.substr(0, a_tratar.size()-1);
      if(value) value = value and existe_palabra_frase(a_tratar);
      recorta(iss);
      if(s.top().op.empty()) s.top().i = value;
      else{
        s.top().d = value;
        bool_exp top = s.top(); s.pop();
        while(not s.empty() and not s.top().op.empty()){
          if(top.op == "&") value = top.i and top.d;
          else value = top.i or top.d;
          top = s.top(); top.d = value; s.pop();
        }
        if(s.empty()) s.push(top);
        else{
          if(top.op == "&") s.top().i = top.i and top.d;
          else s.top().i = top.i or top.d;
        }
      }
    }
    else{
      if(not s.top().op.empty()){
        if(s.top().op == "&") s.top().i = s.top().i and s.top().d;
        else s.top().i = s.top().i or s.top().d;
      }
      s.top().op = a_tratar;
      recorta(iss);
    }
    return i_eval_exp(iss, s);
  }
}