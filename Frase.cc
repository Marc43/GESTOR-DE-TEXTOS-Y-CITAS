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
    if(*it == palabra) match = true;
    ++it;
  }
  return match;
}