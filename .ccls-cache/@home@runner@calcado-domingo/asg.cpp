#include <iostream>
#include "asg.hpp"

using namespace std;

Asg::Asg(){}
Asg::Asg(Pessoa pessoa, string matricula, float salario, float adicionalInsalubridade, int ano_ingr, int mes_ingr, int dia_ingr){
  this->pessoa = pessoa;
  setMatricula(matricula);
  setSalario(salario);
  this->adicionalInsalubridade = adicionalInsalubridade;
  setIngressoEmpresa(ano_ingr, mes_ingr, dia_ingr);

}

Pessoa Asg::getPessoa() {
    return this-> pessoa;
}

void Asg::setPessoa(Pessoa pessoa) {
    this->pessoa = pessoa;
}


float Asg::getInsalubridade(){
  return this->adicionalInsalubridade;
}

void Asg::setInsalubridade(float adicionalInsalubridade){
  this->adicionalInsalubridade=adicionalInsalubridade;
}



void Asg::calcularSalario(){
  diasFaltas = getFaltas();
  float salTemp = getSalario();
  if (diasFaltas > 0){
    salTemp = (salTemp - ((salTemp/30)*diasFaltas));
  }
  salTemp = salTemp+(getQtdFilhos()*100);
  this->setSalario(salTemp);
}

void Asg::calcularRecisao(){
  int anos = getDataDemissao().ano - getIngressoEmpresa().ano;
  
  int meses = getDataDemissao().mes - getIngressoEmpresa().mes;

  int dias = getDataDemissao().dia - getIngressoEmpresa().dia;

  float valor_dia = getSalario()/30;
  float total_dias = 0;

  int dif_dias = 0;
  if (dias <0){
    dif_dias += dias+30;
  } else {
    dif_dias += dias;
  }

  int dif_meses = 0;
  if (meses<0){
    dif_meses += meses+12;
  } else {
    dif_meses += meses;
  }
  
  if (anos == 0){
    total_dias += dif_dias+(dif_meses*30);
  } else if (anos > 0 && meses >= 0){
    total_dias += dif_dias+(dif_meses*30)+(anos*365);
  } else if (anos > 0 && meses < 0){
    total_dias += dif_dias+((dif_meses-1)*30)+((anos-1)*365);
  }
    
  float valor_recisao = total_dias*valor_dia*getInsalubridade();

  cout << "O valor da recisão é: " << valor_recisao << endl;
  
}
