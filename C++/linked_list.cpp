#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	Singlist list;
	HeadNode* L;
	L = list.createList();

	cout << "1. 빈 연결 리스트를 생성했습니다." << endl << endl;

	int data1, data2, data3;
	cout << "2. 연결 리스트에 추가할 노드의 데이터를 3개 정해주세요: ";
	cin >> data1 >> data2 >> data3;
	list.addNode(L, data1);
	list.printList(L);
	list.addNode(L, data2);
	list.printList(L);
	list.addNode(L, data3);
	list.printList(L);
	cout << endl;

	cout << "3. 탐색할 노드의 데이터를 정해주세요 : ";
	int data4;
	cin >> data4;
	list.searchNode(L, data4);

	cout << endl;
	cout << "4-1. 어떤 노드 뒤에 노드를 추가할건가요? ";
	int data5, data6;
	cin >> data5;
	cout << "4-2. 그 노드 뒤에 어떤 데이터를 가진 노드를 추가할건가요? ";
	cin >> data6;
	list.addThisNode(L, data5, data6);
	list.printList(L);
	cout << endl;

	cout << "5. 삭제하고자 하는 노드를 알려주세요 : ";
	int data7;
	cin >> data7;
	list.deleteThisNode(L, data7);
	list.printList(L);
	cout << endl;

	cout << "6. 마지막 노드를 삭제합니다." << endl;
	list.deleteNode(L);
	list.printList(L);
	cout << endl;

	cout << "피곤하니까 연산을 끝내겠습니다." << endl;

}