//pilha dinâmica

typedef int TipoItem;

struct Node{
    TipoItem valor;
    Node* proximo;

};

class pilhadinamica{
    private:
    Node* NodeTopo;

    public:
    pilhadinamica(); //construtor
    ~pilhadinamica(); //destrutor
    bool estavazio(); 
    bool estacheio(); //tem memoria
    void inserir(TipoItem item); //push
    TipoItem remover();
    void imprimir();
};