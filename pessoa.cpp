#include <iostream>
#include "pessoa.hpp"

using namespace std;

Pessoa :: Pessoa(){}

Pessoa :: Pessoa(string nome, string cpf, int ano_nasc, int mes_nasc, int dia_nasc, string cidade, string bairro, string rua, string cep, int numero, string estadoCivil, int qtdFilhos ){
  this->nome = nome;
  this->cpf=cpf;
  dataNascimento.ano = ano_nasc;
  dataNascimento.mes = mes_nasc;
  dataNascimento.dia = dia_nasc;
  enderecoPessoal.cidade = cidade;
  enderecoPessoal.bairro = bairro;
  enderecoPessoal.rua = rua;
  enderecoPessoal.cep = cep;
  enderecoPessoal.numero = numero;
  this->estadoCivil = estadoCivil;
  this->qtdFilhos=qtdFilhos;
  
}

string Pessoa :: getNome(){
  return this->nome;
}

void Pessoa :: setNome(string nome){
  this->nome = nome;
}

std::string Pessoa :: getCpf(){
  return this->cpf;
}

void Pessoa :: setCpf(string cpf){
  this->cpf = cpf;
}

Data Pessoa:: getDataNascimento(){
  return this-> dataNascimento;
}

void Pessoa:: setDataNascimento(int ano_nasc, int mes_nasc, int dia_nasc){
  dataNascimento.ano = ano_nasc;
  dataNascimento.mes = mes_nasc;
  dataNascimento.dia = dia_nasc;
}

Endereco Pessoa:: getEnderecoPessoal(){
  return this-> enderecoPessoal;
}

void Pessoa:: setEnderecoPessoal(string cidade, string bairro, string rua, string cep, int numero){
  enderecoPessoal.cidade = cidade;
  enderecoPessoal.bairro = bairro;
  enderecoPessoal.rua = rua;
  enderecoPessoal.cep = cep;
  enderecoPessoal.numero = numero;
}

string Pessoa :: getEstadoCivil(){
  return this->estadoCivil;
}

void Pessoa :: setEstadoCivil(string estadoCivil){
  this->estadoCivil = estadoCivil;
}

int Pessoa :: getQtdFilhos(){
  return this->qtdFilhos;
}

void Pessoa :: setQtdFilhos(int qtdFilhos){
  this->qtdFilhos = qtdFilhos;
}




