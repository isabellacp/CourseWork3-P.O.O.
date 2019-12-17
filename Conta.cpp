//
// Created by isabe on 15/12/2019.
//

#include "Conta.h"
#include <ctime>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include "Lancamento.h"

using namespace std;

int Conta::QuantidadeContas = 0;
float Conta::MontanteTotal = 0;

Conta::Conta(string cpf_cliente) {
    CPFcliente = cpf_cliente;
    SaldoAtual = 0;
    DataAbertura = time(0); //retorna a data atual
}

Conta::~Conta() {
    if (QuantidadeContas > 0) QuantidadeContas--;
    setMontanteTotal(getMontanteTotal() - getSaldoAtual());
    setSaldoAtual(0);
}

//FAZER LANÇAMENTO
bool Conta::FazerLancamento(int tipo, double valor, tm data) {
    switch (tipo) {
        case 1: {
            return debitoConta(valor, data);
            break;
        }
        case 2: {
            creditoConta(valor, data);
            return true;
            break;
        }
    }
    return true;

}
bool Conta::FazerLancamento(int tipo, double valor) {
    time_t t = time(0);
    tm* agora = localtime(&t);
    return FazerLancamento(tipo, valor, *agora);

}

//CREDITO EM CONTA: retorna 0 caso não consiga fazer a operação
void Conta::creditoConta(double valor, tm data) {
    Lancamento* lancamento = new Lancamento("credito", valor, SaldoAtual);
    //inserção da operação no extrato

    lancamento->setDataLancamento(data);

    lista_lancamentos.push_back(lancamento);
    //realização do credito em conta
    setSaldoAtual(SaldoAtual + valor);
    //atualização do montante total do banco


    setMontanteTotal(getMontanteTotal() + valor);
}
//DEBITO EM CONTA: retorna 0 caso não consiga fazer a operação
bool Conta::debitoConta(double valor, tm data) {
    if (SaldoAtual  < valor) {
        return false;
    }
    Lancamento* lancamento = new Lancamento("debito", valor, SaldoAtual);
    //inserção da operação no extrato

    lancamento->setDataLancamento(data);

    lista_lancamentos.push_back(lancamento);
    //realização do debito em conta
    setSaldoAtual(SaldoAtual - valor);
    //atualização do montante total do banco


    setMontanteTotal(getMontanteTotal() - valor);
    return true;
}


list<Lancamento*> Conta::getLancamentos() {
    return lista_lancamentos;
}
void Conta::imprimeExtrato(tm inicial_struct, tm final_struct) {

    time_t final = mktime(&final_struct);
    time_t inicial = mktime(&inicial_struct);

    if (final < inicial) {
        return;
    }
    double SaldoInicial, SaldoFinal;
    bool primeiro = false;
    for (auto& lancamento : this->getLancamentos()) {
        tm tmCopy = lancamento->getDataLancamento();
        time_t dataLancamento = mktime(&tmCopy);

        if (dataLancamento >= inicial && dataLancamento <= final) {
            if (!primeiro) {
                primeiro = true;
                SaldoInicial = lancamento->getSaldoAnterior();
            }
            if (lancamento->getType() == "debito") {
                cout << "Debito de " << lancamento->getValor()<< " em "<< ctime(&dataLancamento);
                SaldoFinal = lancamento->getSaldoAnterior() - lancamento->getValor();
            }
            else if (lancamento->getType() == "credito") {
                cout << "Credito de " << lancamento->getValor()<< " em "<< ctime(&dataLancamento);
                SaldoFinal = lancamento->getSaldoAnterior()+ lancamento->getValor();
            }
        }
    }
    if (!primeiro) {
        cout << "Não há lançamentos neste intervalo";
    }
    else {
        cout << "Saldo Inicial: " << SaldoInicial <<endl;

        cout << "Saldo Final: " << SaldoFinal <<endl;
    }
}



//GETTERS E SETTERS
//getter e setter para o SaldoAtual
double Conta::getSaldoAtual() const {
    return SaldoAtual;
}
void Conta::setSaldoAtual(double saldoAtual) {
    SaldoAtual = saldoAtual;

}

//getter e setter para o CPF do cliente
const string &Conta::getCPFcliente() const {
    return CPFcliente;
}
void Conta::setCPFcliente(const string &cpfCliente) {
    CPFcliente = cpfCliente;

}

//getter e setter para DataDeAbertura
tm Conta::getDataAbertura() const {
    return *localtime(&DataAbertura);
}
void Conta::setDataAbertura(tm dataAbertura) {
    DataAbertura = mktime(&dataAbertura);
}

//getter para QuantidadeContas
int Conta::GetNumero() {
    return Numero;
}
string Conta::toString() const {

    string result;
    ostringstream sContaCorrente;
    sContaCorrente << endl << " Numero: " << this->Numero << endl
                   << " CPF Cliente: " << this->CPFcliente << endl
                   << fixed << " Saldo Atual: " << this->SaldoAtual << endl
                   << " Data de Abertura: " << ctime(&this->DataAbertura) << endl;
    result = sContaCorrente.str();

    return result;


}


float Conta::getMontanteTotal() {
    return MontanteTotal;
}

int Conta::getNumero() const {
    return Numero;
}

void Conta::setNumero(int numero) {
    Numero = numero;
}

void Conta::setMontanteTotal(float montanteTotal) {
    MontanteTotal = montanteTotal;
}

Conta::Conta() {

}




