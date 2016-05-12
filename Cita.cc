#include "Cita.hh"

Cita::Cita(vector<Frase> contenido, string titulo_texto, string autor_texto, int x, int y, string identificador){
  this->contenido = contenido;
  this->titulo_texto = titulo_texto;
  this->autor_texto = autor_texto;
  this->x = x;
  this->y = y;
}

void Cita::info(){
  cout << autor_texto << ' "' << titulo_texto << '"' << endl;
  cout << x << "-" << y << endl;
  for(int i = 0; i < contenido.size(); ++i){
    cout << x + i << " "; contenido[i].escribir_frase();
  }
}

string Cita::titulo(){
  return titulo_texto;
}

string Cita::autor(){
  return autor_texto;
}

vector<Frase> Cita::contenido(){
  return contenido;
}