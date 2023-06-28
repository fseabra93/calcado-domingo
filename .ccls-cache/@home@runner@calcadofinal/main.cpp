#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
#include "empresa.hpp"

using namespace std;

/**
* @file: main.cpp
* @brief Arquivo principal (main)
* @author Flavio Roberto Guerra Seabra
* @Date Data de criação (26 de junho de 2023)
* @brief Criação dinâmica da Empresa e chamada da função carregaFuncoes()
*/

int main( ) {

  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
 
}

//Comprovante do SIGAA -> Submissão da tarefa realizada com sucesso. Comprovante de submissão Nº 2907997