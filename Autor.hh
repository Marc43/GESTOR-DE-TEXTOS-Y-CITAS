#include "Texto.hh"
#include "Cita.hh"

class Autor {
  private:
    //Atributos de la clase Autor
    vector<Texto> textos;
    map<string, Cita> citas;
    string nombre;
  public:
    //Metodos de la clase Autor
    
    void anadir_text(Texto texto);
    /* Pre: Texto es un texto no vacio */
    /* Post texto pertenece al p.i     */
    
    void eliminar_text(string titulo);
    /* Pre: Existe un texto en el p.i tal que su titulo == titulo */
    /* Post: Dicho texto ya no pertenece al p.i                  */
    
    void anadir_cita(Cita cita);
    /* Pre: cita es una Cita no vacia */
    /* Post: cita pertenece al p.i    */
    
    void eliminar_cita(string identificador);
    /* Pre: Identificador = ID, existe una cita en p.i tal que */
    /* su ID == identificador...                               */
    /* Post: Dicha cita ya no pertenece al p.i                 */
    
    void citas_autor();
    /* Pre: Cierto */
    /* Post: Muestra la informacion de todas citas del autor */
    /* es decir, contenido y el titulo del cual provienen, ordenadas por referencia */
    
    void texto_autor();
    /* Pre: Cierto */
    /* Post: Muestra por pantalla todos los textos  */
    /* del p.i ordenadas por titulo alfabeticamente */
    
}