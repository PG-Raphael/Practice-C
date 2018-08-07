/* -----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name name = { { 0 } };
	struct Address address = { 0, "", 0, "", ""};
	struct Numbers numbers = { { 0 } };
	char option;
	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");
	// Contact Name Input:

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name.firstName);
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &option);
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition check
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name.lastName);
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf(" %d", &address.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address.street);
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter an apartment number? (y or n): ");
		scanf(" %c", &option);
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition check
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf(" %d", &address.apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address.postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address.city);
	// Contact Numbers Input:
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a cell phone number? (y or n): ");
		scanf(" %c", &option);
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", numbers.cell);
	}
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &option);
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", numbers.home);
	}
	//loop if user prompt different value, it will ask repeatedly
	do {
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &option);
	} while ((option != 'y' && option != 'Y') && (option != 'n' && option != 'N'));
	//condition
	if (option == 'y' || option == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", numbers.business);
	}
	// Display Contact Summary Details
	// if the value of option != y || Y, these parts will not display
	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", name.firstName);
	if (option == 'y' || option == 'Y') {
		printf("Middle initial(s): %s\n", name.middleInitial);
	}
	printf("Last name: %s\n\n", name.lastName);

	printf("Address Details\n");
	printf("Street number: %d\n", address.streetNumber);
	printf("Street name: %s\n", address.street);
	if (option == 'y' || option == 'Y') {
		printf("Apartment: %d\n", address.apartmentNumber);
	}
	printf("Postal code: %s\n", address.postalCode);
	printf("City: %s\n\n", address.city);

	if (numbers.cell[0] != 0 || numbers.home[0] != 0 || numbers.business[0] != 0) {

		printf("Phone Numbers:\n");
		if (numbers.cell[0] != 0) {
			printf("Cell phone number: %s\n", numbers.cell);
		}
		if (numbers.home[0] != 0) {
			printf("Home phone number: %s\n", numbers.home);
		}
		if (numbers.business[0] != 0) {
			printf("Business phone number: %s\n\n", numbers.business);
		}
	}
	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");
	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/