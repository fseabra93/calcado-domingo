#include <iostream>
#include "asg.hpp"

using namespace std;

/**
* @class: Classe ASG
* @brief Arquivo CPP da classe ASG
*/

Asg::Asg(){}
Asg::Asg(float adicionalInsalubridade){
    this->adicionalInsalubridade = adicionalInsalubridade;
}


float Asg::getInsalubridade(){
  return this->adicionalInsalubridade;
}

void Asg::setInsalubridade(float){
  this->adicionalInsalubridade = adicionalInsalubridade;
}

/**
* @fn: Função calcularSalario na Classe ASG
* @brief Calcula os salários dos ASG
* @param Recebe a quantidade de faltas
* return Retorna o salário
*/

float Asg::calcularSalario(int diasFaltas){

  float salarioDia = getSalario()/30;
  float insalubr = getInsalubridade() + 1;
  float sal = getSalario()*insalubr;

  sal = sal + (getQtdFilhos()*100) - (salarioDia*diasFaltas);
  return sal;
}

/**
* @fn: Função calcularRecisao na Classe ASG
* @brief Calcula as recisões dos ASG
* @param Recebe a data do desligamento do ASG
* return Retorna o valor da recisão dos ASGs
*/

float Asg::calcularRecisao(Data desligamento){

    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano; 
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
  
}
