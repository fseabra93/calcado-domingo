#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "empresa.hpp"

using namespace std;

/**
* @class: Classe Empresa
* @brief Arquivo CPP da classe Empresa
*/

  Empresa::Empresa(){}
  Empresa::Empresa(string nomeEmpresa, float faturamentoMensal, string cnpj){
    this->faturamentoMensal = faturamentoMensal;
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
}

  float Empresa::getFaturamentoMensal(){
    return this->faturamentoMensal; 
}
  void Empresa::setFaturamentoMensal(float faturamentoMensal){
    this->faturamentoMensal = faturamentoMensal;
}

  string Empresa::getNomeEmpresa(){
    return this->nomeEmpresa;
  }
  void Empresa::setNomeEmpresa(string nomeEmpresa){
    this->nomeEmpresa=nomeEmpresa;
  }

  string Empresa::getCnpj(){
    return this->cnpj;
  }
  void Empresa::setCnpj(string cnpj){
    this->cnpj=cnpj;
  }

  Pessoa* Empresa::getDono(){ 
    return Dono; 
}

  vector<Asg> Empresa::getAsgs(){
    return asgs;
  }

  vector<Vendedor> Empresa::getVendedores(){
    return vendedores;
  }

  vector<Gerente> Empresa::getGerentes(){
    return gerentes;
  }

/**
* @fn: Função carregaFuncoes na Classe Empresa
* @brief Carrega as funções lidas no arquivo funcoes.txt
*/

void Empresa::carregaFuncoes(){
    string linha;
    vector<string> vetor_func;
    fstream arquivoCarregarFunc;
    
    try{
      arquivoCarregarFunc.open("funcoes.txt", ios::in);
      if (!arquivoCarregarFunc) {
            throw std::runtime_error("Falha ao abrir o arquivo ");
        }

      while(getline(arquivoCarregarFunc, linha)){
        vetor_func.push_back(linha);
      }
      arquivoCarregarFunc.close(); //fecha o arquivo lido.
     
        } catch (exception &e){
      cout << "erro: " << e.what() << "funcoes.txt"<< endl;
    }
        for (int i = 0; i<vetor_func.size(); i++) {
            if (vetor_func[i]  == "carregarEmpresa()"){
              carregarEmpresa();
            }
            else if (vetor_func[i]   == "carregarAsg()"){
              carregarAsg();
            }
            else if (vetor_func[i]   == "carregarVendedor()"){
              carregarVendedor();
            }         
            else if (vetor_func[i]   == "carregarGerente()"){
              carregarGerente();
            }
            else if (vetor_func[i]   == "carregaDono()"){
              carregaDono();
            }
            else if (vetor_func[i]   == "imprimeAsgs()"){
              imprimeAsgs();
            }
            else if (vetor_func[i]   == "imprimeVendedores()"){
              imprimeVendedores();
            }
            else if (vetor_func[i]   == "imprimeGerentes()"){
              imprimeGerentes();
            }   
            else if(vetor_func[i]  == "imprimeDono()"){
                imprimeDono();
            }else if(vetor_func[i]  == "buscaFuncionario()"){
                string matricula = vetor_func[i+1];
                i++;
                buscaFuncionario(matricula);
            }else if(vetor_func[i]  == "calculaSalarioFuncionario()"){
                string matricula = vetor_func[i+1];
                i++;
                calculaSalarioFuncionario(matricula);
            }else if(vetor_func[i] == "calculaTodoOsSalarios()"){
                calculaTodoOsSalarios();
            }else if(vetor_func[i]  == "demitirFuncionario()"){
                string matricula = vetor_func[i+1];
                Data desligamento;
                time_t tempoAtual = std::time(nullptr);
                tm* tempoLocal = std::localtime(&tempoAtual);
                desligamento.ano = tempoLocal->tm_year + 1900; 
                desligamento.mes = tempoLocal->tm_mon + 1;
                desligamento.dia = tempoLocal->tm_mday;
                i+=4;
  
                //calcularRecisao(matricula, desligamento);
                demitirFuncionario(matricula, desligamento);
            }else if (vetor_func[i] == "contratarFuncionario()"){
              
              contratarFuncionario();
            }

        }
}

/**
* @fn: Função carregarEmpresa na Classe Empresa
* @brief Carrega os dados da empresa lidas a partir do arquivo empresa.txt
*/

void Empresa::carregarEmpresa(){
  
  string linha;
  vector<string> vetor_empresa;
  fstream arquivoCarregarEmpresa;

  try{
    
    arquivoCarregarEmpresa.open("empresa.txt", ios::in);
    if (!arquivoCarregarEmpresa) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }
    cout << "## Carregando dados da Empresa... ##" << endl;
    while(getline(arquivoCarregarEmpresa, linha)){
      if (linha[0] != '#'){
          vetor_empresa.push_back(linha);
      }
    }
    cout << "## Dados de Empresa carregados corretamente##" << endl << endl;
    arquivoCarregarEmpresa.close(); //fecha o arquivo lido.
    } catch (exception &e){
      cout << "erro: " << e.what() << "empresa.txt"<< endl;
    }


    this->nomeEmpresa = vetor_empresa[0];
    this->cnpj = vetor_empresa[1];
    this->faturamentoMensal = stof(vetor_empresa[2]);

    cout << "Nome da Empresa: " << getNomeEmpresa() << endl;
    cout << "CNPJ: " << getCnpj() << endl;
    cout << "Faturamento Mensal: " << getFaturamentoMensal() << endl;
    cout << "**************************************\n\n" << endl << endl;

}

/**
* @fn: Função carregarAsg na Classe Empresa
* @brief Carrega os dados dos ASGs lidos a partir do arquivo asg.txt
*/

void Empresa::carregarAsg(){
  string linha;
  vector<string>vetor_asg;
  fstream arquivoCarregarAsg;
  try{
      arquivoCarregarAsg.open("asg.txt", ios::in);
        if (!arquivoCarregarAsg) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }
    cout << "## Carregando dados de ASGs ##" << endl;
      while(getline(arquivoCarregarAsg, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'S' && linha[2] != 'G'){
          //cout << linha << endl;
          vetor_asg.push_back(linha);
        }
        
      }
      cout << "## Dados de ASGs carregados corretamente ##" << endl;
      arquivoCarregarAsg.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "asg.txt"<< endl;
    }

    Asg tAsg;

    for (int i=0; i<vetor_asg.size(); i+=19) {
      tAsg.setNome(vetor_asg[i]);
      tAsg.setCpf(vetor_asg[i+1]);
      tAsg.setQtdFilhos(stoi(vetor_asg[i+2]));
      tAsg.setEstadoCivil(vetor_asg[i+3]);
      Endereco tEnd;
      tEnd.cidade = (vetor_asg[i+4]);
      tEnd.cep = vetor_asg[i+5];
      tEnd.bairro = vetor_asg[i+6];
      tEnd.rua = vetor_asg[i+7];
      tEnd.numero = stoi(vetor_asg[i+8]);
      tAsg.setEnderecoPessoal(tEnd);
      Data tnasc;
      tnasc.ano = stoi(vetor_asg[i+9]);
      tnasc.mes = stoi(vetor_asg[i+10]);
      tnasc.dia = stoi(vetor_asg[i+11]);
      tAsg.setDataNascimento(tnasc);
      tAsg.setMatricula(vetor_asg[i+12]);
      tAsg.setSalario(stof(vetor_asg[i+13]));
      tAsg.setInsalubridade(stof(vetor_asg[i+14]));
      tAsg.setFaltas(stoi(vetor_asg[i+15]));
      Data ting;
      ting.ano=stoi(vetor_asg[i+16]);
      ting.mes=stoi(vetor_asg[i+17]);
      ting.dia=stoi(vetor_asg[i+18]);
      tAsg.setIngressoEmpresa(ting);
      asgs.push_back(tAsg);

    }

}

/**
* @fn: Função imprimeAsgs na Classe Empresa
* @brief Imprime os dados dos ASGs no console e no arquivo relatorio_final.txt
*/

void Empresa::imprimeAsgs(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  cout << "____________________________________________________________" << endl;
  arquivo << "____________________________________________________________" << endl;
  
  cout << "\n######### Relatório ASGs ########\nCargo: ASG\n" << endl;
  arquivo << "\n######### Relatório ASGs ########\nCargo: ASG\n" << endl;

    for (int i = 0; i < asgs.size(); i++) {
        arquivo << "Nome: " << asgs[i].getNome() << endl;
        cout << "Nome: " << asgs[i].getNome() << endl;
        arquivo << "CPF: " << asgs[i].getCpf() << endl;
        cout << "CPF: " << asgs[i].getCpf() << endl;
        arquivo << "Qtde de Filhos: " << asgs[i].getQtdFilhos() << endl;
        cout << "Qtde de Filhos: " << asgs[i].getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << asgs[i].getEstadoCivil() << endl;
        cout << "Estado Civil: " << asgs[i].getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << asgs[i].getEnderecoPessoal().rua << ", " << asgs[i].getEnderecoPessoal().numero << ", " << asgs[i].getEnderecoPessoal().bairro << ", " << asgs[i].getEnderecoPessoal().cidade <<  ", CEP: " << asgs[i].getEnderecoPessoal().cep << endl;
        cout << "Endereço: Rua " << asgs[i].getEnderecoPessoal().rua << ", " << asgs[i].getEnderecoPessoal().numero << ", " << asgs[i].getEnderecoPessoal().bairro << ", " << asgs[i].getEnderecoPessoal().cidade <<  ", CEP: " << asgs[i].getEnderecoPessoal().cep << endl;
        arquivo << "DN: " << asgs[i].getDataNascimento().dia<< "/" << asgs[i].getDataNascimento().mes << "/" << asgs[i].getDataNascimento().ano << endl;
      cout << "DN: " << asgs[i].getDataNascimento().dia<< "/" << asgs[i].getDataNascimento().mes << "/" << asgs[i].getDataNascimento().ano << endl;
        arquivo << "Matrícula: " << asgs[i].getMatricula() << endl;
        cout << "Matrícula: " << asgs[i].getMatricula() << endl;
        arquivo << "Salário Base: " << asgs[i].getSalario() << endl;
        cout << "Salário Base: " << asgs[i].getSalario() << endl;
        float salario = calculaSalarioIndividual(asgs[i].getMatricula());
        arquivo << "Salário do Mês: " << salario << endl;
        cout << "Salário do Mês: " << salario << endl;
        arquivo << "Funcionário da empresa desde: " << asgs[i].getIngressoEmpresa().dia<< "/" << asgs[i].getIngressoEmpresa().mes << "/" << asgs[i].getIngressoEmpresa().ano << endl;
      cout << "Funcionário da empresa desde: " << asgs[i].getIngressoEmpresa().dia<< "/" << asgs[i].getIngressoEmpresa().mes << "/" << asgs[i].getIngressoEmpresa().ano << endl;
      arquivo << "*****************************************" <<endl;
      cout << "*****************************************" <<endl;

      

    arquivo << endl;
    cout << endl;
        
    }

  arquivo.close();

   //////////////////////////////////////////////////////////////////////

}

/**
* @fn: Função carregarVendedor na Classe Empresa
* @brief Carrega os dados dos Vendedores lidos a partir do arquivo vendedor.txt
*/

void Empresa::carregarVendedor(){
  string linha;
  vector<string>vetor_vend;
  fstream arquivoCarregarVendedor;
  int cont = 0;
  try{
      arquivoCarregarVendedor.open("vendedor.txt", ios::in);
        if (!arquivoCarregarVendedor) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }

    cout << "## Carregando dados de vendedores ##" << endl;
      while(getline(arquivoCarregarVendedor, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'E' && linha[2] != 'N'){
          vetor_vend.push_back(linha);
        }
        
      }
      cout << "## Dados de Vendedores carregados corretamente ##" << endl;
      arquivoCarregarVendedor.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "vendedor.txt"<< endl;
    }

    Vendedor tVend;

    for (int i=0; i<vetor_vend.size(); i+=19) {
        tVend.setNome(vetor_vend[i]);
        tVend.setCpf(vetor_vend[i+1]);
        tVend.setQtdFilhos(stoi(vetor_vend[i+2]));
        tVend.setEstadoCivil(vetor_vend[i+3]);
        Endereco tEnd;
        tEnd.cidade = vetor_vend[i+4];
        tEnd.cep = vetor_vend[i+5];
        tEnd.bairro = vetor_vend[i+6];
        tEnd.rua = vetor_vend[i+7];
        tEnd.numero = stoi(vetor_vend[i+8]);
        tVend.setEnderecoPessoal(tEnd);
        Data tnasc;
        tnasc.ano = stoi(vetor_vend[i+9]);
        tnasc.mes = stoi(vetor_vend[i+10]);
        tnasc.dia = stoi(vetor_vend[i+11]);
        tVend.setDataNascimento(tnasc);
        tVend.setMatricula(vetor_vend[i+12]);
        tVend.setSalario(stof(vetor_vend[i+13]));
        tVend.setTipo(vetor_vend[i+14][0]);
        tVend.setFaltas(stoi(vetor_vend[i+15]));
        Data ting;
        ting.ano = stoi(vetor_vend[i+16]);
        ting.mes = stoi(vetor_vend[i+17]);
        ting.dia = stoi(vetor_vend[i+18]);
        tVend.setIngressoEmpresa(ting);
        vendedores.push_back(tVend);
             
    }
    
}

/**
* @fn: Função imprimeVendedores na Classe Empresa
* @brief Imprime os dados dos Vendedores no console e no arquivo relatorio_final.txt
*/

void Empresa::imprimeVendedores(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);
  arquivo << "____________________________________________________________" <<endl;
  cout << "____________________________________________________________" <<endl;
  cout << "\n######### Relatório Vendedores ########\nCargo: Vendedor\n" << endl;
  arquivo << "\n######### Relatório Vendedores ########\n" << endl;

  float somaSalario = 0;

    for (int i = 0; i < vendedores.size(); i++) {
        arquivo << "Nome: " << vendedores[i].getNome() << endl;
        arquivo << "CPF: " << vendedores[i].getCpf() << endl;
        arquivo << "Qtde de Filhos: " << vendedores[i].getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << vendedores[i].getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << vendedores[i].getEnderecoPessoal().rua << ", " << vendedores[i].getEnderecoPessoal().numero << ", " << vendedores[i].getEnderecoPessoal().bairro << ", " << vendedores[i].getEnderecoPessoal().cidade <<  ", CEP: " << vendedores[i].getEnderecoPessoal().cep << endl;
        arquivo << "DN: " << vendedores[i].getDataNascimento().dia<< "/" << vendedores[i].getDataNascimento().mes << "/" << vendedores[i].getDataNascimento().ano << endl;
        arquivo << "Matrícula: " << vendedores[i].getMatricula() << endl;
        arquivo << "Na empresa desde: " << vendedores[i].getIngressoEmpresa().dia << "/" << vendedores[i].getIngressoEmpresa().mes << "/" << vendedores[i].getIngressoEmpresa().ano << endl;
        arquivo << "Salário Base: " << vendedores[i].getSalario() << endl;
        float salario = calculaSalarioIndividual(vendedores[i].getMatricula());
        arquivo << "Salário do Mês: " << salario << endl;

    arquivo << endl;

        cout << "Nome: " << vendedores[i].getNome() << endl;
        cout << "CPF: " << vendedores[i].getCpf() << endl;
        cout << "Qtde de Filhos: " << vendedores[i].getQtdFilhos() << endl;
        cout << "Estado Civil: " << vendedores[i].getEstadoCivil() << endl;
        cout << "Endereço: Rua " << vendedores[i].getEnderecoPessoal().rua << ", " << vendedores[i].getEnderecoPessoal().numero << ", " << vendedores[i].getEnderecoPessoal().bairro << ", " << vendedores[i].getEnderecoPessoal().cidade <<  ", CEP: " << vendedores[i].getEnderecoPessoal().cep << endl;
        cout << "DN: " << vendedores[i].getDataNascimento().dia<< "/" << vendedores[i].getDataNascimento().mes << "/" << vendedores[i].getDataNascimento().ano << endl;
        cout << "Matrícula: " << vendedores[i].getMatricula() << endl;
        cout << "Na empresa desde: " << vendedores[i].getIngressoEmpresa().dia << "/" << vendedores[i].getIngressoEmpresa().mes << "/" << vendedores[i].getIngressoEmpresa().ano << endl;
        cout << "Salário Base: " << vendedores[i].getSalario() << endl;
        cout << "Salário do Mês: " << salario << endl;

            arquivo << "*****************************************" <<endl;
      cout << "*****************************************" <<endl;

    cout << endl;
        
    }

  arquivo.close();
  
}

/**
* @fn: Função carregarGerente na Classe Empresa
* @brief Carrega os dados dos Gerentes lidos a partir do arquivo gerente.txt
*/

void Empresa::carregarGerente(){
  string linha;
  vector<string>vetor_ger;
  fstream arquivoCarregarGerente;
  try{
      arquivoCarregarGerente.open("gerente.txt", ios::in);
        if (!arquivoCarregarGerente) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }

    cout << "## Carregando dados de Gerente ##" << endl;
      while(getline(arquivoCarregarGerente, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'E' && linha[2] != 'R' ){
          vetor_ger.push_back(linha);
        }
        
      }
      cout << "## Dados de Gerente carregados corretamente ##" << endl;
      arquivoCarregarGerente.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "gerente.txt"<< endl;
    }

    Gerente tGer;

    int i=0;
    tGer.setNome(vetor_ger[i]);
    tGer.setCpf(vetor_ger[i+1]);
    tGer.setQtdFilhos(stoi(vetor_ger[i+2]));
    tGer.setEstadoCivil(vetor_ger[i+3]);
    Endereco tEnd;
    tEnd.cidade = vetor_ger[i+4];
    tEnd.cep = vetor_ger[i+5];
    tEnd.bairro = vetor_ger[i+6];
    tEnd.rua = vetor_ger[i+7];
    tEnd.numero = stoi(vetor_ger[i+8]);
    tGer.setEnderecoPessoal(tEnd);
    Data tnasc;
    tnasc.ano = stoi(vetor_ger[i+9]);
    tnasc.mes = stoi(vetor_ger[i+10]);
    tnasc.dia = stoi(vetor_ger[i+11]);
    tGer.setDataNascimento(tnasc);
    tGer.setMatricula(vetor_ger[i+12]);
    tGer.setSalario(stof(vetor_ger[i+13]));
    tGer.setParticipacaoLucros(stof(vetor_ger[14]));
    tGer.setFaltas(stoi(vetor_ger[15]));
    Data ting;
    ting.ano = stoi(vetor_ger[i+16]);
    ting.mes = stoi(vetor_ger[i+17]);
    ting.dia = stoi(vetor_ger[i+18]);
    tGer.setIngressoEmpresa(ting);
    gerentes.push_back(tGer);

}

/**
* @fn: Função imprimeGerentes na Classe Empresa
* @brief Imprime os dados dos Gerentes no console e no arquivo relatorio_final.txt
*/

void Empresa::imprimeGerentes(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);
  arquivo << "____________________________________________________________" <<endl;
  cout << "____________________________________________________________" <<endl;
  cout << "\n######### Relatório Gerente ########\n" << endl;
  arquivo << "\n######### Relatório Gerente ########\n" << endl;

  float somaSalario = 0;

    for (int i = 0; i < gerentes.size(); i++) {
        arquivo << "Nome: " << gerentes[i].getNome() << endl;
        arquivo << "CPF: " << gerentes[i].getCpf() << endl;
        arquivo << "Qtde de Filhos: " << gerentes[i].getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << gerentes[i].getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << gerentes[i].getEnderecoPessoal().rua << ", " << gerentes[i].getEnderecoPessoal().numero << ", " << gerentes[i].getEnderecoPessoal().bairro << ", " << gerentes[i].getEnderecoPessoal().cidade <<  ", CEP: " << gerentes[i].getEnderecoPessoal().cep << endl;
        arquivo << "DN: " << gerentes[i].getDataNascimento().dia<< "/" << gerentes[i].getDataNascimento().mes << "/" << gerentes[i].getDataNascimento().ano << endl;
        arquivo << "Matrícula: " << gerentes[i].getMatricula() << endl;
        arquivo << "Na empresa desde: " << gerentes[i].getIngressoEmpresa().dia << "/" << gerentes[i].getIngressoEmpresa().mes << "/" << gerentes[i].getIngressoEmpresa().ano << endl;
        arquivo << "Salário Base: " << gerentes[i].getSalario() << endl;
        float salario = gerentes[i].calcularSalario(gerentes[i].getFaltas());
        //salario = salario+gerentes[i].getParticipacaoLucros();
        arquivo << "Participação nos Lucros: " << gerentes[i].getParticipacaoLucros() << endl;
        arquivo << "Salário do Mês: " << salario << endl;
        

    arquivo << endl;

        cout << "Nome: " << gerentes[i].getNome() << endl;
        cout << "CPF: " << gerentes[i].getCpf() << endl;
        cout << "Qtde de Filhos: " << gerentes[i].getQtdFilhos() << endl;
        cout << "Estado Civil: " << gerentes[i].getEstadoCivil() << endl;
        cout << "Endereço: Rua " << gerentes[i].getEnderecoPessoal().rua << ", " << gerentes[i].getEnderecoPessoal().numero << ", " << gerentes[i].getEnderecoPessoal().bairro << ", " << gerentes[i].getEnderecoPessoal().cidade <<  ", CEP: " << gerentes[i].getEnderecoPessoal().cep << endl;
        cout << "DN: " << gerentes[i].getDataNascimento().dia<< "/" << gerentes[i].getDataNascimento().mes << "/" << gerentes[i].getDataNascimento().ano << endl;
        cout << "Matrícula: " << gerentes[i].getMatricula() << endl;
        cout << "Na empresa desde: " << gerentes[i].getIngressoEmpresa().dia << "/" << gerentes[i].getIngressoEmpresa().mes << "/" << gerentes[i].getIngressoEmpresa().ano << endl;
        cout << "Salário Base: " << gerentes[i].getSalario() << endl;
        cout << "Salário do Mês: " << salario << endl;

        arquivo << "*****************************************" <<endl;
        cout << "*****************************************" <<endl;

    cout << endl;
        
    }

  arquivo.close();

}

/**
* @fn: Função carregaDono na Classe Empresa
* @brief Carrega os dados do dono da empresa lidos a partir do arquivo dono.txt
*/

void Empresa::carregaDono(){
  string linha;
  vector<string> vetor_dono;
  fstream arquivoCarregarDono;
  try{
      arquivoCarregarDono.open("dono.txt", ios::in);
        if (!arquivoCarregarDono) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }
      while(getline(arquivoCarregarDono, linha)){
        if (linha[0] != '#' ){
          vetor_dono.push_back(linha);
        }

      }
      cout << "## Dados de Dono carregados corretamente ##" << endl;
      cout << "**************************************\n\n" << endl;
    
      arquivoCarregarDono.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "dono.txt"<< endl;
    }

    getDono()->setNome(vetor_dono[0]);
    getDono()->setCpf(vetor_dono[1]);
    getDono()->setQtdFilhos(stoi(vetor_dono[2]));
    getDono()->setEstadoCivil(vetor_dono[3]);
    Endereco tEnd;
    tEnd.cidade = vetor_dono[4];
    tEnd.cep = vetor_dono[5];
    tEnd.bairro = vetor_dono[6];
    tEnd.rua = vetor_dono[7];
    tEnd.numero = stoi(vetor_dono[8]);
    getDono()->setEnderecoPessoal(tEnd);
    Data tnasc;
    tnasc.ano=stoi(vetor_dono[9]);
    tnasc.mes=stoi(vetor_dono[10]);
    tnasc.dia=stoi(vetor_dono[11]);
    getDono()->setDataNascimento(tnasc);

}

/**
* @fn: Função imprimeDono na Classe Empresa
* @brief Imprime os dados do dono da empresa no console e no arquivo relatorio_final.txt
*/

void Empresa::imprimeDono(){
  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  arquivo << "\n######### Dados do Dono da Empresa ########\n" << endl;

  arquivo << "Nome: "<< getDono()->getNome() << "\nCPF: " <<getDono()->getCpf() << "\nDN: "<< getDono()->getDataNascimento().dia << "/"<< getDono()->getDataNascimento().mes << "/"<<getDono()->getDataNascimento().ano << "\nEstado Civil: "<<getDono()->getEstadoCivil() << "\nFilhos: " << getDono()->getQtdFilhos() << "\nReside em: "<< getDono()->getEnderecoPessoal().cidade << ", na rua " << getDono()->getEnderecoPessoal().rua << ", " << getDono()->getEnderecoPessoal().numero << ", " << getDono()->getEnderecoPessoal().bairro << ", CEP: "<< getDono()->getEnderecoPessoal().cep << ".\n";

  arquivo << "****************************************" << endl;

  arquivo.close();

    cout << "\n######### Dados do Dono da Empresa ########\n" << endl;

cout << "Nome: "<< getDono()->getNome() << "\nCPF: " <<getDono()->getCpf() << "\nDN: "<< getDono()->getDataNascimento().dia << "/"<< getDono()->getDataNascimento().mes << "/"<<getDono()->getDataNascimento().ano << "\nEstado Civil: "<<getDono()->getEstadoCivil() << "\nFilhos: " << getDono()->getQtdFilhos() << "\nReside em: "<< getDono()->getEnderecoPessoal().cidade << ", na rua " << getDono()->getEnderecoPessoal().rua << ", " << getDono()->getEnderecoPessoal().numero << ", " << getDono()->getEnderecoPessoal().bairro << ", CEP: "<< getDono()->getEnderecoPessoal().cep << ".\n";

  cout << "****************************************" << endl;
    
}

/**
* @fn: Função buscaFuncionario na Classe Empresa
* @brief Busca funcionários a partir do número da matrícula
* @param Recebe a matrícula de um funcionário
* @return Retorna os dados de um funcionário
*/

void Empresa::buscaFuncionario(string matricula){
    int encontrado = 0;
  
    fstream arquivo;
    arquivo.open("relatorio_final.txt", ios::out | ios::app);
  
    cout << "\n##########    Buscando funcionário    ##########" <<endl;
    arquivo << "\n##########    Buscando funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            encontrado = 1;
            cout << "Função: ASG" << endl;
            cout << "Nome: " <<asgs[i].getNome() << endl;
            cout << "CPF: " <<asgs[i].getCpf() << endl;
            cout << "Salário base: " <<asgs[i].getSalario() << endl;
            arquivo << "Função: ASG" << endl;
            arquivo << "Nome: " <<asgs[i].getNome() << endl;
            arquivo << "CPF: " <<asgs[i].getCpf() << endl;
            arquivo << "Salário base: " <<asgs[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            encontrado = 1;
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " <<vendedores[i].getNome() << endl;
            cout << "CPF: " <<vendedores[i].getCpf() << endl;
            cout << "Salário base: " <<vendedores[i].getSalario() << endl;
            arquivo << "Função: Vendedor" << endl;
            arquivo << "Nome: " <<vendedores[i].getNome() << endl;
            arquivo << "CPF: " <<vendedores[i].getCpf() << endl;
            arquivo << "Salário base: " <<vendedores[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            encontrado = 1;
            cout << "Função: Gerente" << endl;
            cout << "Nome: " <<gerentes[i].getNome() << endl;
            cout << "CPF: " <<gerentes[i].getCpf() << endl;
            cout << "Salário base: " <<gerentes[i].getSalario() << endl;
            arquivo << "Função: Gerente" << endl;
            arquivo << "Nome: " <<gerentes[i].getNome() << endl;
            arquivo << "CPF: " <<gerentes[i].getCpf() << endl;
            arquivo << "Salário base: " <<gerentes[i].getSalario() << endl;
            return;
        }
    }
  if (encontrado == 0){
    cout  << "Funcionario não localizado no sistema!" << endl;
    arquivo  << "Funcionario não localizado no sistema!" << endl;
  }
  arquivo.close();
}

/**
* @fn: Função calculaSalarioFuncionario na Classe Empresa
* @brief Calcula o salário de funcionários a partir do número da matrícula
* @param Recebe a matrícula de um funcionário
* @return Retorna o salário do funcionário
*/

void Empresa::calculaSalarioFuncionario(string matricula){
    int encontrado = 0;
  
    fstream arquivo;
    arquivo.open("relatorio_final.txt", ios::out | ios::app);
    cout << "\n##########    Calculando salário de funcionário    ##########" <<endl;
  arquivo << "\n##########    Calculando salário de funcionário    ##########" <<endl;
  
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
          encontrado = 1;
            cout << "Função: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "Salario base: " << asgs[i].getSalario() << endl;
            cout << "Salario calculado: " << asgs[i].calcularSalario(asgs[i].getFaltas()) << endl;
            arquivo << "Função: ASG" << endl;
            arquivo << "Nome: " << asgs[i].getNome() << endl;
            arquivo << "Salario base: " << asgs[i].getSalario() << endl;
            arquivo << "Salario calculado: " << asgs[i].calcularSalario(asgs[i].getFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
          encontrado = 1;
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "Salario base: " << vendedores[i].getSalario() << endl;
            cout << "Salario calculado: " << vendedores[i].calcularSalario(vendedores[i].getFaltas()) << endl;
            arquivo << "Função: Vendedor" << endl;
            arquivo << "Nome: " << vendedores[i].getNome() << endl;
            arquivo << "Salario base: " << vendedores[i].getSalario() << endl;
            arquivo << "Salario calculado: " << vendedores[i].calcularSalario(vendedores[i].getFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
          encontrado = 1;
            cout << "Função: Gerente" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "Salario base: " << gerentes[i].getSalario() << endl;
            cout << "Salario calculado: " << gerentes[i].calcularSalario(gerentes[i].getFaltas()) << endl;
            arquivo << "Função: Gerente" << endl;
            arquivo << "Nome: " << gerentes[i].getNome() << endl;
            arquivo << "Salario base: " << gerentes[i].getSalario() << endl;
            arquivo << "Salario calculado: " << gerentes[i].calcularSalario(gerentes[i].getFaltas()) << endl;
            return;
        }
    }
      if (encontrado == 0){
          cout  << "Funcionario não localizado no sistema!" << endl;
          arquivo  << "Funcionario não localizado no sistema!" << endl;
  }
  arquivo.close();
}

/**
* @fn: Função calculaSalarioIndividual na Classe Empresa
* @brief Calcula o salário de funcionários a partir do número da matrícula
* @param Recebe a matrícula de um funcionário
* @return Retorna o salário do funcionário
*/

float Empresa::calculaSalarioIndividual(string matricula){

        for(int i = 0; i<asgs.size() ;i++){
            if(matricula == asgs[i].getMatricula()){
                return asgs[i].calcularSalario(asgs[i].getFaltas());
            }
        }
        for(int i = 0; i<vendedores.size() ;i++){
            if(matricula == vendedores[i].getMatricula()){
                return vendedores[i].calcularSalario(vendedores[i].getFaltas());
            }
        }
        for(int i = 0; i<gerentes.size() ;i++){
            if(matricula == gerentes[i].getMatricula()){
                return gerentes[i].calcularSalario(gerentes[i].getFaltas());
            }
        }
}

/**
* @fn: Função calculaTodoOsSalarios na Classe Empresa
* @brief Calcula a soma dos salários por categoria e imprime no console e no arquivo relatorioFinanceiro.txt
*/

void Empresa::calculaTodoOsSalarios(){

    fstream relatorio;
    relatorio.open("relatorioFinanceiro.txt", ios::out);

    float soma = 0, somaAsg = 0, somaVend = 0, somaGer = 0;
    
    cout << "\n##########    Calculando todos os salários    ##########" <<endl;
    relatorio << "##########    Relatório Financeiro    ##########\n\n" << endl;
    relatorio << "##########    ASGS    ##########" << endl;
    cout << "##########    ASGS    ##########" << endl;
    for(int i = 0; i<asgs.size() ;i++){
        float sal = asgs[i].calcularSalario(asgs[i].getFaltas());
        relatorio << "Nome: " << asgs[i].getNome() << " - R$ " << sal << endl; 
        cout << "Nome: " << asgs[i].getNome() << " - R$ " << sal << endl; 
        somaAsg += sal;
    }
    soma += somaAsg;
    relatorio << "Soma ASGs: " <<somaAsg << endl;
    cout << "Soma ASGs: " <<somaAsg << endl;
  
    relatorio << "\n##########    Vendedores    ##########" << endl;
    for(int i = 0; i<vendedores.size() ;i++){
      float sal = vendedores[i].calcularSalario(vendedores[i].getFaltas());
        relatorio << "Nome: " << vendedores[i].getNome() << " - R$ " << sal << endl;
        cout << "Nome: " << vendedores[i].getNome() << " - R$ " << sal << endl;

        somaVend += sal;
        
    }
    soma += somaVend;
    relatorio << "Soma Vendedores: " << somaVend << endl;
    cout << "Soma Vendedores: " << somaVend << endl;
  
    relatorio << "\n##########    Gerentes    ##########" << endl;
    for(int i = 0; i<gerentes.size() ;i++){
      float sal = gerentes[i].calcularSalario(gerentes[i].getFaltas());
        relatorio << "Nome: " << gerentes[i].getNome() << " - R$ " << sal << endl; 
        cout << "Nome: " << gerentes[i].getNome() << " - R$ " << sal << endl; 
        somaGer += sal;
    }
    soma += somaGer;
    relatorio << "Soma Gerentes: " << fixed << setprecision(2)<< somaGer << endl;
    relatorio << endl;
    cout << "Soma Gerentes: " << fixed << setprecision(2)<< somaGer << endl;
    cout << endl;
    relatorio << "**************************** " << endl;
    relatorio << "CUSTO TOTAL: " << soma << endl;
    relatorio << "**************************** " << endl;
    cout << "**************************** " << endl;
    cout << "CUSTO TOTAL: " << soma << endl;
    cout << "**************************** " << endl;

    relatorio  << "\nFATURAMENTO MENSAL: "<< getFaturamentoMensal() << endl;
    cout  << "\nFATURAMENTO MENSAL: "<< getFaturamentoMensal() << endl;
  
    relatorio << "\nCusto ASG(%): " << fixed << setprecision(2) << (somaAsg/soma)*100 << "%" << endl;
  relatorio << "Custo Vendedores(%): " << fixed << setprecision(2) << (somaVend/soma)*100 << "%" << endl;
  relatorio << "Custo Gerente(%): " << fixed << setprecision(2) << (somaGer/soma)*100 << "%" << endl;

      cout << "\nCusto ASG(%): " << fixed << setprecision(2) << (somaAsg/soma)*100 << "%" << endl;
  cout << "Custo Vendedores(%): " << fixed << setprecision(2) << (somaVend/soma)*100 << "%" << endl;
  cout << "Custo Gerente(%): " << fixed << setprecision(2) << (somaGer/soma)*100 << "%" << endl;

  float balanco = getFaturamentoMensal()- soma;

  if (balanco > 0){
    relatorio << "\nLucro da empresa: R$" << balanco << endl;
    relatorio << "\nSITUAÇÃO: Lucro"<< endl;
    cout << "\nLucro da empresa: R$" << balanco << endl;
    cout << "\nSITUAÇÃO: Lucro"<< endl;
  } else if (balanco < 0){
    relatorio << "\nPrejuízo da empresa: R$" << balanco << endl;
    relatorio << "\nSITUAÇÃO: Prejuízo"<< endl;
    cout << "\nPrejuízo da empresa: R$" << balanco << endl;
    cout << "\nSITUAÇÃO: Prejuízo"<< endl;
  } else {
    relatorio << "Não houve lucro nem prejuízo no mês"<< endl;
    cout << "Não houve lucro nem prejuízo no mês"<< endl;
  }

}

/**
* @fn: Função calcularRecisao na Classe Empresa
* @brief Calcula a recisão
* @param Recebe a matrícula de um funcionário e a data do desligamento do funcionário
* @return Retorna o valor da recisão
*/

float Empresa::calcularRecisao(string matricula, Data desligamento){
    //cout << "\n##########    Calculando a rescisão de funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
           // cout << "Função: ASG" << endl;
           // cout << "Nome: " << asgs[i].getNome() << endl;
           // cout << "Salario base: " << asgs[i].getSalario() << endl;
           // cout << "Rescisão calculada: " << asgs[i].calcularRecisao(desligamento) << endl;
            return asgs[i].calcularRecisao(desligamento);
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
           // cout << "Função: Vendedor" << endl;
           // cout << "Nome: " << vendedores[i].getNome() << endl;
           // cout << "Salario base: " << vendedores[i].getSalario() << endl;
           // cout << "Rescisão calculada: " << vendedores[i].calcularRecisao(desligamento) << endl;
            return vendedores[i].calcularRecisao(desligamento);
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
          //  cout << "Função: Gerente" << endl;
          //  cout << "Nome: " << gerentes[i].getNome() << endl;
          //  cout << "Salario base: " << gerentes[i].getSalario() << endl;
          //  cout << "Rescisão calculada: " << gerentes[i].calcularRecisao(desligamento) << endl;
            return gerentes[i].calcularRecisao(desligamento);
        }
    }
    //cout  << "Funcionario não localizado no sistema!" << endl;
}

/**
* @fn: Função demitirFuncionario na Classe Empresa
* @brief Realiza a demissão de um funcionário. Imprime o relatório demissional no console e no arquivo relatorioDemissional.txt. Chama a função removerFuncionario()
* @param Recebe a matrícula de um funcionário e a data do desligamento do funcionário
*/

void Empresa::demitirFuncionario(string matricula, Data desligamento){
  
    string nome;
    string cargo;
    float recisao;
    int tempo_dia, tempo_mes, tempo_ano;

    //pegar data de hoje
    time_t tempoAtual = std::time(nullptr);
    tm* tempoLocal = std::localtime(&tempoAtual);
    int ano_h = tempoLocal->tm_year + 1900; 
    int mes_h = tempoLocal->tm_mon + 1;
    int dia_h = tempoLocal->tm_mday;

    fstream arquivo;
  arquivo.open("relatorioDemissional.txt", ios::out | ios::app);
  
    cout << "\n##############################\n    Relatorio Demissional    \n##############################" <<endl;
    arquivo << "\n##############################\n    Relatorio Demissional    \n##############################" <<endl;


    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
          cout << "Cargo: ASG" << endl;
          arquivo << "Cargo: ASG" << endl;
          cout << "Nome: "<<asgs[i].getNome() << endl; 
          arquivo << "Nome: "<<asgs[i].getNome() << endl;
          nome = asgs[i].getNome();
          cout << "CPF: "<<asgs[i].getCpf() << endl; 
          arquivo << "CPF: "<<asgs[i].getCpf() << endl; 
          cout << "Matrícula: "<<matricula << endl; 
          arquivo << "Matrícula: "<<matricula << endl;
          cout << "******************************"<< endl;
          arquivo << "******************************"<< endl; 
          recisao = calcularRecisao(matricula, desligamento);
          cout << "Valor de rescisão: R$ "<< recisao<< endl;
          arquivo << "Valor de rescisão: R$ "<< recisao<< endl;
          if (dia_h >= asgs[i].getIngressoEmpresa().dia){
            tempo_dia = dia_h-asgs[i].getIngressoEmpresa().dia;
          } else {
            tempo_dia = dia_h+(30-asgs[i].getIngressoEmpresa().dia);
          }
          if (mes_h >= asgs[i].getIngressoEmpresa().mes){
            tempo_mes = mes_h -asgs[i].getIngressoEmpresa().mes;
          } else {
            tempo_mes = mes_h +(asgs[i].getIngressoEmpresa().mes-12);
          }
          tempo_ano = ano_h - asgs[i].getIngressoEmpresa().ano;
          cout << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          arquivo << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          cargo = "asg";
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
      if(matricula == vendedores[i].getMatricula()){
          cout << "Cargo: Vendedor" << endl;
          arquivo << "Cargo: Vendedor" << endl;
          cout << "Nome: "<<vendedores[i].getNome() << endl; 
          arquivo << "Nome: "<<vendedores[i].getNome() << endl;
          nome = vendedores[i].getNome();
          cout << "CPF: "<<vendedores[i].getCpf() << endl; 
          arquivo << "CPF: "<<vendedores[i].getCpf() << endl; 
          cout << "Matrícula: "<<matricula << endl; 
          arquivo << "Matrícula: "<<matricula << endl;
          cout << "******************************"<< endl;
          arquivo << "******************************"<< endl; 
          recisao = calcularRecisao(matricula, desligamento);
          cout << "Valor de rescisão: R$ "<< recisao<< endl;
          arquivo << "Valor de rescisão: R$ "<< recisao<< endl;
          if (dia_h >= vendedores[i].getIngressoEmpresa().dia){
            tempo_dia = dia_h-vendedores[i].getIngressoEmpresa().dia;
          } else {
            tempo_dia = dia_h+(30-vendedores[i].getIngressoEmpresa().dia);
          }
          if (mes_h >= vendedores[i].getIngressoEmpresa().mes){
            tempo_mes = mes_h -vendedores[i].getIngressoEmpresa().mes;
          } else {
            tempo_mes = mes_h +(vendedores[i].getIngressoEmpresa().mes-12);
          }
          tempo_ano = ano_h - vendedores[i].getIngressoEmpresa().ano;
          cout << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          arquivo << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          cargo = "vendedor";
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
          cout << "Cargo: Gerente" << endl;
          arquivo << "Cargo: Gerente" << endl;
          cout << "Nome: "<<gerentes[i].getNome() << endl; 
          arquivo << "Nome: "<<gerentes[i].getNome() << endl;
          nome = gerentes[i].getNome();
          cout << "CPF: "<<gerentes[i].getCpf() << endl; 
          arquivo << "CPF: "<<gerentes[i].getCpf() << endl; 
          cout << "Matrícula: "<<matricula << endl; 
          arquivo << "Matrícula: "<<matricula << endl;
          cout << "******************************"<< endl;
          arquivo << "******************************"<< endl; 
          recisao = calcularRecisao(matricula, desligamento);
          cout << "Valor de rescisão: R$ "<< recisao<< endl;
          arquivo << "Valor de rescisão: R$ "<< recisao<< endl;
          if (dia_h >= gerentes[i].getIngressoEmpresa().dia){
            tempo_dia = dia_h-gerentes[i].getIngressoEmpresa().dia;
          } else {
            tempo_dia = dia_h+(30-gerentes[i].getIngressoEmpresa().dia);
          }
          if (mes_h >= gerentes[i].getIngressoEmpresa().mes){
            tempo_mes = mes_h -gerentes[i].getIngressoEmpresa().mes;
          } else {
            tempo_mes = mes_h +(gerentes[i].getIngressoEmpresa().mes-12);
          }
          tempo_ano = ano_h - gerentes[i].getIngressoEmpresa().ano;
          cout << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          arquivo << "Tempo de Trabalho: "<<tempo_ano<<" anos, "<<tempo_mes<<" meses e "<<tempo_dia<<" dias"<< endl;
          cargo = "gerente";
        }
    }

  removerFuncionario(nome, cargo);
}

////////////////////////////////////////////////////////////////////////////

/**
* @fn: Função removerFuncionario na Classe Empresa
* @brief Remove o funcionário do arquivo original asg.txt, vendedor.txt ou gerente.txt
* @param Recebe o nome e o cargo de um funcionário gerados na função demitirFuncionario()
*/

void Empresa::removerFuncionario(string nome, string cargo){

  if (cargo == "asg"){
     string linha;
     vector<string>vetor_asg;
     fstream arquivo;
     arquivo.open("asg.txt", ios::in);
     while(getline(arquivo, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'S' && linha[2] != 'G'){
          //cout << linha << endl;
          vetor_asg.push_back(linha);
        }
     }
     arquivo.close();
     arquivo.open("asg.txt", ios::out);
     for (int i = 0; i<vetor_asg.size(); i++) {
            if (vetor_asg[i]  != nome){
              arquivo << vetor_asg[i] << endl;
            } else {
              i = i+18;
            }
     }
     arquivo.close();
       
   } else if (cargo == "vendedor"){
     string linha;
     vector<string>vetor_vend;
     fstream arquivo;
     arquivo.open("vendedor.txt", ios::in);
     while(getline(arquivo, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'E' && linha[2] != 'N'){
          //cout << linha << endl;
          vetor_vend.push_back(linha);
        }
     }
     arquivo.close();
     arquivo.open("vendedor.txt", ios::out);
     for (int i = 0; i<vetor_vend.size(); i++) {
           
            if (vetor_vend[i]  != nome){
              arquivo << vetor_vend[i] << endl;
            } else {
              i = i+18;
            }
     }
     arquivo.close();

   } else if (cargo == "gerente"){
     fstream arquivo;
     arquivo.open("gerente.txt", ios::out);
     arquivo.close();
    

   }
  
}

/**
* @fn: Função contratarFuncionario na Classe Empresa
* @brief Insere um funcionário lido do arquivo novoFuncionario.txt no arquivo original asg.txt, vendedor.txt ou gerente.txt
*/

void Empresa::contratarFuncionario(){

  vector<string>novo;
  fstream arquivo;
  arquivo.open("novoFuncionario.txt", ios::in);
  string linha;
  while(getline(arquivo, linha)){
    novo.push_back(linha);
  }
  arquivo.close();
  fstream arquivo_in;
  if (novo[0] == "ASG"){
      arquivo_in.open("asg.txt", ios::out | ios::app);
      for (int i = 1; i<novo.size(); i++) {
            arquivo_in << novo[i] << endl;
     }
     arquivo_in.close();
  } else if (novo[0] == "Vendedor"){
      arquivo_in.open("vendedor.txt", ios::out | ios::app);
      for (int i = 1; i<novo.size(); i++) {
            arquivo_in << novo[i] << endl;
     }
  }else if (novo[0] == "Gerente"){
      arquivo_in.open("gerente.txt", ios::out | ios::app);
      for (int i = 1; i<novo.size(); i++) {
            arquivo_in << novo[i] << endl;
     }
  }
}


