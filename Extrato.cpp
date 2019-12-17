//
// Created by isabe on 16/12/2019.
//

#include <iostream>
#include "Extrato.h"

ostream &operator<<(ostream &out, Extrato &g) {
    out << g.getListaLancamentos().size() << std::endl;
    for (Lancamento *lancamento : g.getListaLancamentos()) {
        out << *lancamento << std::endl;
    }
    return out;
}

istream &operator>>(istream &in, Extrato &g) {
    Lancamento l;
    int quantidade;
    in >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        auto *lancamento = new Lancamento();
        in >> l;
        g.getListaLancamentos().push_back(lancamento);
    }
    return in;
}

list<Lancamento *> Extrato::getListaLancamentos() {
    return lista_lancamentos;
}

void Extrato::setListaLancamentos(const list<Lancamento *> listaLancamentos) {
    lista_lancamentos = listaLancamentos;
}

int Extrato::getQuantidade() const {
    return lista_lancamentos.size();
}
