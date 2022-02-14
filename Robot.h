#pragma once
// Robot.h는 주어짐
class Robot
{
private:
	char* name;  // 실제 이름 공간은 동적할당해서 붙여서 사용 : 사용자 정의 생성자, 소멸자에서 메모리 할당, 해제
	int energy;
	void errPrn(); // 에너지 부족- 에러메시지 출력, go~jump 행동함수들이 사용하는 멤버함수
public:
	Robot();  // name은 Null string으로, energy는 0으로 초기화
	~Robot();
	Robot(const char* name, int energy = 0);
	Robot(const Robot& r);  // 복사생성자 deep copy constructor
	void go();              // 전진 메시지 출력 후 에너지 10 감소
	void back();            // 후진 메시지 출력 후 에너지 20 감소
	void turn();             // 턴 메시지 출력 후 에너지 30 감소
	void jump();            // 점프 메시지 출력 후 에너지 40 감소
	void charge(int e);      // e값 만큼 충전 (전달인자가 음수일 경우 에너지값 유지)
	char* getName();       // name멤버의 값 리턴
	void setName(const char*);   // name멤버의 값을 전달된 문자열로 재 초기화 (깊은복사)
	int getEnergy();         // energy멤버의 값 리턴  
	void setEnergy(int);     // energy멤버의 값을 전달된 숫자로 재 초기화(전달인자가 음수일때는 0으로 초기화 
};
