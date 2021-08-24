#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Hello, I am Prakash K. This is my C game project.
First, I would like to thank Gautam and Suraj 
for their goodwill and genuine help for this project.
 I thank my friends for motivating and trying out this game.
 Finally, I am grateful for the feedback and contribution for
making this game better over time. 

Project: Katttam-kuttta® in C
Github: pkaushal-bharat/C-Projects-by-K/
Description: TicTacToe like game in C which you can run without graphics.h
Repo link: https://github.com/pkaushal-bharat/C-Projects-by-K/
Time-spent: 3 Days
Version: 2.०
Last updated: Tuesday, 24 August 2021
*/
void intro();
int start_gm();
void about();

void game();
void ref_gm();
void play_gm();
void reset_m();
void show_mat(int, int);
short unsigned int gm_input(int);
short unsigned int gm_input_chk(int);
int gm_status();
void gm_result(int);
int play_again();

void keypress(void);
void clearIN(void);
int nory(void);

void col_reset(void);
void col_black(void);
void col_red(void);
void col_green(void);
void col_yellow(void);
void col_blue(void);
void col_purple(void);
void col_cyan(void);
void col_white(void);

char m[9];
short int gm_mode;
const char ch0 = '_', ch1 = 'X', ch2 = 'O'; //choices
const int mode_pvc = 1, mode_pvp = 2;       // game modes: 1 is comp, 2 is pvp

unsigned short int pl1 = 1, pl2 = 2;
int main()
{
    intro();
    srand(time(0));
    if (start_gm() == 1)
        game();
    return 0;
}
void intro()
{
    col_purple();
    printf("Welcome to Katttam-kuttta® v1.0\nby Prakash K");
    col_reset();
    printf("\n(Press 3 for more info)\n");
}
int start_gm()
{
    col_cyan();
    printf("\nKhelega Katttam-kuttta?\n");
    printf("Enter 0 for \"Nahi\"\n\t ya \"1 for PvsComp or 2 for PvsP\"\n");
    col_reset();
    int start_ttt = 0;
    scanf("%d", &start_ttt);
    if (start_ttt != 0)
    {
        if (start_ttt == 3)
        {
            about();
            col_cyan();
            printf("Play with computer?? (y/n)");
            col_reset();
            if (nory() == 1)
                gm_mode = mode_pvc;
            else
                gm_mode = mode_pvp;
            return 1;
        }
        else
        {
            if (start_ttt == 2)
                gm_mode = mode_pvp;
            else
                gm_mode = mode_pvc;
            return 1;
        }
    }
    else
        return 0;
}
void about()
{
    col_purple();
    printf("/*Hello, I am Prakash K. This is my C game project.\nFirst, I would like to thank my friends for motivation for this project.\nFinally, I am grateful for your feedback and contribution for\nmaking this game better over time. \n\n\nProject: Katttam-kuttta® in C \nDescription: TicTacToe like game in C which you can run everywhere \nTime-spent: 2 Days\nVersion: 2.0(2.०)\nLast updated: Tuesday, 24 August 2021\n*/");
    col_reset();
    keypress();
}
void game()
{
    do
    {
        ref_gm();
        play_gm();
    } while (play_again() == 1);
    {
        col_purple();
        printf("\nThank you for playing. Please share your suggestions💭 to the developer by mail....\n");
        printf("\nGet the latest version of Katttam-kuttta® from my Github repo🙂 \nand give it a star⭐");
        printf("\nat https://github.com/pkaushal-bharat/C-Projects-by-K");
        col_reset();
    }
    printf("\nThe END");
}
void ref_gm()
{
    printf("In each player's turn, to select a cell using the numeric pad\n");
    printf(" The reference for keys are as follows:\n");
    col_yellow();
    printf(" -----------\n");
    for (int i = 6; i >= 0; i -= 3)
    {
        printf("|");
        for (int j = 0; j < 3; ++j)
        {
            col_cyan();
            printf(" %d ", (i + j + 1));
            col_yellow();
            printf("|");
        }
        printf("\n -----------\n");
    }
    col_reset();

    printf("\n\n Hope u understood the input method\n");
    printf("Press any key to continue....");
    keypress();
    //clearIN();
    //system("CLS");
}
void play_gm()
{
    unsigned short int cell = 0; //the current cell box
    unsigned short int gm_round = 1, pl_turn = pl1, status = 0; //game round and turns
    reset_m();
    if (gm_mode == 1)
        pl2 = 0;
    do
    {
        show_mat(gm_round, pl_turn);
        cell = gm_input(pl_turn); // cell on which we have to operate
        gm_round++;
        if (pl_turn == pl1)
        {
            m[cell] = ch1;
            pl_turn = pl2;
        }
        else if (pl_turn == pl2)
        {
            m[cell] = ch2;
            pl_turn = pl1;
        }
        status = gm_status();
    } while (status == 0);
    show_mat(0, 0);
    gm_result(status);
}
void reset_m()
{
    for (short i = 0; i < 9; i++)
    {
        m[i] = ch0;
    }
}
void show_mat(int round, int turn)
{
    system("CLS");
    col_white();
    if (round != 0)
    {
        printf("Round: %i", round);
        printf("\t & \t");
        if (turn != 0)
            printf("Player %i\'s turn", turn);
        else
            printf("Computer");
    }
    printf("\n");
    col_reset();
    printf("The board looks as :\n");
    col_yellow();
    printf(" -----------\n");
    for (int i = 6; i >= 0; i -= 3)
    {
        printf("|");
        for (int j = 0; j < 3; ++j)
        {
            if (m[i + j] == ch1)
                col_red();
            else if (m[i + j] == ch2)
                col_blue();
            else
                col_green();
            printf(" %c ", m[i + j]);
            col_yellow();
            printf("|");
        }
        printf("\n -----------\n");
    }
    col_reset();
}
short unsigned int gm_input(int turn)
{
    short unsigned int v_in = 0; // only accept valid input
    do
    {
        if (turn != 0)
        {
            //clearIN();
            if (scanf(" %hu", &v_in) == 1)
            {
                v_in = gm_input_chk(v_in);
                if (v_in < 10)
                    return v_in;
                else if (v_in == 11)
                    printf(" cell is already filled\n");
                else
                    printf("enter a valid cell integer number  in range[1,9]");
            }
            else
                clearIN();
        }
        else
        {
            v_in = rand() % 10;
            v_in = gm_input_chk(v_in);
            if (v_in < 10)
                return v_in;
        }
    } while (1);
}
short unsigned int gm_input_chk(int v_in)
{
    if (v_in > 0 && v_in < 10)
    {
        v_in--;
        if (m[v_in] == ch0)
            return v_in;
        else
            return 11;
    }
    return 10;
}

int gm_status()
{
    // 0 is continue, 1 is pl1's win, 2 is pl 2's win, 3 is draw match'

    //center cell check
    if (m[4] != ch0)
    {
        if ((m[0] == m[4] && m[4] == m[8]) || (m[1] == m[4] && m[4] == m[7]) || (m[2] == m[4] && m[4] == m[6]) || (m[3] == m[4] && m[4] == m[5]))
        {
            if (m[4] == ch1)
                return 1;
            else if (m[4] == ch2)
                return 2;
        }
    }
    //first cell check
    if (m[0] != ch0)
    {
        if ((m[0] == m[1] && m[0] == m[2]) || (m[0] == m[3] && m[0] == m[6]))
        {
            if (m[0] == ch1)
                return 1;
            else if (m[0] == ch2)
                return 2;
        }
    }
    //last cell check
    if (m[8] != ch0)
    {
        if ((m[8] == m[7] && m[8] == m[6]) || (m[8] == m[5] && m[5] == m[2]))
        {
            if (m[8] == ch1)
                return 1;
            else if (m[8] == ch2)
                return 2;
        }
    }
    //check for draw
    for (short i = 0; i < 9; i++)
    {
        if (m[i] == ch0)
            return 0;
    }
    return 3;
}
void gm_result(int f_status)
{
    switch (f_status)
    {
    case 1:
        col_red();
        if (gm_mode != 1)
            printf("Player %d with %c won.. Better luck next time, player %d", pl1, ch1, pl2);
        else
            printf("You beat the computer");
        col_reset();
        break;
    case 2:
        col_blue();
        if (gm_mode != 1)
            printf("Player %d with %c won..\n Better luck next time, player %d", pl2, ch2, pl1);
        else
            printf("Computer wins. you try again.");
        col_reset();
        break;
    case 3:
        col_green();
        printf("You played well, but the match was draw\n Play again to decide the champion.");
        col_reset();
        break;
    }
    col_white();
    printf("\n\nHope you enjoyed the game, \nPlease write your feedback✍️ at pkaushal41119@gmail.com under subject \"Katttam-Kuttta in C\"");
    col_reset();
    keypress();
};
int play_again()
{
    //clearIN();
    system("CLS");
    col_cyan();
    printf("\n\nPlay again?? (y/n)\t");
    col_reset();
    if (nory() == 1)
    {
        col_purple();
        printf("Restarting..\n\n");
        col_reset();
        return 1;
    }
    return 0;
}

void keypress(void)
{
    clearIN();
    char nouse = getchar();
}
void clearIN(void)
{
    while (getchar() != '\n')
        ;
}
int nory(void)
{
    char ch;
    do
    {
        ch = getchar();
        if ((ch == 'y') || (ch == 'n') || (ch == 'Y') || (ch == 'N'))
            break;
    } while (1);
    if ((ch == 'y') || (ch == 'Y'))
    {
        return 1;
    }
    else
        return 0;
}

//Text colored
void col_reset(void)
{
    printf("\033[0m");
}
void col_black(void)
{
    printf("\033[1;30m");
}
void col_red(void)
{
    printf("\033[1;31m");
}
void col_green(void)
{
    printf("\033[1;32m");
}
void col_yellow(void)
{
    printf("\033[1;33m");
}
void col_blue(void)
{
    printf("\033[1;34m");
}
void col_purple(void)
{
    printf("\033[1;35m");
}
void col_cyan(void)
{
    printf("\033[1;36m");
}
void col_white(void)
{
    printf("\033[1;37m");
}