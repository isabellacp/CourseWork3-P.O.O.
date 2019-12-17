//
// Created by isabe on 15/12/2019.
//

#include "Lancamento.h"
#include <string>
#include <sstream>
using namespace std;
Lancamento::Lancamento(string type, float valor, float saldoAnterior)
{

    this->type = type;
    this->valor = valor;
    this->SaldoAnterior = saldoAnterior;
    this->DataLancamento = time(0);
}

string Lancamento::getType()
{
    return type;
}

float Lancamento::getValor()
{
    return valor;
}

tm Lancamento::getDataLancamento()
{
    return *localtime(&DataLancamento);
}
void Lancamento::setDataLancamento(tm data)
{
    DataLancamento = mktime(&data);
}


float Lancamento::getSaldoAnterior()
{
    return SaldoAnterior;
}
string Lancamento::toString() {

    ostringstream output;
    output << "Tipo: " << type << " | ";
    output << "Valor: " << fixed << valor << " | ";
    output << "Saldo Anterior: " << SaldoAnterior << " | ";
    output << "Data: " << ctime(&DataLancamento);

    return output.str();

}

void Lancamento::setType(const string &type) {
    Lancamento::type = type;
}

void Lancamento::setValor(float valor) {
    Lancamento::valor = valor;
}



void Lancamento::setSaldoAnterior(float saldoAnterior) {
    SaldoAnterior = saldoAnterior;
}

Lancamento::Lancamento() {

}


ostream &operator<<(ostream &out, Lancamento &g) {

    out << g.getType() << std::endl
        << g.getValor() << std::endl
        << g.getSaldoAnterior() << std::endl;
    return out;
}

istream &operator>>(istream &in, Lancamento &g) {
    string type;
    float valor, saldoanterior;
    in >> type >> valor  >> saldoanterior;
    g.setType(type);
    g.setValor(valor);
    g.setSaldoAnterior(saldoanterior);


    return in;
}