#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Paciente
{
    //operador global
    friend ostream &operator<<(ostream&, const Paciente &);

    public:
        //Construtor nome, idade, sexo, cpf, telefone
        Paciente(string, unsigned, string, string, string);
        //Destrutor
        ~Paciente();
        //retorna o nome
        string getNome();
        //atualiza nome
        void setNome(string);
        //retorna idade
        unsigned getIdade();
        //atualiza nome
        void setIdade(unsigned);
        //retorna o sexo
        string getSexo();
        //atualiza o sexo
        void setSexo(string);
        //retorna o cpf
        string getCpf();
        //atualiza o cpf
        void setCpf(string);
        //retorna o telefone
        string getTelefone();
        //atualiza o telefone
        void setTelefone(string);
        //operador comparacao menor que
        bool operator<(Paciente&);
        //operador comparacao maior que
        bool operator>(Paciente&);
        //operador comparacao igual
        bool operator==(Paciente&);
        //retorna os dados da classe derivada
        virtual string getDadosDerivada();

    private:
        string nome;
        unsigned idade;
        string sexo;
        string cpf;
        string telefone;
        string toLowerString(string);
};

#endif