/** @file Palabra.hh
  * @brief Especificacion de la clase Palabra
  */

#ifndef PALABRA_HH
#define PALABRA_HH

#include<iostream>
#include <list>
using namespace std;

/*
 * Clase Palabra
 */

/** @class Palabra
  * @brief Reperesenta la unidad minima de un texto, la palabra
  * <b>palabra</b> la lista contiene los caracteres de la palabra
  * <b> longitud</b> es el <b>palabra</b>.size() es decir, la longitud  
  */

class Palabra {
  private:
    //Atributos de la clase Palabra
    list<char> palabra;
    int longitud;
  public:
    //Metodos de la clase Palabra
    
    /* Cronstructoras */
    
     /** @brief Constructora de la clase Palabra
     * \pre cierto
     * \post crea un objeto de la clase Palabra
     */
    Palabra(string palabra);

    
    /* Consultoras */
    
    /** @brief Consultora de la longitud de la palabra
     * \pre cierto
     * \post retorna la longitud del p.i
     */
    int longitud();
    
    /** @brief Consultora acerca de si la palabra contiene un signo de puntuacion
     * \pre cierto
     * \post retorna true si el p.i tiene un signo de puntuacion
     * pegado al final, en caso contrario, retorna false
     */
    bool signo_puntuacion();
    
    /** @brief Consultora de igualdad de palabras
     * \pre cierto
     * \post retorna true si <b>p</b> es igual 
     * al p.i en cualquier otro caso, false
     */
    bool son_iguales(Palabra p);
    
    /* Modificadoras */
    
    /** @brief Modificadora de signo de puntuacion en una palabra
     * \pre cierto
     * \post if (p.i).signo_puntuacion(); == true, devuelve la 
     * palabra del p.i sin ninguna clase de signo de puntuacion,
     * else, retorna la palabra, sin importar su estado
     */
    list<char> palabra(bool refined);
    
    /** @brief Modificadora de tamaño de una palabra (identificador)
     * \pre el p.i es un identificador de cita = ID
     * \post ID = ID + la concatenacion del caracter c
     * es decir, ID.size() += 1, donde ID[ID.size() - 1] = c
     * obteninedo: [0...n - 1, c]
     */
    void ampliar_palabra(char c);

    /** @brief Modificadora de la composicion de una palabra
     * \pre el p.i es una palabra vacia
     * \post el p.i contiene la palabra entrada por pantalla
     */
    void leer_palabra(string s); 
    
}
