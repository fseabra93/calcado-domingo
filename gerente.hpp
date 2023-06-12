#ifndef GERENTE_HPP
#define GERENTE_HPP
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

class Gerente : public Pessoa, Funcionario{

  Pessoa pessoa;
  float participacaoLucros = 2000;

  public:
  Gerente();
  Gerente(Pessoa pessoa, float participacaoLucros, float salario, string matricula, int ano_ingr, int mes_ingr, int dia_ingr);

  float getParticipacaoLucros();
  void setParticipacaoLucros(float participacaoLucros);

  Pessoa getPessoa();
  void setPessoa(Pessoa pessoa);

  void calcularSalario();
  void calcularRecisao();


};

#endif