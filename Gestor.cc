//
// Created by Zebs on 17/05/2016.
//

#include "Gestor.hh"

Gestor::Gestor(){
    escogido = false;
}

bool Gestor::existe_autor(string nombre){
    map<string, Autor>::iterator it;
    it = autores.find(nombre);
    return it != autores.end();
}

void Gestor::todos_autores(){
    for(map<string, Autor>::iterator it = autores.begin(); it != autores.end(); ++it){
        map<string, Texto> t_a = it->second.textos_autor();
        int num_t = t_a.size();
        int num_f = 0;
        int num_p = 0;
        for(map<string, Texto>::iterator it2 = t_a.begin(); it2 != t_a.end(); ++it2){
            num_f += i2t->second.numero_frases();
            num_p += it2->second.numero_palabras();
        }
        cout << it->first << " " << num_t << " " << num_f << " " << num_p << " " << endl;
    }
}

void Gestor::anadir_autor(Autor autor){
    autores[autor.nombre_autor()] = autor;
}

void Gestor::eliminar_autor(string nombre){ //no hace falta
    autores.erase(nombre);
}

void Gestor::anadir_texto(const Texto &texto){
    if(existe_autor(texto.autor_texto())){
        autores[texto.autor_texto()].anadir_texto(texto);
    }
    else{
        Autor a(texto.autor_texto());
        a.anadir_texto(texto);
        autores[texto.autor_texto()] = a;
    }
    textos[texto.titulo_texto()] = texto;
}

void Gestor::eliminar_texto(){
    if(autores[texto_escogido->second.autor_texto()].textos_autor().size() == 1){
        eliminar_autor(texto_escogido->second.autor_texto());
    }
    texto_escogido = textos.erase(texto_escogido);
    escogido = false;
}

bool escoger_texto(const list<string>& p, Texto& t){
    bool match = false;
    for(map<string, Texto>::iterator it = textos.begin(); it != textos.end(); ++it){
        list<string> aux = p;
        for(list<string>::iterator it2 = aux.begin(); it != aux.end(); ++it){
            list<Frase> aux2 = t.contenido(); //contenido devuelve frases (list string)
            bool encontrado = false;
            for(list<Frase>::iterator it3 = aux2.begin(); not encontrado and it != aux2.end(); ++it){
                for(list<string>::iterator it4 = (*it3).begin(); not encontrado and it4 != (*it3).end(); ++it){
                    if(*it4 == *it2){
                        encontrado = true;
                        it2 = aux.erase(it2);
                        --it2;
                    }
                }
            }
        }
        if(aux.size() == 0){
            if(not match){
                match = true;
                t = it->second;
            }
            else{
                escogido = false;
                return false;
            }
        }
    }
    escogido = match;
    return match;
}

void Gestor::todos_textos(){
    for(map<string, Autor>::iterator it = autores.begin(); it != autores.end(); ++it){
        map<string, Texto> m_t = it->second.textos_autor();
        for(map<string, Texto>::iterator it2 = m_t.begin(); it2 != m_t.end(); ++it2){
            cout << it->first << " " << '"' << it2->first << '" ' << endl;
        }
    }
}

bool Gestor::escogido(){
    return escogido;
}

void Gestor::todas_citas(){
    for(map<string, Cita>::iterator it = citas.begin(); it != citas.end(); ++it){
        it->second.escribir_cita();
    }
}

void Gestor::anadir_cita(const Cita &cita){
    istringstream iss(cita.autor_cita());
    string a_tratar, id; iss >> a_tratar;
    while(iss >> a_tratar){
        id += a_tratar[0];
    }
    map<string, int>::iterator it = this->id.find(id);
    if(it != this->id.end()){
        id += str(it->second);
        it->second += 1;
    }
    else{
        this->id[id] = 2;
        id += '1';
    }
    citas[id] = cita;
}

void eliminar_cita(string id){
    this->id-erase(id);
    id = id.substr(0, id.size()-1);
    map<string, int>::iterator it = this->id.find(id);
    if(it->second > 1) it->second -= 1;
    else{
        this->id.erase(id);
    }
}