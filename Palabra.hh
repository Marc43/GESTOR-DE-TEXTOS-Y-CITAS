#ifndef PALABRA_HH
#define PALABRA_HH

#include<iostream>
#include <string>
using namespace std;

class Palabra {
  private:
    //Atributos de la clase Palabra
    string palabra;
    int longitud;
  public:
    //Metodos de la clase Palabra
    
    string palabra(bool refined);
    /* Pre: Cierto */
    /* Post: if refined == true, devuelve la palabra del p.i    */
    /* sin ninguna clase de signo de puntuacion, es decir, sola */
    /* else, retorna la palabra, sin importar su estado...      */
    
    int longitud();
    /* Pre: Cierto */
    /* Post: Retorna la longitud del p.i */
    
    bool signo_puntuacion();
    /* Pre: Cierto */
    /* Post: Devuelve true si el p.i tiene un signo de      */
    /* puntuacion pegado al final, en caso contrario, false */
    
    void ampliar_palabra(char c);
    /* Pre: El p.i es un identificador de cita = ID          */
    /* Post: ID = ID + la concatenacion del caracter c       */
    /* es decir, ID.size() += 1, donde ID[ID.size() - 1] = c */
    /* obteniendo: [0...n - 1, c]... */    
}