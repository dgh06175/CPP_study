#include <iostream>
using namespace std;
#pragma warning(disable:4996)


class San {
private:
	char* name; // ��� ������, �Ҹ���, ���Կ����� �Լ� ���� �ۼ��ؾ���
	int height;
public:
	San();
	San(const char*, int);
	San(const San& r);
	~San();

	San& operator = (const San&);

	void setName(char*);
	char* getName();
	void setHeight(int);
	int getHeight();
};
/*--------------------------------������� �ۼ�--------------------------------*/

San::San()
{
	this->name = new char[strlen("�̸�����") + 1];
	strcpy(this->name, "�̸�����");
	this->height = 0;
}

San::San(const char* pname, int pheight)
{
	this->name = new char[strlen(pname) + 1];
	strcpy(this->name, pname);
	this->height = pheight;
}

San::San(const San& r)
{
	this->name = new char[strlen(r.name)+1];
	strcpy(this->name, r.name);
	this->height = r.height;
}

San::~San()
{
	delete[] name;
}

San& San:: operator = (const San& a) // ���Կ����� �Լ�
{
	if (this == &a)return *this;
	delete[] name;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->height = a.height;
	return *this;
}

void San::setName(char* pname)
{
	this->name = new char[sizeof(pname) + 1];
	strcpy(this->name, pname);
}

char* San::getName()
{
	return this->name;
}

void San::setHeight(int pheight)
{
	this->height = pheight;
}

int San::getHeight()
{
	return this->height;
}

/*--------------------------------������� �ۼ�--------------------------------*/
int main()
{
	char str[100];
	San a("����", 629);
	San b = a; // San b; b=a; (���Կ����� �Լ�) �̰͵� �۵��ؾ���.

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	cout << "���ο� ���̸��� �Է� �Ͻÿ� : " << endl;
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	return 0;
}