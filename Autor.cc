#include "Autor.hh"

Autor::Autor(string nombre){
  this->nombre = nombre;
}

void Autor::citas_autor(){
  map<string, cita>::iterator it = citas.begin();
  while(it != citas.end()){
    cout << it->first << endl;
    int i = 0;
    while(i < it->second.contenido().size()){
      if(i != 0) cout << " ";
      it->second.contenido()[i].escribir_frase();
    } cout << endl;
    cout << it->second.titulo(); << endl;
  }
}

void Autor::textos_autor(){
  map<string, Texto>::iterator it = textos.begin();
  while(while it != textos.end()){
    if(it != textos.begin()) cout << " ";
    cout << it->second.titulo_texto();
    ++it;
  } cout << endl;
}

void Autor::anadir_texto(Texto texto){ //excepcion tratada main
  list<Texto>::iterator it = --textos.end();
  textos.insert(it, texto);
}

void Autor::eliminar_text(string titulo){
  map<string, Texto>::iterator it = textos.find(titulo);
  it = textos.erase(it);
}

void Autor::anadir_cita(Cita cita){
  citas[cita.identificador()] = cita;
}

void Autor::eliminar_cita(string identificador){ //excepcion trata main
  map<string, Cita>::iterator it = citas.find(identificador);
  it = citas.erase(it);
}