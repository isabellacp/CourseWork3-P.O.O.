//
// Created by isabe on 15/12/2019.
//

#ifndef COURSEWORK03_LANCAMENTO_H
#define COURSEWORK03_LANCAMENTO_H

#include <string>
#include <time.h>
using namespace std;
class Lancamento {
public:
    Lancamento();

    Lancamento(string type, float valor, float saldoAnterior);
    string getType();
    float getValor();
    tm getDataLancamento();
    void setDataLancamento(tm);

    float getSaldoAnterior();
    string toString();

    void setType(const string &type);

    void setValor(float valor);


    void setSaldoAnterior(float saldoAnterior);

private:
    string type;
    float valor = 0;
    time_t DataLancamento;
    float SaldoAnterior;

};

ostream &operator<<(ostream &out, Lancamento &g);

istream &operator>>(istream &in, Lancamento &g);
#endif //COURSEWORK03_LANCAMENTO_H
