#include <iostream>
#include <fstream>

using namespace std;

class Veiculo {

    string marca;
    string cor;
    int ano;
    float peso;

public:
    Veiculo(string marca, string cor, int ano, float peso) {
        this->marca = marca;
        this->cor = cor;
        this->ano = ano;
        this->peso = peso;
    }

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    string getCor() const { return cor; }
    void setCor(const string& cor) { this->cor = cor; }

    int getAno() const { return ano; }
    void setAno(int ano) { this->ano = ano; }

    float getPeso() const { return peso; }
    void setPeso(float peso) { this->peso = peso; }
};

class Concessionaria {
    Veiculo veiculos;
    int capacidade;
    int quantidade;

public:
    Concessionaria(int capacidade) {
        this->capacidade = capacidade;
        this->veiculos = Veiculo;
        this->quantidade = 0;
    }

    ~Concessionaria() {
        for (int i = 0; i < quantidade; ++i) {
            delete veiculos[i];
        }
        delete[] veiculos;
    }
    void adicionarVeiculo(const Veiculo& veiculo) {
        if (quantidade < capacidade) {
            veiculos[quantidade++] = Veiculo(veiculo);
        } else {
            cout << "Lotou a concessionaria" << endl;
        }
    }

    void imprimirVeiculos() const {
        for (int i = 0; i < quantidade; ++i) {
            cout << "Marca: " << veiculos[i]->getMarca() << ", ";
            cout << "Cor: " << veiculos[i]->getCor() << ", ";
            cout << "Ano: " << veiculos[i]->getAno() << ", ";
            cout << "Peso: " << veiculos[i]->getPeso() << endl;
        }
    }

    void imprimirArquivoTxt(const string& nomeArquivo) const {
        ofstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            for (int i = 0; i < quantidade; ++i) {
                arquivo << "Marca: " << veiculos[i]->getMarca() << ", ";
                arquivo << "Cor: " << veiculos[i]->getCor() << ", ";
                arquivo << "Ano: " << veiculos[i]->getAno() << ", ";
                arquivo << "Peso: " << veiculos[i]->getPeso() << endl;
            }
            arquivo.close();
            cout << "Arquivo " << nomeArquivo << " criado com sucesso!" << endl;
        } else {
            cout << "Erro ao abrir o arquivo " << nomeArquivo << "!" << endl;
        }
    }
};

int main() {
    Concessionaria concessionaria(5);
    Veiculo veiculo1("Ford", "Preto", 2022, 1500.5);
    Veiculo veiculo2("Toyota", "Branco", 2021, 1400.2);
    Veiculo veiculo3("Chevrolet", "Prata", 2023, 1600.8);

    // Adicionando veículos à concessionária
    concessionaria.adicionarVeiculo(veiculo1);
    concessionaria.adicionarVeiculo(veiculo2);
    concessionaria.adicionarVeiculo(veiculo3);

    cout << "Veículos cadastrados: " << endl;
    concessionaria.imprimirVeiculos();
    concessionaria.imprimirArquivoTxt("veiculos_cadastrados.txt");

    return 0;
}

