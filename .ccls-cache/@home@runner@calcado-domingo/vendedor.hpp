#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

class Vendedor : public Pessoa, Funcionario{

  Pessoa pessoa;
  char tipoVendedor;

  public:
    Vendedor();
    Vendedor(Pessoa pessoa, string matricula, float salario, char tipoVendedor, int ano_ingr, int mes_ingr, int dia_ingr);

  Pessoa getPessoa();
  void setPessoa(Pessoa pessoa);

  char getTipo();
  void setTipo(char tipoVendedor);

  void calcularSalario();
  void calcularRecisao();

};

#endif