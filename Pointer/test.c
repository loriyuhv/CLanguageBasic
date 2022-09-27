//#include<stdio.h>
//
//void f(int** q) {
//	**q = 20;
//}
//
//void g() {
//	int i = 10;
//	int* p = &i;
//	f(&p);
//	printf("%d\n", *p);
//}
//
//int main() {
//	g();
//	return 0;
//}

//#include<stdio.h>
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}NODE, *LinkList;
//
//int main() {
//	NODE L;
//	LinkList R;
//	printf("%d\n%d\n", sizeof(L), sizeof(R));
//	return 0;
//}