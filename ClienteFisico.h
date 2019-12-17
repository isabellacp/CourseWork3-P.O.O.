//
// Created by isabe on 15/12/2019.
//

#ifndef COURSEWORK03_CLIENTEFISICO_H
#define COURSEWORK03_CLIENTEFISICO_H
#include "Cliente.h"
#include <string>
using namespace std;

class ClienteFisico : public Cliente  {
public:
    ClienteFisico();

    ClienteFisico (string nome, string cpf, string endereco, string telefone, string email);
    ~ClienteFisico();

    static list<ClienteFisico*> ListaClientesFisicos;
    static void SalvarLista();
    static void CarregarLista();
    static void ReiniciarLista();
    static string NomeArquivo;

    static int getTotalClientesFisico();


private:

};
ostream &operator<<(ostream &out, ClienteFisico &g);

istream &operator>>(istream &in, ClienteFisico &g);

#endif //COURSEWORK03_CLIENTEFISICO_H
