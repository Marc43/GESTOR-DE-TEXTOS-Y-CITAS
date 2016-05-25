/** @file Frase.hh
 *  @brief Especificacion de la clase Frase
 */

#ifndef FRASE_HH
#define FRASE_HH

#include <string>
#include <list>
#include <iostream>

using namespace std;

/*
 * Clase Frase
 */

/** @class Frase
 *  @brief Representa la frase, es decir, la union de palabras
 *  <b>frase</b> es un vector de palabras ya que siempre mantendran su forma
 *  <b>num_palabras</b> es el atributo destinado a guardar el numero de palabras
 *  del parametro implicito, es decir, frase.size();
 */

class Frase {
private:
    //Atributos clase Frase
    list<string> frase;
    int num_palabras; // num_palabras == frase.size();
    int num_frase;

public:
    //Metodos clase Frase

    /* Constructoras */

    /** @brief Constructora de la clase Frase
     * \pre cierto
     * \post crea un objeto de la clase Frase vacio
     */
    Frase();

    /** @brief Constructora de la clase Frase
     * \pre cierto
     * \post crea un objeto de la clase Frase con los atributos correspondientes
     */
    Frase(list<string>& frase, int num_frase);

    /* Consultora */

    /** @brief Consultora del contenido del p.i.
     * \pre cierto
     * \post muestra por pantalla el contenido del p.i.
     */
    void escribir_frase();

    /** @brief Consultora de Frase en cuanto a su longitud
     * \pre cierto
     * \post retorna el numero de palabras de. p.i
     */
    int longitud_frase();

    /** @brief Consultora que devuelve el conte4nido de la frase
     * 	\pre cierto
     * 	\post devuelve el contenido del p.i.
     */
    list<string> contenido_frase();

    /** @brief Consultora sobre la existencia de una palabra en el pi
     *  \pre cierto
     *  \post devuelve cierto si la palabra esta en el pi, falso en caso contrario
     */
    bool existe_palabra_frase(string palabra);
};
#endif