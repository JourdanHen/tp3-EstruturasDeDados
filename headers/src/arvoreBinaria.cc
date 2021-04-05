// slides de uala usados como inspiração
#include <iostream>
#include "../includes/arvoreBinaria.h"

ArvoreBinaria::ArvoreBinaria(){
  raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria(){
  Limpa();
}

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave) {
  return PesquisaRecursivo(raiz, chave);
}

TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave) {
  if (chave < no->item.GetChave())
    return PesquisaRecursivo(no->esq, chave);
  else if (chave>no->item.GetChave())
    return PesquisaRecursivo(no->dir, chave);
  else
    return no->item;
}

void ArvoreBinaria::Insere(TipoItem item){
  InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
  if(p==NULL){
    p = new TipoNo();
    p->item = item;
  } else {
    if(item.GetChave() < p->item.GetChave()) {
      InsereRecursivo(p->esq, item);
    } else {
      InsereRecursivo(p->dir, item);
    }
  }
}

void ArvoreBinaria::Remove(TipoChave chave) {
  return RemoveRecursivo(raiz, chave);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, TipoChave chave){
  TipoNo *aux;
  
  if (no == NULL) {
    throw("Item nao está presente");
  }
  
  if (chave < no->item.GetChave())
    return RemoveRecursivo(no->esq, chave);
  else if (chave > no->item.GetChave())
    return RemoveRecursivo(no->dir, chave);
  else {
    if (no->dir == NULL) {
      aux = no;
      no = no->esq;
      free(aux);
    } else if (no->esq == NULL) {
      aux = no;
      no = no->dir;
      free(aux);
    } else 
      Antecessor(no, no->esq);
  }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
  if(r->dir != NULL) {
    Antecessor(q, r->dir);
    return;
  }

  q->item = r->item;
  q = r;
  r = r->esq;
  free(q);
}

void ArvoreBinaria::Encripta(TipoChave palavra, int *i) {
  return EncriptaPreOrdem(raiz, palavra, i);
}

void ArvoreBinaria::EncriptaPreOrdem(TipoNo *p, TipoChave palavra, int *i) {
  if(p!=NULL) {
    *i += 1;
    if (p->item.GetChave() == palavra) {
      std::cout << *i << " ";
    }
    EncriptaPreOrdem(p->esq, palavra, i);
    EncriptaPreOrdem(p->dir, palavra, i);
  }
}

void ArvoreBinaria::Desencripta(int msgCriptografada, int *i) {
  return DesencriptaPreOrdem(raiz, msgCriptografada, i);
}

void ArvoreBinaria::DesencriptaPreOrdem(TipoNo *p, int msgCriptografada, int *i) {
  if(p!=NULL) {
    *i += 1;
    if (*i == msgCriptografada) {
      std::cout << p->item.GetChave() << " ";
    }
    DesencriptaPreOrdem(p->esq, msgCriptografada, i);
    DesencriptaPreOrdem(p->dir, msgCriptografada, i);
  }
}

void ArvoreBinaria::Limpa(){
  ApagaRecursivo(raiz);
  raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
  if(p!=NULL){
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
  }
}