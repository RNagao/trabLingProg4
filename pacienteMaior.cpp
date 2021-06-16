#include <iostream>
#include <string>

#include "paciente.h"
#include "pacienteMaior.h"

using namespace std;

PacienteMaior::PacienteMaior(string nomePaciente, unsigned idadePaciente, string sexoPaciente, string cpfPaciente, string telefonePaciente, string profissaoPaciente):
    Paciente(nomePaciente, idadePaciente, sexoPaciente, cpfPaciente, telefonePaciente){
        profissao = profissaoPaciente;
}

PacienteMaior::~PacienteMaior()
{
    cout << "Destrutor PacienteMaior" << endl;
}

string PacienteMaior::getProfissao()
{
    return profissao;
}

void PacienteMaior::setProfissao(string profissaoAtualizada)
{
    profissao = profissaoAtualizada;
}

string PacienteMaior::getDadosDerivada() const
{
    string dados;
    dados = "Profissao: " + profissao;
    return dados;
}