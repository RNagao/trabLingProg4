#include <iostream>
#include <string>
#include <exception>

#include "cadastro.h"
#include "arvore.h"

using namespace std;

Cadastro::Cadastro (Arvore<Paciente> *raiz)
{
    arvore = raiz;
}

void Cadastro::adicionaPaciente(Paciente *paciente) noexcept(false)
{
    Arvore<Paciente> *ponteiro = ((*arvore) += paciente);
    if (ponteiro == NULL)
    {
        throw PacienteJaCadastrado();
    }
    else
    {
        cout << "Paciente cadastrado com sucesso" << endl;
    }
}

void Cadastro::buscaPaciente() noexcept(false)
{
    if (arvore->getNo() == NULL)
    {
        cout << "Nenhum paciente cadastrado" << endl;
        return ;
    }

    string nomePaciente;
    cout << "Digite o nome do paciente: " << endl;
    cin >> nomePaciente;

    Arvore<Paciente> *ponteiro = ((*arvore)(nomePaciente));
    if (ponteiro == NULL)
    {
        throw PacienteNaoExiste();
    }
    else
    {
        cout << (*ponteiro->getNo()) << endl;
    }
}

void Cadastro::imprimePacientes()
{
    if (arvore->getNo() == NULL)
    {
        cout << "Nenhum paciente cadastrado" << endl;
        return ;
    }
    cout << (*arvore);
}