//
// Created by Zebs on 17/05/2016.
//

#include "Gestor.hh"
#include <stdlib.h>

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

bool Gestor::existe_cita(int x, int y, string autor, string titulo){
  bool match = false;
  map<string, map<int, Cita> >::iterator it = citas.begin();
  while(not match and it != citas.end()){
    map<int, Cita>::iterator it2 = it->second.begin();
    while(not match and it2 != it->second.end()){
      if(it2->second.autor_cita() == autor and it2->second.titulo_texto_cita() == titulo and it2->second.frase_inicial() == x and it2->second.frase_final() == y) match = true;
      ++it2;
    }
    ++it;
  }
  return match;
}

void Gestor::anadir_texto_gestor(string nombre, string titulo){ //Si hay tiempo, reestructurarla
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
	  char c = pa[pa.length()-1];
	  bool es_signo = not ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'));
	  string aux = pa; refina_signo(aux);
	  map<string, int>::iterator frec = frecuencia_palabras.find(aux);
	  if (not aux.empty() and frec != frecuencia_palabras.end()) ++frecuencia_palabras[aux];
	  else if(not aux.empty()) frecuencia_palabras[aux] = 1;
	  if (not ini_frase and es_signo) {
		if(pa.size() == 1){
		  list<string>::iterator aux = it2;
		  --aux;
		  *aux += pa; //Le concatenamos el signo
		}
		else{
		   f.insert(it2, pa);
		   ++num_p;
		}
                if (pa[pa.length()-1] == '.' or pa[pa.length()-1] == '?' or pa[pa.length()-1] == '!') {
                    Frase frase(f, num_f + 1);
                    contenido.insert(it1, frase);
                    ++num_f; //Si es un signo de final de frase la insertamos
                    f.clear();
                    it2 = f.begin();
                    ini_frase = true; //Empezamos nueva frase
                }
            }
            else if (ini_frase and es_signo) { //NO TRATAR LOS SIGNOS SOLOS COMO FRASES!!!!
	      if(pa[pa.length()-1] == '.' or pa[pa.length()-1] == '?' or pa[pa.length()-1] == '!'){
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
	      else{
		f.insert(it2, pa);
		++num_p; //No se comprueba el size por que no puede haber comas en principio de frase
		ini_frase = false;
	      }
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
    textos.insert(textos.end(), t);
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
  textos.insert(textos.end(), t);
  texto_escogido = textos.end(); --texto_escogido; //Lo anadimos y lo seleccionamos (la funcion esta hecha expresamente para eso)
  escogido = true;
}

void Gestor::eliminar_texto_gestor(){
    string nombre_autor = (*texto_escogido).autor_texto();
    if(autores[nombre_autor].numero_textos_autor() == 1){
        map <string, Autor>::iterator it = autores.find(nombre_autor);
        autores.erase(it);
    }
    else autores[nombre_autor].eliminar_texto_autor((*texto_escogido).titulo_texto());
    textos.erase(texto_escogido);
    escogido = false;
}

bool Gestor::escoger_texto(const list<string>& p){ //version con frecuencia? TRATAR SIGNOS DE PUNTUACION
    if(p.empty()){escogido = false; return false;}
    bool match = false;
    list<Texto>::iterator t;
    list<Texto>::iterator it = textos.begin();
    while(it != textos.end()){
        list<string> aux = p;
        list<string>::iterator aux_it = aux.begin();
        map<string, int> f_p = (*it).frecuencia_palabras_texto();
        while(aux_it != aux.end() and not aux.empty()){
            map<string, int>::iterator f_it = f_p.find(*aux_it);
            if(f_it != f_p.end()) aux_it = aux.erase(aux_it);
            else ++aux_it;
        }
        string a_tratar;
        istringstream autor((*it).autor_texto());
        while(not autor.str().empty() and not aux.empty()){
            autor >> a_tratar;
            recorta(autor);
            bool match2 = false;
            aux_it = aux.begin();
            while(aux_it != aux.end() and not match2){
                if(*aux_it == a_tratar){
                    aux_it = aux.erase(aux_it);
                    match2 = true;
                }
                else ++aux_it;
            }
        }
        istringstream titulo((*it).titulo_texto());
        while(not titulo.str().empty() and not aux.empty()){
            titulo >> a_tratar;
	    refina_signo(a_tratar);
            recorta(titulo);
            bool match2 = false;
            aux_it = aux.begin();
            while(aux_it != aux.end() and not match2){
                if(*aux_it == a_tratar){
                    aux_it = aux.erase(aux_it);
                    match2 = true;
                }
                else ++aux_it;
            }
        }	
        if(aux.empty()){
            if(match){
                escogido = false;
                return false;
            }
            else{
                t = it;
                match = true;
            }
        }
        ++it;
    }
    escogido = match;
    texto_escogido = t;

    return match;
}

void Gestor::todos_textos(){
    for(map<string, Autor>::iterator it = autores.begin(); it != autores.end(); ++it){ //Iteramos autores 
      it->second.textos_autor(1);
        //Imprimir usando el autor.imprimir_textos();
    }
}

void Gestor::textos_autor(string nombre){
  autores [nombre].textos_autor(0);
}

bool Gestor::esta_escogido(){
    return escogido;
}

Texto Gestor::texto_escogido_gestor(){
  return *texto_escogido;
}

void Gestor::todas_citas(){ //daños colaterales
    for(map<string, map<int, Cita> >::iterator it = citas.begin(); it != citas.end(); ++it){
        for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout << it->first << it2->first << endl;
            it2->second.escribir_cita();
            cout << it2->second.autor_cita() << " \"" << it2->second.titulo_texto_cita() << '"' << endl;
        }
    }
}

void Gestor::anadir_cita_gestor(int x, int y){
    if(x <= y and not (x <= 0 or y <= 0) and y <= (*texto_escogido).numero_frases() and not existe_cita(x, y, (*texto_escogido).autor_texto(), (*texto_escogido).titulo_texto())){
        istringstream iss((*texto_escogido).autor_texto());
        string a_tratar, id, id_cita; id = ""; //id es nula
        while(iss >> a_tratar){
            char inicial = a_tratar[0];
//             if(inicial >= 'a' and inicial <= 'z'){ //Si no es mayuscula, convertirla
//                 inicial = (inicial - 'a') + 'A';
//             }
            id += inicial;
	    recorta(iss);
        }
        list<Frase> l = (*texto_escogido).contenido_texto();
        vector<Frase> v(y-x+1);
        list<Frase>::iterator itf = l.begin();
        for(int i = 1; i < x; ++i) ++itf;
        for(int i = 0; i < y-x+1; ++i){
            v[i] = *itf;
            ++itf;
        }
        Cita c(v, (*texto_escogido).titulo_texto(), (*texto_escogido).autor_texto(), x, y);
        map<string,int >::iterator it = this->id.find(id);
        int num;
        if(it != this->id.end()){
            num = it->second + 1;
            this->id[id] += 1;
        }
        else{
            this->id[id] = 1;
            num = 1;
        }
        citas[id][num] = c;
	(*texto_escogido).anadir_cita_texto(c, id, num);
    }
    else cout << "error" << endl;
}

void Gestor::eliminar_cita_gestor(string id){
    int i = 0;
    while((id[i] >= 'A' and id[i] <= 'Z') or (id[i] >= 'a' and id[i] <= 'z')) ++i;
    int num = atoi(id.substr(i, id.size() - i).c_str());
    string ini = id.substr(0, i);
    map<string, map<int, Cita> >::iterator it1 = citas.find(ini);
    if(it1 != citas.end()){
      map<int, Cita>::iterator it2 = it1->second.find(num);
      if(it2 != it1->second.end()){
	string autor = citas[ini][num].autor_cita();
	string titulo = citas[ini][num].titulo_texto_cita();
	bool encontrado = false;
	list<Texto>::iterator it = textos.begin();
	while(not encontrado and it != textos.end()){
	  if((*it).autor_texto() == autor and (*it).titulo_texto() == titulo) encontrado = true;
	  else ++it;
      }
      if(encontrado){
	(*it).eliminar_cita_texto(ini, num);
	map<int, Cita>::iterator itaux = citas [ini].find(num);
	if(itaux != citas [ini].end()) citas [ini].erase(itaux);
      }
      if(citas[ini].empty()) citas.erase(ini);
      }
      else cout << "error" << endl;
    }
    else cout << "error" << endl;
}

void Gestor::citas_autor(string autor){
  for(map<string, map<int, Cita>>::iterator it = citas.begin(); it != citas.end(); ++it){
    for(map<int, Cita>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      if(it2->second.autor_cita() == autor){
	cout << it->first << it2->first << endl;
	it2->second.escribir_cita();
	cout << "\"" << it2->second.titulo_texto_cita() << "\"" << endl;
      }
    }
  }
}

void Gestor::info_cita(string id){
    int i = 0;
    while(id[i] >= 'A' and id[i] <= 'Z') ++i;
    string ini = id.substr(0, i);
    int num = atoi((id.substr(i, id.size() - 1)).c_str());
    map<string, map<int, Cita> >::iterator it1 = citas.find(ini);
    if(it1 != citas.end()){
      map<int, Cita>::iterator it2 = it1->second.find(num);
      if(it2 != it1->second.end()) citas[ini][num].info();
      else cout << "error" << endl;
    }
    else cout << "error" << endl;
}
