#include "Gestor.hh"

// void gestor.recorta(istringstream& iss){ //iss es un parametro de salida
//   int pos = 0;
//   bool encontrado = false;
//   string aux = iss.str();
//   while(aux[pos] == ' ') ++pos; //Llegamos hasta el primer espacio
//   while(aux[pos] != ' ' and pos < aux.length()) ++pos; //Numero de posiciones hasta el espacio
//   aux.erase(0, pos + 1); //Contamos el ultimo espacio tambien
//   iss.str(aux); //Convertimos la string aux en un iss
// }

int main(){
  Gestor gestor;
  string linea, op;
  getline(cin, linea);
  while(linea != "sortir"){ //Condicion de salida
    istringstream iss(linea); iss >> op;
      if(op == "afegir"){
	cout << iss.str() << endl;
	gestor.recorta(iss);
	iss >> op;
	if(op == "text"){ //afegir text "<titol>"
	  gestor.recorta(iss);
	  string titulo = iss.str(); //Titulo del texto a anadir
	  titulo = titulo.substr(1, titulo.length() - 2);
	  getline(cin, linea); 
	  iss.str(linea);
	  iss >> op; gestor.recorta(iss); iss.ignore('"'); 
	  string nombre_autor = iss.str(); //Nombre del autor
	  nombre_autor = nombre_autor.substr(1, nombre_autor.length() - 2);
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
      cout << iss.str() << endl;
      gestor.recorta(iss); gestor.recorta(iss);
      list<string> p;
      list<string>::iterator it = p.begin();
      op = iss.str(); op = op.substr(1, op.length() - 2); //Quita las llaves 
      iss.str(op); //Lo volvemos a transformar en istringstream pero sin {}
      while(iss >> op){
	  string w(op);
	  p.insert(it, w);
	  gestor.recorta(iss);
      }
      it = p.begin(); 
      Texto t;
      bool encontrado = gestor.escoger_texto(p, t);
      if(not encontrado) cout << "error" << endl;
    }
    else if(op == "eliminar"){
      cout << iss.str() << endl;
      gestor.recorta(iss); iss >> op;
      if(op == "text"){ //eliminar text
	if(not gestor.esta_escogido()) cout << "error" << endl;
	else gestor.eliminar_texto_gestor();
      }
      else{ //eliminar cita
          iss.ignore('"'); gestor.recorta(iss); iss >> op;
          string ref(op); gestor.eliminar_cita_gestor(ref);
      }
    }
    else if(op == "substitueix"){ //substitueix "<paraula1>" per "<paraula2>"
      cout << iss.str() << endl;
      gestor.recorta(iss);
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else{
	iss.ignore('"');
	iss >> op; string p1 = op;
	gestor.recorta(iss); gestor.recorta(iss);
	iss >> op; string p2 = op;
	string titulo = gestor.texto_escogido_gestor().titulo_texto();
	gestor.eliminar_texto_gestor();
	Texto t = gestor.texto_escogido_gestor();
	t.sustituir_palabra(p1, p2);
	gestor.anadir_texto_gestor(t);
      }
    }
    else if(op == "textos"){ //textos autor "<autor>" ?
      cout << iss.str() << endl;
      gestor.recorta(iss); gestor.recorta(iss); iss.ignore('"'); string nombre = iss.str();
      if(not gestor.existe_autor(nombre)) cout << "error" << endl;
      else gestor.textos_autor(nombre);
    }
    else if(op == "tots"){ 
      cout << iss.str() << endl;
      gestor.recorta(iss); iss >> op;
      if(op == "autors"){ //tots autors ?
        gestor.todos_autores();
      }
      else{ //tots textos ?
        gestor.todos_textos();
      }
    }
    else if(op == "info"){
      cout << iss.str() << endl;
      gestor.recorta(iss); iss >> op; gestor.recorta(iss);
      if(op == "cita"){ //info cita "<referencia>"
	string id = iss.str(); id = id.substr(1, id.length() - 2);
	gestor.info_cita(id);
      }
      else if(not gestor.esta_escogido()) cout << "error" << endl;
      else{ //info ?
	cout << gestor.texto_escogido_gestor().autor_texto() << endl << gestor.texto_escogido_gestor().titulo_texto() << endl;
	cout << gestor.texto_escogido_gestor().numero_frases() << endl << gestor.texto_escogido_gestor().numero_palabras() << endl;
	gestor.texto_escogido_gestor().citas_texto();
      }
    }
    else if(op == "autor"){ //autor ?
      cout << iss.str() << endl;
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else cout << gestor.texto_escogido_gestor().autor_texto() << endl;
    }
    else if(op == "contingut"){ //contingut ?
      cout << iss.str() << endl;
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else gestor.texto_escogido_gestor().mostrar_contenido_texto();
    }
    else if(op == "frases"){
     gestor.recorta(iss); iss >> op;
     if(not gestor.esta_escogido() or op[0] == '-' or op[0] == '0') cout << "error" << endl;
     else if(op[0] >= '1' and op[0] <= '9'){ //frases x y
	gestor.recorta(iss); int x, y;
	istringstream aux; aux.str(op); aux >> x; iss >> y; 
	gestor.texto_escogido_gestor().frases_xy(x, y);
     }
     else if(op[0] == '"'){ //frases secuencia
	string aux = iss.str(); aux = aux.substr(1, aux.length() - 2);
	iss.str(aux); //La reconvertimos en un stream
	list<string> l; list<string>::iterator it = l.begin();
	iss >> aux; l.insert(it, aux); gestor.recorta(iss);
	while(iss >> op){
	  l.insert(it, op);
	  gestor.recorta(iss);
	}
	gestor.texto_escogido_gestor().frases_seq(l);
     }
     else{ //frases expressio
     	//falta 
         cout << endl;
     }
    }
    else if(op == "nombre"){
      cout << iss.str() << endl;
      gestor.recorta(iss); //Quitamos el "de" 
      iss >> op; //Guardamos el paraules o frases
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else if(op == "paraules") cout << gestor.texto_escogido_gestor().numero_palabras() << endl; //nombre de paraules ?
      else cout << gestor.texto_escogido_gestor().numero_frases() << endl; //nombre de frases ?
    }
    else if(op == "taula"){ //Taula de frequencies
      cout << iss.str() << endl;
      gestor.texto_escogido_gestor().tabla_frecuencias_texto();
    }
    getline(cin, linea); //Entrada de un nuevo comando
  }
}