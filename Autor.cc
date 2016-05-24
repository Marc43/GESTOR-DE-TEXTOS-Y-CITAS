#include "Autor.hh"

Autor::Autor(string nombre){
  this->nombre = nombre;
}

void Autor::citas_autor(){
  for(map<string, Cita>::iterator it = citas.begin(); it != citas.end(); ++it){
    cout << it->first << endl;
    it->second.escribir_cita();
    cout << it->second.titulo_texto_cita();
  }
}

string Autor::nombre_autor(){
  return nombre;
}

void Autor::textos_autor(){
  map<string, Texto>::iterator it = textos.begin();
  while(while it != textos.end()){
    if(it != textos.begin()) cout << " ";
    cout << it->second.titulo_texto();
    ++it;
  } cout << endl;
}

int Autor::numero_palabras_autor(){
  return num_palabras;
}

int Autor::numero_frases_autor(){
  return num_frases;
}

int Autor::numero_textos_autor(){
  return num_textos;
}

void Autor::anadir_texto_autor(Texto texto){ //actualizar las palabras, frases, textos del autor
  list<Texto>::iterator it = textos.end();
  it = textos.insert(it, texto);
}

void Autor::eliminar_text_autor(string titulo){
  map<string, Texto>::iterator it = textos.find(titulo);
  it = textos.erase(it);
}

void Autor::anadir_cita_autor(const Cita& c, string ini, int num){
  citas[ini][num] = c;
}

void Autor::eliminar_cita_autor(string ini, int num){
  citas[ini].erase(num);
  if(citas[ini].empty()) citas.erase(ini);
}
