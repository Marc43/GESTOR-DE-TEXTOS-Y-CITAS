/** @file Texto.hh
 *  @brief Especificacion de la clase Texto
 */

#ifndef TEXTO_HH
#define TEXTO_HH

#include <set>
#include <map>
#include "Frase.hh"
#include "Cita.hh"

/*
 * Clase Texto
 */

/** @class Texto
 *  @brief Representa un texto.
 *  <b>autor</b> es el nombre del autor del texto.
 *  <b>titulo</b> es el titulo del texto
 *  <b>contenido</b> es el conjunto de frases que forman el cuerpo del texto
 *  <b>citas</b> son las frases citadas del texto
 *  <b>num_frases</b> es el numero de frases, <b>num_palabras</b> es el numero de palabras
 *  <b>frecuencia_palabras</b> es un diccionario, donde el key es la frecuencia de las palabras, y 
 *  cada key le corresponde un vector de palabras donde el indice es la longitud de las
 *  palabras, y el vector en esa posicion contiene el set de las palabras con esa longitud
 */

class Texto {

    struct bool_exp{
        list<Frase> i, d;
        char op;
    };

private:

    //Atributos de la clase Texto

    string autor;
    string titulo;
    list<Frase> contenido;
    map<string, map<int, Cita> > citas;
    int num_frases;
    int num_palabras;
    map<int, vector< set <string> > > tabla_frecuencias;
    map<string, int> frecuencia_palabras;

    //funciones auxiliares
    /*list<Frase> frases_palabra(string palabra);
    list<Frase> interseccion(list<Frase> a, list<Frase> b);
    list<Frase> fusion(list<Frase> a, list<Frase> b);*/

public:

    //Metodos de la clase Texto

    /* Constructoras */

    /**	@brief Constructora de la clase Texto
     * 	\pre cierto
     * 	\post crea un objeto de la clase Texto vacio
     */
    Texto();

    /**	@brief Constructora de la clase Texto
     * 	\pre cierto
     * 	\post crea un objeto de la clase Texto con los atributos correspondientes
     *  y la tabla de frecuencias ya creada con su correspondiente asignacion
     */
    Texto(string autor, string titulo, int num_p, int num_f, list<Frase> contenido, map<string, int> frecuencia_palabras);

    /* Consultoras */

    /**	@brief Consultora del autor del p.i.
     * 	\pre cierto
     * 	\post devuelve el autor del texto
     */
    string autor_texto();

    /**	@brief Consultora del titulo del p.il
     * 	\pre cierto
     * 	\post devuelve el titulo del texto
     */
    string titulo_texto();

    /**	@brief Consultora de las citas del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla las citas del texto, acompanadas por su referencias
     *  en caso que valga false el booleano c, si valiese true, ademas imprimiria el autor
     *  y texto al cual van asociadas las citas imprimidas por pantalla.
     */
    void citas_texto(bool c);

    /** @brief Consultora sobre si una cita existe en el p.i.
     *  \pre cierto
     *  \post devuelve cierto si la cita esta almacenada 
     *  en el p.i., falso en caso contrario
     */
    bool existe_cita(int x, int y);

    /**	@brief Consultora del numero de frases del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el numero
     *  de frases del texto
     */
    int numero_frases();

    /**	@brief Consultora del numero de palabras del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el numero 
     *  de palabras del texto
     */
    int numero_palabras();

    /**	@brief Consultora del contenido del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el contenido 
     *  (las frases con su numeracion) del texto.
     */
    void mostrar_contenido_texto();

    /**	@brief Consultora de las frecuencias de cada palabra del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla las palabras del texto ordenadas
     * 	decrecientemente por frecuencia, y en caso de empate, crecientemente
     * 	por largada y alfabeticamente.
     */
    void tabla_frecuencias_texto();

    /**	@brief Consultora de las frases entre la #x y la #y, ambas incluidas
     * 	\pre x y forman un intervalo valido
     *  (x > 0 & y > 0) y ademas y < numero de frases
     * 	\post Muestra por pantalla las frases <b>x</b> e 
     *  <b>y</b>, ambas incluidas en el intervalo
     */
    void frases_xy(int x, int y);

    /**	@brief Consultora de un conjunto de frases dada una expresion logica
     * 	\pre cierto
     * 	\post muestra por pantalla las frases del texto escogido
     *  que cumplen las expresion logica dada
     */
    void frases_exp(istringstream &iss);

    /** @brief Consultora de frases dada una expresion sequencial
     *  \pre cierto
     *  \post muestra por pantalla las frases del texto escogido que 
     *  cumplen la sequencia de palabras dada
     */
    void frases_seq(list<string>& seq);
    
    /** @brief Consultora de la frecuencia de las palabras en un texto
     *  \pre cierto
     *  \post Devuelve un map asociado al texto
     *  el cual tiene de key la palabra y contiene
     *  la frecuencia de dicha palabra.
     */
    map<string, int> frecuencia_palabras_texto();
    
    
    /** @brief Consultora del contenido de un texto
     *  \pre cierto
     *  \post Devuelve una lista que contiene
     *  todas y cada una de las frases (objeto Frase)
     *  pertenecientes al texto del cual estamos 
     *  devolviendo su contenido
     */
    list<Frase> contenido_texto();
    
    /* Modificadoras */

    /**	@brief Modificadora que anade una cita al p.i.
     * 	\pre cierto
     * 	\post <b>c</b> pertenece a las citas del texto, con su identificador.
     */
    void anadir_cita_texto(const Cita &c, string ini, int num);

    /**	@brief Modificadora que elimina una cita del p.i.
     * 	\pre existe una cita cuyo identificador es <b>identificador</b>
     * 	\post dicha cita deja de pertenecer a las citas del texto.
     */
    void eliminar_cita_texto(string ini, int num);

    /**	@brief Modificadora que sustituye una palabra por otra del p.i.
     * 	 \pre <b>p1</b> aparece en el texto
     * 	\post todas las apariciones de <b>p1</b> en el texto son <b>p2</b>
     */
    void sustituir_palabra(string &p1, string &p2);
    
};
#endif
