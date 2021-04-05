#ifndef TipoItem_H
#define TipoItem_H

#include <string>

typedef std::string TipoChave; // TipoChave é um string

class TipoItem {
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();

    private:
        TipoChave chave;
};

#endif