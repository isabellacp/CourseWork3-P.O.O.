//
// Created by isabe on 15/12/2019.
//
#include "ClienteJuridico.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


string ClienteJuridico::NomeArquivo = "ClientesJuridicos.txt";
list<ClienteJuridico*> ClienteJuridico::ListaClientesJuridicos;

//construtor
ClienteJuridico::ClienteJuridico(string nome, string cpf, string endereco, string telefone, string
email, string cnpj, string atuacao, string funcao, string atualizacao) : Cliente(nome, cpf, endereco, telefone, email) {

    Cnpj = cnpj;
    Atuacao = atuacao;
    Funcao = funcao;
    Atualizacao = atualizacao;
    ClienteJuridico::ListaClientesJuridicos.push_back(this);
    numero = ClienteJuridico::ListaClientesJuridicos.size();

}

ClienteJuridico::~ClienteJuridico() {

    ClienteJuridico::ListaClientesJuridicos.remove(this);

}



//getters e setters
const string &ClienteJuridico::getCnpj() const {
    return Cnpj;
}

void ClienteJuridico::setCnpj(const string cnpj) {
    Cnpj = cnpj;
}

const string &ClienteJuridico::getAtuacao() const {
    return Atuacao;
}

void ClienteJuridico::setAtuacao(string atuacao) {
    Atuacao = atuacao;

}

const string &ClienteJuridico::getFuncao() const {
    return Funcao;
}

void ClienteJuridico::setFuncao(string funcao) {
    Funcao = funcao;
}

const string &ClienteJuridico::getAtualizacao() const {

    return Atualizacao;
}

void ClienteJuridico::setAtualizacao(string atualizacao) {
    Atualizacao = atualizacao;
}

int ClienteJuridico::getTotalClientesJuridico() {
    return ListaClientesJuridicos.size();
}

string ClienteJuridico::toString() const {
    string result;
    ostringstream sJuridico;
    sJuridico << endl << "CNPJ: " << this->Cnpj << endl
              << "Atuacao: " << this->Atuacao << endl
              << "Funcao: " << this->Funcao << endl
              << "Ultima data de atualizacao do Contrato " << this->Atualizacao << endl;
    result = sJuridico.str();

    return result;

}


void ClienteJuridico::CarregarLista() {
    std::ifstream Lista(ClienteJuridico::NomeArquivo,  ios::in | ios::binary);
    int quantidade;
    Lista >> quantidade;

    for(int i=0; i<quantidade; i++) {
        ClienteJuridico* cliente = new ClienteJuridico();
        Lista >> (*cliente);
        ClienteJuridico::ListaClientesJuridicos.push_back(cliente);
    }

}

void ClienteJuridico::SalvarLista() {
    std::ofstream Lista(ClienteJuridico::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << ClienteJuridico::ListaClientesJuridicos.size() << std::endl;
    for(auto cliente: ClienteJuridico::ListaClientesJuridicos) {
        Lista << *cliente;
    }
    Lista.flush();


}
void ClienteJuridico::ReiniciarLista() {
    std::ofstream Lista(ClienteJuridico::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << "0" << std::endl;
    while(!ClienteJuridico::ListaClientesJuridicos.empty()) {
        delete ClienteJuridico::ListaClientesJuridicos.back();
        ClienteJuridico::ListaClientesJuridicos.pop_back();
    }

}

ClienteJuridico::ClienteJuridico() {

}




ostream &operator<<(ostream &out, ClienteJuridico &g) {

    out << g.getNome() << " "
        << g.getNumero() << " "
        << g.getCpf() << " "
        << g.getEndereco() << " "
        << g.getTelefone() << " "
        << g.getEmail() << " "
        << g.getCnpj() << " "
        << g.getAtuacao() << " "
        << g.getFuncao() << " "
        << g.getAtualizacao() << std::endl;
    return out;
}

istream &operator>>(istream &in, ClienteJuridico &g) {
    string nome, cpf, endereco, telefone, email, cnpj, atuacao, funcao, atualizacao;
    int numero;
    in >> nome >>  numero >> cpf >> endereco >> telefone >> email >> cnpj >> atuacao >> funcao >> atualizacao;
    g.setNome(nome);
    g.setCpf(cpf);
    g.setNumero(numero);
    g.setEndereco(endereco);
    g.setTelefone(telefone);
    g.setEmail(email);
    g.setCnpj(cnpj);
    g.setAtuacao(atuacao);
    g.setFuncao(funcao);
    g.setAtualizacao(atualizacao);

    return in;
}

