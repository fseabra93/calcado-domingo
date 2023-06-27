#include <iostream>
#include "funcionario.hpp"

using namespace std;

/**
* @class: Classe Funcionario
* @brief Arquivo CPP da classe Funcionario
*/

float Funcionario::getSalario(){
    return this->salario;
  }
void Funcionario::setSalario(float salario){ 
    this->salario = salario; 
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
  void Funcionario::setIngressoEmpresa(Data ingressoEmpresa){
    this->ingressoEmpresa = ingressoEmpresa;
  }

  Data Funcionario::getDataDesligamento(){
    return this->desligamento;
  }

void Funcionario::setDataDesligamento(Data desligamento){
  this->desligamento = desligamento;
}

int Funcionario::getFaltas(){
  return this->diasFaltas;
}

void Funcionario::setFaltas(int diasFaltas){
  this->diasFaltas = diasFaltas;
}