/*
 * 작성자 : 장경혁 
 * 설명 : 입력 받은 일(Day)를 YYYY년 MM월 DD일 로 계산하는 프로그램
 */

#include <stdio.h>
#include <stdlib.h>

void Day(int day)
{
	printf("%d일 ", day);
}

void Week(int day)
{
	int W, D;
	
	W = day / 7;
	D = day % 7;
	
	printf("%d주 ", W);
	
	if(D > 0)
	{
		printf("%d일 ", D);
	}
}

void Month(int day)
{
	int temp;
	int M, W, D;
	
	M = day / 30;
	temp = day % 30;    //temp = 월을 제외한 수
	W = temp / 7;     // 몇 주인지.
	D = temp % 7;    // 몇 일인지.
	
	printf("%d월 ", M);
	
	if(W > 0)
	{
		printf("%d주 ", W);
	}
	if(D > 0)
	{
		printf("%d일 ", D);
	}
}

void Year(int day)
{
	int temp, temp1;
	int Y, M, W, D;
	
	Y = day / 360;
	temp = day % 360;    //temp = 년 을 제외한 수
	M = temp / 30;    // 몇 개월인지.
	temp1 = temp % 30;   //주를 구하기 위한 임시변수
	W = temp1 / 7;
	D = temp1 % 7;
	
	printf("%d년 ", Y);
	
	if(M > 0)
	{
		printf("%d월 ", M);
	}
	if(W > 0)
	{
		printf("%d주 ", W);
	}
	if(D > 0)
	{
		printf("%d일", D);
	}
}

int main()
{
	int day;
	
	printf(" 날짜를 입력하세요. >> ");
	scanf("%d", &day);
	
	if(day <= 0)
	{
		printf("0 혹은 음수를 입력하여 종료합니다.");
		
		return 0;
	}
	
	printf("*******************************************\n");
	printf("일수 : %d\n", day);
	printf("%d일 --->> ", day);
	
	if(day < 7)
	{
		Day(day);	//day 크기를 고려하여 함수 호출.
	}
	else if(day < 30)
	{
		Week(day);
	}
	else if(day < 360)
	{
		Month(day);
	}
	else if(day >= 360)
	{
		Year(day);
	}
	
	printf("\n*******************************************\n");
	
	return 0;
}
