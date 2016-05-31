#include "Texto.hh"

Texto::Texto(){
  this->num_frases = 0;
  this->num_palabras = 0;
}

Texto::Texto(string autor, string titulo, int num_p, int num_f, list<Frase> contenido, map<string, int> frecuencia_palabras){
  this->autor = autor;
  this->titulo = titulo;
  this->contenido = contenido;
  this->num_frases = num_f;
  this->num_palabras = num_p;
  this->frecuencia_palabras = frecuencia_palabras;
  for(map<string, int>::iterator it = frecuencia_palabras.begin(); it != frecuencia_palabras.end(); ++it){
    if(tabla_frecuencias[it->second].size() < it->first.length()) tabla_frecuencias[it->second].resize(it->first.length());
    tabla_frecuencias[it->second][it->first.size()-1].insert(it->first);
  }
}

string Texto::autor_texto(){
  return autor;
}

string Texto::titulo_texto(){
  return titulo;
}

void Texto::citas_texto(bool c){
  map<string, map<int, Cita> >::iterator it = citas.begin();
  if(not c) cout << "Cites Associades:" << endl;
  while(it != citas.end()){
    for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      cout << it->first << it2->first << endl;
      it2->second.escribir_cita();
    }
    if(c) cout << autor << " \"" << titulo << '"' << endl;
    ++it;
  }
}

bool Texto::existe_cita(int x, int y){
  for(map<string, map<int, Cita> >::iterator it = citas.begin(); it != citas.end(); ++it){
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

void Texto::mostrar_contenido_texto(){
  list<Frase>::iterator it = contenido.begin();
  while(it != contenido.end()){ //Cambiado for por un while por si aca fallaba
    (*it).escribir_frase();
    ++it;
  }
}

void Texto::tabla_frecuencias_texto(){
  for(map<int, vector< set<string> > >::reverse_iterator it = tabla_frecuencias.rbegin(); it != tabla_frecuencias.rend(); ++it){
    for(int i = 0; i < it->second.size(); ++i){
      for(set<string>::iterator it2 = it->second[i].begin(); it2 != it->second[i].end(); ++it2){
        cout << *it2 << " " << it->first << endl;
      }
    }
  }
}

void Texto::frases_xy(int x, int y){ // Removido por que ya se trata en el main: or x <= 0 
  if(x > y or y <= 0 or y > num_frases) cout << "error" << endl;
  else{
    list<Frase>::iterator it = contenido.begin();
    int cont = 1;
    while(x != cont){++it; ++cont;} //Ajustamos el iterador a la primera frase
    while(x <= y){
      (*it).escribir_frase();
      ++it; ++x;
    }
  }
}

void Texto::frases_exp(istringstream &iss){
    for(list<Frase>::iterator it = contenido.begin(); it != contenido.end(); ++it){
      istringstream iss2(iss.str());
      if((*it).eval_exp(iss2)) (*it).escribir_frase();
    }
}

void Texto::frases_seq(list<string> &seq){ //mirar, tiene que tratar los signos
  list<Frase>::iterator frase_act = contenido.begin();
  while(frase_act != contenido.end()){ //Mientras estemos dentro del contenido...
    list<string> frase = (*frase_act).contenido_frase(); //Es una lista auxiliar, asi que podemos modificar su contenido...
    list<string>::iterator pf = frase.begin();
    bool match = false;
    while(pf != frase.end() and not match){
      bool es_seq = true;
      refina_signo(*pf);
      list<string>::iterator pseq = seq.begin();
      if(*pf == *pseq){
        list<string>::iterator aux_pf = pf; ++aux_pf;
        list<string>::iterator aux_pseq = pseq; ++aux_pseq;
        while(seq.size() <= frase.size() and es_seq and aux_pf != frase.end() and aux_pseq != seq.end()){
	  refina_signo(*aux_pf);
          if(*aux_pf != *aux_pseq) es_seq = false;
          ++aux_pf; ++aux_pseq;
        }
        if(es_seq and aux_pseq == seq.end()) {(*frase_act).escribir_frase(); match = true;}
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

void Texto::sustituir_palabra(string &p1, string &p2){ //tratar resize tabla frecuencias sustituir peta para dos numeros
  bool iguales = p1 == p2; //Si las palabras son iguales... ESTO YA SE HACE EN EL MAIN
  map<string, int>::iterator ex1 = frecuencia_palabras.find(p1);
  bool existe = ex1 != frecuencia_palabras.end(); //Si la palabra esta en el texto...
  if(not iguales and existe){
    //Cambios en las frecuencias
    int frec1 = ex1->second;
    tabla_frecuencias [frec1] [ex1->first.length() - 1].erase(ex1->first);
    frecuencia_palabras.erase(ex1); //Guardamos su anterior frec y lo borramos (se sustituyen todas las apariciones)
    map<string, int>::iterator ex2 = frecuencia_palabras.find(p2);
    if(ex2 != frecuencia_palabras.end()){
      tabla_frecuencias [ex2->second] [ex2->first.length() - 1].erase(ex2->first);
      frecuencia_palabras [ex2->second] += frec1;
      int v_size = tabla_frecuencias [ex2->second].size();
      if(ex2->first.length() < v_size){
        tabla_frecuencias [ex2->second].resize(ex2->first.length());
        tabla_frecuencias [ex2->second] [ex2->first.length()].insert(ex2->first);
      }
      else tabla_frecuencias [ex2->second] [ex2->first.length()].insert(ex2->first);
    }
    else{
      frecuencia_palabras [p2] = frec1;
      int v_size = tabla_frecuencias [ex2->second].size();
      if(ex2->first.length() < v_size){
        tabla_frecuencias [ex2->second].resize(ex2->first.length());
        tabla_frecuencias [ex2->second] [ex2->first.length()].insert(ex2->first);
      }
      else tabla_frecuencias [ex2->second] [ex2->first.length()].insert(ex2->first);
    }
    list<Frase>::iterator it1 = contenido.begin();
    int num_frase = 1;
    while(it1 != contenido.end()){ //Iteramos sobre las frases
      list<string> p = (*it1).contenido_frase();
      list<string>::iterator it2 = p.begin();
      while(it2 != p.end()){ //Iteramos sobre el contenido de dicha frase
        /*char signo; signo = (*it2) [(*it2).length() - 1];
        bool es_signo = not ((signo >= 'a' and signo <= 'z') or (signo >= 'A' and signo <= 'Z')) and not (signo >= '0' and signo <= '9');
        if(es_signo){
          string aux = *it2; aux.substr(0, aux.size()-1);
          if(aux == p1){
            aux = p2; aux += signo;
            *it2 = aux;
          }
        }
        else if(*it2 == p1) *it2 = p2;*/
        string a_tratar = (*it2); refina_signo(a_tratar);
        if(a_tratar == p1){
          if(a_tratar == *it2) *it2 = p2;
          else{
            string aux = ""; aux += (*it2)[(*it2).size()-1];
            *it2 = p2;
            *it2 += aux;
          }
        }
        ++it2;
      }
      Frase f (p, num_frase);
      *it1 = f;
      ++num_frase;
      ++it1;
    }
  }
}

map<string, int> Texto::frecuencia_palabras_texto(){
  return frecuencia_palabras;
}

list<Frase> Texto::contenido_texto(){
  return contenido;
}
