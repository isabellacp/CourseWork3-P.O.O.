//
// Created by isabe on 14/12/2019.
//
#include <iostream>
#include "Cliente.h"

Cliente::Cliente(string nome, string cpf, string endereco, string telefone, string email) {
    Nome = nome;
    CPF = cpf;
    Endereco = endereco;
    Telefone = telefone;
    Email = email;
}
Cliente::Cliente() {}

Cliente::~Cliente(){

}
const string &Cliente::getNome() const {
    return Nome;
}

void Cliente::setNome(const string &nome) {
    Nome = nome;
}


const string &Cliente::getCpf() const {
    return CPF;
}

void Cliente::setCpf(const string &cpf) {
    CPF = cpf;

}

const string &Cliente::getEndereco() const {
    return Endereco;
}

void Cliente::setEndereco(const string &endereco) {
    Endereco = endereco;
}

const string &Cliente::getTelefone() const {
    return Telefone;
}

void Cliente::setTelefone(const string &telefone) {
    Telefone = telefone;
}

const string &Cliente::getEmail() const {
    return Email;
}

void Cliente::setEmail(const string &email) {
    Email = email;
}
string Cliente::toString() {
    return  " CPF: "  +  CPF +   + "  Nome: " + Nome ;

}

int Cliente::getNumero() const {
    return numero;
}

void Cliente::setNumero(int numero) {
    Cliente::numero = numero;
}

