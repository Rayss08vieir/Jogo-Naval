
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeBoard(int board[][5]) {
    int row, col;
    for (row = 0; row < 5; row++)
        for (col = 0; col < 5; col++)
            board[row][col] = -1;
}

void showBoard(int board[][5]) {
    int row, col;

    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");

    for (row = 0; row < 5; row++) {
        printf("%d", row + 1);
        for (col = 0; col < 5; col++) {
            if (board[row][col] == -1) {
                printf("\t~");
            } else if (board[row][col] == 0) {
                printf("\t*"); 
            } else if (board[row][col] == 1) {
                printf("\tX"); 
            }
        }
        printf("\n");
    }
}

void placeShips(int ships[][2]) {
    srand(time(NULL));
    int ship, prev;

    for (ship = 0; ship < 3; ship++) {
        ships[ship][0] = rand() % 5;
        ships[ship][1] = rand() % 5;

        
        for (prev = 0; prev < ship; prev++) {
            if ((ships[ship][0] == ships[prev][0]) && (ships[ship][1] == ships[prev][1]))
                do {
                    ships[ship][0] = rand() % 5;
                    ships[ship][1] = rand() % 5;
                } while ((ships[ship][0] == ships[prev][0]) && (ships[ship][1] == ships[prev][1]));
        }
    }
}

void takeShot(int shot[2]) {
    printf("Row: ");
    scanf("%d", &shot[0]);
    shot[0]--;

    printf("Column: ");

    scanf("%d", &shot[1]);
    shot[1]--;
}

int isHit(int shot[2], int ships[][2]) {
    int ship;

    for (ship = 0; ship < 3; ship++) {
        if (shot[0] == ships[ship][0] && shot[1] == ships[ship][1]) {
            printf("Voce acertou o navio em : (%d,%d)\n", shot[0] + 1, shot[1] + 1);
            return 1;
        }
    }
    return 0;
}

void giveHint(int shot[2], int ships[][2], int attempt) {
    int sameRow = 0, sameCol = 0, i;

    for (i = 0; i < 3; i++) {
        if (ships[i][0] == shot[0])
            sameRow++;
        if (ships[i][1] == shot[1])
            sameCol++;
    }

    printf("\nHint %d:\nRow %d -> %d ships\nColumn %d -> %d ships\n",
           attempt, shot[0] + 1, sameRow, shot[1] + 1, sameCol);
}

void updateBoard(int shot[2], int ships[][2], int board[][5]) {
    if (isHit(shot, ships))
        board[shot[0]][shot[1]] = 1;
    else
        board[shot[0]][shot[1]] = 0;
}

int main() {
    int board[5][5];
    int ships[3][2];
    int shot[2];
    int attempts = 0, hits = 0;

    initializeBoard(board);
    placeShips(ships);

    printf("\n~~~~(BATALHA NAVAL)~~~~\n");
    printf("\nVoce precisa acertar os 3 navios escondidos!\n");
    printf("Boa sorte!\n\n");

    do {
        showBoard(board);
        takeShot(shot);
        attempts++;

        if (isHit(shot, ships)) {
            giveHint(shot, ships, attempts);
            hits++;
        } else
            giveHint(shot, ships, attempts);

         updateBoard(shot, ships, board);

    } while (hits != 3);

    printf("\n\n FIM DE JOGO. Voce ganhou com %d tentativas!\n", attempts);
    showBoard(board);

    return 0;
}
