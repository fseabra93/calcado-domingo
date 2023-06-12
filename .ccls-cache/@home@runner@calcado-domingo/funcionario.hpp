#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include "util.hpp"

using namespace std;

class Funcionario{

protected:
  float salario;
  string matricula;
  Data ingressoEmpresa;
  Data desligamento; // ver se será definida em outro lugar
  int diasFaltas = 0; // ver se será definida em outro lugar
  virtual void calcularSalario() = 0;
  virtual void calcularRecisao() = 0;


  public:
  Funcionario();
  Funcionario(float salario, string matricula, int ano_ingr, int mes_ingr, int dia_ingr, int ano_demiss, int mes_demiss, int dia_demiss, int diasFaltas);

  float getSalario();
  void setSalario(int diasFaltas);
  string getMatricula();
  void setMatricula(string matricula);
  Data getIngressoEmpresa();
  void setIngressoEmpresa(int ano_ingr, int mes_ingr, int dia_ingr);
  Data getDataDemissao();
  void setDataDemissao(int ano_demiss, int mes_demiss, int dia_demiss);
  int getFaltas();
  void setFaltas(int diasFaltas);


};


#endif