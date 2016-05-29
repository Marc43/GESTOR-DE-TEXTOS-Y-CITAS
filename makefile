FLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: Autor.o Cita.o Frase.o funciones_aux.o Gestor.o program.o Texto.o
	g++ -o program.exe *.o $(FLAGS)

Autor.o: Autor.cc Autor.hh
	g++ -c Autor.cc $(FLAGS)

Cita.o: Cita.cc Cita.hh
	g++ -c Cita.cc $(FLAGS)

Frase.o: Frase.cc Frase.hh
	g++ -c Frase.cc $(FLAGS)

funciones_aux.o: funciones_aux.cc funciones_aux.hh
	g++ -c funciones_aux.cc $(FLAGS)

Gestor.o: Gestor.cc Gestor.hh
	g++ -c Gestor.cc $(FLAGS)

program.o: program.cc
	g++ -c program.cc $(FLAGS)

Texto.o: Texto.cc Texto.hh
	g++ -c Texto.cc $(FLAGS)