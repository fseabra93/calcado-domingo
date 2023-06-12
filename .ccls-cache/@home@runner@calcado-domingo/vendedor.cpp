#include <iostream>
#include "vendedor.hpp"

using namespace std;

Vendedor::Vendedor(){}
Vendedor::Vendedor(Pessoa pessoa, string matricula, float salario, char tipoVendedor, int ano_ingr, int mes_ingr, int dia_ingr){
  this->pessoa=pessoa;
  setMatricula(matricula);
  setSalario(salario); 
  this->tipoVendedor = tipoVendedor;
  setIngressoEmpresa( ano_ingr, mes_ingr, dia_ingr);

}

char Vendedor::getTipo(){
  return this->tipoVendedor;
}

void Vendedor::setTipo(char tipoVendedor){
  this->tipoVendedor=tipoVendedor;
}

Pessoa Vendedor::getPessoa() {
    return this-> pessoa;
}

void Vendedor::setPessoa(Pessoa pessoa) {
    this->pessoa = pessoa;
}


void Vendedor::calcularSalario(){
  diasFaltas = getFaltas();
  float salTemp = getSalario();
  if (diasFaltas > 0){
    salTemp = salTemp - ((salTemp/30)*diasFaltas);
  }

  char tipo = getTipo();

  if(tipo == 'A'){
    salTemp = salTemp*1.25; 
  } else if (tipo == 'B'){
    salTemp = salTemp*1.15;
  } else if (tipo == 'C'){
    salTemp = salTemp*1.05;
  }
  salTemp = salTemp+(getQtdFilhos()*100);
  this->setSalario(salTemp);
}

void Vendedor::calcularRecisao(){
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
    
  float valor_recisao = total_dias*valor_dia*getTipo();

  cout << "O valor da recisão é: " << valor_recisao << endl;
  
}
