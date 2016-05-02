/** @file Textos.hh
 *  @brief Especificacion de la clase Textos
 */

#ifndef TEXTOS_HH
#define TEXTOS_HH

#include "Texto.hh"

/*
 * Clase Textos
 */

/** @class Textos
 *  @brief Representa todos los textos almacenados por el programa
 */

class Textos {
  
  private:
    //Atributos de Textos
    
    vector<Texto> textos;
    Texto texto_escogido;
    bool escogido;
    
    //Funcion auxiliar 
    bool comp(Texto t1, Texto t2);
    
  public:
    
    //Funciones de Textos
    
    /* Constructoras */
    
    /** @brief Constructora de la clase Textos
     * 	\pre cierto
     * 	\post crea un objeto de la clase Textos 
     */
    Textos();
    
    /* Modificadoras */
    
    /** @brief Modificadora del p.i. para anadir un texto
     * 	\pre <b>texto</b> es un Texto con título y autor
     * 	\post <b>texto</b> pertenece al p.i y su autor ha 
     *  sido añadido a <b>autores</b> 
     */
    void anadir_texto(Texto texto, Autores& autores);
    
    /** @brief Modificadora del p.i. para eliminar un texto
     * 	\pre cierto
     * 	\post elimina el ultimo texto seleccionado del p.i.
     */
    void eliminar_texto();
    
    /* Consultoras */
  
    /** @brief Consultora que escoge un texto en funcion de la aparicion
     * 	de palabras en éste
     * 	\pre cierto
     * 	\post devuelve cierto si se encuentra un texto en el que aparezcan las
     * 	palabras, y <b>t</b> es este texto. Devuelve falso en caso contrario.
     */
    bool escoger_texto(Texto &t); 
    
    /**
     * @brief Consultora que muestra todos los textos almacenados por el programa
     * 	\pre cierto
     * 	\post muestra por pantalla todos los textos del p.i.
     */
    void todos_textos();
    
}