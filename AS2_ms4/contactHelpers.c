/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include "string.h"

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt:
int getInt(void)
{
	int input;
	char tmp;

	scanf("%d%c", &input, &tmp);
	if (tmp != '\n') {
		do {
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
			scanf("%d%c", &input, &tmp);
		} while (tmp != '\n');
	}
	return input;
}


// getIntInRange:
int getIntInRange(int min, int max) {
	int input;
	do {
		input = getInt();
		if (input < min || input > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (input < min || input > max);

	return input;
}


// yes:
int yes(void) {
	char option;
	char tmp;
	int answer = 3;
	do {
		scanf(" %c%c", &option, &tmp);
		if (tmp == '\n') {

			if (option == 'y' || option == 'Y') {
				answer = 1;
			}
			else if (option == 'n' || option == 'N') {
				answer = 0;
			}
			else {
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			}
		}
		else {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	} while (answer != 1 && answer != 0);
	return answer;
}


// menu:
int menu(void) {

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);

}


// ContactManagerSystem:
void ContactManagerSystem(void) {
	int option;
	int exit = 99;
	struct Contact contact[MAXCONTACTS] = { { { "Rick",{'\0'}, "Grimes" },{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },{ "4161112222", "4162223333", "4163334444" } },
	{ { "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9051112222", "9052223333", "9053334444" } },
	{ { "Morgan", "A.", "Jones" },{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },{ "7051112222", "7052223333", "7053334444" } },
	{ { "Sasha",{'\0'}, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };
	do {
		option = menu();
		printf("\n");
		switch (option) {

		case 1: displayContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 2: addContact(contact, MAXCONTACTS);
			pause();
			break;
		case 3: updateContact(contact, MAXCONTACTS);
			pause();
			break;
		case 4: deleteContact(contact, MAXCONTACTS);
			pause();
			break;
		case 5: searchContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 6: sortContacts(contact, MAXCONTACTS);
			pause();
			break;
		case 0:   printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			if (exit == 1) {
				printf("\nContact Management System: terminated");
			}
			break;
		}
		printf("\n");

	} while (exit != 1);

}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0;
	int j = -1;
	int flag = 0;
	for (i = 0; i < size && flag == 0; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			j = i;
			flag = 1;
		}
	}
	return j;
}


// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
void displayContactFooter(int footer) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", footer);

}


// displayContact:
void displayContact(const struct Contact *displayOne) {
	printf(" %s", displayOne->name.firstName);
	if (displayOne->name.middleInitial[0] != '\0')
	{
		printf(" %s", displayOne->name.middleInitial);
	}
	printf(" %s\n", displayOne->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", displayOne->numbers.cell, displayOne->numbers.home, displayOne->numbers.business);
	printf("       %d %s,", displayOne->address.streetNumber, displayOne->address.street);
	if (displayOne->address.apartmentNumber > 0)
	{
		printf(" Apt# %d,", displayOne->address.apartmentNumber);
	}
	printf(" %s, %s\n", displayOne->address.city, displayOne->address.postalCode);
}



// displayContacts:
void displayContacts(const struct Contact display[], int num) {
	int i;
	int j = 0;
	displayContactHeader();
	for (i = 0; i < num; i++) {
		if (display[i].numbers.cell[0] > 0) {
			displayContact(&display[i]);
			j++;
		}
	}
	displayContactFooter(j);
}




// searchContacts:
void searchContacts(const struct Contact search[], int num) {
	int i;
	char cell[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell);
	printf("\n");
	i = findContactIndex(search, num, cell);
	if (i != -1)
	{
		displayContact(&search[i]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

}


// addContact:
void addContact(struct Contact contact[], int num) {
	int i;
	int j = 0;
	int flag = 0;

	for (i = 0; i < num && flag == 0; i++)
	{
		if (strlen(contact[i].numbers.cell) == 0)
		{
			j++;
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			flag = 1;
		}
	}
	if (j == 0)
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
}


// updateContact:
void updateContact(struct Contact contactsUpdate[], int num) {
	int i;
	char cell[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell);
	i = findContactIndex(contactsUpdate, num, cell);
	if (i == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contactsUpdate[i]);
		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1)
		{
			getName(&contactsUpdate[i].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
		{
			getAddress(&contactsUpdate[i].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
		{
			getNumbers(&contactsUpdate[i].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}

}


// deleteContact:
void deleteContact(struct Contact contactsDelete[], int num) {
	int i;
	char cell[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell);
	printf("\n");
	i = findContactIndex(contactsDelete, num, cell);
	if (i == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("Contact found:\n");
		displayContact(&contactsDelete[i]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{
			contactsDelete[i].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}

}


// sortContacts:
void sortContacts(struct Contact contactsSort[], int num) {
	int i, j;
	struct Contact temp;


	for (i = 0; i < num; i++)
	{
		/*
		* Place currently selected element array[i]
		* to its correct place.
		*/
		for (j = i + 1; j < num; j++)
		{

			//compare each elements and if first string is greater than second one it wll not replace it, otherwise replace.
			if (strcmp(contactsSort[i].numbers.cell, contactsSort[j].numbers.cell) > 0)
			{
				temp = contactsSort[i];
				contactsSort[i] = contactsSort[j];
				contactsSort[j] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}
