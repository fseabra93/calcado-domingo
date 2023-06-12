#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

using namespace std;

class Empresa : public Pessoa, Funcionario {

  string nomeEmpresa;
  string cnpj;
  float faturamentoMensal;
  Pessoa dono;
  vector<Asg>asgs;
  vector<Vendedor>vendedores;
  vector<Gerente>gerentes;
  Data hoje;


  public:
  Empresa();
  Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, string nome_dono, vector<Asg>asgs, vector<Vendedor>vendedores, vector<Gerente>gerentes, int h_ano, int h_mes, int h_dia);

  Data getHoje();
  void setHoje(int h_ano, int h_mes, int h_dia);

  float getFaturamento();
  void setFaturamento(float faturamentoMensal);

  std::string getNomeEmpresa();
  void setNomeEmpresa(std::string nomeEmpresa);

  std::string getCnpj();
  void setCnpj(std::string cnpj);

  Pessoa getDono();
  void setDono(string nome_dono, string cpf_dono, int n_filhos_dono, string est_civ_dono, string cidade_dono, string cep_dono, string bairro_dono, string rua_dono, int n_casa_dono, int ano_nasc_dono, int mes_nsac_dono, int dia_nasc_dono);

  vector<Asg> getAsgs();
  void setAsgs(vector<Asg>asgs);
  vector<Vendedor> getVendedores();
  void setVendedores(vector<Vendedor>vendedores);
  vector<Gerente> getGerentes();
  void setGerentes(vector<Gerente>gerentes);

  void carregaFuncoes(Empresa *empr);
  void carregarEmpresa(Empresa *em);
  void carregarAsg();
  void carregarVendedor();
  void carregarGerente();
  void carregaDono();
  void imprimeAsgs(); 
  //void imprimeVendedores();
  //void imprimeGerentes();

  
  
  //imprimeDono();
  //buscaFuncionario(int matricula);
  //calculaSalarioFuncionario(int matricula);
  //calculaTodoOsSalarios();
  //calcularRecisao(int matricula, Data desligamento);
  
  


};

#endif
