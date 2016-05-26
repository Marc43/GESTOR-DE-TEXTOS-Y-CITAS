//
// Created by Zebs on 17/05/2016.
//

#ifndef GESTOR_HH
#define GESTOR_HH

#include "Autor.hh"


/* Anadido el atributo num_textos a la clase Autor, modificada el metodo textos_autor(), ahora solo imprime
 * anadido el metodo, numero_textos_autor()                                                                 */



/*
 * Clase Gestor
 */

/** @class Gestor
 *  @brief Gestiona todas las estructuras generales
 *  de lo que viene siendo el gestor de textos y citas,
 *  es decir, Autores, Textos y Citas.
 */

class Gestor {

    private:

        //Atributos de la clase Gestor

        //Autores
        map <string, Autor> autores;

        //Textos
        map <string, Texto> textos;
        map <string, Texto>::iterator texto_escogido; //Iterador que apunta al texto
        bool escogido;

        //Citas
        map<string, map<int, Cita> > citas;

    public:

        //Metodos de la clase Gestor

        /* Constructoras */

        /** @brief Constructora de la clase Gestor
         *  Crea un objeto vacio
         */
        Gestor();

        /** @brief Consultora de existencia de un autor dado su nombre
         *  \pre cierto
         *  \post devuelve cierto si existe un autor con nombre <b>nombre</b>
         *  en la estructura, en caso contrario, devuelve falso
         */
         bool existe_autor(string nombre);

        /** @brief Consultora de existencia de un texto
         *  \pre cierto
         *  \post devuelve cierto si existe un texto de tal autor
         *  con el mismo titulo, para <b>nombre</b> y <b>titulo</b>
         */
        bool existe_texto_autor(string nombre, string titulo);

        /** @brief Consultora de los autores almacenados en la estructura
         *  \pre cierto
         *  \post imprime por pantalla dichos autores
         */
        void todos_autores();

        /* Modificadoras */

        /** @brief Modificadora que anade un autor a los autores
         *  \pre <b>autor</b> no es vacio
         *  \post <b>autor</b> pertenece a los autores, en caso
         *  de pertenecer anteriormente, ha sido actualizado con
         *  la nueva version introducida en parametros.
         */
        void anadir_autor_gestor(Autor autor);

        /** @brief Modificadora que anade un texto a gestor
         *  \pre cierto
         *  \post el Texto <b>texto</b> ha sido anadido al p.i
         *  en caso de no existir uno con mismo autor y titulo
         */
        void anadir_texto_gestor(string nombre, string titulo);

        /** @brief Modificadora que elimina un texto del gestor
         * \pre hay un texto escogido
         * \post dicho texto ha sido eliminador del p.i
         * y no hay ningun texto escogido
         */
        void eliminar_texto_gestor();

        /** @brief Consultora que escoge un texto en funcion de la aparicion
         * de las palabras en este...
         * \pre cierto
         * \post devuelve cierto si se encuentra un texto en el que aparezcan las
         * palabras de la lista, y <b>t</b> es dicho texto, devuelve falso y
         * un texto vacio en caso que no exista tal texto
         */
        bool escoger_texto(const list<string>& p, Texto& t);

        /** @brief Consultora que muestra todos los textos almacenados por el gestor
         *  \pre cierto
         *  \post muestra por pantalla todos los textos del p.i
         */
        void todos_textos();

        /** @brief Consultora que muestra todos los textos de un autr
         *  \pre cierto
         *  \post muestra todos los textos del autor con
         *  nombre <b>nombre</b>
         */
        void textos_autor(string nombre);

        void citas_autor(string nombre);

        void citas_texto_escogido();

        /** @brief Consultora que retorna si hay un texto escogido
         *  \pre cierto
         *  \post retorna cierto si existe tal texto,
         *  false en caso contrario
         */
        bool esta_escogido();

        /** @brief Consultora que retorna el texto_escogido
         *  \pre cierto
         *  \post retorna el texto_escogido
         */
        Texto texto_escogido_gestor();

        /** @brief Consultora delas citas del p.i.
         * \pre cierto
         * \post muestra por pantalla las citas del gestor
         */
        void todas_citas();

        /** @brief Modificadora que anade una cita al p.i.
         *  \pre cierto
         *  \post <b>cita</b> ha sido anadida al p.i. con su correspondiente etiqueta
         */
        void anadir_cita_gestor(int x, int y);

        /** @brief modificadora que elimina una cita dado su identificador
         *  \pre existe una cita con identificador = <b>id</b>
         *  \post dicha cita ya no pertence al p.i.
         */
        void eliminar_cita_gestor(string id);

        void info_cita(string id);

	void recorta(istringstream& iss);
	
	void anadir_texto_gestor(Texto& t);

};

#endif //GESTOR_HH
