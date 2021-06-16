#ifndef PACIENTEMAIOR_H
#define PACIENTEMAIOR_H

#include <iostream>
#include <string>

#include "paciente.h"

class PacienteMaior : public Paciente
{
    public:
        //Construtor nome, idade, sexo, cpf, telefone, profissao
        PacienteMaior(string, unsigned, string, string, string, string);
        //destrutor
        ~PacienteMaior();
        //retorna nome responsavel
        string getProfissao();
        //atualiza nome responsavel
        void setProfissao(string);
        //dados da classe para ser usada na base
        virtual string getDadosDerivada() const;

    private:
        string profissao;
};

#endif