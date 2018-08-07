/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4
//declare struct
struct Employee {
	int id;
	int age;
	double salary;
};
int main() {
	//declare integers
	int option = 0;
	int i, employID;
	int empCount = 0;
	int flag = 0;
	//initializing struct array is 0
	struct Employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");
	// loop until user input 0
	do {
		printf("1. Dispaly Employee Information\n"
			"2. Add Employee\n"
			"3. Update Employee Salary\n"
			"4. Remove Employee\n"
			"0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
			//when user input 1, the outcome will display
		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0)
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;
			//when user input 2, user prompt the information of empoyees
		case 2:
			flag = 0;
			printf("Adding Employee\n");
			printf("===============\n");
			//check condition the total of employees must be less than the SIZE 
			if (empCount < SIZE) {
				//if condition is true, the code will execute for loop
				for (i = 0; i < SIZE&&flag == 0; i++) {
					if (emp[i].id == 0) {
						printf("Enter Employee ID: ");
						scanf(" %d", &emp[i].id);
						printf("Enter Employee Age: ");
						scanf(" %d", &emp[i].age);
						printf("Enter Employee Salary: ");
						scanf(" %lf", &emp[i].salary);
						printf("\n");
						//add total when
						empCount++;
						flag = 1;
					}
				}
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			break;
		case 3:
			flag = 0;
			printf("Update Employee Information\n");
			printf("===========================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &employID);
				for (i = 0; i < SIZE&&flag == 0; i++) {
					if (employID == emp[i].id) {
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						printf("\n\n");
						flag = 1;
					}
				}
			} while (flag == 0);
			break;
		case 4:
			flag = 0;
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &employID);
				for (i = 0; i < SIZE&&flag == 0; i++) {
					if (employID == emp[i].id) {
						printf("Employee %d will be removed\n\n", employID);
						emp[i].id = 0;
						empCount--;
						flag = 1;
					}
				}
			} while (flag == 0);
			break;
		default:
			printf("ERROR: Incorrect option: Try Again\n\n");
		}
	} while (option != 0);
	return 0;
}