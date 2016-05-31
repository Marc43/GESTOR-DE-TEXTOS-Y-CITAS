/** @file Autor.hh
 *  @brief Especificacion de la clase Autor
 */

#ifndef AUTOR_HH
#define AUTOR_HH

#include "Texto.hh"
#include "Cita.hh"

/*
 * Clase Autor
 */

/** @class Autor
 *  @brief Representa un autor de algún texto almacenado por el programa
 *  <b>textos</b> es una map donde el key es el titulo, mapeando al texto correspondiente, todos escritos por el autor
 *  <b>nombre</b> representa el nombre del autor en concreto
 */

class Autor {
  
  private:
    
    //Atributos de la clase Autor
    
    map<string, Texto> textos;
    string nombre;
    int num_textos;
    int num_palabras;
    int num_frases;
    
  public:
    
    //Metodos de la clase Autor
    
    /* Constructoras */

    /** @brief Constructora de la clase Autor
     * 	\pre cierto
     * 	\post crea un objeto de la clase Autor vacio
     */
    Autor();

    /** @brief Constructora de la clase Autor
     * 	\pre cierto
     * 	\post crea un objeto de la clase Autor, con <b>nombre</b> = nombre
     */
    Autor(string nombre);
    
    /* Consultoras */

    /** @brief Consultora del nombre del autor
     *  \pre ciert
     *  \post devuelve el nombre del autor
     */
    string nombre_autor();
    
    /** @brief Consultora de los textos del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla todos los textos del autor, ordenados
     * 	alfabeticamente. Si c, muestra el nombre del autor
     */
    void textos_autor(bool c);

    /** @brief Consultora del numero de palabras del p.i
     *  \pre cierto
     *  \post devuelve el atributo num_palabras del p.i
     */
    int numero_palabras_autor();

    /** @brief Consultora del numero de frases del p.i
     *  \pre cierto
     *  \post devuelve el atributo num_frases del p.i
     */
    int numero_frases_autor();

    /** @brief Consultora del numero de textos del p.i
     *  \pre cierto
     *  \post devuelve el atributo num_textos del p.i
     */
    int numero_textos_autor();

    /** @brief Consultora de la existencia de un texto
     *  \pre cierto
     *  \post devuelve cierto si existe un texto
     *  con nombre <b>titulo</b>, si no, false
     */
     bool existe_texto_autor(string titulo);
    
    /* Modificadoras */
    
    /** @brief Modificadora que anade un texto al p.i.
     * 	\pre texto es un texto no vacio
     * 	\post texto pertenece a los textos del autor
     */
     void anadir_texto_autor(Texto texto);
    
    /** @brief Modificadora que elimina un texto del p.i.
     * 	\pre existe un texto del autor tal que su titulo es <b>titulo</b>
     * 	\post en la lista de textos del autor no existe dicho texto
     */
    void eliminar_texto_autor(string titulo);
    
};
#endif