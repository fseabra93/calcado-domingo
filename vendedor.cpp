#include <iostream>
#include "vendedor.hpp"

using namespace std;

/**
* @class: Classe Vendedor
* @brief Arquivo CPP da classe Vendedor
*/

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

/**
* @fn: Função calcularSalario na Classe Vendedor
* @brief Calcula os salários dos Vendedores
* @param Recebe a quantidade de faltas
* return Retorna o salário
*/

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

/**
* @fn: Função calcularRecisao na Classe Vendedor
* @brief Calcula as recisões dos Vendedores
* @param Recebe a data do desligamento do Vendedores
* return Retorna o valor da recisão dos Vendedores
*/

float Vendedor::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano;
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
  
}
