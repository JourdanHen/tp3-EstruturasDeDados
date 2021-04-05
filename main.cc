#include <iostream>

#include "headers/includes/arvoreBinaria.h"

int main() {
  ArvoreBinaria A;

  char comand;
  TipoItem palavra, pesquisaitem;
  std::string auxiliar;
  int i, j, k;

  while (scanf("%c", &comand) != EOF) {
    switch (comand) {
      case 105:
      // entrada i
        std::cin >> auxiliar;
        palavra.SetChave(auxiliar);

        A.Insere(palavra);

        break;
      case 115:
      // entrada s
        std::cin >> auxiliar;
        pesquisaitem = A.Pesquisa(auxiliar);
        A.Remove(pesquisaitem.GetChave());

        std::cin >> auxiliar;
        palavra.SetChave(auxiliar);

        A.Insere(palavra);

        break;
      case 101:
      // entrada e
        std::cin >> i;

        for (j = 0; j < i; j++) {
          k = 0;
          std::cin >> auxiliar;
          A.Encripta(auxiliar, &k);
        }
        std::cout << std::endl;

        break;
      case 100:
      // entrada d
        int mensagemCript;
        std::cin >> i;

        for (j = 0; j < i; j++) {
          k = 0;
          std::cin >> mensagemCript;
          A.Desencripta(mensagemCript, &k);
        }
        std::cout << std::endl;
        
        break;
    }
  }

  return 0;
}