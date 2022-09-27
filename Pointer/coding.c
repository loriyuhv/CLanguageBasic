/*学自《郝斌C语言》*/
/*1.1 基本类型的指针*/
/*1.1.1 指针变量的定义及初始化*/
//#include<stdio.h>
//
//int main() {
//	int* p;
//	int i = 10;
//	p = &i;
//	printf("i的地址：%x, %p\n", &i, &i);
//	printf("p的值,也就是i的地址：%p\n", p);
//	printf("i的值：%d\n", *p);
//	return 0;
//}
/*1.1.2 基本类型及常见错误分析*/
//错误1
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	*q = p; // error
//	printf("%d\n", *q);
//	return 0;
//}
//错误2
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	*q = *p; // error
//	printf("%d", *q);
//}
//错误3
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	p = q;	// error
//	printf("%d", *q);
//}
//改进
//#include<stdio.h>
//int main() {
//	int i = 5, * p = &i, * q;
//	q = p;
//	printf("%d", *q); /*13行*/
//}

/*1.1.3 经典指针程序_互换两个数字*/
// 例1
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
// 例2
//#include<stdio.h>
//void swap(int a, int b)
//{
//	int t;
//	t = a, a = b, b = t;
//	return;
//}
//// 注意，当函数调用完成之后会自动释放
//
//int main()
//{
//	int a = 3, b = 5, t;
//	swap(a, b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
// 例3
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
// 错误1
//void swap(int* a, int* b) {
//	int t;
//	t = a, a = b, b = t;
//  return;
//}
// 错误2
//void swap(int* a, int* b) {
//	int* t;
//	t = a, a = b, b = t;
//	return;
//}
// 改进
//void swap(int* a, int* b) {
//	int t;
//	t = *a, * a = *b, * b = t;
//	return;
//}
/*1.1.5 指针函数返回一个以上的值*/
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

/*2.指针和数组*/
/*2.1指针和一维数组*/
//#include<stdio.h>
//
//int main() {
//	int a[5]; /*a是数组名 5是数组元素的个数 元素就是变量 a[0] ~a[4]*/
//	int b[3][4]; /*3行4列 a[0][0] 是第一个元素 a[i][j]是第i+1行j+1列*/
//	int c[5];
//	a[1] = 5;
//	// a = c; /*error a是常量*/
//	printf("%p\n", &a[0]);
//	printf("%p\n", a);
//	return 0;
//}

// 确定一个一维数组需要几个参数？
// 一个是数组第一个元素的地址，一个是数组的长度

//#include<stdio.h>
//
//void f(int* pArr, int len) {
//	//*pArr = 2; // a[0]
//	//*(pArr + 1) = 3; // 注意：*(pArr + i) 等价于 a[i]
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
//	// 注意：如果初始化是赋了一部分值，其余值为0。若没有赋值，则为垃圾值
//	int e[100];
//	
//	f(a, 5); // a是int*(指针变量）
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
//	printf("p和q所指向的单元相隔%d个单元\n", q-p); // p-q没有实际意义
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
//	// r = &p; // 逻辑错误 因为r是int ***类型，r只能存放int **类型变量的地址。
//	printf("i的地址%x\n", &i);
//	printf("q的地址%x\n", &q);
//	printf("r的地址%x\n", &r);
//	printf("p的值%x, q的值%x, r的值%x\n", p, q, r);
//	printf("p的值%x\n", **r);
//	// printf("%d\n", ***r);
//	return 0;
//}

//#include<stdio.h>
//
//void f(int** q) {
//	**q = 20; // *q 就是p **q == *p 
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

