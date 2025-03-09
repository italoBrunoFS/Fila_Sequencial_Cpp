#include <iostream>
using namespace std;

class FilaSequencial {
private:
    int inicio;
    int fim;
    int* dados;
    int nElementos;
    static const int tamanhoMax = 100;

public:
    FilaSequencial() {
        inicio = 0;
        fim = -1;
        nElementos = 0;
        dados = new int[tamanhoMax];
    }

    ~FilaSequencial() {
        delete[] dados;
    }

    bool Vazia() {
        return nElementos == 0;
    }

    bool Cheia() {
        return nElementos == tamanhoMax;
    }

    int GetTamanho() {
        return nElementos;
    }

    int Primeiro() {
        if (Vazia()) {
            return -1;
        }
        return dados[inicio];
    }

    bool Inserir(int n) {
        if (Cheia()) {
            return false;
        }
        fim = (fim + 1) % tamanhoMax;
        dados[fim] = n;
        nElementos++;
        return true;
    }

    int Remover() {
        if (Vazia()) {
            return -1;
        }
        int res = dados[inicio];
        inicio = (inicio + 1) % tamanhoMax;
        nElementos--;
        return res;
    }

    void Imprimir() {
        if (Vazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }
        int i = inicio;
        for (int count = 0; count < nElementos; count++) {
            cout << dados[i] << " ";
            i = (i + 1) % tamanhoMax;
        }
        cout << endl;
    }
};

int main() {
    FilaSequencial fila;
    cout << "Nova fila criada!" << endl;
    cout << "Menu:\n";
    cout << "1- Inserir Elemento\n";
    cout << "2- Remover Elemento\n";
    cout << "3- Obter Primeiro Elemento\n";
    cout << "4- Obter Tamanho\n";
    cout << "5- Verificar se a fila está Vazia\n";
    cout << "6- Verificar se a fila está cheia\n";
    cout << "7- Exibir Fila\n";
    cout << "8- Sair\n";
    
    int n;
    cin >> n;
    while (n != 8) {
        switch (n) {
            case 1: {
                cout << "Digite quantos elementos quer inserir na fila: ";
                int NumElementos;
                cin >> NumElementos;
                for (int i = 0; i < NumElementos; i++) {
                    cout << "Digite o elemento que deseja adicionar a fila: ";
                    int Elemento;
                    cin >> Elemento;
                    if (!fila.Inserir(Elemento)) {
                        throw runtime_error("Erro ao inserir elemento!");
                    }
                }
                cout << "Todos os Elementos inseridos com Sucesso!" << endl;
                break;
            }
            case 2: {
                int dado = fila.Remover();
                if (dado != -1) {
                    cout << "Removido Com Sucesso!" << endl;
                }
                break;
            }
            case 3: {
                int res = fila.Primeiro();
                if (res == -1) {
                    throw runtime_error("Erro, fila Vazia!");
                }
                cout << "Primeiro elemento: " << res << endl;
                break;
            }
            case 4:
                cout << "Tamanho: " << fila.GetTamanho() << endl;
                break;
            case 5:
                if (fila.Vazia()) {
                    cout << "A fila está vazia." << endl;
                } else {
                    cout << "A fila não está vazia e possui " << fila.GetTamanho() << " elementos" << endl;
                }
                break;
            case 6:
                if (fila.Cheia()) {
                    cout << "A fila está cheia." << endl;
                } else {
                    cout << "A fila não está cheia e possui " << fila.GetTamanho() << " elementos" << endl;
                }
                break;
            case 7:
                fila.Imprimir();
                break;
            default:
                cout << "Opção Inválida!" << endl;
                break;
        }
        cin >> n;
    }
    return 0;
}
