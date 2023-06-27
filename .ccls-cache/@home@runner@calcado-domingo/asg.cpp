#include <iostream>
#include "asg.hpp"

using namespace std;

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

float Asg::calcularSalario(int diasFaltas){

  float salarioDia = getSalario()/30;
  float insalubr = getInsalubridade() + 1;
  float sal = getSalario()*insalubr;

  sal = sal + (getQtdFilhos()*100) - (salarioDia*diasFaltas);
  return sal;
}

float Asg::calcularRecisao(Data desligamento){

    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano; 
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
  
}
