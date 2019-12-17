//
// Created by isabe on 14/12/2019.
//

#ifndef COURSEWORK03_CLIENTE_H
#define COURSEWORK03_CLIENTE_H
#include <string>
#include <list>

using namespace std;



class Cliente {
public:
    Cliente(string nome, string cpf, string endereco, string telefone, string email); //Construtor
    Cliente(); //construtor default
    ~Cliente(); //destrutpr

    //getter e setters
    const string &getNome() const;
    void setNome(const string &nome);

    const string &getCpf() const;
    void setCpf(const string &cpf);

    const string &getEndereco() const;
    void setEndereco(const string &endereco);

    const string &getTelefone() const;
    void setTelefone(const string &telefone);

    const string &getEmail() const;
    void setEmail(const string &email);

    string toString();

    int getNumero() const;

    void setNumero(int numero);


protected:
    int numero;
    string Nome;
    string CPF;
    string Endereco;
    string Telefone;
    string Email;

};


#endif //COURSEWORK03_CLIENTE_H
