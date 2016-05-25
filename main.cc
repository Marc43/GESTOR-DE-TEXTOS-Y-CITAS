#include "Gestor.hh"

int main(){
  Gestor gestor;
  string linea, op;
  getline(cin, linea);
  while(linea != "sortir"){ //Condicion de salida
    istringstream iss(linea); iss >> op;
      if(op == "afegir"){
	iss >> op;
	if(op == "text"){ //afegir text "<titol>"
	  iss.ignore('"');
	  string titulo = iss.str(); //Titulo del texto a anadir
	  getline(cin, linea); 
	  iss.str(linea);
	  iss >> op; iss.ignore('"'); 
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
      iss >> op;
      iss.ignore('{'); iss.ignore('}');
      list<string> p;
      list<string>::iterator it = p.begin();
      while(iss >> op){
	    string w(op);
	    p.insert(it, w);
      }
      Texto t;
      bool encontrado = gestor.escoger_texto(p, t);
      if(not encontrado) cout << "error" << endl;
    }
    else if(op == "eliminar"){
      iss >> op;
      if(op == "text"){ //eliminar text
	if(not gestor.esta_escogido()) cout << "error" << endl;
	else gestor.eliminar_texto_gestor();
      }
      else{ //eliminar cita
          iss.ignore('"'); iss >> op;
          string ref(op);
	      gestor.eliminar_cita_gestor(ref);
      }
    }
    else if(op == "substitueix"){ //substitueix "<paraula1>" per "<paraula2>"
      if(not gestor.esta_escogido()) cout << "error" << endl;
      else{
	iss.ignore('"');
	iss >> op; string p1(op);
	iss >> op;
	iss >> op; string p2(op);
	gestor.texto_escogido_gestor().sustituir_palabra(p1, p2);
      }
    }
    else if(op == "textos"){ //textos autor "<autor>" ?
      iss >> op; string nombre = iss.str();
      if(not gestor.existe_autor(nombre)) cout << "error" << endl;
      else gestor.textos_autor(nombre);
    }
    else if(op == "tots"){ 
      iss >> op;
      if(op == "autors"){ //tots autors ?
          gestor.todos_autores();
      }
      else{ //tots textos ?
          gestor.todos_textos();
      }
    }
    else if(op == "info"){ 
      iss >> op;
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
     iss >> op;
     if(not gestor.esta_escogido()) cout << "error" << endl;
     else if(int(op[0]) >= 0 and int(op[0]) <= 9){ //frases x y
        istringstream aux(op);
        int x; aux >> x;
	    int y; iss >> y;
	    gestor.texto_escogido_gestor().frases_xy(x, y);
     }
     else if(op[0] == '"'){ //frases secuencia
	list<string> l; list<string>::iterator it = l.begin();
	string p(op); l.insert(it, p);
	while(op[op.size()-1] != '"'){
	  iss >> op;
	  l.insert(it, op);
	}
	gestor.texto_escogido_gestor().frases_seq(l);
     }
     else{ //frases expressio
     	//falta 
         cout << endl;
     }
    }
    else if(op == "nombre"){
      iss >> op; //Quitamos el "de" 
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