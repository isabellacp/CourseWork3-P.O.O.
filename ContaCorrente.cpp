//
// Created by isabe on 16/12/2019.
//
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "ContaCorrente.h"
#include "Conta.h"

using namespace std;

int ContaCorrente::QuantidadeCorrente =0;
float ContaCorrente::MontanteTotalCorrente =0;
string ContaCorrente::NomeArquivo = "ContasCorrente.txt";
list<ContaCorrente*> ContaCorrente::ListaContasCorrentes;

ContaCorrente::ContaCorrente(string cpf_cliente) : Conta(cpf_cliente) {
    LimiteChequeEspecial = 100.00; //limite inicial
    setQuantidadeContas(getQuantidadeContas()+1);
    setNumero(getQuantidadeContas());
    ContaCorrente::ListaContasCorrentes.push_back(this);


}

bool ContaCorrente::debitoConta(double valor, tm data) {
    if (getSaldoAtual() + LimiteChequeEspecial < valor) {
        return false;
    }
    Lancamento *lancamento = new Lancamento("debito", valor, getSaldoAtual());
    //inserção da operação no extrato

    lancamento->setDataLancamento(data);

    lista_lancamentos.push_back(lancamento);
    //realização do debito em conta
    setSaldoAtual(getSaldoAtual() - valor);
    //atualização do montante total do banco


    setMontanteTotal(getMontanteTotal() - valor);
    return true;
}

float ContaCorrente::getLimiteChequeEspecial() const {
    return LimiteChequeEspecial;
}

void ContaCorrente::setLimiteChequeEspecial(float limiteChequeEspecial) {
    LimiteChequeEspecial = limiteChequeEspecial;
}


float ContaCorrente::getMontanteTotal() {
    return MontanteTotalCorrente;
}

void ContaCorrente::setMontanteTotal(float montanteTotal) {
    MontanteTotalCorrente = montanteTotal;
}

int ContaCorrente::getQuantidadeContas() {
    return QuantidadeCorrente;
}

void ContaCorrente::setQuantidadeContas(int quantidadeContas) {
    QuantidadeCorrente = quantidadeContas;
}

void ContaCorrente::SalvarLista() {
    std::ofstream Lista(ContaCorrente::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << ContaCorrente::ListaContasCorrentes.size() << std::endl;
    for(auto conta: ContaCorrente::ListaContasCorrentes) {
        Lista << *conta;
    }
    Lista.flush();
}

void ContaCorrente::ReiniciarLista() {
    std::ofstream Lista(ContaCorrente::NomeArquivo,   ios::out | ios::binary | std::ofstream::trunc);
    Lista << "0" << std::endl;
    while(!ContaCorrente::ListaContasCorrentes.empty()) {
        delete ContaCorrente::ListaContasCorrentes.back();
        ContaCorrente::ListaContasCorrentes.pop_back();
    }

}

void ContaCorrente::CarregarLista() {

    std::ifstream Lista(ContaCorrente::NomeArquivo,  ios::in | ios::binary);
    Lista >> QuantidadeCorrente;
    for(int i=0; i<QuantidadeCorrente; i++) {
        ContaCorrente* cliente = new ContaCorrente();
        Lista >> (*cliente);
        ContaCorrente::ListaContasCorrentes.push_back(cliente);
    }
}

ContaCorrente::ContaCorrente():Conta() {

}

ContaCorrente::~ContaCorrente() {

        MontanteTotalCorrente -= getSaldoAtual();


}

ostream &operator<<(ostream &out, ContaCorrente &g) {
    out << g.getNumero() << " "
        << g.getCPFcliente() << " "
        << fixed << setprecision(2)<< g.getSaldoAtual() << " "
        << g.getLimiteChequeEspecial() << std::endl;
    return out;
}

istream &operator>>(istream &in, ContaCorrente &g) {
    int numero;
    double saldo, limite;
    string cpf;
    in >> numero >> cpf >> saldo >> limite;
    g.setNumero(numero);
    g.setCPFcliente(cpf);
    g.setSaldoAtual(saldo);
    g.setLimiteChequeEspecial(limite);
    return in;
}

