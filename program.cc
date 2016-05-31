#include "Gestor.hh"

int main(){
  Gestor gestor;
  string linea, op;
  getline(cin, linea);
  while(linea != "sortir"){ //Condicion de salida
      cout << linea << endl; op = ""; //Lo declaramos vacio
      istringstream iss(linea); 
      if(not linea.empty()) iss >> op; //Si linea esta vacio dejamos op vacio
      if(op == "afegir"){
	recorta(iss);
	iss >> op;
	if(op == "text"){ //afegir text "<titol>"
	  recorta(iss);
	  string titulo = iss.str(); //Titulo del texto a anadir
      refina_pf(titulo); iss.str(titulo);
      titulo = normalizar(iss); //refina_signo(titulo);
	  getline(cin, linea); 
	  istringstream a(linea);
	  recorta(a);
	  string nombre_autor = a.str(); //Nombre del autor
      refina_pf(nombre_autor); a.str(nombre_autor);
      nombre_autor = normalizar(a);
	  if(gestor.existe_autor(nombre_autor) and gestor.existe_texto_autor(nombre_autor, titulo)) cout << "error" << endl; //Ya existe tal texto en este autor
	  else gestor.anadir_texto_gestor(nombre_autor, titulo);
	}
	else if(gestor.esta_escogido()){ //afegir cita x y
	  char p;
	  iss >> p; int x = p - '0'; //Funcionara para digitos mas grandes? por ejemplo de la frase 10 a la 20
	  iss >> p; int y = p - '0';
	  gestor.anadir_cita_gestor(x, y); //No le pasamos el texto ya que trabaja sobre el escogido
	}
	else cout << "error" << endl; //Ningun texto escogido
    }
    else if(op == "triar"){ //triar text {titol}
      recorta(iss); recorta(iss);
      list<string> p;
      op = iss.str(); refina_pf(op); //Quita las llaves 
      iss.str(op); //Lo volvemos a transformar en istringstream pero sin {}
      list<string>::iterator it = p.end();
      while(iss >> op){
	    string w(op);
	    p.insert(it, w);
	    recorta(iss);
      }
      bool encontrado = gestor.escoger_texto(p);
      if(not encontrado) cout << "error" << endl;
    }
    else if(op == "eliminar"){
      recorta(iss); iss >> op; //Cites associadas ?? Frases secuencia ??
      if(op == "text"){ //eliminar text
	if(not gestor.esta_escogido()) cout << "error" << endl;
	else gestor.eliminar_texto_gestor();
      }
      else{ //eliminar cita
          recorta(iss); iss >> op; refina_pf(op);
          gestor.eliminar_cita_gestor(op);
      }
    }
    else if(op == "substitueix"){ //substitueix "<paraula1>" per "<paraula2>"
      recorta(iss);
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else{
          string p1, p2;
          iss >> p1; recorta(iss);
          if(p1 == "\"") {iss >> p1; recorta(iss);}
          else p1 = p1.substr(1, p1.size()-1);
          string paux = p1;
          refina_signo(p1);
          if(paux == p1) recorta(iss);
          recorta(iss);
          iss >> p2; recorta(iss);
          if(p2 == "\"") {iss >> p2; recorta(iss);}
          else p2 = p2.substr(1, p2.size()-1);
	  refina_signo(p2);
          Texto t = gestor.texto_escogido_gestor();
          gestor.eliminar_texto_gestor();
          if(p1 != p2) t.sustituir_palabra(p1, p2);
          gestor.anadir_texto_gestor(t);
      }
    }
    else if(op == "textos"){ //textos autor "<autor>" ?
      recorta(iss); recorta(iss); string nombre = iss.str();
      nombre = nombre.substr(0, nombre.length() - 2);
      refina_pf(nombre);
      if(not gestor.existe_autor(nombre)) cout << "error" << endl;
      else gestor.textos_autor(nombre);
    }
    else if(op == "tots"){ 
      recorta(iss); iss >> op;
      if(op == "autors"){ //tots autors ?
        gestor.todos_autores();
      }
      else{ //tots textos ?
        gestor.todos_textos();
      }
    }
    else if(op == "info"){
      recorta(iss); iss >> op; recorta(iss);
      if(op == "cita"){ //info cita "<referencia>"
	string id = iss.str(); refina_pf(id);
	gestor.info_cita(id);
      }
      else if(not gestor.esta_escogido()) cout << "error" << endl;
      else{ //info ?
	cout << gestor.texto_escogido_gestor().autor_texto() << " \"" << gestor.texto_escogido_gestor().titulo_texto() << "\"";
	cout << ' ' << gestor.texto_escogido_gestor().numero_frases() << ' ' << gestor.texto_escogido_gestor().numero_palabras() << endl;
	gestor.texto_escogido_gestor().citas_texto(0);
      }
    }
    else if(op == "autor"){ //autor ?
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else cout << gestor.texto_escogido_gestor().autor_texto() << endl;
    }
    else if(op == "contingut"){ //contingut ?
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else gestor.texto_escogido_gestor().mostrar_contenido_texto();
    }
    else if(op == "frases"){
     recorta(iss); iss >> op;
     if(not gestor.esta_escogido() or op[0] == '-' or op[0] == '0') cout << "error" << endl;
     else if(op[0] >= '1' and op[0] <= '9'){ //frases x y
	recorta(iss); int x, y;
	istringstream aux; aux.str(op); aux >> x; iss >> y; 
	gestor.texto_escogido_gestor().frases_xy(x, y);
     }
     else if(op[0] == '"'){ //frases secuencia
	string aux = iss.str(); aux = aux.substr(0, aux.length() - 2); //Quitamos el " ?"
	refina_pf(aux);
	iss.str(aux); //La reconvertimos en un stream
	list<string> l; list<string>::iterator it = l.begin();
	iss >> aux; l.insert(it, aux); recorta(iss);
	while(iss >> op){
	  l.insert(it, op);
	  recorta(iss);
	}
	gestor.texto_escogido_gestor().frases_seq(l);
     }
     else{ //frases expressio
         iss.str(iss.str().substr(0, iss.str().size() - 2));
         istringstream aux(iss.str());
         string saux, exp; exp = " ";
         while(aux >> saux){
	    char last = exp[exp.size()-1];
            if(saux == "(" or saux == "{" or saux == "}" or saux == ")") {
	       if(last == '&' or last == '|') exp += " ";
	       exp += saux;
	    }
            else if(last == '(' or last == '(') exp += saux;
            else if(last == ')' or last == '}') {exp += " "; exp += saux;}
            else if(last == '|' or last == '&'){exp += " "; exp += saux;}
            else if((last >= 'a' and last <= 'z') or (last >= 'A' and last <= 'Z')) {exp += " "; exp += saux;}
            else exp += saux;
            recorta(aux);
         }
         iss.str(exp);
         gestor.texto_escogido_gestor().frases_exp(iss);
     }
    }
    else if(op == "nombre"){
      recorta(iss); recorta(iss); //Quitamos el "de" 
      iss >> op; //Guardamos el paraules o frases
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else if(op == "paraules") cout << gestor.texto_escogido_gestor().numero_palabras() << endl; //nombre de paraules ?
      else cout << gestor.texto_escogido_gestor().numero_frases() << endl; //nombre de frases ?
    }
    else if(op == "totes"){
        gestor.todas_citas();
      }
    else if(op == "cites"){
        recorta(iss); iss >> op;
        if(op == "autor"){ //cites autor
          recorta(iss);
          string autor = iss.str(); autor = autor.substr(0, autor.length() - 2); //Quitamos el " ?"
	  refina_pf(autor);
          gestor.citas_autor(autor);
        }
        else{ //cites ?
          gestor.texto_escogido_gestor().citas_texto(1);
        }
      }
    else if(op == "taula"){ //Taula de frequencies
      gestor.texto_escogido_gestor().tabla_frecuencias_texto();
    }
    getline(cin, linea); //Entrada de un nuevo comando
  }
}
