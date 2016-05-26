//
// Created by Zebs on 17/05/2016.
//

#include "Gestor.hh"
#include <stdlib.h>

/* Privada (Ya no) */

void Gestor::recorta(istringstream& iss){ //iss es un parametro de salida
  int pos = 0;
  bool encontrado = false;
  string aux = iss.str();
  while(aux[pos] == ' ') ++pos; //Llegamos hasta el primer espacio
  while(aux[pos] != ' ' and pos < aux.length()) ++pos; //Numero de posiciones hasta el espacio
  aux.erase(0, pos + 1); //Contamos el ultimo espacio tambien
  iss.str(aux); //Convertimos la string aux en un iss
}

/////////////////

Gestor::Gestor(){
    escogido = false;
}

bool Gestor::existe_autor(string nombre){
    map<string, Autor>::iterator it;
    it = autores.find(nombre);
    return it != autores.end();
}

bool Gestor::existe_texto_autor(string nombre, string titulo){
    if(existe_autor(nombre)){
        map<string, Autor>::iterator it = autores.find(nombre);
        return it->second.existe_texto_autor(titulo);
    }
    else return false; //Si no existe el autor, de seguro que no existe el texto...
}

void Gestor::todos_autores() {//revisar, motivos de eficiencia
    for(map<string, Autor>::iterator it = autores.begin(); it != autores.end(); ++it){
        cout << it->second.nombre_autor() << " " << it->second.numero_textos_autor() << " " << it->second.numero_frases_autor()
                << " " << it->second.numero_palabras_autor() << endl;
    }
}

void Gestor::anadir_autor_gestor(Autor autor) {
    autores[autor.nombre_autor()] = autor;
}

void Gestor::anadir_texto_gestor(Texto& t){
  string nombre = t.autor_texto();
  string titulo = t.titulo_texto();
  map<string, Autor>::iterator it = autores.find(nombre);
  if(it != autores.end()) it->second.anadir_texto_autor(t);
  else{
    Autor autor (nombre);
    autor.anadir_texto_autor(t);
    autores [nombre] = autor;
  }
  textos [titulo] = t;
  texto_escogido = textos.find(titulo);
  escogido = true;
}

void Gestor::anadir_texto_gestor(string nombre, string titulo){
    string entrada, pa; getline(cin, entrada);
    bool ini_frase = true;
    list<Frase> contenido;
    list<Frase>::iterator it1 = contenido.end();
    list<string> f;
    list<string>::iterator it2 = f.end();
    int num_p, num_f; num_p = num_f = 0;
    map<string, int> frecuencia_palabras;
    while(entrada != "****") {
        istringstream iss(entrada);
	while(iss >> pa){
	    recorta(iss);
            bool es_signo = not ((pa[pa.length()-1] >= 'a' and pa[pa.length()-1] <= 'z') or (pa[pa.length()-1] >= 'A' and pa[pa.length()-1] <= 'Z'));
            if (not es_signo or (es_signo and pa.length() > 1)) { //Ajustamos las frecuencias de las palabras
              if(es_signo){
		//tratar luego
	      }
	      map<string, int>::iterator frec = frecuencia_palabras.find(pa);
              if (frec != frecuencia_palabras.end()) ++frecuencia_palabras[pa];
              else frecuencia_palabras[pa] = 1;
            }
            if (not ini_frase and es_signo) {
		if(pa.size() == 1){
		  list<string>::iterator aux = it2;
		  --aux;
		  *aux += pa; //Le concatenamos el signo
		}
		else ++num_p;
                if (pa[pa.length()-1] == '.' or pa[pa.length()-1] == '?' or pa[pa.length()-1] == '!') {
                    Frase frase(f, num_f + 1);
                    contenido.insert(it1, frase);
                    ++num_f; //Si es un signo de final de frase la insertamos
                    f.clear();
                    it2 = f.begin();
                    ini_frase = true; //Empezamos nueva frase
                }
            }
            else if (ini_frase and es_signo) {
                //Hemos encontrado una frase vacia, y volvemos a empezar otra nueva
                f.insert(it2, pa);
                Frase frase(f, num_f + 1);
                contenido.insert(it1, frase);
                ++num_f; //Es una frase (vacia) pero no una palabra.
                if(pa.size() > 1) ++num_p;
                f.clear();
                it2 = f.begin();
                ini_frase = true; //Empezamos nueva frase
            }
            else {
                f.insert(it2, pa);
                ++num_p;
                ini_frase = false;
            }
        }
        getline(cin, entrada);
    }
    Texto t (nombre, titulo, num_p, num_f, contenido, frecuencia_palabras);
    map<string, Autor>::iterator aut = autores.find(nombre);
    if(aut != autores.end()) autores [nombre].anadir_texto_autor(t);
    else{
        Autor autor (nombre); autor.anadir_texto_autor(t);
        autores [nombre] = autor;
    }
}

void Gestor::eliminar_texto_gestor(){
    string nombre_autor = texto_escogido->second.autor_texto();
    if(autores[nombre_autor].numero_textos_autor() == 1){
        map <string, Autor>::iterator it = autores.find(nombre_autor);
        autores.erase(it);
    }
    else autores[nombre_autor].eliminar_texto_autor(texto_escogido->second.titulo_texto());
    textos.erase(texto_escogido);
    escogido = false;
}

bool Gestor::escoger_texto(const list<string>& p, Texto& t){ //version con frecuencia? TRATAR SIGNOS DE PUNTUACION
    bool match = false;
    for(map<string, Texto>::iterator it = textos.begin(); it != textos.end(); ++it){
        list<string> aux = p;
        for(list<string>::iterator it2 = aux.begin(); not aux.empty() and it2 != aux.end(); ++it2) {
            map<string, int>::iterator it3 = it->second.frecuencia_palabras_texto().find(*it2);
            if (it3 != it->second.frecuencia_palabras_texto().end()) {
                it2 = aux.erase(it2);
                --it2;
            }
        }
        string a_tratar;
        istringstream autor(it->second.autor_texto());
        while(autor >> a_tratar and not aux.empty()){
            bool match2 = false;
            for(list<string>::iterator it2 = aux.begin(); not match2 and it2 != aux.end(); ++it2){
                if(*it2 == a_tratar){
                    it2 = aux.erase(it2);
                    --it2;
                    match2 = true;
                }
            }
        }
        istringstream titulo(it->second.titulo_texto());
        while(titulo >> a_tratar and not aux.empty()){
            bool match2 = false;
            for(list<string>::iterator it2 = aux.begin(); not match2 and it2 != aux.end(); ++it2){
                if(*it2 == a_tratar){
                    it2 = aux.erase(it2);
                    --it2;
                    match2 = true;
                }
            }
        }
        if(aux.empty()){
            if(match) return false;
            else{
                t = it->second;
                match = true;
            }
        }
    }
    return match;
}

void Gestor::todos_textos(){
    for(map<string, Autor>::iterator it = autores.begin(); it != autores.end(); ++it){ //Iteramos autores
      cout << it->first << " ";  
      it->second.textos_autor();
        //Imprimir usando el autor.imprimir_textos();
    }
}

void Gestor::textos_autor(string nombre){
  autores [nombre].textos_autor();
}

bool Gestor::esta_escogido(){
    return escogido;
}

Texto Gestor::texto_escogido_gestor(){
  return texto_escogido->second;
}

void Gestor::todas_citas(){//daños colaterales
    for(map<string, map<int, Cita> >::iterator it = citas.begin(); it != citas.end(); ++it){
        for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout << it->first << it2->first;
            it2->second.escribir_cita();
            cout << it2->second.autor_cita() << " \"" << it2->second.titulo_texto_cita() << '"' << endl;
        }
    }
}

void Gestor::anadir_cita_gestor(int x, int y){
    if(x <= y and not (x <= 0 or y <= 0) and y <= texto_escogido->second.numero_frases() and not texto_escogido->second.existe_cita(x, y)){
        istringstream iss(texto_escogido->second.autor_texto());
        string a_tratar, id; id = ""; //id es nula
        while(iss >> a_tratar){
	    recorta(iss);
            char inicial = a_tratar[0];
            if(inicial >= 'a' and inicial <= 'z'){ //Si no es mayuscula, convertirla
                inicial = (inicial - 'a') + 'A';
            }
            id += inicial;
        }
        list<Frase> l = texto_escogido->second.contenido_texto();
        vector<Frase> v(y-x+1);
        list<Frase>::iterator itf = l.begin();
        for(int i = 0; i < x; ++i){
                ++itf;
        }
        for(int i = 0; i < y-x+1; ++i){
            v[i] = *itf;
            ++itf;
        }
        Cita c(v, texto_escogido->second.titulo_texto(), texto_escogido->second.autor_texto(), x, y);
        map<string, map<int, Cita> >::iterator it = citas.find(id);
        int num;
        if(it != citas.end()){
            map<int, Cita>::iterator it2 = it->second.end(); --it2;
            num = it2->first + 1;
        }
        else{
            num = 1;
        }
        citas[id][num] = c;
        texto_escogido->second.anadir_cita_texto(c, id, num);
        autores[texto_escogido->second.autor_texto()].anadir_cita_autor(c, id, num);
    }
    else cout << "error" << endl;
}

void Gestor::eliminar_cita_gestor(string id){
    int i = 0;
    while(id[i] >= 'A' and id[i] <= 'Z'){
        ++i;
    }
    int num = atoi(id.substr(i, id.size() - i).c_str());
    string ini = id.substr(0, i);
    autores[citas[ini][num].autor_cita()].eliminar_cita_autor(ini, num);
    textos[citas[ini][num].titulo_texto_cita()].eliminar_cita_texto(ini, num);
    citas[ini].erase(num);
    if(citas[ini].empty()) citas.erase(ini);
}

void Gestor::citas_autor(string autor){
    autores[autor].citas_autor();
}

void Gestor::info_cita(string id){
    int i = 0;
    while(id[i] >= 'A' and id[i] <= 'Z'){
        ++i;
    }
    int num = atoi((id.substr(i, id.size() - i)).c_str());
    string ini = id.substr(0, i);
    citas[ini][num].info();
}
