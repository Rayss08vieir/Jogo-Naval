# 🚢 Batalha Naval (Battleship Game)

## Visão Geral do Projeto

Este projeto é uma implementação do clássico jogo de estratégia **Batalha Naval**, desenvolvido em linguagem **C**. O jogo é jogado em um tabuleiro **5 x 5** onde o jogador tem o desafio de localizar e afundar **3 navios** escondidos em posições aleatórias.

O foco é a simplicidade da lógica e o uso de recursos de console para proporcionar uma experiência de jogo imediata, incluindo um sistema de **Dicas** para auxiliar na estratégia.

### Objetivo do Jogo
Localizar e afundar os **3 navios** no menor número de tentativas.

---

## Tecnologias e Configuração

| Recurso | Detalhe |
| :--- | :--- |
| **Linguagem Principal** | C (Padrão ANSI/ISO) |
| **IDE Recomendada** | VS Code ou Dev-C++ |
| **Compilador** | **GCC** (Recomendado MinGW para Windows) |

## Como Compilar e Executar

1.  **Salve** o código em um arquivo chamado `Game.c`.
2.  **Compile** usando o GCC no terminal:
    ```bash
    gcc Game.c -o BatalhaNaval
    ```
3.  **Execute** o jogo:
    ```bash
    ./BatalhaNaval
    ```
4.  O jogo iniciará, e você deverá inserir as coordenadas de Linha e Coluna (de **1 a 5**) para cada tiro.

---

## Regras e Símbolos do Jogo

O tabuleiro 5x5 utiliza os seguintes símbolos para representar o estado das células:

| Símbolo | Significado | Representação no Código |
| :--- | :--- | :--- |
| **~** | **Água** | Posição ainda não atacada (`-1`) |
| **\*** | **Errou o Tiro** | Tiro na água (`0`) |
| **X** | **Acertou o Navio** | Navio atingido (`1`) |

### Dicas Estratégicas (Hints)

Após cada tiro, o sistema fornece uma dica essencial para a sua estratégia:

> **"Row R $\rightarrow$ S ships"**
> Indica quantos navios (ainda não atingidos) estão localizados na **Linha R**.
>
> **"Column C $\rightarrow$ S ships"**
> Indica quantos navios (ainda não atingidos) estão localizados na **Coluna C**.

---

## Estrutura do Código (`Game.c`)

O código está modularizado em funções claras, cada uma responsável por uma etapa do jogo.

### Mapeamento das Funções

| Função | Descrição |
| :--- | :--- |
| `main()` | Controla o loop principal do jogo, a contagem de tentativas e a condição de vitória. |
| `initializeBoard()` | Inicializa a matriz do tabuleiro com o valor padrão de "água" (`-1`). |
| `placeShips()` | Posiciona os **3 navios** em coordenadas aleatórias, garantindo que não haja sobreposição. |
| `showBoard()` | Imprime o tabuleiro na tela, utilizando os símbolos `~`, `*` e `X`. |
| `takeShot()` | Captura a entrada do usuário (Linha e Coluna 1-5) e converte para índices de array (0-4). |
| `isHit()` | Verifica se as coordenadas do tiro correspondem a algum navio. |
| `giveHint()` | Calcula e exibe a dica para a jogada atual. |
| `updateBoard()` | Atualiza o tabuleiro com o resultado do tiro (acerto ou erro). |

### Estrutura de Dados

| Variável | Tipo | Tamanho | Uso |
| :--- | :--- | :--- | :--- |
| `board` | `int` | 5 x 5 | Representa o tabuleiro do jogo (estado das células). |
| `ships` | `int` | 3 x 2 | Armazena as coordenadas fixas (Row, Col) dos 3 navios. |
| `shot` | `int` | 2 | Armazena a coordenada (Row, Col) do tiro atual do jogador.
