#pragma once
struct ILandAnimal 
{
	virtual ~ILandAnimal() {};
	virtual void creep()=0; // = ���������Լ�. ��ӹ޴� �Ļ�Ŭ�������� �ݵ�� overriding�� �ؾ� ��
};
