#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

/**
* @class: Classe Vendedor
* @brief Arquivo HPP da classe Vendedor
*/

class Vendedor : public Pessoa, public Funcionario{

  char tipoVendedor;

  public:
    Vendedor();
    Vendedor(char tipoVendedor);

  char getTipo();
  void setTipo(char tipoVendedor);

  float calcularSalario(int diasFaltas);
  float calcularRecisao(Data desligamento);

};

#endif