#include "Palabra.hh"

/* Constructoras */

Palabra::Palabra(const string& t){
  longitud = t.size();
  list<char>::iterator *it = palabra.begin();
  for(int i = 0; i < longitud; ++i){
    palabra.insert(it, t[i]);
  }
}

/* Consultoras */

int Palabra::longitud(){
  return longitud;
}

bool Palabra::signo_puntuacion(){
  list<char>::iterator it = palabra.end(); --it; //Ahora it apunta al caracter final de la palabra
  char c = *it; bool signo = true;
  if((('a' <= c) and ('z' >= c)) or (('A' <= c) and ('Z' >= c))) signo = false;
  
  return signo;
}

bool Palabra::son_iguales(Palabra p){
  list<char>::iterator it1 = palabra.begin(); list<char>::iterator it2 = p.palabra.begin();
  bool iguales = true;
  while(iguales and it1 != palabra.end() and it2 != p.palabra.end()){
    if((*it1) != (*it2)) iguales = false;
    ++it1; ++it2;
  }
  if(it1 != palabra.end() or it2 != p.palabra.end()) return false;
  
  return iguales;
}

list<char> Palabra::palabra(bool refined){
  if(refined and signo_puntuacion()){
    list<char>::iterator it = palabra.end(); --it;
    it = palabra.erase(it);
    
    return palabra;
  }
  else return palabra;
}

void Palabra::ampliar_palabra(char c){
  list<char>::iterator it = palabra.end();
  palabra.insert(it, c);
}



