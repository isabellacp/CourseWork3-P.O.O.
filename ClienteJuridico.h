//
// Created by isabe on 15/12/2019.
//

#ifndef COURSEWORK03_CLIENTEJURIDICO_H
#define COURSEWORK03_CLIENTEJURIDICO_H
#include <string>
#include <ctime>
#include "Cliente.h"

using namespace std;

class ClienteJuridico : public Cliente {
public:
    ClienteJuridico();

    ClienteJuridico (string nome, string cpf, string endereco, string telefone, string
    email, string cnpj, string atuacao, string funcao, string atualizacao); //construtor
    ~ClienteJuridico();
    void resetTotal();


    const string &getCnpj() const;
    void setCnpj(const string cnpj);
    const string &getAtuacao() const;
    void setAtuacao(string atuacao);
    const string &getFuncao() const;
    void setFuncao(string funcao);
    const string &getAtualizacao() const;
    void setAtualizacao(string atualizacao);
    static int getTotalClientesJuridico();
    string toString() const;

    static string NomeArquivo;
    static list<ClienteJuridico*> ListaClientesJuridicos;

    static void SalvarLista();

    static void ReiniciarLista();

    static void CarregarLista();


protected:
    string Cnpj;
    string Atuacao;
    string Funcao;
    string Atualizacao;

};
ostream &operator<<(ostream &out, ClienteJuridico &g);

istream &operator>>(istream &in, ClienteJuridico &g);

#endif //COURSEWORK03_CLIENTEJURIDICO_H
