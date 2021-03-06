#ifndef FUNCIONES_AXU_HH
#define FUNCIONES_AUX_HH

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

/** @brief Elimina la primera parte de un sstream
 *  \pre cierto
 *  \post se ha eliminado la primera palabra
 *  antes del primer espacio de <b>iss</b>
 */
void recorta(istringstream& iss);

/** @brief Elimina el primer y ultimo caracter
 * \pre cierto
 * \post se han eliminado el primer y
 * ultimo caracter de la cadena
 */
void refina_pf(string& palabra);

/** @brief Elimina el signo de una palabra
 *  \pre cierto
 *  \post si tenia un signo al final
 *  de la palabra este ha sido eliminado,
 *  en caso contrario no se modifica
 */
void refina_signo(string& palabra);

/** @brief Normaliza una entrada
 * \pre cierto
 * \post eliminado el exceso de espacios
 * en una entrada por pantalla
 */
string normalizar(istringstream& iss);

#endif