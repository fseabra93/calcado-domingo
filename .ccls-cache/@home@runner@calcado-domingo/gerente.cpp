#include <iostream>
#include "gerente.hpp"

using namespace std;

/**
* @class: Classe Gerente
* @brief Arquivo CPP da classe Gerente
*/

Gerente::Gerente(){}
Gerente::Gerente(float participacaoLucros){
    this->participacaoLucros = participacaoLucros;
};

float Gerente::getParticipacaoLucros(){
  return this->participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros){
  this->participacaoLucros=participacaoLucros;
}

/**
* @fn: Função calcularSalario na Classe Gerente
* @brief Calcula os salários dos Gerente
* @param Recebe a quantidade de faltas
* return Retorna o salário
*/

float Gerente::calcularSalario(int diasFaltas){
    float precoDia = getSalario() / 30;     // valor do dia
    float desconto = precoDia * diasFaltas; // descontos de falta
    float salarioMes = (getSalario() - desconto) + this->participacaoLucros + (getQtdFilhos()*100);
    return salarioMes;
}

/**
* @fn: Função calcularRecisao na Classe Vendedor
* @brief Calcula as recisões dos Gerente
* @param Recebe a data do desligamento do Gerente
* return Retorna o valor da recisão do Gerente
*/

float Gerente::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano;
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
}