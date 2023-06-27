#include <iostream>
#include "vendedor.hpp"

using namespace std;

Vendedor::Vendedor(){}
Vendedor::Vendedor(char tipoVendedor){ 
    this->tipoVendedor = tipoVendedor;
}

char Vendedor::getTipo(){
  return this->tipoVendedor;
}

void Vendedor::setTipo(char tipoVendedor){
  this->tipoVendedor=tipoVendedor;
}

float Vendedor::calcularSalario(int diasFaltas){
  float precoDia = getSalario()/30;     
  float desconto = precoDia * diasFaltas;
  float sal = (getSalario() - desconto); 

  char tipo = getTipo();

  if(tipo == 'A'){
    sal = sal*1.25; 
  } else if (tipo == 'B'){
    sal = sal*1.15;
  } else if (tipo == 'C'){
    sal = sal*1.05;
  }
  sal = sal+(getQtdFilhos()*100);
  return sal;
}

float Vendedor::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano;
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
  
}
