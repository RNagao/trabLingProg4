#include <string>
#include <iostream>

#include "paciente.h"

using namespace std;

ostream &operator<<(ostream &output, const Paciente & paciente)
{
    output << "Nome: " << paciente.nome << endl
            << "Idade: " << paciente.idade << endl
            << "Sexo: " << paciente.sexo << endl
            << "CPF: " << paciente.cpf <<endl
            << "Telefone: " << paciente.telefone << endl
            << paciente.getDadosDerivada() << endl << endl;
    return output;
}

Paciente::Paciente (string nomePaciente, unsigned idadePaciente, string sexoPaciente, string cpfPaciente, string telefonePaciente)
{
    nome = nomePaciente;
    idade = idadePaciente;
    sexo = sexoPaciente;
    cpf = cpfPaciente;
    telefone = telefonePaciente;
}

Paciente::~Paciente()
{
    cout << "Destrutor Paciente" << endl;
}

string Paciente::getNome()
{
    return nome;
}

void Paciente::setNome(string nomeAtualizado)
{
    nome = nomeAtualizado;
}

unsigned Paciente::getIdade()
{
    return idade;
}

void Paciente::setIdade(unsigned idadeAtualizada)
{
    idade = idadeAtualizada;
}

string Paciente::getSexo()
{
    return sexo;
}

void Paciente::setSexo(string sexoAtualizado)
{
    sexo = sexoAtualizado;
}

string Paciente::getCpf()
{
    return cpf;
}

void Paciente::setCpf(string cpfAtualizado)
{
    cpf = cpfAtualizado;
}

string Paciente::getTelefone()
{
    return telefone;
}

void Paciente::setTelefone(string telefoneAtualizado)
{
    telefone = telefoneAtualizado;
}

string Paciente::toLowerString(string dado)
{
    string dadoLower;
    unsigned indice;

    for (indice = 0; indice < dadoLower.length(); indice++)
    {
        dadoLower += tolower(dado[indice]);
    }

    return dadoLower;
}

bool Paciente::operator<(Paciente & pacienteComparado)
{
    if (toLowerString(nome) < toLowerString(pacienteComparado.getNome()))
    {
        return true;
    }

    return false;
}

bool Paciente::operator>(Paciente & pacienteComparado)
{
    if (toLowerString(nome) > toLowerString(pacienteComparado.getNome()))
    {
        return true;
    }

    return false;
}

bool Paciente::operator==(Paciente & pacienteComparado)
{
    if (toLowerString(nome) == toLowerString(pacienteComparado.getNome()))
    {
        return true;
    }

    return false;
}