//
// Created by isabe on 16/12/2019.

//

#ifndef COURSEWORK03_EXTRATO_H
#define COURSEWORK03_EXTRATO_H
#include <list>
#include "Lancamento.h"

class Extrato {
public:


protected:
    //struct que armazena dados sobre as operações feitas nas contas
    int quantidade;
    list <Lancamento*>  lista_lancamentos;

public:
    int getQuantidade() const;

    void setQuantidade(int quantidade);

    list<Lancamento*>getListaLancamentos();

    void setListaLancamentos( list<Lancamento*> listaLancamentos);
};

ostream &operator<<(ostream &out, Extrato &g);


istream &operator>>(istream &in, Extrato &g);
#endif //COURSEWORK03_EXTRATO_H
