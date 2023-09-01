#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define MAX_QUEUE_SIZE 20

void print_tree(TreeNode *node)
{
	if (node) {
		print_tree(node -> left);
		printf("%d ", node-> data);
		print_tree(node -> right);
	}
}

TreeNode* search(TreeNode *node, int target)
{
	if (node == NULL) return NULL;

	if (node -> data == target) {
		return node;
	} else if (node -> data > target){
		return search(node -> left, target);
	} else {
		return search(node -> right, target);
	}
	//return NULL;
}

TreeNode* search2(TreeNode *node, int target)
{
	while (node != NULL) {
		if (node -> data == target) return node;
		else if (node -> data > target) node = node -> left;
		else node = node -> right;
	}
	return NULL;
}

void insert_node(TreeNode **root, int key){
	TreeNode *p, *t, *n;
	t = *root;
	p = NULL;

	while (t != NULL) {
		if (key == t->data) return;
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;

	n->data = key;
	n->left = n->right = NULL;
	
	if (p != NULL) {
		if (p->data > key) p->left = n;
		else p->right = n;
	} else {
		*root = n;
	}
}


void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;
	// key 를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;

	// key 가 어디있는지 탐색.
	// t에 key가 있는 노드의 주소 저장되고, p에 t의 부모노드 저장됨
	while (t != NULL && t->data != key) {
		p = t;
		t = (key < t->data) ? t -> left : t -> right;
	}
	// tree 에 key가 없는경우.
	if (t == NULL) { // p == NULL 아닌가?
		printf("KEY is not in the TREE");
		return;
	}

	// CASE 1 : 삭제 노드가 단말 노드 (자식 없음))
	if ((t->left == NULL) && (t->right == NULL)){
		if (p != NULL) {
			if (p->left == t) p->left = NULL;
			else p->right = NULL;
		} else {
			printf("부모노드NULL\n");
			*root = NULL;
		}
	}
	// CASE 2 : 삭제 노드의 자식 트리가 하나
	else if ((t->left == NULL) || (t->right == NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if(p->left == t) p->left = child;
			else p->right = child;
		} else {
			printf("부모노드NULL\n");
			*root = child; // NULL?
		}

	}
	// CASE 3 : 삭제 노드의 자식이 둘
	else {
		succ_p = t;
		succ = t -> right;
		while(succ->left != NULL){
			succ_p = succ;
			succ = succ->left;
		}

		if (succ_p->left == succ) succ_p->left = succ->right;
		else succ_p->right = succ->right;
		t->data = succ->data;
		t = succ;
	}
	free(t);
}



//    20
//  10  30
int main()
{
	TreeNode *n1;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n1->right = NULL;

	insert_node(&n1, 20);
	insert_node(&n1, 30);
	insert_node(&n1, 5);
	insert_node(&n1, 12);
	insert_node(&n1, 15);
	print_tree(n1);
	delete_node(&n1, 10);
	printf("\n");
	print_tree(n1);

	//if (result != NULL) printf("%d", result -> data);
	//else printf("NULL");
}