# RPG X1 de Console em C++

Pequeno jogo de RPG em texto feito em C++ para treinar lógica de programação e uso de cores no console do Windows.

## Funcionalidades

- Batalha 1x1 por turnos.
- Ataque e defesa aleatórios para você e para o oponente.
- Interface colorida no console (Windows) usando `windows.h`.
- Telas de vitória, derrota e empate.
- Contador de rodadas.

## Como compilar

No Windows, com g++ (por exemplo, MinGW):

g++ main.cpp -o rpg_x1.exe


O código usa `windows.h`, `system("cls")` e `system("pause")`, então foi pensado para rodar no Windows.

## Como jogar

- Você é o jogador 1.
- A cada rodada o jogo mostra:
  - Sua vida.
  - A vida do oponente.
  - O número da rodada.
- Escolha:
  - `1` para atacar.
  - `2` para defender.
- O jogo rola os valores de ataque e defesa e mostra o que aconteceu na tela com cores.

## Fim de jogo

- **Vitória**: o oponente chega a 0 ou menos de vida.
- **Derrota**: sua vida chega a 0 ou menos.
- **Empate**: os dois chegam a 0 ou menos na mesma rodada.

## Observações

- Projeto de estudo em C++, focado em:
  - Estruturas de controle.
  - Funções.
  - Classe simples (`Player`).
  - Uso de cores no console do Windows.
