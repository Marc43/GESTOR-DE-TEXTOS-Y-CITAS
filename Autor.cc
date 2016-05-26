#include "Autor.hh"

Autor::Autor(){

}

Autor::Autor(string nombre){
  this->nombre = nombre;
  num_textos = 0;
  num_palabras = 0; //Daba problemas no inicializarlas...
  num_frases = 0;
}

void Autor::citas_autor(){
  for(map<string, map<int, Cita> >::iterator it = citas.begin(); it != citas.end(); ++it){
    //rehacer, 2for
  }
}

string Autor::nombre_autor(){
  return nombre;
}

void Autor::textos_autor(){
  map<string, Texto>::iterator it = textos.begin();
  while(it != textos.end()){
    if(it != textos.begin()) cout << " ";
    cout << '\"' << it->second.titulo_texto() << '\"';
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

bool Autor::existe_texto_autor(string titulo){
  map<string, Texto>::iterator it = textos.find(titulo);
  return it != textos.end();
}

void Autor::anadir_texto_autor(Texto texto){ //actualizar las palabras, frases, textos del autor
  textos[texto.titulo_texto()] = texto;
  ++num_textos;
  num_frases = texto.numero_frases();
  num_palabras = texto.numero_palabras();
}

void Autor::eliminar_texto_autor(string titulo){
  map<string, Texto>::iterator it = textos.find(titulo);
  --num_textos;
  num_frases -= it->second.numero_frases();
  num_palabras -= it->second.numero_palabras();
  textos.erase(it);
}

void Autor::anadir_cita_autor(Cita cita, string ini, int num){
    citas[ini][num] = cita;
}

void Autor::eliminar_cita_autor(string ini, int num){
    citas[ini].erase(num);
    if(citas[ini].empty()) citas.erase(ini);
}
