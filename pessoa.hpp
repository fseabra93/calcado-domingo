#ifndef PESSOA_HPP
#define PESSOA_HPP
#include "util.hpp"

using namespace std;

class Pessoa{
    protected:
    string nome;
    string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    string estadoCivil;
    int qtdFilhos = 0;

    public:
    Pessoa();
    Pessoa(string nome, string cpf, int ano_nasc, int mes_nasc, int dia_nasc, string cidade, string bairro, string rua, string cep, int numero, string estadoCivil, int qtdFilhos);
    
    string getNome();
    void setNome(string nome);
    string getCpf();
    void setCpf(string cpf);
    Data getDataNascimento();
    void setDataNascimento(int ano_nasc, int mes_nasc, int dia_nasc);
    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(string cidade, string bairro, string rua, string cep, int numero);
    string getEstadoCivil();
    void setEstadoCivil(string estadoCivil);
    int getQtdFilhos();
    void setQtdFilhos(int qtdFilhos);

};

#endif