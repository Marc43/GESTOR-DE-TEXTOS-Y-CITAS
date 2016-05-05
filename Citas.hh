/** @file Citas.hh
 *  @brief Especificacion de la clase Citas
 */

#ifndef CITAS_HH
#define CITAS_HH

#include "Cita.hh"

/*
 * Clase Citas
 */

/** @class Citas
 *  @brief Representa todas el conjunto de citas almacenada por el programa
 *  <b>citas</b> es un map, donde el key es el identificador de la cita, formado por las iniciales del autor
 *  y un entero que representa un orden, acompañadas de una Cita
 *  <b>id</b> es un map, con un string, que son las letras del identificador (las inciales de uno o mas autores),
 *  acompañadas en cada momento de la ejecucion por el numero que tocaria en caso de anadir una Cita con ese
 *  identificador
 */

class Citas {
  
  private:
    
    //Atributos de la clase Citas
    
    map<string, Cita> citas; //Contiene todas las citas de todos los textos de Textos.
    map<string, int> id; //Contiene el numero de citas actuales con las dos iniciales como key.
  
  public:
    
    //Metodos de la clase Citas
    
    /* Constructoras */
    
    Citas();
    
    /* Consultoras */
    
    /** @brief Consultora que muestra todas las citas del p.i., ordenados por referencia
     * 	\pre cierto
     * 	\post imprime por pantalla todas las citas del p.i., por orden de referencia
     */
    void todas_citas();
    
    /* Modificadoras */
    
    /**	@brief Modificadora que anade una cita al p.i.
     * 	\pre cierto
     * 	\post <b>cita</b> ha sido anadida al p.i., con su correspondiente identificador.
    void anadir_cita(Cita cita);
    
    /**	@brief Modificadora que elimina una cita dado su identificador
     * 	\pre existe una cita cuyo identificador es <b>identificador</b>
     * 	\post se ha eliminado dicha cita del p.i.
     */
    void eliminar_cita(string identificador);
    
}