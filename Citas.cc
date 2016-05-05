#include "Citas.hh"

Citas::Citas(){
  //NO_OP
}

void Citas::todas_citas(){
  map<string, Cita>::iterator it = citas.begin();
  while(it != citas.end()){
    cout << it->first << endl;
    int i = 0;
    vector<Frase> contenido = it->second.contenido();
    while(i < contenido.size()){
      contenido[i].escribir_frase();
    }
    it->second.autor().escribir_frase();
    it->second.titulo().escribir_frase();
  }
}

void Citas::anadir_cita(Cita cita){
  Palabra id;
  list<Palabra> autor = cita.autor().contenido_frase();
  list<Palabra>::iterator ita = autor.begin();
  while(ita != autor.end()){
    list<char> c = (*ita).palabra(false)
    id.ampliar_palabra(*(c.begin()));
  }
  map<string, int>::iterator it = d.begin();
}