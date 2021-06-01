#include <iostream>
#include <string>
#include <exception>

#include "arvore.h"
#include "cadastro.h"
#include "paciente.h"
#include "pacienteMenor.h"
#include "pacienteMaior.h"

using namespace std;

#define SUCESSO         0

unsigned menu()
{
    unsigned opcao;
    cout << "Menu" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Imprimir todos os pacientes no cadastro" << endl;
    cout << "2 - Buscar por paciente" << endl;
    cout << "3 - Adicionar paciente genérico" << endl;
    cout << "Digite o numero da funcionalidade desejada" << endl;
    cin >> opcao;
    return opcao;
}

int main()
{
    unsigned opcao;

    Arvore <Paciente> *arvorePacientes = new Arvore<Paciente>();
    Cadastro cadastro(arvorePacientes);

    opcao = menu();
    while (opcao != 0)
    {
        switch (opcao)
        {
            case 1:
            {
                cout << "\nTODOS OS PACIENTES" << endl;
                cadastro.imprimePacientes();
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "\nBUSCA POR PACIENTE" << endl;
                cadastro.buscaPaciente();
                cout << endl;
                break;
            }
            case 3:
            {
                string nome, idade, sexo, cpf, telefone, opcaoMenor, nomeResponsavel, telefoneResponsavel, profissao;
                Paciente *ponteiro = NULL;
                cout << "\nADICIONAR PACIENTE" << endl;
                cout << "Digite o nome do paciente: " << endl;
                cin >> nome;
                cout << "Digite o idade do paciente: " << endl;
                cin >> idade;
                cout << "Digite o sexo do paciente: " << endl;
                cin >> sexo;
                cout << "Digite o cpf do paciente: " << endl;
                cin >> cpf;
                cout << "Digite o telefone do paciente: " << endl;
                cin >> telefone;
                cout << "O paciente e menor de idade?" << endl;
                cout << "Se sim digite 1" << endl;
                cin >> opcaoMenor;
                if (opcaoMenor == "1")
                {
                    cout << "Digite o nome do responsavel: " << endl;
                    cin >> nomeResponsavel;
                    cout << "Digite o telefone do responsavel: " << endl;
                    cin >> telefoneResponsavel;
                    ponteiro = new PacienteMenor(nome, stoi(idade), sexo, cpf, telefone, nomeResponsavel, telefoneResponsavel);
                }
                else
                {
                    cout << "Digite a ocupacao do paciente: " << endl;
                    cin >> profissao;
                    ponteiro = new PacienteMaior(nome, stoi(idade), sexo, cpf, telefone, profissao);
                }
                try
                {
                    cadastro.adicionaPaciente(ponteiro);
                }
                catch (exception &erro)
                {
                    cout << erro.what() <<endl;
                }
                cout << endl;
                break;
            }
            default:
            {
                cout << "Opcao invalida" << endl;
                cout << endl;
            }
        }

        opcao = menu();
    }

    return SUCESSO;
}