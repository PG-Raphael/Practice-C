/*-----------------------------------------------------------------------
Name : Seungmin Yun
Student No. :010820132
Section: IPC144SJJ
----------------------------------------------------------------------*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double money, gst, gst1, change, change1, change2, change3, change4; //declare

	int z, quarter, loonie, dime, nickel, penny;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &money); //input money

	gst = money * .13 + .005;
	gst1 = gst * 100;
	printf("GST: %.2lf\n", (double)gst1 / 100); //output of gst's value

	printf("Balance owing: $%.2lf\n", money + gst1 / 100); //total money

	loonie = money + gst1 / 100;
	change = money + gst1 / 100 - loonie;

	printf("Loonies required: %d, balance owing $%.2lf\n", loonie, change); // output of loonies and change

	z = change * 100;
	quarter = z / 25;
	change1 = z - quarter * 25;

	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, change1 / 100); // output of quarters and change

	dime = change1 / 10;
	printf("Dimes required: %d", dime); // output of dimes

	change2 = change1 - dime * 10;

	if (dime == 0) //rest of money - dimes
		printf(", balance owing $%.2lf\n", change1 / 100);
	else
		printf(", balance owing $%.2lf\n", change2 / 100);

	nickel = change2 / 5;
	printf("Nickels required: %d", nickel); //output of nickels

	change3 = change2 - nickel * 5;
	if (nickel == 0) //remaining balance - nickels
		printf(", balance owing $%.2lf\n", change2 / 100);
	else
		printf(", balance owing $%.2lf\n", change3 / 100);

	penny = change3 / 1;
	printf("Pennies required: %d", penny); //oupput of pennies

	change4 = change3 - penny;
	printf(", balance owing $%.2lf\n", change4 / 100);  //remaining balance = 0

	return 0;
}