#include <iostream>


using namespace std;

// pilha = stack
typedef int TipoItem;
const int max_itens = 100;

class pilha {
private:
    int tamanho;
    TipoItem* estrutura;

public:
    pilha(); //construtora //stack
    ~pilha(); //destrutora //~stack
    bool estacheia(); //verifica se a pilha esta cheia //isfull
    bool estavazia(); //verifica se a pilha esta vazia //isempty
    void inserir(TipoItem item); //push
    TipoItem remover(); //pop
    void imprimir(); //print
    int qualtamanho(); //lenght

};






using namespace std;

pilha::pilha() //construtora //stack
{
    tamanho = 0;
    estrutura = new TipoItem[max_itens];
}

pilha::~pilha() //destrutora //~stack
{
    delete[] estrutura;
}

bool pilha::estacheia() //verifica se a pilha esta cheia //isfull
{
    return (tamanho == max_itens);
}

bool pilha::estavazia() //verifica se a pilha esta vazia //isempty
{
    return (tamanho == 0);
}

void pilha::inserir(TipoItem item) //push
{
    if (estacheia()) {
        cout << "A pilha esta cheia!\n";
        cout << "Nao e possivel inserir este elemento!\n";
    }
    else {
        estrutura[tamanho] = item;
        tamanho++;
    }
}

TipoItem pilha::remover() //pop
{
    if (estavazia()) {
        cout << "A pilha esta vazia!\n"; //throw
        cout << "Nao tem elemento para ser removido!\n";
        return 0;
    }
    else {
        tamanho--;
        return estrutura[tamanho];
    }
}

void pilha::imprimir() //print
{
    cout << "Pilha: [ ";
    for (int i = 0; i < tamanho; i++) {
        cout << estrutura[i] << " ";
    }
    cout << "]\n";
}

int pilha::qualtamanho() //lenght
{
    return tamanho;
}



int main() {
    pilha pilha1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de pilha:\n";

    do {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a pilha!\n";
        cin >> opcao;
        if (opcao == 1) {
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            pilha1.inserir(item);
        }
        else if (opcao == 2) {
            item = pilha1.remover();
            cout << "Elemento Removido: " << item << endl;
        }
        else if (opcao == 3) {
            pilha1.imprimir();
        }

    } while (opcao != 0);

    return 0;
}