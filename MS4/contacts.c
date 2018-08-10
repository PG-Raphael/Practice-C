/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name)
{
	char option;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &option);
		if ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'))
			clear();
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition check
	//clear buffer if it is wrong
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
}
// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *address)
{
	char option;
	// Contact Address Input:
	do {
		printf("Please enter the contact's street number: ");
		scanf(" %d", &address->streetNumber);
		if (address->streetNumber < 0) {
			printf("Invalid Number!\n");
			clear();
		}
	} while (address->streetNumber < 0);
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter an apartment number? (y or n): ");
		scanf(" %c", &option);
		if ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'))
			clear();
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition check
	do {
		if (option == 'y' || option == 'Y') {
			printf("Please enter the contact's apartment number: ");
			scanf(" %d", &address->apartmentNumber);
		}
		if (address->apartmentNumber < 0) {
			printf("Invalid Number!\n");
			clear();
		}
	} while (address->apartmentNumber < 0);
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
}
// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbers)
{
	char option;
	// Contact Numbers Input:
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a cell phone number? (y or n): ");
		scanf(" %c", &option);
		if ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'))
			clear();
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", numbers->cell);
	}
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &option);
		if ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'))
			clear();
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", numbers->home);
	}
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &option);
		if ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'))
			clear();
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", numbers->business);
	}
}

void clear(void) {
	while (getchar() != '\n');
}