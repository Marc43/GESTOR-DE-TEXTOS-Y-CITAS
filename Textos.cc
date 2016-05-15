#include "Textos.hh"
#include <set>

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
  else{
    Autor a(nombre_autor);
    a.anadir_texto(texto);
    autores.anadir_autor(a);
  }
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
  set textos_condicion;
  while(textos_condicion.size() <= 1 and it1 != textos.end()) {
    list<Palabra> aux = p;
    istringstream i_titulo_texto((*it1).titulo_texto());
    string s_aux;
    list<Palabra> titulo; list<Palabra>::iterator t_it = titulo.begin();
    while(i_titulo_texto >> s_aux){
      titulo.insert(t_it, s_aux);
    }
    t_it = titulo.begin();
    while(aux.size() != 0 and t_it != titulo.end()){
      bool match = false;
      list<Palabra>::iterator aux_it = aux.begin();
      while(not match and aux_it != aux.end()){
        if((*t_it).son_iguales(*aux_it)){
          match = true;
          aux_it = aux.erase(aux_it);
        }
      }
    }
    //tratamiento string
    istringstream i_autor_texto((*it1).autor_texto());
    string s_aux;
    list<Palabra> autor; list<Palabra>::iterator t_it = autor.begin();
    while(i_autor_texto >> s_aux){
      autor.insert(t_it, s_aux);
    }
    t_it = autor.begin();
    while(aux.size() != 0 and t_it != titulo.end()){
      bool match = false;
      list<Palabra>::iterator aux_it = aux.begin();
      while(not match and aux_it != aux.end()){
        if((*t_it).son_iguales(*aux_it)){
          match = true;
          aux_it = aux.erase(aux_it);
        }
      }
    }
    //tratamiento string
    contenido = (*it).contenido();
    list<Frase>::iterator it2 = contenido.begin();
    while(aux.size() != 0 and it2 != contenido.end()) {
      list<Palabra>::iterator it3 = (*it2).begin();
      while(aux.size() != 0 and it3 != (*it2).end()){
        bool match = false;
        list<Palabra>::iterator aux_it = aux.begin();
        while(not match and aux_it != aux.end()){
          if((*it3).son_iguales(*aux_it)){
            match = true;
            aux_it = aux.erase(aux_it);
          }
        }
      }
    }
    if(aux.size() == 0) textos_condicion.insert(textos_condicion.end(), *it1);
  }
  if(aux.size() == 1) return *(aux.begin());
  else cout << "ERROR" << endl;
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

