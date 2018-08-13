/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
	int answer;
	//start to prmopt input from users
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	//clear the buffer to prompt option yes or no and protect to input over letters
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	//saving yes function value
	answer = yes();
	//condition check if answer is y or Y
	if (answer == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
	}
	//if answer is 'n' or 'N' making array empty
	if (answer == 0) {
		name->middleInitial[0] = '\0';
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	//clear the buffer to protect to input over letters
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address *address)
{
	int answer;

	// Contact Address Input:
	printf("Please enter the contact's street number: ");

	do {
		address->streetNumber = getInt();
		if (address->streetNumber < 1) {
			address->streetNumber = getInt();
		}
	} while (address->streetNumber < 1);
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	//clear the buffer to protect to input over letters
	clearKeyboard();
	//ask apartment numbers
	printf("Do you want to enter an apartment number? (y or n): ");

	//saving yes function value
	answer = yes();
	//condition check if answer is y or Y
	if (answer == 1) {
		printf("Please enter the contact's apartment number: ");
		// do get integer value to store aparmentNumber
		do {
			address->apartmentNumber = getInt();
			//if the value is less than 1 redo it
			if (address->apartmentNumber < 1) {
				address->apartmentNumber = getInt();
			}
		} while (address->apartmentNumber < 1);
	}
	//if answer is 'n' or 'N' making array empty
	if (answer == 0) {
		address->apartmentNumber = 0;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	//clear the buffer to protect to input over letters
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	//clear the buffer to protect to input over letters
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbers)
{
	int answer;
	// Contact Numbers Input:
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");

	//saving yes function value
	answer = yes();
	//condition check if answer is y or Y
	if (answer == 1) {
		printf("Please enter the contact's home phone number: ");
		//input NO. has to be 10 digits
		getTenDigitPhone(numbers->home);
	}
	//if answer is 'n' or 'N' making array empty
	if (answer == 0) {
		numbers->home[0] = '\0';
	}
	printf("Do you want to enter a business phone number? (y or n): ");

	//saving yes function value
	answer = yes();
	//condition check if answer is y or Y
	if (answer == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	//if answer is 'n' or 'N' making array empty
	if (answer == 0) {
		numbers->business[0] = '\0';
	}

}

// getContact:
void getContact(struct Contact *contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
