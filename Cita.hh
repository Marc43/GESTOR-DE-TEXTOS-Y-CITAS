/** @file Cita.hh
 *  @brief Especificacion de la clase Cita
 */

#ifndef CITA_HH
#define CITA_HH

#include "Frase.hh"
#include <string>

/*
 * Clase Cita
 */

/** @class Cita
 *  @brief Representa una cita de un texto
 *  <b>contenido</b> contiene las frases que forman la cita
 *  <b>titulo_texto</b> es el titulo asociado al texto al que pertenece
 *  <b>autor</b> representa el nombre del autor del texto al que pertenece
 *  <b>x</b> e <b>y</b> representan el numero de frases inicial y final en el texto
 *  <b>identificador</b> es el identificador asociado a la cita, dada por las iniciales del
 *    autor y un numero de orden de aparicion
 */

class Cita {
  
  private:
    
    //Atributos de la clase Cita
    
    vector<Frase> contenido;
    string titulo_texto;
    string autor_texto;
    int x, y;
    string identificador;
  
  public:
    
    //Metodos de la clase Cita
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Cita 
     * 	\pre cierto
     * 	\post crea un objeto de la clase Cita
     */
    Cita(vector<Frase> contenido, string titulo_texto, string autor_texto, int x, y, string identificador);
    
    /* Consultoras */
    
    /**	@brief Muestra toda la informacion relativa a una Cita
     * 	\pre cierto
     * 	\post muestra por pantalla la informacion del p.i. (titulo, autor, frase inicial, final y contenido)
     */
    void info();
    
    /** @brief Devuelve el titulo asociado a la cita
     *  \pre cierto
     *  \post devuelve el titulo del texto asociado al p.i.
     */
     string titulo();
     
     /** @brief Devuelve el autor de la cita
      *  \pre cierto
      *  \post devuelve el autor asociado al p.i.
      */
      string autor();
      
      /** @brief Devuelve el contenido de la cita
       *  \pre cierto
       *  \post devuelve el contenido del p.i.
       */
       vector<Frase> contenido();
  
}
