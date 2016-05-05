#include "Frase.hh"

Frase::Frase(){
  num_palabras = 0;
}

int Frase::longitud_frase(){
  return num_palabras;
}

void Frase::leer_frase(){
  list<Palabra>::iterator it = frase.begin();
  Palabra p;
  p.leer_palabra();
  list<char> pal = p.palabra(false);
  while(pal[--pal.end()] != '.' and pal[--pal.end()] != '?' and pal[--pal.end()] != '!'){
    frase.insert(it, p);
    p.leer_palabra(); pal = p.palabra(false);
    ++num_palabras();
  }
}

void Frase::escribir_frase(){
  list<Palabra>::iterator it = frase.begin();
  bool f = true;
  while(it != frase.end()){
    if(not f) cout << " ";
    list<char> palabra = (*it).palabra(false);
    list<char>::iterator it2 = palabra.begin();
    while(it2 != palabra.end()){
      cout << *it2;
    }
  }cout << endl;
}

list<Palabra> Frase::contenido_frase(){
  return frase;
}