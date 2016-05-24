#include "Cita.hh"

Cita::Cita(vector<Frase> contenido, string titulo_texto, string autor_texto, int x, int y){
  this->contenido = contenido;
  this->titulo_texto = titulo_texto;
  this->autor_texto = autor_texto;
  this->x = x;
  this->y = y;
}

void Cita::info(){
  cout << autor_texto << ' "' << titulo_texto << '"' << endl;
  cout << x << "-" << y << endl;
  escribir_cita();
}

string Cita::titulo(){
  return titulo_texto;
}

string Cita::autor(){
  return autor_texto;
}

void Cita::escribir_cita(){
  for(int i = 0; i < contenido.size(); ++i){
    cout << contenido[i].escribir_frase(); cout << endl;
  }
}

int frase_inicial(){
  return x;
}

int frase_final(){
  return y;
}