#ifndef ArvoreBinaria_H
#define ArvoreBinaria_H

#include "tipoItem.h"
#include "tipoNo.h"

class ArvoreBinaria {
  public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    
    void Insere(TipoItem item);
    TipoItem Pesquisa(TipoChave chave);
    void Remove(TipoChave chave);
    void Limpa();
    void Encripta(TipoChave word, int *i);
    void Desencripta(int msgCriptografada, int *i);

  private:
    void InsereRecursivo(TipoNo* &p, TipoItem item);
    void ApagaRecursivo(TipoNo* p);
    TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave);
    void RemoveRecursivo(TipoNo* &p, TipoChave chave);
    void Antecessor(TipoNo* q, TipoNo* &r);
    void EncriptaPreOrdem(TipoNo* p, TipoChave word, int *i);
    void DesencriptaPreOrdem(TipoNo* p, int msgCriptografada, int *i);

    TipoNo *raiz;
};

#endif