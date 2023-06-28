#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
* @class: Classe ASG
* @brief Arquivo HPP da classe ASG
*/

using namespace std;

class Asg : public Pessoa, public Funcionario{

  float adicionalInsalubridade;

  public:
  Asg();
  Asg(float adicionalInsalubridade);
  
  float getInsalubridade();
  void setInsalubridade(float);

  float calcularSalario(int diasFaltas);
  float calcularRecisao(Data desligamento);

};


#endif