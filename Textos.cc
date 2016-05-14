#include "Textos.hh"

Textos::Textos(){
  escogido = false;
  /* Un objeto Textos nuevo es, una lista */
  /* con los textos del gestor, el texto  */ 
  /* escogido, y un bool que indica si    */
  /* se ha escogido un texto o no.	  */
}

void Textos::anadir_texto(Texto texto, Autores& autores){
  string nombre_autor = texto.autor_texto();
  if(autores.existe_autor()) autores.anadir_texto_autor(texto, nombre_autor);
  textos.insert(textos.end(), texto);
  /* texto ha sido anadido a su autor correspondiente 
     y ha quedado almacenado en textos. */
}

void Textos::eliminar_texto(){
  if(escogido){
    list<Texto>::iterator it = textos.begin();
    bool eliminado = false;
    while(not eliminado and it != textos.end()){ //Busqueda
      if((*it).autor_texto == texto_escogido.nombre_autor()){
	it = it.erase();
	eliminado = true;
	escogido = false;
      }
    }
  }
  else cout << "ERROR" << endl;
}

bool Textos::escoger_texto(const list<Palabra>& p){
  list<Texto>::iterator it1 = textos.begin();
  bool t1 = false; bool t2 = false;
  while(it1 != textos.end and (not t1 or not t2)){
    //Implementar
  }
  
}

void Textos::todos_textos(){
  list<Texto>::iterator it = textos.begin();
  while(it != textos.end()){
    (*it).contenido();
    ++it;
  }
}

Texto Textos::texto_escogido(){
  if(escogido) return texto_escogido;
  else cout << "ERROR" << endl;
}

bool Textos::escogido(){
  return escogido;
}

bool Textos::existe_texto(string titulo, string autor){
  list<Texto>::iterator it = textos.begin();
  bool encontrado = false;
  while(not encontrado and it != textos.end()){
    if(texto.titulo_texto() == titulo and texto.autor_texto() == autor) encontrado = true;
    ++it;
  }
  
  return encontrado;
}

