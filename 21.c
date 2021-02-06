#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void give_card(int* sum)
{
	char cards[13] = { '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };

	int mast = rand() % 4;

	int x = rand() % 13;
	if (x == 8)
	{
		printf("10 ");

		*sum += 10;
	}
	else if(x < 8)
	{
		printf("%c ", cards[x]);

		*sum += cards[x] - '0';
	}
	else if(x == 12)
	{
		printf("%c ", cards[x]);

		if (sum < 11)
		{
			*sum += 11;
		}

		else
		{
			*sum += 1;
		}
	}
	else 
	{
		printf("%c ", cards[x]);

		*sum += 10;
	}

	switch (mast)
	{
	case 0:
		printf("Boobi\n");
		break;

	case 1:
		printf("Kresti\n");
		break;

	case 2:
		printf("Piki\n");
		break;

	case 3:
		printf("Chervi\n");
		break;
	}
}

int main()
{
	int cash = 100;

	int input;

	int sum = 0;

	int bet;

	int sum_dealer = 0;

	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));

		sum = 0;

		sum_dealer = 0;

		printf("\nEnter 1 to play, enter 2 to show your cash, 3 to exit\n");
		scanf("%d", &input);

		if (input == 3) break;

		if (input == 2)
		{
			printf("\nYou have %d$\n", cash);

			continue;
		}

		printf("\nEnter your bet\n");
		scanf("%d", &bet);

		if (bet > cash)
		{
			printf("\nError! You don't have so much money\n");
			
			continue;
		}

		cash -= bet;

		printf("\nYour 2 cards:\n\n");

		give_card(&sum);
		give_card(&sum);

		printf("Right now summ is %d\n", sum);

		for (int j = 0; j < 20; j++)
		{
			printf("\nEnter 1 to take another one, enter 2 to stop\n");
			scanf("%d", &input);

			if (input == 1)
			{
				give_card(&sum);

				printf("Right now summ is %d\n", sum);

				if (sum > 21)
				{
					printf("This is to much\n");

					break;
				}
			}
			else break;
		}

		if (sum <= 21)
		{
			printf("\nDealer's turn\n\n");

			printf("Dealer's 2 cards:\n");

			give_card(&sum_dealer);
			give_card(&sum_dealer);

			printf("Right now dealer's summ is %d\n\n", sum_dealer);

			while (sum_dealer < 17)
			{
				give_card(&sum_dealer);

				printf("Right now dealer's summ is %d\n\n", sum_dealer);

				if (sum_dealer > 21) break;
			}

			if ( (sum > sum_dealer) || (sum_dealer > 21) )
			{
				printf("\nYou win!!!\n");

				cash += bet * 2;
			}
			else if (sum == sum_dealer)
			{
				printf("\nDraw\n");

				cash += bet;
			}
			else
			{
				printf("\nYou lose...\n");
			}
		}
		else
		{
			printf("\nYou lose...\n");
		}
	}

	printf("\nEbany rot etogo kazino BLYAT");
	
	return 0;
}
