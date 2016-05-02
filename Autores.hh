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
 *  @brief Representacion el conjunto de autores de los textos guardados
 *  <b>autores</b> es un vector que recoge objetos de clase autor, de los cuales existe algun texto
 */

class Autores {
  
  private:
    
    //Atributos de la clase Autores
    
    vector<Autor> autores;  
  
  public:
    
    //Metodos de la clase Autores
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Autores
     * 	\pre cierto
     * 	\post crea un objeto de la clase Autores
     */
    Autores();
    
    /* Consultoras */
    
    /**	@brief Consultora de un autor del p.i. dado su nombre
     * 	\pre cierto
     * 	\post devuelve un autor perteneciente al p.i. tal que su nombre es <b>nombre</b>
     */
    Autor autor_nombre(string nombre);

    /**	@brief Consultora de todos los autores almacenados
     * 	\pre cierto
     * 	\post imprime por pantalla todos los elementos del p.i.
     */
    void todos_autores();

    /* Modificadoras */
    
    /**	@brief Modificadora que anade un autor al p.i.
     * 	\pre <b>autor</b> no es vacio
     * 	\post <b>autor</b> pertenece al p.i.
    void anadir_autor(Autor autor);
    
    /**	@brief Modificadora que elimina un autor dado su nombre
     * 	\pre cierto
     * 	\post si existe un autor cuyo nombre es <b>nombre</b>, lo elimina
     * 	de los autores
     */
    void eliminar_autor(string nombre);
    
}