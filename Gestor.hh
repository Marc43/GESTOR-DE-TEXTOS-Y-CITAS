//
// Created by Zebs on 17/05/2016.
//

#ifndef GESTOR_HH
#define GESTOR_HH

#include "Autor.hh"


/* Anadido el atributo num_textos a la clase Autor, modificada el metodo textos_autor(), ahora solo imprime
 * anadido el metodo, numero_textos_autor() */



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
        map<string, Autor> autores;

        //Textos
        map <string, Texto> textos;
        map <string, Texto>::iterator texto_escogido; //Iterador que apunta al texto
        bool escogido;

        //Citas
        map<string, map<int, Cita>> citas;

        
        /**@brief Operacion auxiliar de strings
         * \pre cierto
         * \post Todas las minusculas de la cadena
         * son ahora mayusculas
         */
         void a_mayus(string& s);

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

        /** @brief Consultora de los autores almacenados en la estructura
         *  \pre cierto
         *  \post imprime por pantalla dichos autores
         */
        void todos_autores();

        /** @brief Consultora de un autor almacenado
         *  \pre cierto
         *  \post imprime por pantalla dicho autor
         */
        void info_autor(string nombre_autor);

        /* Modificadoras */

        /** @brief Modificadora que anade un autor a los autores
         *  \pre <b>autor</b> no es vacio
         *  \post <b>autor</b> pertenece a los autores, en caso
         *  de pertenecer anteriormente, ha sido actualizado con
         *  la nueva version introducida en parametros.
         */
        void anadir_autor(Autor autor);

        /** @brief Modificadora que anade un texto a gestor
         *  \pre cierto
         *  \post el Texto <b>texto</b> ha sido creado y anadido al p.i,
         *  en caso de no existir uno con mismo autor y titulo.
         */
        void anadir_texto_gestor();

        /** @brief Modificadora que elimina un texto del gestor
         * \pre hay un texto escogido
         * \post dicho texto ha sido eliminador del p.i
         * y no hay ningun texto escogido
         */
        void eliminar_texto();

        /** @brief Consultora que escoge un texto en funcion de la aparicion
         * de las palabras en este...
         * \pre cierto
         * \post devuelve cierto si se encuentra un texto en el que aparezcan las
         * palabras de la lista, y <b>t</b> es dicho texto, devuelve falso en
         * caso contrario
         */
        bool escoger_texto(const list<string>& p);
        
        /** @brief Consultora que muestra todos los textos almacenados por el gestor
         *  \pre cierto
         *  \post muestra por pantalla todos los textos del p.i
         *
         */
        void todos_textos();

        /** @brief Consultora que retorna si hay un texto escogido
         *  \pre cierto
         *  \post retorna cierto si existe tal texto,
         *  false en caso contrario
         */
        bool esta_escogido();
        
        /** @brief Consultora(???) del texto escogido
         * \pre cierto
         * \post si, escogido era true, la funcion 
         * devuelve el texto escogido en el gestor
         */
         Texto texto_escogido();

        /** @brief Consultora sobre si existe un texto
         *  \pre cierto
         *  \post si existe un texto con nombre <b>nombre_texto</b>
         *  y nombre del autor <b>nombre_autor</b>
         *  devuelve True, en caso contrario, False
         */
         bool existe_texto(string nombre_texto, string nombre_autor);

        /** @brief Consultora delas citas del p.i.
         * \pre cierto
         * \post muestra por pantalla las citas del gestor
         */
        void todas_citas();

        /** @brief Modificadora que anade una cita al p.i.
         *  \pre cierto
         *  \post <b>cita</b> ha sido anadida al p.i. y a todas 
         *  las estructuras necesarias con su correspondiente id.
         */
        void anadir_cita_gestor(const Cita& cita);

        /** @brief Modificadora que elimina una cita dado su identificador
         *  \pre existe una cita con identificador = <b>id</b>
         *  \post dicha cita ya no pertence al p.i.
         */
        void eliminar_cita(string id);
        
        /** @brief Consultora de las citas de un autor
        *   \pre existe un autor con nombre <b>autor</b>
        *   \post imprime por pantalla todas las referencias,
        *   el contenido y el titulo del texto del cual son las citas
        */
        void citas_autor(string autor);
        
        /** @brief Consultora de una cita por su identificador
        *   \pre existe una cita con identificador <b>id</b>
        *   \post imprime por pantalla el autor, el titulo del 
        *   texto al cual cita, la frase inicial y final y 
        *   el contenido de la cita.
        */
        void info_cita(string id);
        
        /** @brief Consultora de la existencia de una cita
        *   \pre cierto
        *   \devuelve true, si existe una cita sobre el mismo
        *   texto del mismo autor y tiene el mismo rango x-y
        */
        bool existe_cita(const Cita& c);
};

#endif //GESTOR_HH
