cmake_minimum_required(VERSION 3.15)
project(coursework03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coursework03
        Cliente.cpp
        Cliente.h
        ClienteFisico.cpp
        ClienteFisico.h
        ClienteJuridico.cpp
        ClienteJuridico.h
        Conta.cpp
        Conta.h
        ContaCorrente.cpp
        ContaCorrente.h
        ContaPoupanca.cpp
        ContaPoupanca.h
        Extrato.cpp
        Extrato.h
        Lancamento.cpp
        Lancamento.h
        main.cpp)
