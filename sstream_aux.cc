#include<string>
#include<sstream>

void recorta(istringstream& iss){
  int pos = 0;
  bool encontrado = false;
  string aux = iss.str();
  while(aux[pos] == ' ') ++pos;
  while(aux[pos] != ' ' and pos < aux.length()) ++pos;
  aux.erase(0, pos + 1);
  iss.str(aux);
}
