#include "Texto.hh"

Texto::Texto(string autor, string titulo, int num_p, int num_f, list<Frase> contenido, map<string, int> frecuencia_palabras){

}

string Texto::autor_texto(){
  return autor;
}

string Texto::titulo_texto(){
  return titulo;
}

void Texto::citas_texto(){
  for(map<string, map<int, Cita>>::iterator it = citas.begin(); it != citas.end(); ++it){
    for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      cout << it->first << it2->first << endl; it2->second.escribir_cita();
      cout << autor << ' "' << titulo << '"' << endl;
    }
  }
}

bool Texto::existe_cita(int x, int y){
  for(map<string, map<int, Cita>>::iterator it = citas.begin(); it != citas.end(); ++it){
    for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      if(it2->second.frase_inicial() == x and it2->second.frase_final() == y) return true;
    }
  }
  return false;
}

int Texto::numero_frases(){
  return num_frases;
}

int Texto::numero_palabras(){
  return num_palabras;
}

void Texto::contenido_texto(){
  list<Frase>::iterator it = contenido.begin(); int n = 1;
  while(it != contenido.end()){
    (*it).escribir_frase(); ++it;
  }
}

void Texto::tabla_frecuencias_texto(){

}

void Texto::frases_xy(int x, int y){
  if(x > y or x <= 0 or y <= 0 or y > num_frases) cout << "error" << endl;
  else{
    list<Frase>::iterator it = contenido.begin();
    while(x <= y){
      (*it).escribir_frase();
      ++it; ++x;
    }
  }
}

void Texto::frases_exp(istringstream iss){

}

void Texto::frases_seq(const list<string>& seq){
  list<Frase>::iterator frase_act = contenido.begin();
  while(frase_act != contenido.end()){ //Mientras estemos dentro del contenido...
    list<string> frase = (*frase_act).contenido_frase();
    list<string>::iterator pf = frase.begin();
    list<string>::iterator pseq = seq.begin();
    bool seq = true;
    bool match = false;
    while(not match and pf != frase.end()){
        if(*pf == *pseq){
      list<string>::iterator aux_pf = pf; ++aux_pf;
      list<string>::iterator aux_pseq = pseq; ++aux_pseq;
      while(seq and aux_pf != frase.end() and aux_pseq != seq.end()){
              if(*aux_pf != *aux_pseq) seq = false;
              ++aux_pf; ++aux_pseq;
      }
      if(seq and aux_pseq == seq.end()){
         (*pf).escribir_frase();
         match = true;
      }
        }
        ++pf; //Comprueba la secuencia para la siguiente palabra
    }
    ++frase_act; //Pasamos a comprobar la siguiente frase
  }
}

void Texto::anadir_cita_texto(const Cita &c, string ini, int num){
  citas[ini][num] = c;
}

void Texto::eliminar_cita_texto(string ini, int num){
  citas[ini].erase(num);
  if(citas[ini].empty()) citas.erase(ini);
}

void sustituir_palabra(const string &p1, const string &p2){
  list<Frase>::iterator it1 = contenido.begin();
  bool iguales = p1 == p2; //Si las palabras son iguales...
  map<string, int>::iterator ex1 = frecuencia_palabras.find(p1);
  bool existe = ex1 != frecuencia_palabras.end(); //Si la palabra esta en el texto...
  if(not iguales and existe){
    //Cambios en las frecuencias
    int frec1 = ex1->second;
    frecuencia_palabras.erase(ex1);
    set <string>::iterator st = tabla_frecuencias [frec1] [p1.length() - 1].find(p1);
    st = tabla_frecuencias [frec1] [p1.length() - 1].erase(st);
    map<string, int>::iterator ex2 = frecuencia_palabras.find(p2);
    if(ex2 != frecuencia_palabras.end()){
      frecuencia_palabras [p2] += frec1; //Su nueva frecuencia es la suma de ambas frecuencias
      set <string>::iterator sa = tabla_frecuencias [ex2->second] [p2.length() - 1].find(p2);
      sa = tabla_frecuencias [ex2->second] [p2.length() - 1].erase(sa); //Borrado de la antigua p2...
      tabla_frecuencias [frec2] [p2.length() - 1].insert(p2); //Insertado de la nueva p2 (nueva frec.)
    }
    else{
      frecuencia_palabras [p2] = frec1;
      tabla_frecuencias [frec1] [p2.length() - 1].insert(p2);
    }
    while(it1 != contenido.end()){ //Iteramos sobre las frases
      list<string> p = (*it1).contenido_frase();
      list<string>::iterator it2 = p.begin();
      while(it2 != p.end()){ //Iteramos sobre el contenido de dicha frase
        string signo; signo = (*it2) [(*it2).length() - 1];
        bool es_signo = not ((signo >= 'a' and signo <= 'z') or (signo >= 'A' and signo <= 'Z'));
        if(es_signo){
          string aux = *it2; aux.pop_back();
          if(aux == p1){
            aux = p2; aux += signo;
            *it2 = aux;
          }
        }
        else if(*it2 == p1) *it2 = p2;
        ++it2;
      }
      ++it1;
    }
  }
}

list<Frase> Texto::eval_exp(istringstream &iss, stack<bool_exp> &s){
  string a_tratar;
  iss >> a_tratar;
  if(a_tratar.empty()){
    if(s.top().op == '&'){
      return interseccion(s.top().i, s.top().d);
    }
    else if(s.top().op == '|'){
      return fusion(s.top().i, s.top().d);
    }
    else{
      return s.top().i;
    }
  }
  else{
    if(a_tratar[0] == '('){
      bool_exp aux; s.stack(aux);
      a_tratar = a_tratar.substr(1, a_tratar.size()-1);
      string aux2 = iss.str();
      a_tratar += aux2;
      istringstream aux3(a_tratar);
      iss = aux3;
      return eval_exp(iss, s);
    }
    else if(a_tratar[0] == '{'){
      if(a_tratar[a_tratar.size()-1] == '}'){
        a_tratar = a_tratar.substr(1, a_tratar.size() -2);
        if(s.top().op.empty()){
          bool_exp aux;
          list<Frase> i = frases_palabra(a_tratar);
          string op; iss >> op;
          aux.i = i; aux.op = op;
          s.top() = aux;
          return eval_exp(iss, s);
        }
        else{
          if(s.top().op == '&'){
            list<Frase> aux = s.top().i;
            s.pop();
            s.top().i = interseccion(aux, frases_palabra(a_tratar));
            return eval_exp(iss, s);
          }
          else{
            list<Frase> aux = s.top.i;
            s.pop();
            s.top().i = fusion(aux, frases_palabra(a_tratar));
            return eval_exp(iss, s);
          }
        }
      }
      else{
        bool_exp aux;
        aux.i = frases_palabra(a_tratar.substr(1, a_tratar.size() - 1));
        aux.op = '&';
        s.stack(aux);
        return eval_exp(iss, s);
      }
    }
    else{
      if(a_tratar == '&'){
        s.top().op = a_tratar;
        return eval_exp(iss, s);
      }
      else if(a_tratar == '|'){
        s.top().op = a_tratar;
        return eval_exp(iss, s);
      }
      else{
        list<Frase> i = interseccion(s.top().i, a_tratar.substr(0, a_tratar.size() - 1));
        s.pop();
        s.top().i = i;
        return eval_exp(iss, s);
      }
    }
  }
}


