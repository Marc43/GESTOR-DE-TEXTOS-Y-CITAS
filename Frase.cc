#include "Frase.hh"

Frase::Frase(list<string> &frase){
  this->frase = frase;
  num_palabras = frase.size();
}

int Frase::longitud_frase(){
  return num_palabras;
}

list<string> Frase::contenido_frase(){
  return frase;
}

void Frase::escribir_frase(){
  for(list<string>::iterator it = frase.begin(); it != frase.end(); ++it){
    cout << *it << " ";
  }
}