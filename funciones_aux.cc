#include "funciones_aux.hh"

void recorta(istringstream& iss){ //iss es un parametro de salida
    int pos = 0;
    string aux = iss.str();
    while(aux[pos] == ' ') ++pos; //Llegamos hasta el primer espacio
    while(aux[pos] != ' ' and pos < aux.length()) ++pos; //Numero de posiciones hasta el espacio
    aux.erase(0, pos + 1); //Contamos el ultimo espacio tambien
    iss.str(aux); //Convertimos la string aux en un iss
}

void refina_pf(string& palabra){ //Refina principio y final
    palabra = palabra.substr(1, palabra.length() - 2);
}

void refina_signo(string& palabra){ //Refina final si hay signo
    char c = palabra [palabra.length() - 1];
    if(not ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')) and not (c >= '0' and c <= '9')) palabra = palabra.substr(0, palabra.length() - 1);
}