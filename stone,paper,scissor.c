#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game logic
// returns 1  -> user wins
// returns 0  -> computer wins
// returns -1 -> tie
int game(char you, char computer)
{
    // If both choose same
    if (you == computer)
        return -1;

    // Stone vs Paper
    if (you == 's' && computer == 'p')
        return 0;
    else if (you == 'p' && computer == 's')
        return 1;

    // Stone vs Scissor
    if (you == 's' && computer == 'z')
        return 1;
    else if (you == 'z' && computer == 's')
        return 0;

    // Paper vs Scissor
    if (you == 'p' && computer == 'z')
        return 0;
    else if (you == 'z' && computer == 'p')
        return 1;

    return -1;
}

// Driver code
int main()
{
    int n;
    char you, computer, result;

    // Seed random number generator
    srand(time(NULL));

    // Generate random number (0,1,2)
    n = rand() % 3;

    // Assign computer choice
    if (n == 0)
        computer = 's';
    else if (n == 1)
        computer = 'p';
    else
        computer = 'z';

    // User input
    printf("Enter your choice:\n");
    printf("s for Stone, p for Paper, z for Scissor\n");
    scanf(" %c", &you);

    result = game(you, computer);

    // Display choices
    printf("You chose: %c\n", you);
    printf("Computer chose: %c\n", computer);

    // Result
    if (result == 1)
        printf("🎉 You Win!\n");
    else if (result == 0)
        printf("😞 Computer Wins!\n");
    else
        printf("🤝 It's a Tie!\n");

    return 0;
}