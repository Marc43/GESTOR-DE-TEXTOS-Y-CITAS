#ifndef TEXTO_HH
#define TEXTO_HH

#include "Citas.hh"

class Texto {
  private:
    //Atributos de la clase Texto
    string autor;
    string titulo;
    vector<Frase> contenido;
    map<string, Cita> citas;
    vector<string> identificadores;
    int num_frases;
    int num_palabras;
    map<int, vector<string>> frecuencia_palabras; //Acaso se puede hacer map con key de ints?
    int frecuencia_maxima;
  public:
    //Metodos de la clase Texto
    
    /* Constructoras */
    
    Texto();
    
    Texto(Texto t);
    
    /* Consultoras */
    
    string autor();
    /* Pre: Cierto */
    /* Post: Devuelve el autor del p.i */
    
    string titulo();
    /* Pre: Cierto */
    /* Post: Devuelve el titulo del p.i */
    
    void citas_texto();
    /* Pre: Cierto */
    /* Post: Muestra las referencias de las citas asociadas al p.i */
    
    void numero_frases();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla  */
    /* el numero de frases del p.i */
    
    void numero_palabras();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla el */
    /* numero de palabras del p.i    */
    
    void contenido();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla el contenido del p.i */
    
    void tabla_frecuencias();
    /* Pre: Cierto */
    /* Post: Devuelve las palabras del p.i y su frecuencia */
    
    
    Cita frases_xy(int x, int y, bool cita);
    /* Pre: x > 0 ^ y < this->contenido.size(); */
    /* Post: not cita -> muestra por pantalla el contenido del texto */
    /* desde la frase x hasta la frase y ^ devuelve un vector vacio  */
    /* else devuelve el vector de las frases desde x hasta y del p.i */
    /* y genera un identificador para la cita...                     */
    
    void frases_npal();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla las frases   */
    /* que se correspondan con la secuencia de */
    /* de npalabras que entran por pantalla    */
    
    
    void frases_exp(/*expresion*/); //Diferente de frases "<paraula1> ... <paraulaN>" ???
    /* Pre: Cierto */
    /* Post: Muestra por pantalla las frases del p.i */
    /* que corresponden con la expresion introducida */
    /* ordenadas por numero                          */
    
    /* Modificadoras */
    
    void anadir_cita(Cita c);
    /* Pre: Cierto */
    /* Post: c pertenece al p.i */
    /* con el identificador pertinente */
    
    void eliminar_cita(string identificador);
    /* Pre:Identificador = ID, existe una cita en el p.i y */
    /* su ID es identificador 				  */
    
    void sustituir_palabra(Palabra p1, Palabra p2);
    /* Pre: p1 aparece en el texto */
    /* Post: Todas las apariciones de p1 en   */
    /* el p.i son ahora la segunda palabra p2 */
    
}