#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll a six-sided die */
int rollDie()
{
    return (rand() % 6) + 1;
}

/* Global variables to store positions of players */
int player1 = 0, player2 = 0;

/* Function to print the board */
void printBoard()
{
    int board[101];
    for (int i = 0; i <= 100; i++)
        board[i] = i;

    int alt = 0;
    int iterLR = 100;
    int iterRL = 91;

    while (iterLR >= 1)
    {
        if (alt == 0)
        {
            for (int i = iterLR; i >= iterRL; i--)
            {
                if (i == player1)
                    printf("P1 ");
                else if (i == player2)
                    printf("P2 ");
                else
                    printf("%2d ", board[i]);
            }
            printf("\n");
            iterLR -= 10;
            iterRL -= 10;
            alt = 1;
        }
        else
        {
            for (int i = iterRL + 1; i <= iterLR + 10; i++)
            {
                if (i == player1)
                    printf("P1 ");
                else if (i == player2)
                    printf("P2 ");
                else
                    printf("%2d ", board[i]);
            }
            printf("\n");
            alt = 0;
        }
    }
    printf("\n");
}

/* Function to move the player */
int movePlayer(int currentPlayer, int roll)
{
    int newPosition = currentPlayer + roll;

    if (newPosition > 100)
        return currentPlayer;

    int snakesAndLadders[101] = {0};

    /* Ladders (+) and Snakes (-) */
    snakesAndLadders[6]  = 40;
    snakesAndLadders[23] = -10;
    snakesAndLadders[45] = -7;
    snakesAndLadders[61] = -18;
    snakesAndLadders[65] = -8;
    snakesAndLadders[77] = 5;
    snakesAndLadders[98] = -10;

    int newSquare = newPosition + snakesAndLadders[newPosition];

    if (newSquare < 0)
        newSquare = 0;

    return newSquare;
}

int main()
{
    srand(time(0));

    int currentPlayer = 1;
    int won = 0;

    printf("Snake and Ladder Game\n\n");
    printBoard();

    while (!won)
    {
        printf("Player %d, press Enter to roll the die...", currentPlayer);
        while (getchar() != '\n');

        int roll = rollDie();
        printf("You rolled a %d\n", roll);

        if (currentPlayer == 1)
        {
            player1 = movePlayer(player1, roll);
            printf("Player 1 is now at square %d\n\n", player1);
            printBoard();

            if (player1 == 100)
            {
                printf("🎉 Player 1 wins!\n");
                won = 1;
            }
        }
        else
        {
            player2 = movePlayer(player2, roll);
            printf("Player 2 is now at square %d\n\n", player2);
            printBoard();

            if (player2 == 100)
            {
                printf("🎉 Player 2 wins!\n");
                won = 1;
            }
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
