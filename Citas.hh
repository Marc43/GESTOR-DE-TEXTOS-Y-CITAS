#include "Cita.hh"

class Cita {
  private:
    //Atributos de la clase Cita
    map<string, Cita> citas; //Contiene todas las citas de todos los textos de Textos.
  public:
    //Metodos de la clase Cita
    
    void anadir_cita(Cita cita);
    /* Pre: Cierto */
    /* Post cita ha sido anadida al p.i con el identificador pertinente, donde    */
    /* este sera las dos primeras iniciales del nombre del autor con el numero    */
    /* correspondiente al numero de cita creada para un autor con tales iniciales */
    
    void eliminar_cita(string identificador);
    /* Pre: Existe una cita tal que this->identificador == identificador */
    /* Post: Se ha eliminado la cita correspondiente del p.i		 */
    
    void todas_citas();
    /* Pre: Cierto */
    /* Post: Imprime por pantalla todas las citas de todos los textos         */
    /* por orden de referencia, es decir, orden cronologico de adicion al p.i */
    
    void imprimir_citas(vector<string>& identificadores);
    /* Pre: identificadores contiene el identificador de las citas deseadas */
    /* Post: Imprime por pantalla todas las citas correspondientes a los identificadores */
    
}