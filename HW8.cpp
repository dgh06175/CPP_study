#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time(); // ����Ʈ ������ - 0�� 0������ �ʱ�ȭ
	Time(int, int); // �ð�, ������ �ʱ�ȭ�ϴ� ������
	Time(double); // �ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
	Time(const Time &tr); // ���� ������
	Time plus(const Time &tr); // �� ��ü�� �ð��� ���ؼ� �����Ѵ�. (this �� ���޵� ��ü, tr ��ü) 
	void setHour(int); // hour����� ���� �������ڷ� �����ϴ� �Լ�
	int getHour(); // hour����� ���� �����ϴ� �Լ�
	void setMin(int); // min ����� ���� �������ڷ� �����ϴ� �Լ�
	int getMin(); // min ����� ���� �����ϴ� �Լ�
};
/*--------------------------------------������� �ۼ�--------------------------------------*/
Time::Time(void) // ����Ʈ ������ - 0�� 0������ �ʱ�ȭ
{
	this->hour = 0;
	this->min = 0;
}

Time::Time(int hour, int min) // �ð�, ������ �ʱ�ȭ�ϴ� ������
{
	this->hour = hour;
	this->min = min;
}

Time::Time(double double_time) // �ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
{
	this->hour = (int)double_time;
	this->min = (int)((double_time - (double)this->hour) * 60.0);
}

Time::Time(const Time &tr) // ���� ������
{
	this->hour = tr.hour;
	this->min = tr.min;
}

Time Time::plus(const Time& tr) // �� ��ü�� �ð��� ���ؼ� �����Ѵ�. (this �� ���޵� ��ü, tr ��ü)
{
	int subHour = this->hour + tr.hour;
	int subMin = this->min + tr.min;
	if (subMin >= 60) { // �� ���� ���� 60�� �Ѿ�� �ð��� 1�ð� �����ϰ� �п��� 60�� ����.
		subMin -= 60;
		subHour += 1;
	}
	Time subTime(subHour, subMin);
	return subTime;
}

void Time::setHour(int hour) // hour����� ���� �������ڷ� �����ϴ� �Լ�
{
	this->hour = hour;
}

int Time::getHour() // hour����� ���� �����ϴ� �Լ�
{
	return this->hour;
}

void Time::setMin(int min) // min ����� ���� �������ڷ� �����ϴ� �Լ�
{
	this->min = min;
}

int Time::getMin() // min ����� ���� �����ϴ� �Լ�
{
	return this->min;
}

/*--------------------------------------������� �ۼ�--------------------------------------*/
int main()
{
	Time a(3, 20), b;
	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð�" << res.getMin() << "��" << endl;
	return 0;

}