#include <iostream>
#include "gerente.hpp"

using namespace std;

Gerente::Gerente(){}
Gerente::Gerente(Pessoa pessoa, float participacaoLucros, float salario, string matricula, int ano_ingr, int mes_ingr, int dia_ingr){
  this->pessoa=pessoa;
  this->participacaoLucros = participacaoLucros;
  setSalario(salario);
  setMatricula(matricula);
  setIngressoEmpresa(ano_ingr, mes_ingr, dia_ingr);
}

float Gerente::getParticipacaoLucros(){
  return this->participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros){
  this->participacaoLucros=participacaoLucros;
}

Pessoa Gerente::getPessoa() {
    return this-> pessoa;
}

void Gerente::setPessoa(Pessoa pessoa) {
    this->pessoa = pessoa;
}


void Gerente::calcularSalario(){
  diasFaltas = getFaltas();
  float salTemp = getSalario();
  if (diasFaltas > 0){
    salTemp = (salTemp - ((salTemp/30)*diasFaltas));
  }
  salTemp = salTemp+(getQtdFilhos()*100);
  this->setSalario(salTemp+getParticipacaoLucros());
}

void Gerente::calcularRecisao(){
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
    
  float valor_recisao = total_dias*valor_dia;

  cout << "O valor da recisão é: " << valor_recisao << endl;
  
}
