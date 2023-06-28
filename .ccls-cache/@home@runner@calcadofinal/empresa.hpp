#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

using namespace std;

/**
* @class: Classe Empresa
* @brief Arquivo HPP da classe Empresa
*/

class Empresa {

  string nomeEmpresa;
  string cnpj;
  float faturamentoMensal;
  Pessoa *Dono = new Pessoa();
  vector<Asg>asgs;
  vector<Vendedor>vendedores;
  vector<Gerente>gerentes;


  public:
  Empresa();
  Empresa(string nomeEmpresa, float faturamentoMensal, string cnpj);

  float getFaturamentoMensal();
  void setFaturamentoMensal(float faturamentoMensal);

  string getNomeEmpresa();
  void setNomeEmpresa(string nomeEmpresa);

  string getCnpj();
  void setCnpj(string cnpj);

  Pessoa *getDono();

  vector<Asg> getAsgs();
  void setAsgs(vector<Asg>asgs);
  vector<Vendedor> getVendedores();
  void setVendedores(vector<Vendedor>vendedores);
  vector<Gerente> getGerentes();
  void setGerentes(vector<Gerente>gerentes);

  void carregaFuncoes();
  void carregarEmpresa();
  void carregarAsg();
  void carregarVendedor();
  void carregarGerente();
  void carregaDono();
  void imprimeAsgs();
  void imprimeDono();
  void imprimeVendedores();
  void imprimeGerentes();
  float calculaSalarioIndividual(string matricula);

  void buscaFuncionario(string matricula);
  void calculaSalarioFuncionario(string matricula);
  void calculaTodoOsSalarios();
  float calcularRecisao(string matricula, Data desligamento);

  void demitirFuncionario(string matricula, Data desligamento);
  void contratarFuncionario();
  void removerFuncionario(string nome, string cargo);


};

#endif
