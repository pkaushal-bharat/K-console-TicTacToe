#include <stdio.h>
/* Hello, I am Prakash K. This is my C game project.
First, I would like to thank Shashi and Rajnandini 
for their goodwill and genuine help for this project.
 I thank my friends for motivating and trying out this game.
 Finally, I am grateful for the feedback and contribution for
making this game better over time. 

Project: Katttam-kuttta® in C
Github: pkaushal-bharat
Description: TicTacToe like game in C which you can run without graphics.h
Repo link: https://github.com/pkaushal-bharat/C-Projects-by-K/
Time-spent: 2 Days
Version: १.०
Last updated: Monday, 23 August 2021
*/
void intro();
int start_gm();
void about();

void game();
    void ref_gm();
    void play_gm();
        void reset_m();
        void show_mat(int,int);
        short unsigned int gm_input();
        int gm_status();
        void gm_result(int);
    int play_again();

void keypress(void);
void clearIN(void);
int nory(void);

char m[9];
const char ch0 = '_', ch1 = 'X', ch2 = 'O'; //choices
int main()
{
	intro();
	if (start_gm() == 1)
		game();
	return 0;
}
void intro()
{
	printf("Welcome to Katttam-kuttta® v1.0\nby Prakash K");
    printf("\n(Press 3 for more info)\n");
}
int start_gm()
{
	printf("\nKhelega Katttam-kuttta?\n");
	printf("Enter 0 for No and 1 for Yes\n");
	int start_ttt = 0;
	scanf("%d", &start_ttt);
	if (start_ttt != 0)
	{
		if (start_ttt == 3)
			about();
		return 1;
	}
	else
		return 0;
}
void about()
{
	printf("/*Hello, I am Prakash K. This is my C game project.\nFirst, I would like to thank my friends for motivation for this project.\nFinally, I am grateful for your feedback and contribution for\nmaking this game better over time. \n\n\nProject: Katttam-kuttta® in C \nDescription: TicTacToe like game in C which you can run everywhere \nTime-spent: 2 Days\nVersion: 1.0(१.०)\nLast updated: Monday, 23 August 2021\n*/");
    keypress();
}
void game()
{
	do{
		ref_gm();
		play_gm();
	}while(play_again()==1);
    {
		printf("\nThank you for playing. Please share your suggestions💭 to the developer by mail....\n");
		printf("\nGet the latest version of Katttam-kuttta® from my Github repo🙂");
    }
	printf("\nThe END");
}
void ref_gm()
{
	printf("In each player's turn, to select a cell using the numeric pad\n");
	printf(" The reference for keys are as follows:\n");
	printf(" ------------\n");
	printf("| 7 | 8 | 9 |\n");
	printf(" -----------\n");
	printf("| 4 | 5 | 6 |\n");
	printf(" -----------\n");
	printf("| 1 | 2 | 3 |\n");
	printf(" -----------\n");

	printf("\n\n Hope u understood the input method\n");
	printf("Press any key to continue....");
	keypress();
	//clearIN();
	//system("CLS");
}
void play_gm()
{
	unsigned short int pl1 = 1, pl2 = 2, cell = 0;//players and the current cell box
	unsigned short int gm_round = 1, pl_turn = 1, status = 0; //game round and turns
	reset_m();
	do
	{
		show_mat(gm_round, pl_turn);
		cell = gm_input(); // cell on which we have to operate
		gm_round++;
		if (pl_turn == pl1)
		{
			m[cell] = ch1;
			pl_turn=pl2;
		}
		else if (pl_turn == pl2)
		{
			m[cell] = ch2;
			pl_turn=pl1;
		}
		status = gm_status();
	} while (status == 0);
    show_mat(0,0);
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
	if (round != 0)
	{
		printf("Round: %i", round);
		printf("\t & \t");
		printf("Player %i\'s turn", turn);
	}
	printf("\n");
	printf("The board looks as :\n");
	printf(" -----------\n");
	printf("| %c | %c | %c |\n", m[6], m[7], m[8]);
	printf(" -----------\n");
	printf("| %c | %c | %c |\n", m[3], m[4], m[5]);
	printf(" -----------\n");
	printf("| %c | %c | %c |\n", m[0], m[1], m[2]);
	printf(" -----------\n");
}
short unsigned int gm_input()
{
	short unsigned int v_in = 0; // only accept valid input
	do
	{
		if (scanf(" %hu", &v_in) == 1)
		{
			if (v_in > 0 && v_in < 10)
			{
				v_in--;
				if (m[v_in] == ch0)
					return v_in;
				else
					printf(" cell %d is already filled\n", ++v_in);
			}
			else
				printf("enter a valid cell integer number  in range[1,9]");
		}
		else
			clearIN();
	} while (1);
}
int gm_status()
{
	// 0 is continue, 1 is player1's win, 2 is player 2's win, 3 is draw match'

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
		printf("Player 1 with %c won.. Better luck next time, player2", ch1);
		break;
	case 2:
		printf("Player 2 with %c won..\n Better luck next time, player1", ch2);
		break;
	case 3:
		printf("You played well, but the match was draw\n Play again to decide the champion.");
		break;
	}
	printf("\n\nHope you enjoyed the game, \nPlease write your feedback✍️ at pkaushal41119@gmail.com under subject \"Katttam-Kuttta in C\"");
	keypress();
};
int play_again()
{
	//clearIN();
	system("CLS");
	printf("\n\nPlay again?? (y/n)\t");
	if (nory()==1)
	{
		printf("Restarting..\n\n");
		return 1;
	}
	return 0;
}

void keypress(void){
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