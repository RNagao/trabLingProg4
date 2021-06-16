#include <iostream>
#include <string>

#include "paciente.h"
#include "pacienteMenor.h"

using namespace std;

PacienteMenor::PacienteMenor(string nomePaciente, unsigned idadePaciente, string sexoPaciente, string cpfPaciente, string telefonePaciente, string nomeResponsavelPaciente, string telefoneResponsavelPaciente):
    Paciente(nomePaciente, idadePaciente, sexoPaciente, cpfPaciente, telefonePaciente){
        nomeResponsavel = nomeResponsavelPaciente;
        telefoneResponsavel = telefoneResponsavelPaciente;
}

PacienteMenor::~PacienteMenor()
{
    cout << "Destrutor PacienteMenor" << endl;
}

string PacienteMenor::getNomeResponsavel()
{
    return nomeResponsavel;
}

void PacienteMenor::setNomeResponsavel(string nomeAtualizado)
{
    nomeResponsavel = nomeAtualizado;
}

string PacienteMenor::getTelefoneResponsavel()
{
    return telefoneResponsavel;
}

void PacienteMenor::setTelefoneResponsavel(string telefoneAtualizado)
{
    telefoneResponsavel = telefoneResponsavel;
}

string PacienteMenor::getDadosDerivada() const
{
    string dados;
    dados = "Nome do Responsavel: " + nomeResponsavel + "\nTelefone do Responsavel: " + telefoneResponsavel;
    return dados;
}