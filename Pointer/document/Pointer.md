

## 1 指针的分类

### 1.1 基本类型指针

#### 1.1.1 指针变量的定义及初始化

```C
#include<stdio.h>
int main()
{
	int* p;
	int i = 3;
	p = &i;
	printf("i的地址：%x, %p\n", &i, &i);
	printf("p的值,也就是i的地址：%p\n", p);
	printf("i的值：%d\n", *p);
	return 0;
}
```

```C
int* p;	/*定义了一个指针变量p*/
```

- p是变量的名字，int* 表示p变量存放的是int类型变量的地址。
- int* p 不是表示定义了一个名字叫做*p的变量。
- int* p 应该这样理解：p是变量名，p变量的数据类型是``int*``类型，所谓```int*``` 类型实际就是存放int变量地址的类型。

```C
p = &i; /*为指针变量赋值，即初始化。*/
```

- p保存了i的地址，因此p指向i。
- p不是i, i也不是p. 更准确的说：修改p的值不影响i的值，修改i的值也不会影响p的值。
- 如果一个指针变量指向了某个普通变量，则```*指针变量``` 就完全等同于``` 普通变量```  *p = i。

 **例子：**
		如果p是个指针变量，并且p存放了普通变量i的地址，则p指向了普通变量，```*p``` 就完全等同于 i。或者说：在所有出现```*p```的地方都可以替换成i，在所有出现i的地方都可以替换成```*p```。

#### 1.1.2 基本类型指针常见错误分析

```C
#include<stdio.h>
int main() {
	int i = 5, * p = &i, * q;
	//*q = p;	/*error1 语法编译会出错*/
	//*q = *p;	/*error2 使用了未初始化的内存q*/
	//p = q;	/*error3 q是垃圾值，q赋给p，p也变成垃圾值*/
	
	// 改进
	q = p;
	printf("%d\n", *q); /*13行*/
	return 0;
}
```

**错误1**

```C
int i = 5, * p = &i, * q;
*q = p;
printf("%d\n", *q); /*13行*/
```

```int``` 和 ```int *```的间接级别不同。由于p存放的值是地址，而*q的值是普通的数值，

**错误2**

```C
int i = 5, * p = &i, * q;
*q = *p;
printf("%d", *q); /*13行*/
```

使用了未初始化的内存q，所以q存放的是垃圾值。

**错误3**

```C
int i = 5, * p = &i, * q;
p = q;
printf("%d", *q); /*13行*/
```

q的空间是属于本程序的，所以本程序可以读写q的内容，但是如果q内部是垃圾值，则本程序不能读写*p的内容，因为*q所代表的内存单元的控制权限并没有分配给本程序，运行到13行时就会立即报错。

**改进**

```C
int i = 5, * p = &i, * q;
q = p;
printf("%d", *q); /*13行*/
```



#### 1.1.3 经典指针程序_互换两个数字

**例1**

```C
#include<stdio.h>
int main() {
	int a = 3, b = 5, t;
    t = a, a = b, b = t;
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
```

**例2**

 问：为什么最后没有交换

```C
#include<stdio.h>
void swap(int a, int b) {
	int t;
	t = a, a = b, b = t;
	return;
}
// 注意，当函数调用完成之后会自动释放

int main() {
	int a = 3, b = 5, t;
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
```

因为最终交换的是函数里的形参a, b，函数调用完成之后会自动释放，所以实参a，b的值不会被改变。

**例3**

```C
#include<stdio.h>

void swap(int* a, int* b);

int main() {
	int a = 3, b = 5;
	swap(&a, &b);
    printf("a = %d, b= %d\n", a, b);
	return 0;
}
```

**错误1**

```C
void swap(int* a, int* b) {
	int t;
	t = a, a = b, b = t;
    return;
}
```

因为a，b是指针变量，而t是普通变量，间接引用不同，所以会报错。

**错误2**

```C
void swap(int* a, int* b) {
	int* t;
	t = a, a = b, b = t;
	return;
}
```

- 这里互换的是a, b的值；
- 为什么改变的不是实参a, b的值，因为实参a，b是局部变量，程序加载时就已经分配好了地址；

**改进**

```C
void swap(int* a, int* b) {
	int t;
	t = *a, * a = *b, * b = t;
	return;
}
```

**注意：**要交换实参a, b的值，一定要交换实参a, b。

#### 1.1.4  `*`的含义

1. 乘法

2. 定义指针变量

   - ```C
     int* p; /*定义了一个名字叫p的变量*/
     ```

   - int* 表示p只能存放整型变量的地址。

3. ​	指针运算符

   - 该运算符放在已经定义好的指针变量。如果p是一个已经定义好的指针变量，则*p表示以p的内容为地址的变量

#### 1.4.5 指针使函数返回一个以上的值

```C
#include<stdio.h>

void GetElem(int* e, int* e2) {
	*e = 2;
	*e2 = 3;
	return;
}

int main() {
	int e, e2;
	GetElem(&e, &e2);
	printf("e = %d, e2 = %d\n", e, e2);
	return 0;
}
// 
	// 1）
	// 2）
	// 3）
```

如何通过被调函数修改主调函数普通变量的值

- 实参必须为该普通变量的地址
- 形参必须为指针变量
- 在被调函数中通过`*形参名` = ...的方式就可以修改主调函数相关变量的值。



## 2. 指针和数组

### 2.1 指针和一维数组

**数组**：其他高级语言（容器）

**一维数组名**：一维数组名是个指针常量，它存放的是一维数组第一个元素的地址

```C
int main() {
	int a[5]; /*a是数组名 5是数组元素的个数 元素就是变量 a[0] ~a[4]*/
	int b[3][4]; /*3行4列 a[0][0] 是第一个元素 a[i][j]是第i+1行j+1列*/
	int c[5];
	a[1] = 5;
	// a = c; /*error a是常量*/
	printf("%p\n", &a[0]);
	printf("%p\n", a);
	return 0;
}
```

确定一个一维数组需要几个参数？如果一个函数要处理一个一维数组, 则需要接受该数组的哪些信息?

一个是数组**第一个元素**的**地址**，第二个是**数组的长度**。
```C
#include<stdio.h>

void f(int* pArr, int len) {
	//*pArr = 2; // a[0]
	//*(pArr + 1) = 3; // 注意：*(pArr + i) 等价于 a[i]
	for (int i = 0; i < len; i++) {
		printf("%d\t", pArr[i]);
	}
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[6] = { -1, -2, -3, 4, 5, -6 };
	int c[100] = { 1, 99, 22, 33 };
	// 注意：如果初始化是赋了一部分值，其余值为0。若没有赋值，则为垃圾值
	int e[100];
	
	f(a, 5); // a是int*(指针变量）
	// for (int i = 1; i <= 20; i++) {
		// printf("%d\t", c[i]);
		// printf("%d\t", e[i]);
	// }

	printf("%d, %d\n", a[0], a[1]);
	return 0;

```



### 2.2 指针变量的运算

指针变量不能相加，不能相乘，也不能相除
如果两个指针变量指向的是同一块连续空间中的不同存储单元，则这两个指针变量才可以相减。

```C
#include<stdio.h>
int main()
{
	int i = 5, j = 10;
	int* p = &i, * q = &j;
	int a[5];
	p = &a[1];
	q = &a[4];
	//printf("%d:%x, %d:%x\n", q, q, p, p);
	printf("p和q所指向的单元相隔%d个单元\n", q-p); // p-q没有实际意义
	return 0;
}
```

**一个指针变量占几个字节**

- sizeof(数据类型） 功能：返回值就是该数据类型所占字节数 sizeof(int) = 4;
- sizeof(变量名）功能：返回值是该变量所占的字节数
- 假设p指向char类型变量（1个字节）
- 假设q指向int类型变量（4个字节）
- 假设r指向double类型变量（8个字节）

**p q r 本身所占的字节数是否一样？**答：本身都一样。一个指针变量占4个字节(32位），8个字节（64位）。

**注意：**一个变量的地址使用该变量首字节的地址来表示。

```C
#include<stdio.h>
int main()
{
	char ch = 'A';
	int i = 99;
	double x = 66.6;
	char* p = &ch;
	int* q = &i;
	double* r = &x;
	printf("%d, %d, %d\n", sizeof(p), sizeof(q), sizeof(r));
	return 0;
}
```

**32位的操作系统的寻址空间是0-2^32，即0x00000000-0xFFFFFFFF，指针长度为4个字节；**

**64位的操作系统的寻址空间是0-2^64，即0x0000000000000000-0xFFFFFFFFFFFFFFFF，指针长度为8个字节**

### 2.3 指针和二维数组 

### 2.4 指针和函数
### 2.5 指针和结构体

### 2.6 多级指针

**例1：**

```C
# include<stdio.h>
int main()
{
	int i = 10;
	int* p = &i; 
	int** q = &p;
	int*** r = &q;
	// r = &p; // 逻辑错误 因为r是int ***类型，r只能存放int **类型变量的地址。
	printf("i的地址%x\n", &i);
	printf("q的地址%x\n", &q);
	printf("r的地址%x\n", &r);
	printf("p的值%x, q的值%x, r的值%x\n", p, q, r);
	printf("p的值%x\n", **r);
	// printf("%d\n", ***r);
	return 0;
}
```

**例2：**

```C
#include<stdio.h>
void f(int** q) {
	**q = 20; // *q 就是p **q == *p 
}
void g() {
	int i = 10;
	int* p = &i;
	f(&p);
	printf("%d\n", *p);
}
int main()
{
	g();
	return 0;
}
```

### 专题 动态内存分配

//传统数组的缺点

// 1) 数组长度必须事先制定，且只能是常整数，不能是变量
// 例子
// int a[5]; // OK
// int len = 5; int a[len]; //error
// 2）传统形式定义的数组，该数组的内存程序员无法手动释放,
// 在一个函数运行期间，系统为该函数中数组所分配的空间会一直存在，
// 直到该函数运行完毕时，数组的空间才会被系统释放
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	// 20个字节的存储空间程序员无法手动编程释放它，
//	// 它只能在本函数运行完毕时由系统自动释放
//
//	printf("%d\n", a[2]);
//
//	return 0;
//}
// 
// 3) 数组的长度一旦定义，其长度就不能再更改
// 数组的长度不能在函数运行的过程中动态的扩充或缩小。
// 
// 4)A函数定义的数组，在A函数运行期间可以被其它函数使用，
// 但A函数运行完毕之后，A函数中的数组将无法再被其他函数使用。
//#include<stdio.h>
//
//void g(int* pArr, int len) {
//	//pArr[2] = 88;
//	*(pArr + 2) = 88;
//}
//
//void f() {
//	int a[5] = { 1, 2, 3, 4, 5 };
//
//	g(a, 5);
//	printf("%d\n", a[2]);
//}
//
//int main()
//{
//
//	f();
//	return 0;
//}
// 注意：传统方式定义的数组不能跨函数使用。


//为什么需要动态分配内存

	// 动态数组很好地解决了传统数组的这4个缺陷。
	// 传统数组也叫静态数组
//#include<stdio.h>
//#include<malloc.h>
//
//struct Student {
//	int a;
//	float b;
//	char c;
//};
//
//int main()
//{
//	struct Student st;
//	// malloc 是memory（内存）allocate（分配）的缩写
//	int i = 5; // 分配了4个字节 静态分配 //11行
//	int* p = (int*)malloc(4);
//	int* q = (struct Student*)malloc(sizeof(int) * 2);
//	printf("%d\n", sizeof(st));
//
//	printf("%d", sizeof(p));
//	// 1）要使用malloc函数，必须添加malloc.h这个头文件。
//	// 2）malloc函数只有一个形参，并且形参是整型。
//	// 3）4表示请求系统为本程序分配4个字节。
//	// 4）malloc函数只能返回第一个字节的地址。
//		// (char*)malloc(200); 200个char型变量
//		// (int*)malloc(200); 50个int型变量
//	// 5）这行分配了8个字节，p变量占4个字节，p所指向的内存也占4个字节。
//	// 6）p本身所占的内存是静态分配的，p所指向的内存是动态分配的。
//	*p = 5; // *p代表的就是一个int型变量，只不过*p这个整型变量的内存分配方式和11行的i变量的分配方式不同。
//	free(p); // free(p) 表示把p所指向的内存给释放掉。
//			// p本身的内存是静态的，不能由程序员手动释放，p本身的内存只能在p变量所在的函数运行终止时由系统自动释放。
//	printf("同志们好！！！\n");
//
//	return 0;
//}
// malloc函数用法
//#include<stdio.h>
//#include<malloc.h>
//
//void f(int* pArr) {
//	*pArr = 5;
//	printf("%d\n", *pArr);
//	// free(pArr); // 把pArr所指向的内存释放掉
//}
//
//int main()
//{
//	int* p = (int*)malloc(sizeof(int));
//	*p = 10;
//	printf("%d\n", *p);
//	f(p);
//	printf("%d\n", *p);
//	return 0;
//}

//动态内存分配举例_ 动态数组的构造
//#include<stdio.h>
//#include<malloc.h>
//
//int main()
//{
//	int a[5]; // 如果int占4个字节的话，则数组总共包含有20个字节，
//			  // 每四个字节被当做一个int变量来使用
//	int i, len;
//	int* pArr;
//
//	// 动态构造一维数组
//	printf("请输入您要存放元素的个数：");
//	scanf_s("%d", &len);
//	pArr = (int*)malloc(4 * len);
//
//	// 对一维数组进行操作 如：对动态一维数组进行赋值
//	for (i = 0; i < len; i++)
//		scanf_s("%d", pArr + i);
//
//	// 对一维数组进行输出
//	printf("一维数组的内容是：\n");
//	for (i = 0; i < len; i++)
//		//printf("%d\t", *(pArr + i));
//		printf("%d\t", pArr[i]);
//	// realloc(pArr, 100);
//	// 动态扩充缩小函数 把pArr指向的内存缩小到20
//	// 如果数值比原来大，就是扩充，否则就是缩小
//	realloc(pArr, 20);
//	printf("\n");
//	for (i = 0; i < 5; i++)
//		//printf("%d\t", *(pArr + i));
//		printf("%d\t", pArr[i]);
//
//	//free(pArr); // 释放动态分配的数组所占用的内存
//	// realloc(pArr, 100); 动态扩充缩小函数 把pArr指向的内存扩充到100
//
//	return 0;
//}
//静态内存和动态内存的比较
	// 静态内存是由系统自动分配，由系统自动释放。
	// 静态内存是在栈分配的。
	// 动态内存是由程序员手动分配，手动释放。
	// 动态内存是在堆分配的


// 跨函数使用内存的问题
// 例1.
//#include<stdio.h>
//
//void f(int** q) {
//	int i = 5;
//	// *q等价于p q和**q都不等价于p
//	*q = &i; // p = &i;
//
//}
//
//int main()
//{
//	int* p;
//	f(&p);
//	printf("%d\n", *p); // 本语句语法没有问题，但逻辑上有问题。
//
//	return 0;
//}
// 注意：这样写程序是会造成逻辑上的错误。
// 所以：静态内存不能跨函数使用
// 例2.
//#include<stdio.h>
//#include<malloc.h>
//
//void f(int** q) {
//	*q = (int*)malloc(sizeof(int));
//	// 等价于 p = (int*)malloc(sizeof(int));
//	// q = 5; // error
//	// *q = 5; // p = 5;
//	**q = 5;
//}
//int main()
//{
//	int* p;
//
//	f(&p);
//	printf("%d\n", *p);
//	return 0;
//}
// 所以：动态内存能跨函数使用

//以下取自C语言程序（第4版）

// 9.1 指向变量的指针变量
// 1. 指针变量的定义及初始化
/*一个变量在内存中的地址称为该变量的指针，变量的地址在程序
执行过程中是不会发生变化的，所以一个变量的指针使常量，举例
如下：int a, 那么&a就是常量。专门用来存放地址的变量称为指针
变量，与简单变量一样，指针变量也是先定义后使用。一般而言，
指针变量的定义形式为：
类型标识符* 指针变量名 int* a, * b;
同样,也可以在定义时为指针变量赋初值，即初始化。一般为：
类型标识符 *指针变量名 = &变量名 int* a = &b;
指针变量初始化后，该指针就指向了具体的变量，对变量的访问就可以
通过指针变量完成。
#include<stdio.h>
int main()
{
	int a = 10;
	printf("a=%d, a变量的指针是：%p\n", a, &a);
	a = 5;
	printf("a=%d, a变量的指针是：%p\n", a, &a);
	int* b = &a;
	printf("指针变量b指向a变量的值：%d\n", *b);
	return 0;
}
*/

// 2. 指针运算
/*当一个指针指向一个变量时，程序就可以利用这个指针间接引用
这个变量，间接引用格式为：*指针变量 *b
其中，*是间接引用运算符，为单目运算符，优先级与++、--相同，
它可以访问指针变量所指向变量的值。
*/

















