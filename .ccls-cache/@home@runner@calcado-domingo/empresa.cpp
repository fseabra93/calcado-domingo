#include <iostream>
#include <fstream>
#include "empresa.hpp"

using namespace std;

  Empresa::Empresa(){}
  Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, string nome_dono, vector<Asg>asgs, vector<Vendedor>vendedores, vector<Gerente>gerentes, int h_ano, int h_mes, int h_dia){
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj=cnpj;
    this->faturamentoMensal=faturamentoMensal;
    dono.setNome(nome_dono);
    this->asgs=asgs;
    this->vendedores=vendedores;
    this->gerentes=gerentes;
    hoje.ano=h_ano;
    hoje.mes=h_mes;
    hoje.dia=h_dia;


  }


  Data Empresa::getHoje(){
    return this->hoje;
  }
  void Empresa::setHoje(int h_ano, int h_mes, int h_dia){
    hoje.ano=h_ano;
    hoje.mes=h_mes;
    hoje.dia=h_dia;
  }

  float Empresa::getFaturamento(){
    return this->faturamentoMensal;
  }
  void Empresa::setFaturamento(float faturamentoMensal){
    this->faturamentoMensal=faturamentoMensal;
  }

  string Empresa::getNomeEmpresa(){
    return this->nomeEmpresa;
  }
  void Empresa::setNomeEmpresa(std::string nomeEmpresa){
    this->nomeEmpresa=nomeEmpresa;
  }

  std::string Empresa::getCnpj(){
    return this->cnpj;
  }
  void Empresa::setCnpj(std::string cnpj){
    this->cnpj=cnpj;
  }

  Pessoa Empresa::getDono(){
    return this->dono;
  }
  void Empresa::setDono(string nome_dono, string cpf_dono, int n_filhos_dono, string est_civ_dono, string cidade_dono, string cep_dono, string bairro_dono, string rua_dono, int n_casa_dono, int ano_nasc_dono, int mes_nsac_dono, int dia_nasc_dono){
    dono.setNome(nome_dono);
    dono.setCpf(cpf_dono);
    dono.setQtdFilhos(n_filhos_dono);
    dono.setEstadoCivil(est_civ_dono);
    dono.setEnderecoPessoal(cidade_dono, cep_dono, bairro_dono, rua_dono, n_casa_dono);
    dono.setDataNascimento(ano_nasc_dono, mes_nsac_dono, dia_nasc_dono);
  }

  vector<Asg> Empresa::getAsgs(){
    return asgs;
  }

  void Empresa::setAsgs(vector<Asg>asgs){
    this->asgs=asgs;
  }

  vector<Vendedor> Empresa::getVendedores(){
    return vendedores;
  }

  void Empresa::setVendedores(vector<Vendedor>vendedores){
    this->vendedores=vendedores;
  }

  vector<Gerente> Empresa::getGerentes(){
    return gerentes;
  }

  void Empresa::setGerentes(vector<Gerente>gerentes){
    this->gerentes=gerentes;
  }
  

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
        if (linha.length() > 9)
        vetor_func.push_back(linha);
      }
      arquivoCarregarFunc.close(); //fecha o arquivo lido.
     
        } catch (exception &e){
      cout << "erro: " << e.what() << "funcoes.txt"<< endl;
    }

        for (auto elemento : vetor_func) {
            if (elemento  == "carregarEmpresa()"){
              carregarEmpresa();
            }
            if (elemento  == "carregarAsg()"){
              carregarAsg();
            }
            if (elemento  == "carregarVendedor()"){
              carregarVendedor();
            }          
            if (elemento  == "carregarGerente()"){
              carregarGerente();
            }
            if (elemento  == "carregaDono()"){
              carregaDono();
            }
            if (elemento  == "imprimeAsgs()"){
              imprimeAsgs();
            }
            if (elemento  == "imprimeVendedores()"){
              imprimeVendedores();
            }
            if (elemento  == "imprimeGerentes()"){
              imprimeGerentes();
            }          
        }    

}


void Empresa::carregarEmpresa(){
  
  string linha;
  vector<string> vetor_empresa;
  fstream arquivoCarregarEmpresa;

  try{
    
    arquivoCarregarEmpresa.open("empresa.txt", ios::in);
    if (!arquivoCarregarEmpresa) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }

    while(getline(arquivoCarregarEmpresa, linha)){
      if (linha[0] != '#'){
          vetor_empresa.push_back(linha);
      }
    }
    cout << "Dados de Empresa carregados corretamente" << endl;
    arquivoCarregarEmpresa.close(); //fecha o arquivo lido.
    } catch (exception &e){
      cout << "erro: " << e.what() << "empresa.txt"<< endl;
    }


   setNomeEmpresa(vetor_empresa[0]);
   setCnpj(vetor_empresa[1]);
   setFaturamento(stof(vetor_empresa[2]));

}


void Empresa::carregarAsg(){
  string linha;
  vector<string>vetor_asg;
  fstream arquivoCarregarAsg;
  try{
      arquivoCarregarAsg.open("asg.txt", ios::in);
        if (!arquivoCarregarAsg) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }
      while(getline(arquivoCarregarAsg, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'S' && linha[2] != 'G'){
          vetor_asg.push_back(linha);
        }
        
      }
      cout << "Dados de ASGs carregados corretamente" << endl;
      arquivoCarregarAsg.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "asg.txt"<< endl;
    }

    vector<Asg>temp;

    for (int i=0; i<vetor_asg.size(); i+=18) {
      string nome = vetor_asg[i];
      string cpf = vetor_asg[i+1];
      int filhos =  stoi(vetor_asg[i+2]);
      string est_civil = vetor_asg[i+3];
      string cidade = vetor_asg[i+4];
      string cep = vetor_asg[i+5];
      string bairro = vetor_asg[i+6];
      string rua = vetor_asg[i+7];
      int numero = stoi(vetor_asg[i+8]);
      int anonasc = stoi(vetor_asg[i+9]);
      int mesnasc = stoi(vetor_asg[i+10]);
      int dianasc = stoi(vetor_asg[i+11]);
      string matricula = vetor_asg[i+12];
      float salario = stof(vetor_asg[i+13]);
      float adicional = stof(vetor_asg[i+14]);
      int anoingr = stoi(vetor_asg[i+15]);
      int mesingr = stoi(vetor_asg[i+16]);
      int diaingr = stoi(vetor_asg[i+17]);

      Pessoa pessoa (nome, cpf, anonasc, mesnasc, dianasc, cidade, bairro, cep, rua, numero, est_civil, filhos);
      Asg asg(pessoa, matricula, salario, adicional, anoingr, mesingr, diaingr);

      temp.push_back(asg); 
    }
    
    setAsgs(temp);
}

void Empresa::imprimeAsgs(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  arquivo << "\n######### Relatório Financeiro ########\nCargo: ASG\n" << endl;

  float somaSalario = 0;

    for (int i = 0; i < asgs.size(); i++) {
        arquivo << "Nome: " << asgs[i].getPessoa().getNome() << endl;
        arquivo << "CPF: " << asgs[i].getPessoa().getCpf() << endl;
        arquivo << "Qtde de Filhos: " << asgs[i].getPessoa().getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << asgs[i].getPessoa().getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << asgs[i].getPessoa().getEnderecoPessoal().cep << ", " << asgs[i].getPessoa().getEnderecoPessoal().numero << ", " << asgs[i].getPessoa().getEnderecoPessoal().bairro << ", " << asgs[i].getPessoa().getEnderecoPessoal().cidade <<  ", CEP: " << asgs[i].getPessoa().getEnderecoPessoal().rua << endl;
        arquivo << "DN: " << asgs[i].getPessoa().getDataNascimento().dia<< "/" << asgs[i].getPessoa().getDataNascimento().mes << "/" << asgs[i].getPessoa().getDataNascimento().ano << endl;

    arquivo << endl;
        
    }

  arquivo.close();
}


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
      while(getline(arquivoCarregarVendedor, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'E' && linha[2] != 'N'){
          vetor_vend.push_back(linha);
        }
        
      }
      cout << "Dados de Vendedores carregados corretamente" << endl;
      arquivoCarregarVendedor.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "vendedor.txt"<< endl;
    }

    vector<Vendedor>temp;

    for (int i=0; i<vetor_vend.size(); i+=18) {
        string nome = vetor_vend[i];
        string cpf = vetor_vend[i+1];
        int filhos =  stoi(vetor_vend[i+2]);
        string est_civil = vetor_vend[i+3];
        string cidade = vetor_vend[i+4];
        string cep = vetor_vend[i+5];
        string bairro = vetor_vend[i+6];
        string rua = vetor_vend[i+7];
        int numero = stoi(vetor_vend[i+8]);
        int anonasc = stoi(vetor_vend[i+9]);
        int mesnasc = stoi(vetor_vend[i+10]);
        int dianasc = stoi(vetor_vend[i+11]);
        string matricula = vetor_vend[i+12];
        float salario = stof(vetor_vend[i+13]);
        char tipo = vetor_vend[i+14][0];
        int anoingr = stoi(vetor_vend[i+15]);
        int mesingr = stoi(vetor_vend[i+16]);
        int diaingr = stoi(vetor_vend[i+17]);

        Pessoa pessoa (nome, cpf, anonasc, mesnasc, dianasc, cidade, bairro, cep, rua, numero, est_civil, filhos);
        Vendedor vendedor(pessoa, matricula, salario, tipo, anoingr, mesingr, diaingr);

        temp.push_back(vendedor);
      
    }
    setVendedores(temp);
    
}

void Empresa::imprimeVendedores(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  arquivo << "\n######### Relatório Financeiro ########\nCargo: Vendedor\n" << endl;

  float somaSalario = 0;

    for (int i = 0; i < vendedores.size(); i++) {
        arquivo << "Nome: " << vendedores[i].getPessoa().getNome() << endl;
        arquivo << "CPF: " << vendedores[i].getPessoa().getCpf() << endl;
        arquivo << "Qtde de Filhos: " << vendedores[i].getPessoa().getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << vendedores[i].getPessoa().getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << vendedores[i].getPessoa().getEnderecoPessoal().cep << ", " << vendedores[i].getPessoa().getEnderecoPessoal().numero << ", " << vendedores[i].getPessoa().getEnderecoPessoal().bairro << ", " << vendedores[i].getPessoa().getEnderecoPessoal().cidade <<  ", CEP: " << vendedores[i].getPessoa().getEnderecoPessoal().rua << endl;
        arquivo << "DN: " << vendedores[i].getPessoa().getDataNascimento().dia<< "/" << vendedores[i].getPessoa().getDataNascimento().mes << "/" << vendedores[i].getPessoa().getDataNascimento().ano << endl;
//arquivo << "Matrícula: " << vendedores[i].getPessoa().getMatricula() << endl;
        //arquivo << "Na empresa desde: " << vendedores[i].getIngressoEmpresa().dia << "/" << vendedores[i].getIngressoEmpresa().mes << "/" << vendedores[i].getIngressoEmpresa().ano << endl;
        //arquivo << "Salario:" << vendedores[i].calcularSalario() << endl;

    arquivo << endl;
        
    }
    //arquivo << "Total ASG: " << somaSalario << endl << endl;
    //somaRH[0] = somaSalario;

  arquivo.close();
}

void Empresa::carregarGerente(){
  string linha;
  vector<string>vetor_ger;
  fstream arquivoCarregarGerente;
  try{
      arquivoCarregarGerente.open("gerente.txt", ios::in);
        if (!arquivoCarregarGerente) {
      throw std::runtime_error("Falha ao abrir o arquivo ");
    }
      while(getline(arquivoCarregarGerente, linha)){
        if (linha[0] != '#' && linha[0] != '*' && linha[1] != 'E' && linha[2] != 'R' ){
          vetor_ger.push_back(linha);
        }
        
      }
      cout << "Dados de Gerente carregados corretamente" << endl;
      arquivoCarregarGerente.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "gerente.txt"<< endl;
    }

    vector<Gerente>temp;

    int i=0;
    string nome = vetor_ger[i];
    string cpf = vetor_ger[i+1];
    int filhos =  stoi(vetor_ger[i+2]);
    string est_civil = vetor_ger[i+3];
    string cidade = vetor_ger[i+4];
    string cep = vetor_ger[i+5];
    string bairro = vetor_ger[i+6];
    string rua = vetor_ger[i+7];
    int numero = stoi(vetor_ger[i+8]);
    int anonasc = stoi(vetor_ger[i+9]);
    int mesnasc = stoi(vetor_ger[i+10]);
    int dianasc = stoi(vetor_ger[i+11]);
    string matricula = vetor_ger[i+12];
    float salario = stof(vetor_ger[i+13]);
    float part_lucro = stof(vetor_ger[14]);
    int anoingr = stoi(vetor_ger[i+15]);
    int mesingr = stoi(vetor_ger[i+16]);
    int diaingr = stoi(vetor_ger[i+17]);

    Pessoa pessoa (nome, cpf, anonasc, mesnasc, dianasc, cidade, bairro, cep, rua, numero, est_civil, filhos);
    Gerente gerente(pessoa, part_lucro, salario, matricula, anoingr, mesingr, diaingr);

    temp.push_back(gerente);

  setGerentes(temp);

}

void Empresa::imprimeGerentes(){

  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  arquivo << "\n######### Relatório Financeiro ########\nCargo: Gerente\n" << endl;

  float somaSalario = 0;

    for (int i = 0; i < gerentes.size(); i++) {
        arquivo << "Nome: " << gerentes[i].getPessoa().getNome() << endl;
        arquivo << "CPF: " << gerentes[i].getPessoa().getCpf() << endl;
        arquivo << "Qtde de Filhos: " << gerentes[i].getPessoa().getQtdFilhos() << endl;
        arquivo << "Estado Civil: " << gerentes[i].getPessoa().getEstadoCivil() << endl;
        arquivo << "Endereço: Rua " << gerentes[i].getPessoa().getEnderecoPessoal().cep << ", " << gerentes[i].getPessoa().getEnderecoPessoal().numero << ", " << gerentes[i].getPessoa().getEnderecoPessoal().bairro << ", " << gerentes[i].getPessoa().getEnderecoPessoal().cidade <<  ", CEP: " << gerentes[i].getPessoa().getEnderecoPessoal().rua << endl;
        arquivo << "DN: " << gerentes[i].getPessoa().getDataNascimento().dia<< "/" << gerentes[i].getPessoa().getDataNascimento().mes << "/" << gerentes[i].getPessoa().getDataNascimento().ano << endl;
//arquivo << "Matrícula: " << gerentes[i].getPessoa().getMatricula() << endl;
        //arquivo << "Na empresa desde: " << gerentes[i].getIngressoEmpresa().dia << "/" << gerentes[i].getIngressoEmpresa().mes << "/" << gerentes[i].getIngressoEmpresa().ano << endl;
        //arquivo << "Salario:" << gerentes[i].calcularSalario() << endl;

    cout << endl;
        
    }
    //arquivo << "Total Gerentes: " << somaSalario << endl << endl;
    //somaRH[0] = somaSalario;

  arquivo.close();
}


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
      cout << "Dados de Dono carregados corretamente" << endl;
      arquivoCarregarDono.close(); //fecha o arquivo lido.
    
  } catch (exception &e){
      cout << "erro: " << e.what() << "dono.txt"<< endl;
    }

    Pessoa dono;
    dono.setNome(vetor_dono[0]);
    dono.setCpf(vetor_dono[1]);
    dono.setQtdFilhos(stoi(vetor_dono[2]));
    dono.setEstadoCivil(vetor_dono[3]);
    dono.setEnderecoPessoal(vetor_dono[4], vetor_dono[5], vetor_dono[6], vetor_dono[7], stoi(vetor_dono[8]));
    dono.setDataNascimento(stoi(vetor_dono[9]), stoi(vetor_dono[10]), stoi(vetor_dono[11]));

  imprimeDono(dono);

}

void Empresa::imprimeDono(Pessoa p){
  fstream arquivo;
  arquivo.open("relatorio_final.txt", ios::out | ios::app);

  arquivo << "######### Dados do Dono da Empresa ########\n\n" << endl;

    arquivo << p.getNome() << ", CPF: " <<p.getCpf() << ", nasceu no dia "<< p.getDataNascimento().dia << "/"<< p.getDataNascimento().mes << "/"<<p.getDataNascimento().ano << ", é "<<p.getEstadoCivil() << ", tem " << p.getQtdFilhos() << " filhos e reside em "<< p.getEnderecoPessoal().cidade << ", na rua " << p.getEnderecoPessoal().cep << ", " << p.getEnderecoPessoal().numero << ", " << p.getEnderecoPessoal().rua << ", CEP: "<< p.getEnderecoPessoal().bairro << ".\n";

  arquivo.close();
    
}

