#include "Autores.hh"

using namespace std;

void leer_entrada_texto(list<Frase>& contenido){ //MODULO IO TEXTOS
  string entrada_texto;
  list<Palabra> frase;
  list<Palabra>::iterator it = frase.begin();
  list<Frase>::iterator fr = contenido.begin(); 
  while(cin >> entrada_texto and entrada_texto != "****"){
    Palabra p(entrada_texto);
    if(not p.signo_puntuacion()) frase.insert(it, p);  
    else{
      frase.insert(it, p);
      Frase f(frase);
      contenido.insert(fr, f);
      frase.clear();
      it = frase.begin();
    }
  }
} 

int main(){
  Citas citas;
  Autores autores;
  Textos textos;
  string linea, op;
  getline(cin, linea);
  while(linea != "sortir"){ //Condicion de salida
    istringstream iss(linea); iss >> op;
      if(p == "afegir"){
	iss >> p;
	if(p == "text"){ //afegir text "<titol>"
	  iss.ignore('"');
	  string titulo = iss.str(); //Titulo del texto a anadir
	  getline(cin, sr); 
	  istringstream iss(sr);
	  iss >> p; iss.ignore('"'); 
	  string nombre_autor = iss.str(); //Nombre del autor
	  if(autores.existe_autor(nombre_autor) and textos.existe_texto(titulo, nombre_autor)) cout << "ERROR" << endl; //Ya existe tal texto en este autor
	  else{  
	    Autor autor(nombre_autor);
	    list<Frase> contenido;
	    leer_entrada_texto(contenido);
	    Texto t(nombre_autor, titulo, contenido);
	    textos.anadir_texto(t, autores);
	  }
	}
	else if(textos.escogido()){ //afegir cita x y
	  iss >> p; int x = p - '0';
	  iss >> p; int y = p - '0';
	  Cita c = frases_xy(x, y, true, citas, textos, autores);
	  //Las cita ha sido anadida a citas y a su texto y autor correspondiente
	}
        else cout << "ERROR" << endl; //Ningun texto escogido
    }
    else if(op == "triar"){ //triar text {titol}
      iss >> op;
      iss.ignore('{'); iss.ignore('}');
      list<Palabra> p;
      list<Palabra>::iterator it = p.begin();
      while(iss >> op){
	Palabra w(op);
	p.insert(it, w);
	textos.escoger_texto(p);
      }
    }
    else if(op == "eliminar"){
      iss >> op;
      if(op == "text"){ //eliminar text
	if(not textos.escogido()) cout << "ERROR" << endl;
	else{
	  textos.eliminar_texto();
	}
      }
      else{ //eliminar cita
	iss.ignore('"'); iss >> op;
	Palabra ref(op);
	citas.eliminar_cita(ref);
      }
    }
    else if(op == "substitueix"){ //substitueix "<paraula1>" per "<paraula2>"
      if(not textos.escogido()) cout << "ERROR" << endl;
      else{
	iss.ignore('"');
	iss >> op; Palabra p1(op);
	iss >> op;
	iss >> op; Palabra p2(op);
	textos.texto_escogido().sustituir_palabra(p1, p2);
      }
    }
    else if(op == "textos"){ //textos autor "<autor>" ?
      iss >> op; string nombre = iss.str();
      autores.autor_nombre(nombre).textos_autor();
    }
    else if(op == "tots"){ 
      iss >> op;
      if(op == "autors"){ //tots autors ?
	autores.todos_autores();
      }
      else{ //tots textos ?
	textos.todos_textos();
      }
    }
    else if(op == "info"){ 
      iss >> op;
      if(op == "cita"){ //info cita "<referencia>"
	iss.ignore('"');
	citas.todas_citas(); 
      }
      else if(not textos.escogido()) cout << "ERROR" << endl;
      else{ //info ?
	cout << textos.texto_escogido().autor_texto() << endl << textos.texto_escogido().titulo_texto() << endl;
	cout << textos.texto_escogido().numero_frases() << endl << textos.texto_escogido().numero_palabras() << endl;
	cout << textos.texto.escogido().citas_texto();
      }
    }
    else if(op == "autor"){ //autor ?
      if(not textos.escogido()) cout << "ERROR" << endl;
      else{
	cout << textos.texto_escogido().autor_texto();
      }
    }
    else if(op == "contingut"){ //contingut ?
      if(not textos.escogido()) cout << "ERROR" << endl;
      else{
	cout << textos.texto_escogido().contenido();
      }
    }
    else if(op == "frases"){
     iss >> op;
     if(not textos.escogido()) cout << "ERROR" << endl;
     else if(int(op[0]) >= 0 and int(op[0]) <= 9){ //frases x y
        int x = int(op); iss >> op; //Extraemos y
	int y = int(op);
	textos.texto_escogido().frases_xy(x, y);
     }
     else if(op[0] == '"'){ //frases secuencia
	list<Palabra> l; list<Palabra>::iterator it = l.begin(); 
	Palabra p(op); l.insert(it, p);
	while(op[op.size()-1] != '"'){
	  iss >> op;
	  Palabra p(op);
	  l.insert(it, p);
	}
	textos.texto_escogido().frases_seq();
     }
     else{ //frases expressio
     	iss.ignore('?');
	textos.texto_escogido().frases_exp(iss);
     }
    }
    else if(op == "nombre"){
      iss >> op; //Quitamos el "de" 
      iss >> op; //Guardamos el paraules o frases
      if(not textos.escogido()) cout << "ERROR" << endl;
      else if(op == "paraules") cout << textos.texto_escogido().numero_palabras() << endl; //nombre de paraules ?
      else cout << textos.texto_escogido().numero_frases() << endl; //nombre de frases ?
    }
    else if(op == "taula"){ //Taula de frequencies
      textos.texto_escogido().tabla_frecuencias();
    }
    getline(cin, linea); //Entrada de un nuevo comando
  }
}