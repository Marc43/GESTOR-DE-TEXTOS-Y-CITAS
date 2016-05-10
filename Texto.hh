/** @file Texto.hh
 *  @brief Especificacion de la clase Texto
 */

#ifndef TEXTO_HH
#define TEXTO_HH

#include "Citas.hh"

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
 *  cada key le corresponde un vector de palabras con esa frecuencia.
 *  <b>frecuencia_maxima</b> guarda la frecuencia de la palabra con frecuencia maxima
 */

class Texto {
  
  private:
    
    //Atributos de la clase Texto
    
    string autor;
    string titulo;
    list<Frase> contenido;
    map<string, Cita> citas;
    vector<string> identificadores;
    int num_frases;
    int num_palabras;
    map<char, list<string>> frecuencia_palabras;
    int frecuencia_maxima;
    
  public:
    
    //Metodos de la clase Texto
    
    /* Constructoras */
    
    /**	@brief Constructora de la clase Texto
     * 	\pre cierto
     * 	\post crea un objeto de la clase Texto
     */
    Texto();
    
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
     */
    void citas_texto();
    
    /**	@brief Consultora del numero de frases del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el numero de frases del texto
     */
    void numero_frases();
    
    /**	@brief Consultora del numero de palabras del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el numero de palabras del texto
     */
    void numero_palabras();
    
    /**	@brief Consultora del contenido del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla el contenido (las frases) del texto.
     */
    void contenido();
    
    /**	@brief Consultora de las frecuencias de cada palabra del p.i.
     * 	\pre cierto
     * 	\post muestra por pantalla las palabras del texto ordenadas
     * 	decrecientemente por frecuencia, y en caso de empate, crecientemente
     * 	por largada y alfabéticamente.
     */
    void tabla_frecuencias();
    
    /**	@brief Consultora de las frases entre la #x y la #y, ambas incluidas
     * 	\pre x > 0 e y < contenido.size()
     * 	\post si <b>cita</b> es falso, muestra por pantalla el contenido del p.i.
     * 	entre las frases <b>x</b> e <b>y</b>, ambas incluidas, y devuelve una cita vacia.
     * 	en caso contrario devuelve una cita con estas frases, creando su identificador.
     */
    Cita frases_xy(int x, int y, bool cita, Citas& citas);
    
    /**	@brief Consultora de un conjunto de frases dado un numero de palabras del texto
     * 	\pre cierto
     * 	\post muestra por pantalla las frases que contengan las palabras correspondientes
    void frases_npal();
    
    /**	@brief Consultora de un conjunto de frases dada una expresion logica
     * 	\pre cierto
     * 	\post muestra por pantalla las frases que cumplen las expresion logica
     */
    void frases_exp(/*expresion*/); //Diferente de frases "<paraula1> ... <paraulaN>" ???
    
    /* Modificadoras */
    
    /**	@brief Modificadora que anade una cita al p.i.
     * 	\pre cierto
     * 	\post <b>c</b> pertenece a las citas del texto, con su identificador.
     */
    void anadir_cita(Cita c);
    
    /**	@brief Modificadora que elimina una cita del p.i.
     * 	\pre existe una cita cuyo identificador es <b>identificador</b>
     * 	\post dicha cita deja de pertenecer a las citas del texto.
    void eliminar_cita(string identificador);
    
    /**	@brief Modificadora que sustituye una palabra por otra del p.i.
     * 	 \pre <b>p1</b> aparece en el texto
     * 	\post todas las apariciones de <b>p1</b> en el texto son <b>p2</b>
     */
    void sustituir_palabra(Palabra p1, Palabra p2);
    
}
