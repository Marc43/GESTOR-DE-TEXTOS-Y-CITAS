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
    cout << it->second.titulo() << ' "' << it->second.autor() << '"' << endl;
  }
}

void Texto::numero_frases(){
  cout << contenido.size();
}