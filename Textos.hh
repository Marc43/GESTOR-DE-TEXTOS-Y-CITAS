#ifndef TEXTOS_HH
#define TEXTOS_HH

#include "Texto.hh"

class Textos {
  private:
    //Atributos de Textos
    vector<Texto> textos;
    Texto texto_escogido;
    bool escogido;
  public:
    //Funciones de Textos
  
    void anadir_texto(Texto texto, Autores autores);
    /* Pre: texto es un Texto con título y autor  */
    /* Post: texto pertenece al p.i y su autor ha */
    /* sido añadido a autores                     */
  
    bool escoger_texto(); 
    /* Pre: Cierto */
    /*Post: return true ^ this->texto_escogido = “Texto requerido”*/
    /*else return false*/
    
    void todos_textos();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla todos los textos ordenados por autor y
    /*posteriormente por titulo*/
    
    void eliminar_texto();
    /* Pre: Cierto */
    /* Post: Ultimo texto seleccionado ha sido borrado ^ bool escogido = false*/
  
}