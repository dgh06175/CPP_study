#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct Heap
{
	element heap_ary[MAX_ELEMENT];
	int heap_size;
}Heap;

void init(Heap *h)
{
	h->heap_size=0;
}

void insert_max_heap(Heap *h, element item)
{
	int i;
	i = ++(h->heap_size);

	while((i != 1) && (item.key > h->heap_ary[i/2].key)){
		h->heap_ary[i] = h->heap_ary[i/2];
		i/=2;
	}
	h->heap_ary[i] = item;
}

element delete_max_heap(Heap *h)
{
	int parent, child;
	element item, temp;

	item = h->heap_ary[1];
	temp = h->heap_ary[(h->heap_size)--];
	parent = 1;
	child = 2;
	while( child <= h->heap_size ) {
		if( (child < h->heap_size) && 
			(h->heap_ary[child].key) < h->heap_ary[child+1].key)
			child ++;
		if (temp.key >= h->heap_ary[child].key) break;
		h->heap_ary[parent] = h->heap_ary[child];
		parent = child;
		child *= 2;
	}
	h->heap_ary[parent] = temp;
	return item;
}

void print_heap(Heap *h)
{
	for(int i=0; i<h->heap_size;i++){
		printf("%d ", h->heap_ary[i].key);
	}
}

int main()
{
	element e1={10}, e2={5}, e3={30};
	element e4, e5, e6;
	Heap heap;
	init(&heap);

	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
//	print_heap(&heap);

	e4 = delete_max_heap(&heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d > ", e6.key);
}