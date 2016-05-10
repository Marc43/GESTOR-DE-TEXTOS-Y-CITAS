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
      iss >> op; iss.str();
      autores.autor_nombre().textos_autor();
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
