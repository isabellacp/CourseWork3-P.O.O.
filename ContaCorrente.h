//
// Created by isabe on 16/12/2019.
//

#ifndef COURSEWORK03_CONTACORRENTE_H
#define COURSEWORK03_CONTACORRENTE_H

#include "Conta.h"
using namespace std;

class ContaCorrente: public Conta {

public:
    ContaCorrente();

    ContaCorrente(string cpf_cliente);
    ~ContaCorrente();
    bool debitoConta(double d, tm tm) override;

    float getLimiteChequeEspecial() const;

    void setLimiteChequeEspecial(float limiteChequeEspecial);

    int getQuantidadeContas() override;

    void setQuantidadeContas(int quantidadeContas) override;

    float getMontanteTotal() override;

    void setMontanteTotal(float montanteTotal) override;

    static float MontanteTotalCorrente;
    static int QuantidadeCorrente;
    static string NomeArquivo;
    static list<ContaCorrente*> ListaContasCorrentes;

    static void SalvarLista();

    static void ReiniciarLista();

    static void CarregarLista();
protected:

    float LimiteChequeEspecial;

};
ostream& operator<<(ostream& out, ContaCorrente& g);
istream& operator>>(istream &in, ContaCorrente &g);

#endif //COURSEWORK03_CONTACORRENTE_H
