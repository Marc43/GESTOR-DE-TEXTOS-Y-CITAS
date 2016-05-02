/** @file Palabra.hh
 *  @brief Especificacion de la clase Palabra
 */

#ifndef FRASE_HH
#define FRASE_HH

#include "Palabra.hh"
#include <vector>

/*
 * Clase Palabra
 */

/** @class Palabra
 *  @brief Representa la unidad minima del texto, la palabra
 */

class Frase {
  private:
    //Atributos clase Frase
    vector<Palabra> frase; 
    int num_palabras; // num_palabras == frase.size();
  public:
    //Metodos clase Frase
    
    /* Constructoras */

    /** @brief Constructora de la clase Palabra
     *  
    
    Frase();
    
    /* Consultora */
    
    void leer_frase();
    /* Pre: Cierto */
    /* Post: Lee por pantalla las frases escritas */
    /* separdas por: '.', '?' y '!'               */
    
    int longitud_frase();
    /* Pre: Cierto */
    /* Post: Retorna el numero de palabras del p.i */
    
}
