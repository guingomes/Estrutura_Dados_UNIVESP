//pilha dinâmica com lista encadeada
#include <iostream>
#include "3.pilhadinamica.h"
#include <cstddef> //NULL

using namespace std;

    pilhadinamica::pilhadinamica() //construtor
    {
        NodeTopo = NULL;

    }

    pilhadinamica::~pilhadinamica() //destrutor
    {
        Node* NodeTemp;
        while (NodeTopo != NULL){
            NodeTemp = NodeTopo;
            NodeTopo = NodeTopo->proximo;
            delete NodeTemp;
        }

    }

    bool pilhadinamica::estavazio() 
    {
        return (NodeTopo == NULL);

    }

    bool pilhadinamica::estacheio() //tem memoria
    {
        Node* NodeNovo;
        try{
            NodeNovo = new Node;
            delete NodeNovo;
            return false;

        } catch(bad_alloc exception){
            return true;

        }

    }

    void pilhadinamica::inserir(TipoItem item) //push
    {
        if (estacheio()){
            cout << "A pilha esta cheia\n";
            cout << " Nao foi possivel inserir este elemento\n";
        } else{
            Node* NodeNovo = new Node;
            NodeNovo->valor = item;
            NodeNovo->proximo = NodeTopo;
            NodeTopo = NodeNovo;
        }

    }
    TipoItem pilhadinamica::remover()
    {
        if (estavazio()){
            cout << "A pilha está vazia\n";
            cout << "Nao foi possivel remover nenhum elemento\n";
            return 0;
        }else{
            Node* NodeTemp;
            NodeTemp = NodeTopo;
            TipoItem item = NodeTopo->valor;
            NodeTopo = NodeTopo->proximo;
            delete NodeTemp;
            return item;
        }

    }
    void pilhadinamica::imprimir()
    {
        Node* NodeTemp = NodeTopo;
        cout << "Pilha: [ ";
        while (NodeTemp != NULL){
            cout << NodeTemp->valor << " ";
            NodeTemp = NodeTemp->proximo;
        }
        cout << "]\n";

    }
