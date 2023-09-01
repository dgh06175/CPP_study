#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link; // 이 구조체 자체를 가리키는 포인터이므로 struct으로 선언
};

struct HeadNode {
	Node* head; // Node를 가리키는 포인터, head
};

class Singlist {

public:
	/*리스트 생성, 헤드노드 */
	HeadNode* createList() {
		HeadNode* H = new HeadNode; // HeadNode를 가리키는 포인터, H
		H->head = NULL;
		return H;
	}
	
	/* 리스트의 마지막에 노드 삽입*/
	void addNode(HeadNode* H, int x) { 
		Node* NewNode = new Node;  //새로 만들 노드 
		Node* LastNode; //원래 있던 노드의 마지막 노드
		NewNode->data = x;
		NewNode->link = NULL;

		if (H->head == NULL) { // 리스트가 비어있을 경우
			H->head = NewNode;
			return;
		}

		LastNode = H->head;   // 리스트가 비어있지 않은 경우에 연결리스트의 가장 처음 노드가 LastNode를 가리키게 한다.
		while (LastNode->link != NULL) LastNode = LastNode->link; // 연결리스트의 마지막 노드를 찾는 과정
		LastNode->link = NewNode; // 마지막 노드를 찾고 while문을 나오면 뒤에 새 노드를 가리키게 한다.
	}

	/* 리스트의 마지막 노드 삭제*/
	void deleteNode(HeadNode* H) {  
		Node* prevNode;  // 삭제되는 노드의 앞 노드
		Node* delNode;  // 삭제되는 노드

		if (H->head == NULL) return; // 리스트가 빈 경우
		if (H->head->link == NULL) { // 한 개의 노드만 가진 경우
			delete H->head;  // head가 가리키던 메모리 공간을 힙 영역에 반환
			H->head = NULL;  // 헤드 노드의 link 부분인 head를 null로 설정.
			return;
		}
		else {  // 리스트에 노드 여러 개 있는 경우
			prevNode = H->head; // 헤드 노드가 가리키는 노드가 prevNode가 되게 설정
			delNode = H->head->link; // prevNode 다음 위치로 delNode 설정
			while (delNode->link != NULL) { //delNode가 마지막노드가 될 때까지
				prevNode = delNode;       // prevNode를 한칸씩 가고
				delNode = prevNode->link; // delNode도 한칸씩 끝으로 간다.
			}
			free(delNode);  // 마지막 노드의 메모리 공간을 반환
			prevNode->link = NULL;
		}
	}

	/* 리스트의 특정 노드 삭제*/
	void deleteThisNode(HeadNode* H, int deldata) {
		Node* delNode;  // 삭제하려는 노드
		Node* prevNode; // 삭제하려는 노드의 앞 노드
		prevNode = H->head;

		while (prevNode->link->data != deldata) {
			prevNode = prevNode->link;
		}

		delNode = prevNode->link;   // prevNode가 가리키는 노드가 삭제할 노드
		prevNode->link = delNode->link;  // prevNode가 delNode 다음 노드를 가리키도록
		free(delNode);  // delNode 삭제

		cout << deldata << " 데이터 값을 가진 노드가 삭제됐습니다." << endl;
		return;
	}

	/* 리스트에 특정 노드 삽입*/
	void addThisNode(HeadNode* H, int afterthisdata, int adddata) {
		// afterthisdata: 이 데이터 뒤에 삽입하고 싶소.
		// adddata: 이 데이터를 삽입하고 싶소.

		Node* prevNode;  //삽입하려는 노드의 이전 노드
		prevNode = H->head;

		while (prevNode->data != afterthisdata) {
			prevNode = prevNode->link;
		}

		Node* NewNode = new Node;
		NewNode->data = adddata;
		NewNode->link = prevNode->link;
		prevNode->link = NewNode;
		return;
	}

	/* 리스트의 특정 노드 검색*/
	void searchNode(HeadNode* H, int thisdata) {
		Node* someNode;
		someNode = H->head;

		while (someNode->data != thisdata) {
			someNode = someNode->link;
		}
		cout << thisdata << " 데이터를 검색하는 데 성공했습니다." << endl;
	}

	/* 연결리스트 출력*/
	void printList(HeadNode* L) {
		//노드 순서대로 리스트 출력
		Node* p;
		cout << "연결리스트 목록 = ( ";
		p = L->head;

		while (p != NULL) {
			cout << p->data;
			p = p->link;
			if(p != NULL) cout << " --> ";
		}
		cout << " )" << endl;
	}
};