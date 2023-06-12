#ifndef ASG_HPP
#define ASG_HPP
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

class Asg : public Pessoa, Funcionario{

  Pessoa pessoa;
  float adicionalInsalubridade = 1.05;

  public:
  Asg();
  Asg(Pessoa pessoa, string matricula, float salario, float adicionalInsalubridade, int ano_ingr, int mes_ingr, int dia_ingr);

  Pessoa getPessoa();
  void setPessoa(Pessoa pessoa);
  
  float getInsalubridade();
  void setInsalubridade(float adicionalInsalubridade);

  void calcularSalario();
  void calcularRecisao();

};


#endif