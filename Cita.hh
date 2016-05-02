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
 */

class Cita {
  
  private:
    
    //Atributos de la clase Cita
    
    vector<Frase> contenido;
    string titulo_texto;
    string autor;
    int x, y; //Frase inicial y frase final respectivamente...
    string identificador;
  
  public:
    
    //Metodos de la clase Cita
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Cita 
     * 	\pre cierto
     * 	\post crea un objeto de la clase Cita
     */
    Cita();
    
    /* Consultoras */
    
    /**	@brief Muestra toda la informacion relativa a una Cita
     * 	\pre cierto
     * 	\post muestra por pantalla la informacion de la Cita
     */
    void info();
  
}