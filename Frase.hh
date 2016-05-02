/** @file Frase.hh
 *  @brief Especificacion de la clase Frase
 */

#ifndef FRASE_HH
#define FRASE_HH

#include "Palabra.hh"
#include <vector>

/*
 * Clase Frase
 */

/** @class Frase
 *  @brief Representa la frase, es decir, la union de palabras
 *  <b>frase</b> es un vector de palabras ya que siempre mantendran su forma
 *  <b>num_palabras</b> es el atributo destinado a guardar el numero de palabras
 *  del parametro implicito, es decir, frase.size();
 */

class Frase {
  private:
    //Atributos clase Frase
    vector<Palabra> frase; 
    int num_palabras; // num_palabras == frase.size();
  public:
    //Metodos clase Frase
    
    /* Constructoras */
    
    /** @brief Constructora de la clase Frase
     * \pre cierto
     * \post crea un objeto de la clase Frase
     */
    Frase();
    
    /* Consultora */
    
    /** @brief Consultora de Frase en cuanto a su longitud
     * \pre cierto
     * \post retorna el numero de palabras de. p.i
     */
    int longitud_frase();

    /* Modificadoras */
    
    /** @brief Modificadora de Frase en cuanto a su contenido
     * \pre cierto
     * \post lee por pantalla las frases escritas
     * separadas por: '.', '?' y '!'
     */
    void leer_frase();    
    
}