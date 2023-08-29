#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time(); // 디폴트 생성자 - 0시 0분으로 초기화
	Time(int, int); // 시간, 분으로 초기화하는 생성자
	Time(double); // 시간을 실수값으로 초기화하는 생성자
	Time(const Time &tr); // 복사 생성자
	Time plus(const Time &tr); // 두 객체의 시간을 더해서 리턴한다. (this 로 전달된 객체, tr 객체) 
	void setHour(int); // hour멤버의 값을 전달인자로 수정하는 함수
	int getHour(); // hour멤버의 값을 리턴하는 함수
	void setMin(int); // min 멤버의 값을 전달인자로 수정하는 함수
	int getMin(); // min 멤버의 값을 리턴하는 함수
};
/*--------------------------------------여기부터 작성--------------------------------------*/
Time::Time(void) // 디폴트 생성자 - 0시 0분으로 초기화
{
	this->hour = 0;
	this->min = 0;
}

Time::Time(int hour, int min) // 시간, 분으로 초기화하는 생성자
{
	this->hour = hour;
	this->min = min;
}

Time::Time(double double_time) // 시간을 실수값으로 초기화하는 생성자
{
	this->hour = (int)double_time;
	this->min = (int)((double_time - (double)this->hour) * 60.0);
}

Time::Time(const Time &tr) // 복사 생성자
{
	this->hour = tr.hour;
	this->min = tr.min;
}

Time Time::plus(const Time& tr) // 두 객체의 시간을 더해서 리턴한다. (this 로 전달된 객체, tr 객체)
{
	int subHour = this->hour + tr.hour;
	int subMin = this->min + tr.min;
	if (subMin >= 60) { // 두 분의 합이 60이 넘어가면 시간을 1시간 증가하고 분에서 60을 뺀다.
		subMin -= 60;
		subHour += 1;
	}
	Time subTime(subHour, subMin);
	return subTime;
}

void Time::setHour(int hour) // hour멤버의 값을 전달인자로 수정하는 함수
{
	this->hour = hour;
}

int Time::getHour() // hour멤버의 값을 리턴하는 함수
{
	return this->hour;
}

void Time::setMin(int min) // min 멤버의 값을 전달인자로 수정하는 함수
{
	this->min = min;
}

int Time::getMin() // min 멤버의 값을 리턴하는 함수
{
	return this->min;
}

/*--------------------------------------여기까지 작성--------------------------------------*/
int main()
{
	Time a(3, 20), b;
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl;
	return 0;

}