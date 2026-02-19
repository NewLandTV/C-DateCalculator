#include <stdio.h>

typedef struct _Time
{
	int year;	// 년 
	int month;	// 월 
	int day;	// 일 
} Time;

int last_day[12] =
{
	31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
	
void ShowDate(Time t)
{
	printf("%d년 %d월 %d일\n", t.year, t.month, t.day);
}

Time AddDate(Time t1, Time t2)
{
	Time result =
	{
		t1.year + t2.year,
		t1.month + t2.month,
		t1.day + t2.day
	};
	
	return result;
}

int get_day(Time t)
{
	if (t.year % 4 == 0 && t.year % 100 != 0 || t.year % 400 == 0)
	{
		return 29;
	}
	
	return 28;
}

int check_input(Time t)
{	
	if (t.year < 0 || t.month < 0 || t.month > 12 || t.day < 0 || t.day > last_day[t.month - 1])
	{
		printf("잘못된 입력\n");
		
		return 0;
	}
	
	return 1;
}

int main()
{	
	Time time1;
	Time time2;
	Time calculate_date;

	printf("날짜를 입력하세요 (yyyy mm dd) : ");
	scanf("%d %d %d", &time1.year, &time1.month, &time1.day);
	
	last_day[1] = get_day(time1);
	
	if (!check_input(time1))
	{
		return -1;
	}
	
	printf("더할 날짜를 입력하세요 (yyyy mm dd) : ");
	scanf("%d %d %d", &time2.year, &time2.month, &time2.day);
	
	last_day[1] = get_day(time2);
	
	if (!check_input(time2))
	{
		return -1;
	}
	
	ShowDate(time1);
	
	calculate_date = AddDate(time1, time2);
	
	ShowDate(calculate_date);
	
	return 0;
}
