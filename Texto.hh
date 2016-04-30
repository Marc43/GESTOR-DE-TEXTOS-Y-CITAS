#include "Frase.hh"

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
    
    string autor();
    /* Pre: Cierto */
    /* Post: Devuelve el autor del p.i */
    
    string titulo();
    /* Pre: Cierto */
    /* Post: Devuelve el titulo del p.i */
    
    void contenido();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla el contenido del p.i */
    
    vector<Frase> frases(int x, int y, bool cita);
    /* Pre: x > 0 ^ y < this->contenido.size(); */
    /* Post: not cita -> muestra por pantalla el contenido del texto */
    /* desde la frase x hasta la frase y ^ devuelve un vector vacio  */
    /* else devuelve el vector de las frases desde x hasta y del p.i */
    /* y genera un identificador para la cita...                     */
    
    void citas_texto();
    /* Pre: Cierto */
    /* Post: Muestra las referencias de las citas asociadas al p.i */
    
    void tabla_frecuencias();
    /* Pre: Cierto */
    /* Post: Devuelve las palabras del p.i y su frecuencia */
    
    list<int> frases(expresion);
    /* Pre: Cierto */
    /* Post: Muestra por pantalla las frases del p.i */
    /* que corresponden con la expresion introducida */
    /* ordenadas por numero                          */
    
    void eliminar_cita(string identificador);
    /* Pre:Identificador = ID, existe una cita en el p.i y */
    /* su ID es identificador 				  */
    
}