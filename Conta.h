//
// Created by isabe on 15/12/2019.
//

#ifndef COURSEWORK03_CONTA_H
#define COURSEWORK03_CONTA_H

#include <ctime>
#include <string>
#include <list>
#include <sstream>
#include "Lancamento.h"

using namespace std;

class Conta {
public:
    Conta(string cpf_cliente); //construtor
    Conta(); //construtor

    ~Conta(); //destrutor

    list <Lancamento*>  lista_lancamentos; //struct que armazena dados sobre as operações feitas nas contas
    //Métodos de Lançamento

    bool FazerLancamento(int, double);
    bool FazerLancamento(int, double, tm data);
    list <Lancamento*> getLancamentos(); //getter - retorna o extrato
    void imprimeExtrato(tm inicial_struct, tm final_struct);
    virtual bool debitoConta (double, tm);
    void creditoConta (double, tm);




//GETTERS E SETTERS
//getter e setter para o SaldoAtual
    int getNumero() const;

    void setNumero(int numero);

    double getSaldoAtual() const;
    void setSaldoAtual(double saldoAtual);

    //getter e setter para o CPF do cliente
    const string &getCPFcliente() const;
    void setCPFcliente(const string &cpFcliente);

    //getter e setter para a Data de Abertura da conta
    tm getDataAbertura() const;
    void setDataAbertura(tm dataAbertura);


    int GetNumero();
    virtual int getQuantidadeContas()=0;

    virtual void setQuantidadeContas(int quantidadeContas)=0;

    virtual float getMontanteTotal();

    virtual void setMontanteTotal(float montanteTotal);

    string toString() const;

private:
    static float MontanteTotal;
    static int QuantidadeContas;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    double SaldoAtual;

};


#endif //COURSEWORK03_CONTA_H
