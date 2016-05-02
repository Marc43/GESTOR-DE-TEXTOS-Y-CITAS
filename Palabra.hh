#ifndef PALABRA_HH
#define PALABRA_HH

#include<iostream>
#include <list>
using namespace std;

class Palabra {
  private:
    //Atributos de la clase Palabra
    list<char> palabra;
    int longitud;
  public:
    //Metodos de la clase Palabra
    
    /* Cronstructoras */
    
    Palabra();
    
    /* Consultoras */
    
    int longitud();
    /* Pre: Cierto */
    /* Post: Retorna la longitud del p.i */
    
    bool signo_puntuacion();
    /* Pre: Cierto */
    /* Post: Devuelve true si el p.i tiene un signo de      */
    /* puntuacion pegado al final, en caso contrario, false */
    
    bool son_iguales(Palabra p);
    /* Pre: Cierto */
    /* Post: Retorna true si las   */
    /* palabras son iguales, false */
    /* en cualquier otro caso...   */
    
    /* Modificadoras */
    
    list<char> palabra(bool refined);
    /* Pre: Cierto */
    /* Post: if refined == true, devuelve la palabra del p.i    */
    /* sin ninguna clase de signo de puntuacion, es decir, sola */
    /* else, retorna la palabra, sin importar su estado...      */
    
    void ampliar_palabra(char c);
    /* Pre: El p.i es un identificador de cita = ID          */
    /* Post: ID = ID + la concatenacion del caracter c       */
    /* es decir, ID.size() += 1, donde ID[ID.size() - 1] = c */
    /* obteniendo: [0...n - 1, c]... */    
    
}