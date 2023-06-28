#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

/**
* @class: Classe Gerente
* @brief Arquivo HPP da classe Gerente
*/

class Gerente : public Pessoa, public Funcionario{

  float participacaoLucros;

  public:
  Gerente();
  Gerente(float participacaoLucros);

  float getParticipacaoLucros();
  void setParticipacaoLucros(float participacaoLucros);

  float calcularSalario(int diasFaltas);
  float calcularRecisao(Data desligamento);


};

#endif