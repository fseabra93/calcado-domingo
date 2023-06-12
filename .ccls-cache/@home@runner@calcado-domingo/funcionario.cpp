#include <iostream>
#include "funcionario.hpp"

using namespace std;

  Funcionario :: Funcionario(){};
  Funcionario :: Funcionario(float salario, string matricula, int ano_ingr, int mes_ingr, int dia_ingr, int ano_demiss, int mes_demiss, int dia_demiss, int diasFaltas){
      this->salario = salario;
      this->matricula = matricula;
      ingressoEmpresa.ano = ano_ingr;
      ingressoEmpresa.mes = mes_ingr;
      ingressoEmpresa.dia = dia_ingr;
      desligamento.ano = ano_demiss;
      desligamento.mes = mes_demiss;
      desligamento.dia = dia_demiss;
      this->diasFaltas = diasFaltas;
  }

  float Funcionario::getSalario(){
    return this->salario;
  }
  void Funcionario::setSalario(int diasFaltas){
    this->salario = salario-((salario*diasFaltas)/30);
  }

  string Funcionario::getMatricula(){
    return this->matricula;
  }
  void Funcionario::setMatricula(string matricula){
    this->matricula = matricula;
  }
  Data Funcionario::getIngressoEmpresa(){
    return this->ingressoEmpresa;
  }
  void Funcionario::setIngressoEmpresa(int ano_ingr, int mes_ingr, int dia_ingr){
      ingressoEmpresa.ano = ano_ingr;
      ingressoEmpresa.mes = mes_ingr;
      ingressoEmpresa.dia = dia_ingr;
  }

  Data Funcionario::getDataDemissao(){
    return this->desligamento;
  }

void Funcionario::setDataDemissao(int ano_demiss, int mes_demiss, int dia_demiss){
  desligamento.ano = ano_demiss;
  desligamento.mes = mes_demiss;
  desligamento.dia = dia_demiss;
}

int Funcionario::getFaltas(){
  return this->diasFaltas;
}

void Funcionario::setFaltas(int diasFaltas){
  this->diasFaltas = diasFaltas;
}