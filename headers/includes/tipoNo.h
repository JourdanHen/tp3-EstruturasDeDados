#ifndef TipoNo_H
#define TipoNo_H

#include "tipoItem.h"

class TipoNo {
  public:
    TipoNo();
  private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;

    friend class ArvoreBinaria;
};

#endif