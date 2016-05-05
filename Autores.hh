/** @file Autores.hh
 *  @brief Especificacion de la clase Autores
 */

#ifndef AUTORES_HH
#define AUTORES_HH

#include "Autor.hh"

/*
 * Clase Autores
 */

/** @class Autores
 *  @brief Representacion el conjunto de autores correspondientes
 *  con los textos...
 *  <b>autores</b> Es un map con los autores de la clase Autores ordenados alfabeticamente
 */

class Autores {
  
  private:
    
    //Atributos de la clase Autores
    
    map<string, Autor> autores;  
  
  public:
    
    //Metodos de la clase Autores
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Autores
     * 	\pre cierto
     * 	\post crea un objeto de la clase Autores
     */
    Autores();
    
    /* Consultoras */
    
    /**	@brief Consultora de un autor dado su nombre
     * 	\pre cierto
     * 	\post devuelve un autor tal que su nombre es <b>nombre</b>
     */
    Autor autor_nombre(string nombre);

    /**	@brief Consultora de todos los autores almacenados
     * 	\pre cierto
     * 	\post imprime por pantalla todos los autores almacenados
     */
    void todos_autores();

    /* Modificadoras */
    
    /**	@brief Modificadora que anade un autor a los autores
     * 	\pre <b>autor</b> no es vacio
     * 	\post <b>autor</b> pertenece a los autores
     */
    void anadir_autor(Autor autor);
    
    /**	@brief Modificadora que elimina un autor dado su nombre
     * 	\pre cierto
     * 	\post si existe un autor cuyo nombre es <b>nombre</b>, lo elimina
     * 	de los autores
     */
    void eliminar_autor(string nombre);
    
}
