#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "paciente.h"

using namespace std;

template <class T>
class Arvore
{
    public:
        //Construtor
        Arvore (T *raiz = NULL, Arvore *arvoreDireita = NULL, Arvore *arvoreEsquerda = NULL)
        {
            no = raiz;
            direita = arvoreDireita;
            esquerda = arvoreEsquerda;
        };
        //Destrutor
        ~Arvore ()
        {
            delete no;
            delete direita;
            delete esquerda;
        }
        //operador golbal
        template <class O>
        friend ostream &operator<<(ostream&, Arvore<O> &);
        //operador de insercao
        Arvore *operator+=(T *);
        //operador de busca
        Arvore *operator()(string);
        //metodo para retornar o No
        T *getNo();
        //metodo para retornar a sub-arvore a direita
        Arvore *getDireita() {return esquerda;};
        //metodo para retornar a sub-arvore a esquerda
        Arvore *getEsquerda() {return direita;};

    private:
        Arvore *esquerda;
        Arvore *direita;
        T *no;
};

template <class T>
T *Arvore<T>::getNo()
{
    return no;
}

template <class T>
Arvore<T> *Arvore<T>::operator+=(T *noAdicionado)
{
    Arvore *ponteiro = NULL;
    if (no == NULL)
    {
        no = noAdicionado;
        ponteiro = this;
    }
    else
    {
        if (no->getNome() == noAdicionado->getNome())
        {
            ponteiro = NULL;
            return NULL;
        }
        else if (no->getNome() < noAdicionado->getNome())
        {
            if (esquerda == NULL)
            {
                esquerda = new Arvore<T>(noAdicionado);
                ponteiro = esquerda;
            }
            else
            {
                ponteiro = ((*esquerda) += noAdicionado);
            }
        }
        else
        {
            if (direita == NULL)
            {
                direita = new Arvore<T>(noAdicionado);
                ponteiro = direita;
            }
            else
            {
                ponteiro = ((*direita) += noAdicionado);
            }
        }
    }
    return ponteiro;
}

template <class T>
Arvore<T> *Arvore<T>::operator()(string nome)
{
    if (nome == no->getNome())
    {
        return this;
    }
    else if (nome < no->getNome())
    {
        if (direita == NULL)
        {
            return NULL;
        }
        else
        {
            return (*direita)(nome);
        }
    }
    else
    {
        if (esquerda == NULL)
        {
            return NULL;
        }
        else
        {
            return (*esquerda)(nome);
        }
    }
}

template <class O>
ostream &operator<<(ostream &output, Arvore<O> &arvore)
{
    if (arvore.esquerda != NULL)
    {
        output << (*arvore.esquerda);
    }
    Paciente *ponteiro = arvore.no;
    output << *ponteiro;
    if (arvore.direita != NULL)
    {
        output << (*arvore.direita);
    }
    return output;
}

#endif