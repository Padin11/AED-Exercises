/*
Questão:
Um banco deseja implementar um sistema de gerenciamento de contas bancárias em C++. Cada conta bancária possui um número de conta, nome do titular, saldo e tipo de conta. Existem dois tipos de contas: conta corrente e conta poupança. As contas correntes permitem saques ilimitados, mas cobram uma taxa por cada operação de saque. Já as contas poupança não permitem saques, apenas depósitos e rendimentos mensais sobre o saldo.

1. Crie uma classe base chamada "ContaBancaria" que contenha os atributos número de conta, nome do titular, saldo e métodos para sacar e depositar dinheiro.

2. Crie duas classes derivadas chamadas "ContaCorrente" e "ContaPoupanca", que herdam da classe base "ContaBancaria". Implemente os métodos de saque e depósito de acordo com as regras de cada tipo de conta.

3. Implemente a funcionalidade de armazenar e recuperar informações sobre as contas bancárias em arquivos de texto utilizando a biblioteca fstream.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ContaBancaria {
protected:
    int numeroConta;
    string nomeTitular;
    float saldo;

public:
    // Construtor
    ContaBancaria(int numeroConta, const string& nomeTitular, float saldo) : numeroConta(numeroConta), nomeTitular(nomeTitular), saldo(saldo) {}

    virtual void sacar(float valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de $" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Saldo insuficiente para realizar o saque." << endl;
        }
    }

    void depositar(float valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de $" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Valor de depósito inválido." << endl;
        }
    }

    float getSaldo() const {
        return saldo;
    }
};

class ContaCorrente : public ContaBancaria {
private:
    float taxaSaque;

public:
    ContaCorrente(int numeroConta, const string& nomeTitular, float saldo, float taxaSaque) : ContaBancaria(numeroConta, nomeTitular, saldo), taxaSaque(taxaSaque) {}

    void sacar(float valor) override {
        if (valor > 0 && valor + taxaSaque <= saldo) {
            saldo -= (valor + taxaSaque);
            cout << "Saque de $" << valor << " realizado com sucesso. Taxa de $" << taxaSaque << " cobrada." << endl;
        } else {
            cout << "Saldo insuficiente para realizar o saque ou valor inválido." << endl;
        }
    }
};

class ContaPoupanca : public ContaBancaria {
private:
    float taxaRendimento;

public:
    // Construtor
    ContaPoupanca(int numeroConta, const string& nomeTitular, float saldo, float taxaRendimento) : ContaBancaria(numeroConta, nomeTitular, saldo), taxaRendimento(taxaRendimento) {}

    void aplicarRendimentoMensal() {
        saldo *= (1 + taxaRendimento);
        cout << "Rendimento mensal aplicado com sucesso." << endl;
    }

    void sacar(float valor) override {
        cout << "Operação não permitida em contas poupança." << endl;
    }
};



    return 0;
}
