#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 6
#define WIDTH 7
int show_board(int b[HEIGHT][WIDTH]);
int check_board(int b[HEIGHT][WIDTH], int pi);
int check_winner(int b[HEIGHT][WIDTH]);
int main()
{
    int board[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = 0;
        }
    }

    int playerinput;
    int player = 1;
    show_board(board);
    while (1)
    {

        printf("Player %d's turn: ", player);
        scanf_s("%d", &playerinput);
        playerinput--;
        int filled = check_board(board, playerinput);

        printf("\n%d\n", filled);
        if (player == 1)
        {
            board[filled][playerinput] = 1;
            player = 2;
        }
        else
        {
            board[filled][playerinput] = 2;
            player = 1;
        }
        int win = check_winner(board);
        if (win == 1)
        {
            printf("Player 1 won\n");
            show_board(board);
            break;
        }
        else if (win == 2)
        {
            printf("Player 1 won\n");
            show_board(board);
            break;
        }
        else
        {
            show_board(board);
        }
    }
    return 0;
}

int check_winner(int b[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int p1[4] = {0, 0, 0, 0};
            int p2[4] = {0, 0, 0, 0};
            for (int r = 0; r < 4; r++)
            {
                if (b[i][j + r] == 1)
                {
                    p1[0]++;
                }
                else if (b[i][j + r] == 2)
                {
                    p2[0]++;
                }
            }
            for (int c = 0; c < 4; c++)
            {
                if (b[i + c][j] == 1)
                {
                    p1[1]++;
                }
                else if (b[i + c][j] == 2)
                {
                    p2[1]++;
                }
            }
            for (int d = 0; d < 4; d++)
            {
                if (b[i + d][j + d] == 1)
                {
                    p1[2]++;
                }
                else if (b[i + d][j + d] == 2)
                {
                    p2[2]++;
                }
            }
            for (int dh = 0, dw = 0; dh < 4; dh++, dw++)
            {
                if (b[i - dh][j + dw] == 1)
                {
                    p1[3]++;
                }
                else if (b[i - dh][j + dw] == 2)
                {
                    p2[3]++;
                }
            }

            for (int z = 0; z < 4; z++)
            {
                if (p1[z] > 3)
                    return 1;
            }

            for (int x = 0; x < 4; x++)
            {
                if (p2[x] > 3)
                    return 2;
            }
        }
    }
    return 0;
}

int check_board(int b[HEIGHT][WIDTH], int pi)
{
    int filled = HEIGHT - 1;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (b[i][pi] != 0)
            {
                filled = i - 1;
                return filled;
            }
        }
    }
    return filled;
}

int show_board(int b[HEIGHT][WIDTH])
{
    // system("clear");
    printf("1 2 3 4 5 6 7\n");
    printf("- - - - - - -\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}