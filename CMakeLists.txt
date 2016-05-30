cmake_minimum_required(VERSION 3.3)
project(GESTOR_DE_TEXTOS_Y_CITAS_master)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES program.cc
Texto.cc
Autor.cc
Cita.cc
Gestor.cc
funciones_aux.cc
Frase.cc)
add_executable(GESTOR_DE_TEXTOS_Y_CITAS_master ${SOURCE_FILES})