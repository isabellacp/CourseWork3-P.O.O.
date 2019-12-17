/* Trabalho 03 da Disciplina de Programação Orientada a Objetos
 * Grupo:
    -Isabella da Costa Pires  RA: 726540
    -Julia Cinel RA:759314
    -Emilia Silva de Sousa RA:758588
    -Karulina Alencar de Freitas RA:757922
 * */






#include <iostream>
#include <fstream>
#include <afxres.h>
#include "Conta.h"
#include "ContaCorrente.h"
#include "ClienteFisico.h"
#include "ClienteJuridico.h"
#include "ContaPoupanca.h"
void Teste1();
void Teste2();
void Teste3();
void Teste4();

void CadastrarClienteJur();

void criaContaCorrente();

tm ConstrutorData(int dia, int mes, int ano) {

    time_t now = time(0);
    tm *data = localtime(&now);
    data->tm_mday = dia;
    data->tm_year = ano - 1900;
    data->tm_mon = mes - 1;
    return *data;
}





int main() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);


    int carregar = 0;

    std::cout << "Digite 1 para carregar e 0 para iniciar novamente as listas" <<std::endl;

    std::cin >> carregar;
    if(carregar) {
        ClienteFisico::CarregarLista();
        ClienteJuridico::CarregarLista();
        ContaPoupanca::CarregarLista();
        ContaCorrente::CarregarLista();

    } else {
        ClienteFisico::ReiniciarLista();
        ClienteJuridico::ReiniciarLista();
        ContaPoupanca::ReiniciarLista();
        ContaCorrente::ReiniciarLista();

    }



    int teste = 0;
    while(true) {
        system("cls||clear");
        std::cout << "Digite um teste para rodar:" <<std::endl;

        std::cin >> teste;

        switch (teste) {
            case 1: {
                Teste1();
                break;
            }
            case 2: {
                Teste2();
                break;
            }
            case 3: {
                Teste3();
                break;
            }
            case 4: {
                Teste4();
                break;
            }
        }
        std::cout << "Arquivos salvos na pasta do executavel" << std::endl;
        system ("PAUSE");

    }




    return 0;
}

void Teste1() {//Pessoa Física 01
    ClienteFisico::ReiniciarLista();

    ClienteJuridico::ReiniciarLista();

    ContaPoupanca::ReiniciarLista();

    ContaCorrente::ReiniciarLista();

    ClienteFisico *pf1 = new ClienteFisico("pessoa-fisica-1", "1101", "pf-street,-100", "123456789",
                                           "fulano@detal.com");
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    ContaCorrente *ccPessoaF1 = new ContaCorrente(pf1->getCpf()); //criando Conta Corrente para a Pessoa Física 01
    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta

    cout << "Conta Corrente criada para Pessoa Física 01:" << ccPessoaF1->toString() << endl;
    //criar poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(pf1->getCpf());
    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA

    cout << "Conta Poupança criada para Pessoa Física 01:" << cpPessoaF1->toString() << endl;

    //Pessoa Física 02
    ClienteFisico *pf2 = new ClienteFisico("pessoa-fisica-2", "1102", "pf-street,-200", "7891011", "fulano2@detal.com");
    cout << "Cliente Criado: Pessoa Física 02" << pf2->toString() << endl;
    ContaCorrente *ccPessoaF2 = new ContaCorrente(pf2->getCpf());
    cout << "Conta Corrente criada para Pessoa Física 02:" << ccPessoaF2->toString() << endl;

    //cria poupança para PF02
    ContaPoupanca *cpPessoaF2 = new ContaPoupanca(pf2->getCpf());
    cpPessoaF1->FazerLancamento(2, 50); //creditando 50 reais na conta poupança
    cout << "Conta Poupança criada para Pessoa Física 02:" << cpPessoaF2->toString() << endl;


    //listar clientes fisicos
    cout << "Total de Clientes Físicos Cadastrados:" << endl;
    cout << ClienteFisico::getTotalClientesFisico() << endl;
    //listar clientes juridicos
    cout << "Total de Clientes Juridicos Cadastrados:" << endl;
    cout << ClienteJuridico::getTotalClientesJuridico() << endl;
    //listar contas correntes
    cout << "Total de Contas Correntes:" << endl;
    cout << ccPessoaF2->getQuantidadeContas() << endl;
    //listar contas poupança
    cout << "Total de Contas Poupança:" << endl;
    cout << cpPessoaF2->getQuantidadeContas() << endl;

    //Pessoa Juridica 01 (vinculado à Pessoa Física 01)
    ClienteJuridico *pj1 = new ClienteJuridico("pessoa-juridica-01", "13579", "endereco", "3123", "empresa1@fulano.com",
                                               "cnpjaa", "atuacao", "funcao",
                                               "atualizacao");
    cout << "Cliente Criado: Pessoa JurÍdica 01" << pj1->toString() << endl;
    ContaCorrente *ccPessoaJ1 = new ContaCorrente("cnpjaa"); //criando Conta Corrente para a Pessoa Jurídica 01
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente criada para Pessoa Jurídica 01:" << ccPessoaJ1->toString() << endl;

    //Pessoa Juridica 02 (vinculado à Pessoa Física 02)
    ClienteJuridico *pj2 = new ClienteJuridico("pessoa-juridica-02", "1202", "enderecoPF2", "telefonePJ2",
                                               "empresa2@fulano.com", "cnpjPJ2", "atuacaoPJ2", "funcaoPJ2",
                                               "atualizacaoPJ2");
    cout << "Cliente Criado: Pessoa JurÍdica 02" << pj2->toString() << endl;
    ContaCorrente *ccPessoaJ2 = new ContaCorrente("cnpjPJ2"); //criando Conta Corrente para a Pessoa Jurídica 01
    ccPessoaJ2->FazerLancamento(2, 500000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente criada para Pessoa Jurídica 02:" << ccPessoaJ2->toString() << endl;


    //listar clientes fisicos
    cout << "Total de Clientes Físicos Cadastrados:" << endl;
    cout << ClienteFisico::getTotalClientesFisico() << endl;
    //listar clientes juridicos
    cout << "Total de Clientes Juridicos Cadastrados:" << endl;
    cout << ClienteJuridico::getTotalClientesJuridico() << endl;
    //listar contas correntes
    cout << "Total de Contas Correntes:" << endl;
    cout << ContaCorrente::QuantidadeCorrente << endl;
    //listar contas poupança
    cout << "Total de Contas Poupança:" << endl;
    cout << ContaPoupanca::QuantidadePoupanca << endl;
    //exibir montante total do banco
    cout << "Montante Total do Banco:" << endl;
    cout << fixed << ContaPoupanca::MontanteTotalPoupanca + ContaCorrente::MontanteTotalCorrente << endl;

    ContaCorrente::SalvarLista();
    ContaPoupanca::SalvarLista();
    ClienteFisico::SalvarLista();
    ClienteJuridico::SalvarLista();

}

void Teste2() {
    ClienteFisico::ReiniciarLista();

    ClienteJuridico::ReiniciarLista();

    ContaPoupanca::ReiniciarLista();

    ContaCorrente::ReiniciarLista();
    //Cenario de Teste C2
    std::cout << " ----------------CENARIO DE TESTE 2-------------------- " << endl;

    //Pessoa Física 01
    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1102", enderecoPF1 = "pf street, 200 ", telefonePF1 = "7891011", emailPF1 = "fulano2@detal.com";
    ClienteFisico *pf1 = new ClienteFisico(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    cout << "Cliente Físico pf1 Criado: " << pf1->toString() << endl;
    ContaCorrente *ccPessoaF1 = new ContaCorrente(cpfPF1); //criando Conta Corrente para a Pessoa Física 01

    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta
    cout << "Conta Corrente c1 criada para pf1:  " << ccPessoaF1->toString() << endl;
    //criar poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(cpfPF1);

    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA
    cpPessoaF1->setSaldoAtual(200);
    cout << "Conta Poupança p1 criada para pf1: " << cpPessoaF1->toString() << endl;
    //lancamentos
    cout << "-________________" << endl;
    cout << "   Lançamentos   " << endl;
    cout << "-________________" << endl;
    ccPessoaF1->FazerLancamento(1, 100); //debito de 100,00 na conta corrente
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaF1->getSaldoAtual() << endl; //out saldo atual
    ccPessoaF1->FazerLancamento(2, 50); //credita 50 na conta corrente
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaF1->getSaldoAtual() << endl; //out saldo atual
    cpPessoaF1->FazerLancamento(2, 30); //credita 30 na conta poupanca
    cout << "Saldo atual Conta Poupança p1:" << cpPessoaF1->getSaldoAtual() << endl; //out saldo atual
    cout << "" << endl;


    //EXIBIR EXTRATO DE CONTA CORRENTE 1
    cout << "EXTRATO DE CONTA CORRENTE c1 " << endl;
    for (auto &lancamento : ccPessoaF1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout << "Saldo Final:" << ccPessoaF1->getSaldoAtual() << endl;

    //EXIBIR EXTRATO POUPANCA 1
    cout << "EXTRATO DE CONTA POUPANCA p1" << endl;
    for (auto &lancamentoPoup : cpPessoaF1->getLancamentos()) {
        cout << lancamentoPoup->toString() << endl;
    }
    cout << "Saldo Final:" << cpPessoaF1->getSaldoAtual() << endl;

    //Pessoa Juridica 01
    string nomePJ1 = "pessoa juridica 01", telefonePJ1 = "13579", emailPJ1 = "empresa1@fulano.com", cnpjPJ1 = "1201", atuacaoPJ1 = "comercio", funcaoPJ1 = "detal", atualizacaoPJ1 = "10/01/2005";
    ClienteJuridico *pj1 = new ClienteJuridico(nomePJ1, cpfPF1, enderecoPF1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1,
                                               funcaoPJ1,
                                               atualizacaoPJ1);
    cout << "Cliente Jurídico pj1 Criado: " << pj1->toString() << endl;
    ContaCorrente *ccPessoaJ1 = new ContaCorrente(cnpjPJ1); //criando Conta Corrente para a Pessoa Jurídica 01
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente c3 criada para pj1:" << ccPessoaJ1->toString() << endl;

    //Pessoa Juridica 02
    string nomePJ2 = "pessoa juridica 02", telefonePJ2 = "813579", emailPJ2 = "empresa2@fulano.com", cnpjPJ2 = "12201", atuacaoPJ2 = "comercio 2", funcaoPJ2 = "detal 2", atualizacaoPJ2 = "10/01/2005";
    ClienteJuridico *pj2 = new ClienteJuridico(nomePF1, cpfPF1, enderecoPF1, telefonePJ2, emailPJ2, cnpjPJ2, atuacaoPJ2,
                                               funcaoPJ2,
                                               atualizacaoPJ2);
    cout << " Cliente Jurídico pj2 Criado: " << pj2->toString() << endl;
    ContaCorrente *ccPessoaJ2 = new ContaCorrente(cnpjPJ2); //criando Conta Corrente para a Pessoa Jurídica 02
    ccPessoaJ2->FazerLancamento(2, 500000); //creditando 500,000.00 reais na conta
    cout << "Conta Corrente  c4 criada para pj2" << ccPessoaJ2->toString() << endl;

    ccPessoaJ1->FazerLancamento(1, 100000); //lancamento debito 100.000,00 em c3
    cout << "Saldo Atual Pessoa juridica 1:" << ccPessoaJ1->getSaldoAtual() << endl;
    ccPessoaJ1->FazerLancamento(1, 200000); //lancamento  debito 200.000,00 em c3
    cout << "Saldo Atual Pessoa juridica 1:" << ccPessoaJ1->getSaldoAtual() << endl;
    ccPessoaJ2->FazerLancamento(1, 30000); //lancamento  debito 30.000,00 em c4
    cout << "Saldo Atual Pessoa juridica 2:" << ccPessoaJ2->getSaldoAtual() << endl;

    //EXIBIR EXTRATO DE C3
    cout << "EXTRATO DE CONTA CORRENTE c3 " << endl;
    for (auto &lancamento : ccPessoaJ1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout << "Saldo Final:" << ccPessoaJ1->getSaldoAtual() << endl;

    //EXIBIR EXTRATO DE C4
    cout << "EXTRATO DE CONTA CORRENTE c4 " << endl;
    for (auto &lancamento : ccPessoaJ2->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout << "Saldo Final:" << ccPessoaJ2->getSaldoAtual() << endl;

    //exibir montante total do banco
    cout << "Montante Total do Banco:" << endl;
    cout << fixed << ContaCorrente::MontanteTotalCorrente + ContaPoupanca::MontanteTotalPoupanca << endl;
    ContaCorrente::SalvarLista();
    ContaPoupanca::SalvarLista();
    ClienteFisico::SalvarLista();
    ClienteJuridico::SalvarLista();

}

void Teste3() {
    ClienteFisico::ReiniciarLista();

    ClienteJuridico::ReiniciarLista();

    ContaPoupanca::ReiniciarLista();

    ContaCorrente::ReiniciarLista();
    cout << " ----------------CENARIO DE TESTE 3-------------------- " << endl;
    //Pessoa Física 01
    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
    ClienteFisico *pf1 = new ClienteFisico(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    //Pessoa Jurídica 01
    cout << "    " << endl;
    string nomePJ1 = "Pessoa Jurídica 01", cpfPJ1 = "1111", enderecoPJ1 = "aaaa, 900", telefonePJ1 = "13589", emailPJ1 = "empresaA@fulano.com", cnpjPJ1 = "1222", atuacaoPJ1 = "comercio", funcaoPJ1 = "detal", atualizacaoPJ1 = "10/01/2005";
    ClienteJuridico *pj1 = new ClienteJuridico(nomePJ1, cpfPJ1, enderecoPJ1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1,
                                               funcaoPJ1,
                                               atualizacaoPJ1);
    cout << "Cliente Jurídico Criado pj1" << pj1->toString() << endl;
    //criando Conta Corrente para a Pessoa Jurídica 01
    ContaCorrente *ccPessoaJ1 = new ContaCorrente(cnpjPJ1);
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente c1 criada para pj1:" << ccPessoaJ1->toString() << endl;
    cout << ccPessoaJ1->getLancamentos().front()->toString();
    cout << "    " << endl;
    //lançar débito de 100, 000.00 em 15 / 11 / 2019 em conta corrente de pj1
    ccPessoaJ1->FazerLancamento(1, 100000, ConstrutorData(15, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;

    //lançar débito de 200, 000.00 em 16 / 11 / 2019 em  conta corrente de pj1
    ccPessoaJ1->FazerLancamento(1, 200000, ConstrutorData(16, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;

    //lançar crédito de 400, 000.00 em 17 / 11 / 2019 em  conta corrente de pj1
    ccPessoaJ1->FazerLancamento(2, 400000, ConstrutorData(17, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;
    cout << "    " << endl;

    //exibir extrato de c1 considerando todo o período
    cout << "EXTRATO INTEGRAL DE CONTA CORRENTE c1 " << endl;

    for (auto &lancamento : ccPessoaJ1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout << "Saldo Inicial:1000000.00 " << endl;
    cout << "Saldo Final:" << ccPessoaJ1->getSaldoAtual() << endl;
    //exibir extrato de c1 de 15 / 11 / 2019 a 16 / 11 / 2019
    cout << " EXTRATO DE CONTA CORRENTE c1 --- INICIO: 15 / 11 / 2019 ||| FIM: 16 / 11 / 2019" << endl;
    ccPessoaJ1->imprimeExtrato(ConstrutorData(15, 11, 2019), ConstrutorData(16, 11, 2019));
    cout << "______________________________________________________________________________" << endl;
    //exibir extrato de c1 de 16 / 11 / 2019 a 17 / 11 / 2019
    cout << " EXTRATO DE CONTA CORRENTE c1 --- INICIO: 16 / 11 / 2019 ||| FIM: 17 / 11 / 2019" << endl;
    ccPessoaJ1->imprimeExtrato(ConstrutorData(16, 11, 2019), ConstrutorData(17, 11, 2019));
    ContaCorrente::SalvarLista();
    ContaPoupanca::SalvarLista();
    ClienteFisico::SalvarLista();
    ClienteJuridico::SalvarLista();


}


void Teste4() {
    ClienteFisico::ReiniciarLista();

    ClienteJuridico::ReiniciarLista();

    ContaPoupanca::ReiniciarLista();

    ContaCorrente::ReiniciarLista();
    cout << " ----------------CENARIO DE TESTE 4-------------------- " << endl;

    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
    ClienteFisico *pf1 = new ClienteFisico(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);

    //criando Conta Corrente para a Pessoa Física 01
    ContaCorrente *ccPessoaF1 = new ContaCorrente(cpfPF1);
    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta
    //criando poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(cpfPF1);
    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA

    cout << "  " << endl;

    cout << " Testar situações de restrição " << endl;
    cout << "______________________________________________________________________________________________" << endl;
    //cadastramento de cliente Pessoa Física (Jurídica?)para proprietário não cadastrado
    cout << " SITUACAO 01: cadastramento de cliente Pessoa Física (Jurídica?)para proprietário não cadastrado" << endl;
     CadastrarClienteJur();
    cout << "--FIM DA SITUAÇÃO 01 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //criação de conta para cliente não cadastrado
    cout << " SITUACAO 02:criação de conta para cliente não cadastrado" << endl;
     criaContaCorrente();
    cout << "--FIM DA SITUAÇÃO 02 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //lançamento que geraria saldo negativo em Conta Poupança
    cout << " SITUACAO 03: lançamento que geraria saldo negativo em Conta Poupança" << endl;
    cout << "Conta Poupanca criada para Pessoa Física 01:" << cpPessoaF1->toString() << endl;
    cout << "---tentiva de débito de 300,00 reais---" << endl;
    bool status = cpPessoaF1->FazerLancamento(1, 300);
    if (!status) {
        cout << "Sem saldo suficiente para esta operação!" << endl;
    }
    cout << "--FIM DA SITUAÇÃO 03 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //remoção de conta com lançamentos
    cout << " SITUACAO 04: remoção de conta com lançamentos" << endl;
    cout << "Conta Corrente criada para Pessoa Física 01:" << ccPessoaF1->toString() << endl;
    {
        int numeroDaConta = ccPessoaF1->GetNumero();
        bool achou = false;
        auto ptrConta = ContaCorrente::ListaContasCorrentes.begin(); // ponteiro para primeira conta da lista
        while (ptrConta != ContaCorrente::ListaContasCorrentes.end()) { // enquanto nao acabarem as contas
            if (numeroDaConta == (*ptrConta)->getNumero()) {
                achou = true;
                if (!(*ptrConta)->getLancamentos().empty()) {
                    cout << "Essa conta não pode ser deletada pois há lançamentos vinculados a ela" << endl;
                    break;
                }
                delete (*ptrConta); // remove conta da lista
                break;
            }
            ptrConta++; // avanca para a proxima conta
        }
        if (!achou) {
            cout << "Conta nao encontrada " << endl;
        }
    }
    cout << "--FIM DA SITUAÇÃO 04 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    // remoção de cliente com contas associadas
    cout << " SITUAÇÃO 05: remoção de cliente com contas associadas " << endl;
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    {
        bool achou = false;
        bool temconta = false;
        string cpf = pf1->getCpf();

        auto ptrCliente = ClienteFisico::ListaClientesFisicos.begin(); // inicia no primeiro cliente

        while (ptrCliente != ClienteFisico::ListaClientesFisicos.end()) { // enquanto nao acabar os clientes
            if (cpf == (*ptrCliente)->getCpf()) {
                achou = true;
                break;

            }
            ptrCliente++; // avança para o primeiro cliente
        }
        if (!achou) {
            cout << "Cliente não encontrado" << endl;

        }

        bool possuiContaCorrente = false;
        for (auto &ContaCorrente : ContaCorrente::ListaContasCorrentes) {
            if (cpf == ContaCorrente->getCPFcliente()) {
                possuiContaCorrente = true;
                cout << "Esse cliente não pode ser deletado pois há pelo menos 01 ContaCorrente vinculada a ele"
                     << endl;
                break;
            }
        }
        if (!possuiContaCorrente) {
            bool possuiContaPoup = false;
            for (auto &ContaPoupanca : ContaPoupanca::ListaContasPoupanca) {
                if (cpf == ContaPoupanca->getCPFcliente()) {
                    possuiContaPoup = true;
                    cout << "Esse cliente não pode ser deletado pois há pelo menos 01 ContaPoupanca vinculada a ele"
                         << endl;
                    break;
                }
            }
            if (!possuiContaPoup) {
                ClienteFisico::ListaClientesFisicos.erase(ptrCliente); //remove cliente da lista
            }
        }


    }
    cout << "--FIM DA SITUAÇÃO 05 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;
    ContaCorrente::SalvarLista();
    ContaPoupanca::SalvarLista();
    ClienteFisico::SalvarLista();
    ClienteJuridico::SalvarLista();

}
void criaContaCorrente() {
    cin.clear();

    bool achou = false;
    string cpf;
    cout << "Insira o CPF do cliente ja cadastrado no sistema:" << endl;
    getline(cin, cpf);
    //busca cpf do cliente na lista de clientes
    for (auto &cliente : ClienteFisico::ListaClientesFisicos) {
        if (cpf == cliente->getCpf()) {
            achou = true;
            ContaCorrente *nova_conta = new ContaCorrente(cpf);
            cout << "Conta Aberta com Sucesso! O numero da sua conta corrente é:" << nova_conta->GetNumero()
                 << endl;

        }
    }
    if (!achou)
        cout << "ABERTURA DE CONTA NÃO AUTORIZADA! O cliente náo esta cadastrado no sistema." << endl;


}

void CadastrarClienteJur() {
    cin.clear();

    bool achou = false;
    string cpfPJ;
    cout << "Insira o CPF do sócio marjoritario:" << endl;
    getline(cin, cpfPJ);
    //busca cpf do cliente na lista de clientes
    for (auto &cliente : ClienteFisico::ListaClientesFisicos) {
        if (cpfPJ == cliente->getCpf()) {
            achou = true;
            string nomePJ, cpfPJ, enderecoPJ, telefonePJ, emailPJ, cnpjPJ, atuacaoPJ, funcaoPJ, atualizacaoPJ;
            cout << "Insira o nome da Pessoa Juridica:" << endl;
            getline(cin, nomePJ);
            cout << "Insira o endereço:" << endl;
            getline(cin, enderecoPJ);
            cout << "Insira o telefone:" << endl;
            getline(cin, telefonePJ);
            cout << "Insira o e-mail:" << endl;
            getline(cin, emailPJ);
            cout << "Insira o CNPJ:" << endl;
            getline(cin, cnpjPJ);
            cout << "Insira a atuação:" << endl;
            getline(cin, atuacaoPJ);
            cout << "Insira a funcao" << endl;
            getline(cin, funcaoPJ);
            cout << "Insira a data da ultima atualização do contrato" << endl;
            getline(cin, atualizacaoPJ);

            ClienteJuridico *pj = new ClienteJuridico(nomePJ, cpfPJ, enderecoPJ, telefonePJ, emailPJ, cnpjPJ, atuacaoPJ, funcaoPJ,
                                                      atualizacaoPJ);

            cout << "Cliente Cadastrado com sucesso!" << endl;
            cout << "________________________________" << endl;
            cout << pj->toString() << endl;
            cout << "________________________________" << endl;

        }
    }
    if (!achou)
        cout
                << "CADASTRO DE PESSOA JÚRIDICA NÃO AUTORIZADO! O sócio marjoritário não está cadastrado como cliente físico."
                << endl;

}
