/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
#include <stdio.h>

int main(void)
{
	//declare
	int hightemp;
	int lowtemp;
	int max_temp = 0 , min_temp = 0 ;
	int max_day = 0, min_day = 0;
	int  i;
	float average = 0;


	printf("---=== IPC Temperature Analyzer ===---\n");

	//for loop to repeat sequence
	for (i = 0; i < NUMS; i++)
	{
		printf("Enter the high value for day %d: ", i + 1);//print with the value of i + 1
		scanf(" %d", &hightemp); //input the highest temperature
		printf("\n");
		printf("Enter the low value for day %d: ", i + 1);//print with the value of i + 1
		scanf(" %d", &lowtemp); // input the lowest temperature
		printf("\n");

		//condition which is false
		while (hightemp > 40 || lowtemp < -40 || hightemp < lowtemp ? 1 : 0)
		{

			printf("Incorrect values, temperatures must be in the range - 40 to 40, high must be greater than"
				"low.\n");


			printf("Enter the high value for day %d: ", i + 1);//print with the value of i + 1
			scanf(" %d", &hightemp); //input the highest temperature
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);//print with the value of i + 1
			scanf(" %d", &lowtemp); // input the lowest temperature
			printf("\n");
			
		}
		//save the highest value
			if (max_temp < hightemp) {

				max_temp = hightemp;
				max_day = i + 1 ;
			}
			//save the lowest value
			if (min_temp > lowtemp) {

				min_temp = lowtemp;
				min_day = i + 1 ;
			}
			
			average += (hightemp + lowtemp); //total value

		
	}
	
		average = average / (NUMS * 2);
		printf("The average (mean) temperature was: %1.2f\n", average);
		printf("The highest temperature was %d, on day %d\n", max_temp, max_day );
		printf("The lowest temperature was %d, on day %d\n", min_temp, min_day );
		

	return 0;
}