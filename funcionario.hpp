#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"

using namespace std;

/**
* @class: Classe Funcionario
* @brief Arquivo HPP da classe Funcionario
*/

class Funcionario{
  string matricula;
  float salario;
  Data ingressoEmpresa;
  Data desligamento; // não tem no do professor
  int diasFaltas;



  public:
  float getSalario();
  void setSalario(float salario);
  string getMatricula();
  void setMatricula(string matricula);
  Data getIngressoEmpresa();
  void setIngressoEmpresa(Data ingressoEmpresa);
  Data getDataDesligamento(); // não tem no do professor
  void setDataDesligamento(Data desligamento); // não tem no do professor
  int getFaltas();
  void setFaltas(int diasFaltas);
  virtual float calcularSalario(int diasFaltas) = 0;
  virtual float calcularRecisao(Data desligamento) = 0;

};


#endif