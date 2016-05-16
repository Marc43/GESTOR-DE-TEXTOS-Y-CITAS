#include "Autores.hh"

Autores::Autores(){/*NO_OP*/}

Autor Autores::autor_nombre(string nombre){
  map<string, Autor>::iterator it = autores.find(nombre);
  if(it != autores.end()) return (*it);
}

void Autores::todos_autores(){
  map<string, Autor>::iterator it = autores.begin();
  while(it != autores.end()){
    cout << (*it).nombre_autor() << " ";
  }
  cout << endl;
  ++it;
}

void Autores::anadir_autor(Autor autor){
  string referencia = autor.nombre_autor();
  autores[referencia] = autor;
}

void Autores::eliminar_autor(string nombre){
  autores.erase(nombre);
}
