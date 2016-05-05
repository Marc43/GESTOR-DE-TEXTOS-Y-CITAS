/** @file Autor.hh
 *  @brief Especificacion de la clase Autor
 */

#ifndef AUTOR_HH
#define AUTOR_HH

#include "Textos.hh"

/*
 * Clase Autor
 */

/** @class Autor
 *  @brief Representa un autor de algún texto almacenado por el programa
 *  <b>textos</b> es un vector que contiene los textos escritos por el autor
 *  <b>citas</b> es un map, donde el key es el identificador de la cita, mapeando a la Cita
 *  <b>nombre</b> representa el nombre del autor en concreto
 */

class Autor {
  
  private:
    
    //Atributos de la clase Autor
    
    vector<Texto> textos;
    map<string, Cita> citas;
    string nombre;
    
  public:
    
    //Metodos de la clase Autor
    
    /* Constructoras */
    
    /** @brief Constructora de la clase Autor
     * 	\pre cierto
     * 	\post crea un objeto de la clase Autor
     */
    Autor();
    
    /* Consultoras */
    
    /** @brief Consultora de las citas de los textos del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla las citas del autor, ordenadas por referencia.
     */
    void citas_autor();
    
    /** @brief Consultora de los textos del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla todos los textos del autor, ordenados
     * 	alfabeticamente
     */
    void textos_autor();
    
    /** @brief Consultora del nombre del p.i.
     *  \pre cierto
     *  \post devuelve la string que 
     *  contiene el nombre del p.i
     */
     string nombre_autor();
    
    /* Modificadoras */
    
    /** @brief Modificadora que anade un texto al p.i.
     * 	\pre texto es un texto no vacio
     * 	\post texto pertenece a los textos del autor
     */
    void anadir_text(Texto texto);
    
    /** @brief Modificadora que elimina un texto del p.i.
     * 	\pre existe un texto del autor tal que su titulo es <b>titulo</b>
     * 	\post en la lista de textos del autor no existe dicho texto
     */
    void eliminar_text(string titulo);
    
    /** @brief Modificadora que anade una cita al p.i.
     * 	\pre <b>cita</b> es una cita no vacia
     * 	\post <b>cita</b> cita pertenece a las citas del autor
     */
    void anadir_cita(Cita cita);
    
    /** @brief Modificadora que elimina una cita de las citas del autor
     * 	\pre existe una cita del autor tal que su referencia es <b>identificador</b>
     * \post dicha cita ya no pertenece a las citas del autor 
     */
    void eliminar_cita(string identificador);
    
}
