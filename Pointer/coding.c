/*ѧ�ԡ��±�C���ԡ�*/
/*1.1 �������͵�ָ��*/
/*1.1.1 ָ������Ķ��弰��ʼ��*/
//#include<stdio.h>
//
//int main() {
//	int* p;
//	int i = 10;
//	p = &i;
//	printf("i�ĵ�ַ��%x, %p\n", &i, &i);
//	printf("p��ֵ,Ҳ����i�ĵ�ַ��%p\n", p);
//	printf("i��ֵ��%d\n", *p);
//	return 0;
//}
/*1.1.2 �������ͼ������������*/
//����1
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	*q = p; // error
//	printf("%d\n", *q);
//	return 0;
//}
//����2
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	*q = *p; // error
//	printf("%d", *q);
//}
//����3
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	p = q;	// error
//	printf("%d", *q);
//}
//�Ľ�
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	q = p;
//	printf("%d", *q); /*13��*/
//}

/*1.1.3 ����ָ�����_������������*/
// ��1
//#include<stdio.h>
//int main()
//{
//	int a = 3, b = 5, t;
//
//	t = a, a = b, b = t;
//
//	printf("a = %d, b = %d\n", a, b);
//
//	return 0;
//}
// ��2
//#include<stdio.h>
//void swap(int a, int b)
//{
//	int t;
//	t = a, a = b, b = t;
//	return;
//}
//// ע�⣬�������������֮����Զ��ͷ�
//
//int main()
//{
//	int a = 3, b = 5, t;
//	swap(a, b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
// ��3
//#include<stdio.h>
//
//void swap(int* a, int* b);
//
//int main() {
//	int a = 3, b = 5;
//	swap(&a, &b);
//	printf("a = %d, b= %d\n", a, b);
//	return 0;
//}
// ����1
//void swap(int* a, int* b) {
//	int t;
//	t = a, a = b, b = t;
//  return;
//}
// ����2
//void swap(int* a, int* b) {
//	int* t;
//	t = a, a = b, b = t;
//	return;
//}
// �Ľ�
//void swap(int* a, int* b) {
//	int t;
//	t = *a, * a = *b, * b = t;
//	return;
//}
/*1.1.5 ָ�뺯������һ�����ϵ�ֵ*/
//#include<stdio.h>
//
//void GetElem(int* e, int* e2) {
//	*e = 2;
//	*e2 = 3;
//	return;
//}
//
//int main() {
//	int e, e2;
//	GetElem(&e, &e2);
//	printf("e = %d, e2 = %d\n", e, e2);
//	return 0;
//}
