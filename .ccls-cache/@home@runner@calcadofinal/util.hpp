#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <string>
using namespace std;

/**
* @struct: Struct Data
*/
  
typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

/**
* @struct: Struct Endereço
*/

typedef struct {
    std::string cidade;
    std::string bairro;
    std::string rua;
    std::string cep;
    int numero;
} Endereco;

#endif