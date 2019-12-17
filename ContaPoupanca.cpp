//
// Created by isabe on 16/12/2019.
//

#include "ContaPoupanca.h"
#include "Conta.h"
#include <string>
#include <fstream>
#include <iomanip>

using  namespace std;
int ContaPoupanca::QuantidadePoupanca =0;
float ContaPoupanca::MontanteTotalPoupanca =0;
string ContaPoupanca::NomeArquivo ="ContasPoupanca.txt";
list<ContaPoupanca*> ContaPoupanca::ListaContasPoupanca;

ContaPoupanca::ContaPoupanca(string cpf_cliente):Conta(cpf_cliente) {
    setQuantidadeContas(getQuantidadeContas()+1);
    setNumero(getQuantidadeContas());
    ContaPoupanca::ListaContasPoupanca.push_back(this);

}


float ContaPoupanca::getMontanteTotal() {
    return MontanteTotalPoupanca;
}

void ContaPoupanca::setMontanteTotal(float montanteTotal) {
    MontanteTotalPoupanca = montanteTotal;
}

int ContaPoupanca::getQuantidadeContas() {
    return QuantidadePoupanca;
}

void ContaPoupanca::setQuantidadeContas(int quantidadeContas) {
    QuantidadePoupanca = quantidadeContas;
}

void ContaPoupanca::SalvarLista() {
    std::ofstream Lista(ContaPoupanca::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << ContaPoupanca::ListaContasPoupanca.size() << std::endl;
    for(auto conta: ContaPoupanca::ListaContasPoupanca) {
        Lista << *conta;
    }
    Lista.flush();
}
void ContaPoupanca::ReiniciarLista() {
    std::ofstream Lista(ContaPoupanca::NomeArquivo,   ios::out | ios::binary | std::ofstream::trunc);
    Lista << "0" << std::endl;
    while(!ContaPoupanca::ListaContasPoupanca.empty()) {
        delete ContaPoupanca::ListaContasPoupanca.back();
        ContaPoupanca::ListaContasPoupanca.pop_back();
    }
}

void ContaPoupanca::CarregarLista() {
    std::ifstream Lista(ContaPoupanca::NomeArquivo,  ios::in | ios::binary);
    Lista >> QuantidadePoupanca;
    for(int i=0; i<QuantidadePoupanca; i++) {
        ContaPoupanca* cliente = new ContaPoupanca();
        Lista >> (*cliente);
        ContaPoupanca::ListaContasPoupanca.push_back(cliente);
    }
}

ContaPoupanca::ContaPoupanca():Conta() {

}

ContaPoupanca::~ContaPoupanca() {
    MontanteTotalPoupanca -= getSaldoAtual();
}

ostream &operator<<(ostream &out, ContaPoupanca &g) {
    out << g.getNumero() << " "
        << g.getCPFcliente() << " "
        << fixed << setprecision(2) << g.getSaldoAtual() << std::endl;
    return out;
}

istream &operator>>(istream &in, ContaPoupanca &g) {
    int numero, saldo;
    string cpf;
    in >> numero >> cpf >> saldo;
    g.setNumero(numero);
    g.setCPFcliente(cpf);
    g.setSaldoAtual(saldo);
    return in;
}
