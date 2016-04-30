#ifndef CITA_HH
#define CITA_HH

#include "Frase.hh"
#include <vector>

class Cita {
  private:
    //Atributos de la clase Cita
    vector<Frase> contenido;
    string titulo_texto;
    string autor;
    int x, y; //Frase inicial y frase final respectivamente...
    string identificador;
  public:
    //Metodos de la clase Cita
    
    void info();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla la informacion del p.i   */
    /* auto, titulo, frase inicial, frase final, contenido */
  
}