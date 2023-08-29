#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13 /* 주민등록번호 길이*/
int availabilityCheck(char* resident_number);
int checkLengthCharacter(char* resident_number);
int checkDate(char* resident_number);
int checkIdentification(char* resident_number);
int checkGender(char* resident_number);
int checkYear(int year);
int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
	"0003154194917", "801203#201122", "7804155328845", "7804150328840",
	"9612241068382", "9902292194322", "0230174326176", "8811391042219",
	"8100122042213", "8112002042213", "9210101069415", "0802294012345",
	"8806311069417","8807311069418" };
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i < count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s 는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s 는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availabilityCheck()함수: 주민등록번호 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효하면 TRUE, 유효하지 않으면 FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char* resident_number)
{
	typedef int(*func_t)(char*);
	func_t p[4] = { checkLengthCharacter, checkDate, checkGender, checkIdentification };
	for (int i = 0; i < 4; i++)
	{
		if (p[i](resident_number) == FALSE) return FALSE;
	}
	return TRUE;
}
/*-------------------------------------------------------------------------
checkLengthCharacter()함수: 주민등록번호 길이 및 문자 유효성검사 함수
전달인자: 검사할 주민등록번호(문자열)
리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면 TRUE,
길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면 FALSE 리턴
--------------------------------------------------------------------------*/
int checkLengthCharacter(char* resident_number)
{
	int count;
	count = 0;
	if (strlen(resident_number) > 13) return FALSE;
	else {
		for (int i = 0; i < 13; i++) {
			if (!(resident_number[i] >= '0' && resident_number[i] <= '9'))count++;
			else;
		}
		if (count == 0)return TRUE;
		else return FALSE;
	}
}
/*----------------------------------------------------------------
checkDate()함수: 첫 6 자리(연,월,일)의 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
*/
int checkDate(char* resident_number)
{
	int y, m = 0, d = 0, n, k = TRUE;
	if (resident_number[6] == '1' || resident_number[6] == '2') y = 1900;
	else y = 2000;
	y += (resident_number[0] - '0') * 10 + resident_number[1] - '0';
	m += (resident_number[2] - '0') * 10 + resident_number[3] - '0';
	d += (resident_number[4] - '0') * 10 + resident_number[5] - '0';
	n = checkYear(y);
	if (y < 1900 || m < 1 || d < 1 || m > 12) k = FALSE; // 음수 거르기
	switch (m) { // 월별 초과일수, 윤년시 2월 29일 거르기
	case 1: if (d > 31) k = FALSE; break;
	case 2:if (n == 1 && d > 29) k = FALSE;
		  else if (n == 0 && d > 28) k = FALSE; break;
	case 3:if (d > 31)k = FALSE; break;
	case 4:if (d > 30)k = FALSE; break;
	case 5:if (d > 31)k = FALSE; break;
	case 6:if (d > 30)k = FALSE; break;
	case 7:if (d > 31)k = FALSE; break;
	case 8:if (d > 31)k = FALSE; break;
	case 9:if (d > 30)k = FALSE; break;
	case 10:if (d > 31)k = FALSE; break;
	case 11:if (d > 30)k = FALSE; break;
	case 12:if (d > 31)k = FALSE; break;
	default: k = FALSE;
	}
	return k;
}

/*----------------------------------------------------------------------
checkGender()함수: 7 번째 자리의 성별식별번호 유효성 검사함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 성별식별번호가'1'~'4'이면 TRUE, 그 외 숫자 문자이면 FALSE 리턴
-----------------------------------------------------------------------*/
int checkIdentification(char* resident_number)
{
	int sum = 0;
	for (int i = 0; i < 12; i++)
		sum += resident_number[i] - '0';
	if (sum % 10 == resident_number[12] - '0') return TRUE;
	else return FALSE;
}

/*------------------------------------------------------------------------
checkIdentification()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면 TRUE, 유효하지 않은 날짜이면 FALSE 리턴
-------------------------------------------------------------------------*/
int checkGender(char* resident_number)
{
	if (resident_number[6] < '1' || resident_number[6]>'4') return FALSE;
	else return TRUE;
}

/*----------------------------------------------------------------
checkYear ()함수: 년도의 윤,평년 여부 검사
전달인자: 윤,평년 검사할 년도
리턴값: 윤년이면 TRUE, 평년이면 FALSE 리턴
------------------------------------------------------------------*/
int checkYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)return TRUE;
	else return FALSE;
}
