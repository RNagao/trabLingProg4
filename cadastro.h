#ifndef CADASTRO_H
#define CADASTRO_H

#include <exception>

#include "paciente.h"
#include "arvore.h"

using namespace std;


class PacienteJaCadastrado : public exception
{
    virtual const char* what() const throw()
    {
        return "Paciente ja cadastrado";
    }
};

class PacienteNaoExiste : public exception
{
    virtual const char* what() const throw()
    {
        return "Paciente nao consta na base de dados";
    }
};

class Cadastro
{
    public:
        //Construtor
        Cadastro(Arvore<Paciente> *);
        //adicionar paciente ao cadastro
        void adicionaPaciente(Paciente*) noexcept(false);
        //busca por paciente
        void buscaPaciente() noexcept(false);
        //imprime todos os pacientes
        void imprimePacientes();
    private:
        Arvore <Paciente> *arvore;
};

#endif