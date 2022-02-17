#include "MyString.h"
using namespace std;
#pragma warning(disable:4996)

// MyString.cpp 파일만 작성함

MyString::MyString()
{
	this->str = new char[strlen("") + 1];
	strcpy(this->str, "");
	this->len = 0;
}

MyString::MyString(const char *cp)
{
	this->str = new char[strlen(cp) + 1];
	strcpy(this->str, cp);
	this->len = strlen(cp);
}

MyString::MyString(const MyString& br)
{
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
}

MyString::~MyString()
{
	delete[] this->str;
}

MyString& MyString::operator=(const MyString& br)
{
	if (this == &br)return *this;
	delete[] this->str;
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
	return *this;
}

MyString MyString::operator+(const MyString& br)
{
	char* sumStr = new char[40];
	strcpy(sumStr,this->str);
	strcat(sumStr, br.str);
	MyString sumMyString(sumStr);
	delete[] sumStr;
	return sumMyString;
}

bool MyString::operator>(const MyString& br)
{
	if (this->len > br.len) {
		return true;
	}
	else {
		return false;
	}
}

void MyString::operator<<(ostream& os)
{
	os << this->str << '(' << this->len << ')';
}

void MyString::operator>>(istream& is)
{
	this->str = new char[21];
	is >> this->str;
	this->len = strlen(this->str);
}

ostream& operator<<(ostream& os, MyString& br)
{
	br << os;
	return os;
}

istream& operator>>(istream& is, MyString& br)
{
	br >> is;
	return is;
}