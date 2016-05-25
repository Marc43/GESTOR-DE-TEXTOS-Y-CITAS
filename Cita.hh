/** @file Cita.hh
 *  @brief Especificacion de la clase Cita
 */

#ifndef CITA_HH
#define CITA_HH

#include "Frase.hh"
#include <vector>

/*
 * Clase Cita
 */

/** @class Cita
 *  @brief Representa una cita de un texto
 *  <b>contenido</b> contiene las frases que forman la cita
 *  <b>titulo_texto</b> es el titulo asociado al texto al que pertenece
 *  <b>autor</b> representa el nombre del autor del texto al que pertenece
 *  <b>x</b> e <b>y</b> representan el numero de frases inicial y final en el texto
 *  <b>id</b> es el identificador asociado a la cita, dada por las iniciales del
 *    autor y un numero de orden de aparicion
 */

class Cita {
  
  private:

    //Atributos de la clase Cita
    
    vector<Frase> contenido;
    string titulo_texto;
    string autor_texto;
    int x, y;
  
  public:
    
    //Metodos de la clase Cita
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Cita 
     * 	\pre cierto
     * 	\post crea un objeto de la clase Cita vacio
     */
    Cita();
    
    /**	@brief Constructora de la clase Cita 
     * 	\pre cierto
     * 	\post crea un objeto de la clase Cita con los atributos correspondientes
     */
    Cita(vector<Frase> contenido, string titulo_texto, string autor_texto, int x, int y);
    
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
     string titulo_texto_cita();
     
     /** @brief Devuelve el autor de la cita
      *  \pre cierto
      *  \post devuelve el autor asociado al p.i.
      */
      string autor_cita();

    /** @brief Consultora que escribe la cita por el canal de salida
    *  \pre cierto
    *  \post la cita ha sido escrita por el canal de salida
    */
    void escribir_cita();

    /** @brief
     *  \pre
     *  \post
     */
    int frase_inicial();

    /** @brief
     *  \pre
     *  \post
     */
    int frase_final();
};
#endif
