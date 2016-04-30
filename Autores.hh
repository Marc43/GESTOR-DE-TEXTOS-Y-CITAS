#ifndef AUTORES_HH
#define AUTORES_HH

#include "Textos.hh"
#include "Autor.hh"

class Autores {
  private:
    //Atributos de la clase Autores
    vector<Autor> autores;  
  public:
    //Metodos de la clase Autores
    
    Autor autor_nombre(string nombre);
    /* Pre: Cierto */
    /* Post: return aturo con this->nombre == nombre */
    
    void anadir_autor(Autor autor);
    /* Pre: Autor no esta vacio (tiene nombre) */
    /* Post: Autor pertenece al p.i...         */
    
    void eliminar_autor(string nombre);
    /* Pre: Cierto */
    /* Post: Si existe un Autor en el p.i tal que                 */
    /* this->nombre == nombre, el autor ha sido eliminado del p.i */
    
    void todos_autores();
    /* Pre: Cierto */
    /* Post: Imprime por pantalla todos los */
    /* autores pertenecientes al p.i...     */
    
}