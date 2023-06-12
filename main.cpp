#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
#include "empresa.hpp"

using namespace std;

int main(/*int argc, char *argv[ ]*/ ) {

  //pegar a data de hoje do argv//////////////////
  //string hoje = argv[1];
  string hoje = {"12/06/2023"};

  char dia[2];
  char mes[2];
  char ano[4];
  
  int h_dia = (hoje[0] - '0')*10 + (hoje[1] - '0');
  int h_mes = (hoje[3] - '0')*10 + (hoje[4] - '0');
  int h_ano = (hoje[6] - '0')*1000 + (hoje[7] - '0')*100 + (hoje[8] - '0')*10 + (hoje[9] - '0');

  cout<< h_dia << "/" << h_mes << "/" << h_ano << endl;
  ///////////////////////////////////////////////

  Empresa *atacadoDosCalcados;
  atacadoDosCalcados->setHoje(h_ano, h_mes, h_dia);
  //atacadoDosCalcados->carregaFuncoes(atacadoDosCalcados);
  atacadoDosCalcados->carregarEmpresa(atacadoDosCalcados);


  
}