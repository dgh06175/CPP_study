#include <iostream>
#include "ram.h"
using namespace std;

// char mem[100 * 1024]; // 100KB 메모리
// int size;

Ram::Ram()
{
    int SIZE = 100 * 1024;
    memset(mem, 0, SIZE);
}; // mem을 0으로 초기화하고 size를 100*1024로 초기화

Ram::~Ram()
{
    cout << "메모리 제거됨" << endl;
} // "메모리 제거됨" 문자열 출력

char Ram::read(int address) // address 주소의 메모리를 읽어 리턴
{
    return mem[address];
}

void Ram::write(int address, char value)
{ // address 주소에 value 저장
    mem[address] = value;
}
// 주소가 범위를 벗어나는 오류 발생하면 에러메시지 출력함.
