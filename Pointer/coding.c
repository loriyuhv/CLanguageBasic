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

/*2.ָ�������*/
/*2.1ָ���һά����*/
//#include<stdio.h>
//
//int main() {
//	int a[5]; /*a�������� 5������Ԫ�صĸ��� Ԫ�ؾ��Ǳ��� a[0] ~a[4]*/
//	int b[3][4]; /*3��4�� a[0][0] �ǵ�һ��Ԫ�� a[i][j]�ǵ�i+1��j+1��*/
//	int c[5];
//	a[1] = 5;
//	// a = c; /*error a�ǳ���*/
//	printf("%p\n", &a[0]);
//	printf("%p\n", a);
//	return 0;
//}

// ȷ��һ��һά������Ҫ����������
// һ���������һ��Ԫ�صĵ�ַ��һ��������ĳ���

//#include<stdio.h>
//
//void f(int* pArr, int len) {
//	//*pArr = 2; // a[0]
//	//*(pArr + 1) = 3; // ע�⣺*(pArr + i) �ȼ��� a[i]
//	for (int i = 0; i < len; i++) {
//		printf("%d\t", pArr[i]);
//	}
//}
//
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int b[6] = { -1, -2, -3, 4, 5, -6 };
//	int c[100] = { 1, 99, 22, 33 };
//	// ע�⣺�����ʼ���Ǹ���һ����ֵ������ֵΪ0����û�и�ֵ����Ϊ����ֵ
//	int e[100];
//	
//	f(a, 5); // a��int*(ָ�������
//	// for (int i = 1; i <= 20; i++) {
//		// printf("%d\t", c[i]);
//		// printf("%d\t", e[i]);
//	// }
//
//	printf("%d, %d\n", a[0], a[1]);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 5, j = 10;
//	int* p = &i, * q = &j;
//	int a[5];
//	p = &a[1];
//	q = &a[4];
//	//printf("%d:%x, %d:%x\n", q, q, p, p);
//	printf("p��q��ָ��ĵ�Ԫ���%d����Ԫ\n", q-p); // p-qû��ʵ������
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char ch = 'A';
//	int i = 99;
//	double x = 66.6;
//	char* p = &ch;
//	int* q = &i;
//	double* r = &x;
//	printf("%d, %d, %d\n", sizeof(p), sizeof(q), sizeof(r));
//	return 0;
//}

//# include<stdio.h>
//int main()
//{
//	int i = 10;
//	
//	int* p = &i; 
//	int** q = &p;
//	int*** r = &q;
//	// r = &p; // �߼����� ��Ϊr��int ***���ͣ�rֻ�ܴ��int **���ͱ����ĵ�ַ��
//	printf("i�ĵ�ַ%x\n", &i);
//	printf("q�ĵ�ַ%x\n", &q);
//	printf("r�ĵ�ַ%x\n", &r);
//	printf("p��ֵ%x, q��ֵ%x, r��ֵ%x\n", p, q, r);
//	printf("p��ֵ%x\n", **r);
//	// printf("%d\n", ***r);
//	return 0;
//}

//#include<stdio.h>
//
//void f(int** q) {
//	**q = 20; // *q ����p **q == *p 
//}
//
//void g() {
//	int i = 10;
//	int* p = &i;
//	f(&p);
//	printf("%d\n", *p);
//}
//
//int main()
//{
//	g();
//	return 0;
//}

