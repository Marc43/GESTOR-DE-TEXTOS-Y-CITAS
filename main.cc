#include <sstream>
#include "Autores.hh"

using namespace std;

int main(){
  Citas citas;
  Autores autores;
  Textos textos;
  string linea, op;
  getline(cin, linea);
  while(linea != "sortir"){
    istringstream iss(linea); iss >> op;
    if(op == "triar"){
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
      if(op == "text"){
	if(textos.escogido() == false) cout << "ERROR" << endl;
	else{
	  textos.eliminar_texto();
	}
      }
      else{
	iss.ignore('"'); iss >> op;
	Palabra ref(op);
	citas.eliminar_cita(ref);
      }
    }
    else if(op == "substitueix"){
      if(textos.escogido() == false) cout << "ERROR" << endl;
      else{
	iss.ignore('"');
	iss >> op; Palabra p1(op);
	iss >> op;
	iss >> op; Palabra p2(op);
	textos.texto_escogido().sustituir_palabra(p1, p2);
      }
    }
    else if(op == "textos"){
      iss >> op; string nombre = iss.str();
      autores.autor_nombre(nombre).textos_autor();
    }
    else if(op == "tots"){
      iss >> op;
      if(op == "autors"){
	autores.todos_autores();
      }
      else{
	textos.todos_textos();
      }
    }
    else if(op == "info"){
      iss >> op;
      if(op == "cita"){
	iss.ignore('"');
	citas.
      }
      if(textos.escogido() == false) cout << "ERROR" << endl;
      else{
	cout << textos.texto_escogido().autor_texto() << endl << textos.texto_escogido().titulo_texto() << endl;
	cout << textos.texto_escogido().numero_frases() << endl << textos.texto_escogido().numero_palabras() << endl;
	cout << textos.texto.escogido().citas_texto();
      }
    }
    else if(op == "autor"){
      if(textos.escogido() == false) cout << "ERROR" << endl;
      else{
	cout << textos.texto_escogido().autor_texto();
      }
    }
    else if(op == "contingut"){
      if(textos.escogido() == false) cout << "ERROR" << endl;
      else{
	cout << textos.texto_escogido().contenido();
      }
    }
    else if(op == "frases"){
      //pendiente
    }
    else if(op == "nombre"){
      if(textos.escogido() == false) cout << "ERROR" << endl;
      iss >> op;
      else if(op == "paraules") cout << textos.texto_escogido().numero_palabras() << endl;
      else cout << textos.texto_escogido().numero_frases() << endl;
    }
    
  }
}
































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
  //Anadir texto
  string sr, p;
  getline(cin, sr); //Extraemos la linea entera
  istringstream iss(sr); iss >> p;
  while(sr != "sortir"){
    Autores autores;
    Textos textos;
    Citas citas;
    istringstream iss(sr);
    iss >> p;
    if(p == "afegir"){
      iss >> p;
      if(p == "text"){
	iss.ignore('"');
	string titulo = iss.str(); //Titulo del texto a anadir
	getline(cin, sr); 
	istringstream iss(sr);
	iss >> p; iss.ignore('"'); 
	string nombre_autor = iss.str(); //Nombre del autor
	if(autores.existe_autor(nombre_autor) and textos.existe_texto(titulo, nombre_autor)) cout << "ERROR" << endl; //Ya existe tal texto en este autor
	Autor autor(nombre_autor);
	list<Frase> contenido;
	leer_entrada_texto(contenido);
	Texto t(nombre_autor, titulo, contenido);
	textos.anadir_texto(t, autores);
      }
      else if(textos.escogido()){
	iss >> p; int x = p - '0';
	iss >> p; int y = p - '0';
	Cita c = frases_xy(x, y, true, citas, textos, autores);
	//Las cita ha sido anadida a citas y a su texto y autor correspondiente
      }
      else cout << "ERROR" << endl; //Ningun texto escogido
    }
  }
}
