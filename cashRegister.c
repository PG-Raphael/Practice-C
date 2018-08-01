/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	double money;
	int loonies;
	double remainder;
	int quaters;
	double i, j, m, k;
	double l;
	scanf("%lf", &money);
	printf("Please enter the amount to be paid: $%.2lf\n", money);

	loonies = money;
	printf("Loonies required: %d,", loonies);

	remainder = money - loonies;
	printf(" balance owing $%.2lf\n", remainder);

	quaters = remainder / 0.25;
	printf("Quarters required: %d,", quaters);
	i = remainder * 100;
	j = quaters * 25 ;
	m = i - j;
	k = m / 100;
	printf(" balance owing $%.2lf\n", k);
	
	
	
	
	return 0;
}
