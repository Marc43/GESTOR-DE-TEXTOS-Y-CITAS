#include "Texto.hh"

Texto::Texto(string autor, string titulo, list<Frase> contenido){
  this->autor = autor;
  this->titulo = titulo;
  this->contenido = contenido;
  num_frases = contenido.size();
  num_palabras = 0;
  frecuencia_maxima = 0;
  int maxima_longitud = 0;
  map<Palabra, int> freq; map<Palabra, int>::iterator it_f;
  for(int i = 0; i < contenido.size(); ++i){
    num_palabras += contenido[i].size();
    list<Palabra> frase = contenido[i].contenido_frase();
    for(list<Palabra>::iterator it = frase.begin(); it != frase.end(); ++it){
      it_f = freq.find(*it);
      if((*it_f).longitud() > maxima_longitud) maxima_longitud = (*it_f).longitud();
      if(it_f != freq.end()){
	freq[*it_f] += 1;
	if(freq[*it_f] > frecuencia_maxima) frecuencia_maxima = freq[*it_f];
      }
      else{
	freq[*it_f] = 1;
	if(freq[*it_f] > frecuencia_maxima) frecuencia_maxima = freq[*it_f];
      }
    }
  }
  it_f = freq.begin();
  while(it_f != freq.end()){
    
     +
    ++it_f;
  }
}

string Texto::autor_texto(){
  return autor;
}

string Texto::titulo_texto(){
  return titulo;
}

void Texto::citas_texto(){
  for(map<string, Cita>::iterator it = citas.begin(); it != citas.end(); ++it){
    cout << (*it)->first << endl;
    int x; int y; (*it)->second.num_frases(x, y);
    vector<Frase> contenido = it->second.contenido();
    for(int i = 0; i < contenido.size(); ++i){
      cout << x + i << " "; contenido[i].escribir_frase();
    }
    cout << it->second.titulo() << '"' << it->second.autor() << '"' << endl;
  }
}

void Texto::numero_frases(){
  cout << num_frases << endl;
}

void Texto::numero_palabras(){
  cout << num_palabras << endl;
}

void Texto::contenido(){
  list<Frase>::iterator it = contenido.begin(); int n = 1;
  while(it != contenido.end()){
    cout << n << ' ';
    (*it).escribir_frase()
    ++it; ++n;
  }
}

void Texto::tabla_frecuencias(){
  
}

Cita Texto::frases_xy(int x, int y, bool cita, Citas& citas, Textos& textos, Autores& autores){
  if(x > y) cout << "ERROR" << endl;
  else{
    list<Frase>::iterator it = contenido.begin();
    while(it != contenido.end() and x >= y){
      cout << x << ' ';
      (*it).escribir_frase();
      ++x; ++it;
    }
  } //Falta el caso de las citas
}

void Texto::frases_exp(istringstream iss){
  
}

void Texto::frases_seq(list<Palabra>& seq){
  list<Frase>::iterator it1 = contenido.begin();
  while(it1 != contenido.end()){
    list<Palabra> p = (*it1).contenido_frase();
    list<Palabra>::iterator it2 = p.begin(); 
    bool imp = false; list<Palabra> aux = seq;
    list<Palabra>::iterator it3 = aux.begin();
    while(not imp and it2 != p.end()){
      if((*it2).son_iguales(*it3)){
	it3 = it3.erase();
      }
      if(aux.size() == 0) imp = true;
      ++it2;
    }
    if(imp == true) (*it1).escribir_frase();
    ++it1;
  }
  
void Texto::anadir_cita(const Cita& c){
  
}

void sustituir_palabra(const Palabra &p1, const Palabra &p2){
  list<Frase>::iterator it1 = contenido.begin();
  while(it1 != contenido.end()){
    list<Palabra> p = (*it1).contenido_frase();
    list<Palabra>::iterator it2 = p.begin();
    while(it2 != p.end()){
      if((*it2).son_iguales(p1)) *it2 = p2;
      ++it2;
    }
    ++it1;
  }
}
  
}
