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
    
    /** @brief Consultora que muestra todas las citas de todos los textos, ordenados por referencia
     * 	\pre cierto
     * 	\post imprime por pantalla todas las citas de todos los textos, por orden de referencia
     */
    void todas_citas();
    
    /* Modificadoras */
    
    /**	@brief Modificadora que anade una cita a las citas
     * 	\pre cierto
     * 	\post <b>cita</b> ha sido anadida a las citas, con su correspondiente identificador.
    void anadir_cita(Cita cita);
    
    /**	@brief Modificadora que elimina una cita dado su identificador
     * 	\pre existe una cita cuyo identificador es <b>identificador</b>
     * 	\post se ha eliminado dicha cita de las citas
     */
    void eliminar_cita(string identificador);
    
}