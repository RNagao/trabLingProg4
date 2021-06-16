#ifndef PACIENTEMENOR_H
#define PACIENTEMENOR_H

#include <iostream>
#include <string>

#include "paciente.h"

class PacienteMenor : public Paciente
{
    public:
        //Construtor nome, idade, sexo, cpf, telefone, nome do responsavel, telefone responsavel
        PacienteMenor(string, unsigned, string, string, string, string, string);
        //destrutor
        ~PacienteMenor();
        //retorna nome responsavel
        string getNomeResponsavel();
        //atualiza nome responsavel
        void setNomeResponsavel(string);
        //retorna telefone responsavel
        string getTelefoneResponsavel();
        //atualiza telefone responsavel
        void setTelefoneResponsavel(string);
        //dados da classe para ser usada na base
        virtual string getDadosDerivada() const;

    private:
        string nomeResponsavel;
        string telefoneResponsavel;
};

#endif