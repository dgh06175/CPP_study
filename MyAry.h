#pragma once
class MyArray
{
private:
	int* ary;
	int size;
public:
	MyArray() { ary = 0; size = 0; }		// ����Ʈ ������
	MyArray(int s);							// �����ε�� ������, ũŰs�� �迭�� �����Ҵ��Ѵ�.
	MyArray(const MyArray& br);				// ���� ������
	~MyArray() { delete[] ary; }			// �Ҹ���
	MyArray& operator = (const MyArray& br);// ���Կ�����
	bool put(int index, int val);			// val�� ���� index�濡 ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
	bool get(int index, int& getdata);		// �迭��� �� index���� ���� getdata�� ����.
											// ������true, ���н� false ��ȯ(ũ�⸦ �����)
	int getSize();							// �迭����� ���� Ȯ��
	int* getAry(void);						// �迭����� ���� Ȯ��
};