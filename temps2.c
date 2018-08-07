// Name: Sang Jun Park
// Student Number: 112293170
// Email: sjpark24@myseneca.ca
// Section: IPC144SXX
// Workshop: 4_at_home

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include<stdio.h>
int main()
{
	int dhigh[10];
	int dlow[10];
	int day;
	int i;
	int j;
	int highestTemp = -50;
	int lowestTemp = 50;
	int highestday;
	int lowestday;
	int question = 1;
	float sum[10];
	float aver = 0;
	float qusetionaver;


	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");
	while (day > 10 || day < 3)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}

	for (i = 0; i < day; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &dhigh[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &dlow[i]);
		while (dhigh[i] < dlow[i])
		{
			printf("Day %d - High: ", i + 1);
			scanf("%d", &dhigh[i]);
			printf("Day %d - Low: ", i + 1);
			scanf("%d", &dlow[i]);
		}
		if (dhigh[i] > highestTemp)
		{
			highestTemp = dhigh[i];
			highestday = i + 1;
		}
		if (dlow[i] < lowestTemp)
		{
			lowestTemp = dlow[i];
			lowestday = i + 1;
		}
		sum[i] = dhigh[i] + dlow[i];
	}

	printf("\nDay  Hi  Low\n");
	for (j = 0; j < day; j++)
	{
		printf("%d    %d    %d\n", j + 1, dhigh[j], dlow[j]);
	}
	printf("\nThe highest temperature was %d, on day %d\n", highestTemp, highestday);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestday);

	printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
	scanf("%d", &question);
	if (question > 0) {
		while (question > day)
		{
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", day);
			scanf("%d", &question);
		}
		for (i = 0; i < question; i++)
		{
			aver += sum[i] / 2;
			qusetionaver = aver / question;
		}printf("The average temperature up to day %d is: %0.2f\n", question, qusetionaver);
		aver = 0;
	}
	else
		printf("\nGoodbye!\n");
		while (question > 0) {
			printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
			scanf("%d", &question);
			printf("\n");
			if (question > 0) {
				while (question > day)
				{
					printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", day);
					scanf("%d", &question);
				}
				for (i = 0; i < question; i++)
				{
					aver += sum[i] / 2;
					qusetionaver = aver / question;				
				}printf("The average temperature up to day %d is: %0.2f\n", question, qusetionaver); 
				aver = 0;
			}
			else
			printf("Goodbye!\n");			
		}
		return 0;
}