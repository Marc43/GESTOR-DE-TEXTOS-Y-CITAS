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
	gestor.recorta(iss);
	iss >> op;
	if(op == "text"){ //afegir text "<titol>"
	  gestor.recorta(iss);
	  iss.ignore('"');
	  string titulo = iss.str(); //Titulo del texto a anadir
	  getline(cin, linea); 
	  iss.str(linea);
	  iss >> op; gestor.recorta(iss); iss.ignore('"'); 
	  string nombre_autor = iss.str(); //Nombre del autor
	  if(gestor.existe_autor(nombre_autor) and gestor.existe_texto_autor(nombre_autor, titulo)) cout << "error" << endl; //Ya existe tal texto en este autor
	  else gestor.anadir_texto_gestor(nombre_autor, titulo);
	}
	else if(gestor.esta_escogido()){ //afegir cita x y
	  char p;
	  iss >> p; int x = p - '0';
	  iss >> p; int y = p - '0';
	  Texto t = gestor.texto_escogido_gestor();
	  gestor.anadir_cita_gestor(x, y); //No le pasamos el texto ya que trabaja sobre el escogido
	}
	else cout << "error" << endl; //Ningun texto escogido
    }
    else if(op == "triar"){ //triar text {titol}
      gestor.recorta(iss); gestor.recorta(iss);
      iss.ignore('{'); iss.ignore('}');
      list<string> p;
      list<string>::iterator it = p.begin();
      cout << iss.str() << endl;
      while(iss >> op){
	    cout << op << endl;
	    string w(op);
	    p.insert(it, w);
	    gestor.recorta(iss);
      }
      Texto t;
      bool encontrado = gestor.escoger_texto(p, t);
      if(not encontrado) cout << "error" << endl;
    }
    else if(op == "eliminar"){
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
      gestor.recorta(iss); gestor.recorta(iss); iss.ignore('"'); string nombre = iss.str();
      if(not gestor.existe_autor(nombre)) cout << "error" << endl;
      else gestor.textos_autor(nombre);
    }
    else if(op == "tots"){ 
      gestor.recorta(iss); iss >> op;
      if(op == "autors"){ //tots autors ?
        gestor.todos_autores();
      }
      else{ //tots textos ?
        gestor.todos_textos();
      }
    }
    else if(op == "info"){ 
      gestor.recorta(iss); iss >> op;
      if(op == "cita"){ //info cita "<referencia>"
	iss.ignore('"');
	gestor.todas_citas(); 
      }
      else if(not gestor.esta_escogido()) cout << "error" << endl;
      else{ //info ?
	cout << gestor.texto_escogido_gestor().autor_texto() << endl << gestor.texto_escogido_gestor().titulo_texto() << endl;
	cout << gestor.texto_escogido_gestor().numero_frases() << endl << gestor.texto_escogido_gestor().numero_palabras() << endl;
	gestor.texto_escogido_gestor().citas_texto();
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
     gestor.recorta(iss); iss >> op;
     if(not gestor.esta_escogido()) cout << "error" << endl;
     else if(int(op[0]) >= 0 and int(op[0]) <= 9){ //frases x y
        istringstream aux(op);
        int x; aux >> x; gestor.recorta(aux);
	int y; iss >> y;
	gestor.texto_escogido_gestor().frases_xy(x, y);
     }
     else if(op[0] == '"'){ //frases secuencia
        iss.ignore('\"'); iss >> op;
	list<string> l; list<string>::iterator it = l.begin();
	it = l.insert(it, op);
	while(iss >> op){
	  gestor.recorta(iss);
	  it = l.insert(it, op);
	}
	gestor.texto_escogido_gestor().frases_seq(l);
     }
     else{ //frases expressio
     	//falta 
         cout << endl;
     }
    }
    else if(op == "nombre"){
      gestor.recorta(iss); //Quitamos el "de" 
      iss >> op; //Guardamos el paraules o frases
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else if(op == "paraules") cout << gestor.texto_escogido_gestor().numero_palabras() << endl; //nombre de paraules ?
      else cout << gestor.texto_escogido_gestor().numero_frases() << endl; //nombre de frases ?
    }
    else if(op == "taula"){ //Taula de frequencies
      gestor.texto_escogido_gestor().tabla_frecuencias_texto();
    }
    getline(cin, linea); //Entrada de un nuevo comando
  }
}