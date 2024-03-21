#include <iostream>
#include <string>
using namespace std;

class Agenda{
private:
  string nome;
  string telefone;


public:
  void setNome(string nome1){
    this->nome = nome1;
  }

string getNome(){
  return this->nome;
}
void setTelefone(string telefone1){
    this->nome = telefone1;
  }

string getTelefone(){
  return this->telefone;
}
};
int main() {
  string x,y;
  cout << "Coloque seu nome: "<<endl;
  cin>>y;
  cout <<"Coloque seu telefone: "<< endl;
  cin>>x;
  Agenda a1;
  a1.setNome(y);
  a1.setTelefone(x);
  cout<<"Nome: "<<a1.getNome()<<endl;
  cout<<"Telefone: "<<a1.getTelefone();
 return 0;
}
