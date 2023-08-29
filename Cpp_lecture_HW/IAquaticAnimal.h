#pragma once
struct IAquaticAnimal {
	virtual ~IAquaticAnimal() {}
	virtual void swim() = 0;  // 상속받는 파생클래스에서 반드시 overriding을 해야 함
	// 순수가상함수는 정의부가 없기 때문에 헤더파일에 소멸자 생성자정도만 만들어준다.
};
