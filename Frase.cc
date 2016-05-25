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
  cout << num_frase << " ";
  for(list<string>::iterator it = frase.begin(); it != frase.end(); ++it){
    cout << *it;
    if(++it != frase.end()) cout << " ";
  }
}

bool Frase::existe_palabra_frase(string palabra){
  bool match = false;
  list<string>::iterator it = frase.begin();
  while(it != frase.end() and not match){
    if(*it == palabra) match = true;
    ++it;
  }
  return match;
}