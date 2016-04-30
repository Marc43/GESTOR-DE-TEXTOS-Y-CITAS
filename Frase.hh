#ifndef FRASE_HH
#define FRASE_HH

#include "Palabra.hh"
#include <list>

class Frase {
  private:
    //Atributos clase Frase
    list<string> frase; 
    int num_palabras; // num_palabras == frase.size();
  public:
    //Metodos clase Frase
    
    void leer_frase();
    /* Pre: Cierto */
    /* Post: Lee por pantalla las frases escritas */
    /* separdas por: '.', '?' y '!'               */
    
    int longitud_frase();
    /* Pre: Cierto */
    /* Post: Retorna el numero de palabras del p.i */
}