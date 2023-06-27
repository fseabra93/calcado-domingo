#include <iostream>
#include "gerente.hpp"

using namespace std;

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

float Gerente::calcularSalario(int diasFaltas){
    float precoDia = getSalario() / 30;     // valor do dia
    float desconto = precoDia * diasFaltas; // descontos de falta
    float salarioMes = (getSalario() - desconto) + this->participacaoLucros + (getQtdFilhos()*100);
    return salarioMes;
}

float Gerente::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano;
    float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
    float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
}