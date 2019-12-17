//
// Created by isabe on 15/12/2019.
//

#include <iostream>
#include <fstream>
#include "ClienteFisico.h"
using namespace std;
string ClienteFisico::NomeArquivo = "ClientesFisicos.txt";
list<ClienteFisico*> ClienteFisico::ListaClientesFisicos;


//construtor
ClienteFisico :: ClienteFisico (string nome, string cpf, string endereco, string telefone, string email):Cliente( nome,  cpf,  endereco,  telefone,  email){
    ClienteFisico::ListaClientesFisicos.push_back(this);
    numero = ClienteFisico::ListaClientesFisicos.size();

}
ClienteFisico::~ClienteFisico(){

    ClienteFisico::ListaClientesFisicos.remove(this);

}

void ClienteFisico::CarregarLista() {
    std::ifstream Lista(ClienteFisico::NomeArquivo,  ios::in | ios::binary);
    int quantidade;
    Lista >> quantidade;
    for(int i=0; i<quantidade; i++) {
        ClienteFisico* cliente = new ClienteFisico();
        Lista >> (*cliente);
        ClienteFisico::ListaClientesFisicos.push_back(cliente);
    }

}

void ClienteFisico::SalvarLista() {
    std::ofstream Lista(ClienteFisico::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << ClienteFisico::ListaClientesFisicos.size() << std::endl;
    for(auto cliente: ClienteFisico::ListaClientesFisicos) {
        Lista << *cliente;
    }
    Lista.flush();

}
void ClienteFisico::ReiniciarLista() {
    std::ofstream Lista(ClienteFisico::NomeArquivo,  ios::out | ios::binary | std::ofstream::trunc);
    Lista << "0" << std::endl;
    while(!ClienteFisico::ListaClientesFisicos.empty()) {
        delete ClienteFisico::ListaClientesFisicos.back();
        ClienteFisico::ListaClientesFisicos.pop_back();
    }


}

ClienteFisico::ClienteFisico() {
}

int ClienteFisico::getTotalClientesFisico() {
    return  ClienteFisico::ListaClientesFisicos.size();
}




ostream &operator<<(ostream &out, ClienteFisico &g) {

    out << g.getNome() << " "
        << g.getNumero() << " "
        << g.getCpf() << " "
        << g.getEndereco() << " "
        << g.getTelefone() << " "
        << g.getEmail() << std::endl;
    return out;
}

istream &operator>>(istream &in, ClienteFisico &g) {
    string nome, cpf, endereco, telefone, email;
    int numero;
    in >> nome >> numero >> cpf>> endereco >> telefone >> email;
    g.setNome(nome);
    g.setNumero(numero);
    g.setCpf(cpf);
    g.setEndereco(endereco);
    g.setTelefone(telefone);
    g.setEmail(email);

    return in;
}

