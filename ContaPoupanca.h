//
// Created by isabe on 16/12/2019.
//

#ifndef COURSEWORK03_CONTAPOUPANCA_H
#define COURSEWORK03_CONTAPOUPANCA_H

#include "Conta.h"
#include <string>

class ContaPoupanca : public  Conta {

public:
    ContaPoupanca();
    ~ContaPoupanca();

    ContaPoupanca(string cpf_cliente);


    int getQuantidadeContas() override;

    void setQuantidadeContas(int quantidadeContas) override;

    float getMontanteTotal() override;

    void setMontanteTotal(float montanteTotal) override;
    static int QuantidadePoupanca;
    static float MontanteTotalPoupanca;
    static string NomeArquivo;
    static list<ContaPoupanca*> ListaContasPoupanca;


    static void ReiniciarLista();

    static void CarregarLista();

    static void SalvarLista();
private:

};
ostream &operator<<(ostream &out, ContaPoupanca &g);

istream &operator>>(istream &in, ContaPoupanca &g);
#endif //COURSEWORK03_CONTAPOUPANCA_H
