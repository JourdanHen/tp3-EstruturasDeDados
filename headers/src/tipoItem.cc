// slides de uala usados como inspiração
#include <iostream>
#include "../includes/tipoItem.h"

TipoItem::TipoItem() {
    chave = '-1';
}

TipoItem::TipoItem(TipoChave c) {
    chave = c;
}

void TipoItem::SetChave(TipoChave c) {
    chave = c;
}

TipoChave TipoItem::GetChave() {
    return chave;
}

void TipoItem::Imprime() {
    std::cout << chave << std::endl;
}