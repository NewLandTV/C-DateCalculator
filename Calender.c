#include <stdio.h>

// Function Prototype
int GetDay(int year, int month);
int GetDayOfMonth(int year, int month);
int IsLeafYear(int year);
void PrintCalender(int startDay, int dayNumber);

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		int year = atoi(argv[1]);
		int month = atoi(argv[2]);
		int startDay = GetDay(year, month);
		int dayNumber = GetDayOfMonth(year, month);
		
		PrintCalender(startDay, dayNumber);
	}
	
	return 0;
}

int GetDay(int year, int month)
{
	int y;
	int m;
	int past = 0;
	
	for (y = 1; y < year; y++)
	{
		past += 365 + IsLeafYear(y);
	}
	
	for (m = 1; m < month; m++)
	{
		past += GetDayOfMonth(year, m);
	}
	
	return (past + 1) % 7;
}

int GetDayOfMonth(int year, int month)
{
	int dayOfMonth[13] =
	{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	
	dayOfMonth[2] += IsLeafYear(year);
	
	return dayOfMonth[month];
}

int IsLeafYear(int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	
	if ((year % 100 != 0) && (year % 4 == 0))
	{
		return 1;
	}
	
	return 0;
}

void PrintCalender(int startDay, int dayNumber)
{
	int i;
	int j;
	int day;
	
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	
	for (i = 0; i < startDay; i++)
	{
		printf("    ");
	}
	
	for (day = 1, j = startDay; day <= dayNumber; day++, j++)
	{
		printf("%4d", day);
		
		if (j % 7 == 6)
		{
			printf("\n");
		}
	}
}
