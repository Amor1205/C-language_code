#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//����������
// + - * / %
//    ���͵ĳ��� 1/2 --> 0
//    �����͵ĳ��� 1.0 / 2 --> 0.5 
// Ҫʵ�ָ����͵ĳ�������Ҫ����������ֻҪ��һ��Ϊ������
// % ȡģ������ ������ĵ������������������������Ϊ����


//��λ������
//  <<���Ʋ�����
//  >>���Ʋ�����
//  ֻ�������
// ��

//int main()
//{
//int a = 7;
//int b = a << 1;
//printf("%d\n", a);//7   111   
//printf("%d\n", b);//14   1110  
//}

// �ƶ����Ƕ�����
// �����Ķ����Ʊ�ʾ������
//ԭ��
//����
//����
//����������ԭ�롢���롢������ͬ
//����������ԭ������Ҫ����

//�� 7 �� 
//ԭ��---> 0000 0000 0000 0000 0000 0000 0000 0111
//����---> 0000 0000 0000 0000 0000 0000 0000 0111
//����---> 0000 0000 0000 0000 0000 0000 0000 0111
//- 7 ��
//ԭ��---> 1000 0000 0000 0000 0000 0000 0000 0111
//����---> 1111 1111 1111 1111 1111 1111 1111 1000��ԭ�����λ���䣬����λ��λȡ����
//����---> 1111 1111 1111 1111 1111 1111 1111 1001������+1Ϊ���룩
//����-1ȡ���õ�����
// 
//�������ڴ��д���ǲ���
// ���Կ���
//int main()
//{
//int a = 7;
//int b = a << 1;
//printf("%d\n", a);//7   111   
//printf("%d\n", b);//14   1110  
//}
//a  �ڴ��� 0000 0000 0000 0000 0000 0000 0000 0111
//b  �ڴ���a�����ƶ�һλ ���Ʋ�������߶������ұ߲�0
//b  �ڴ��� 0000 0000 0000 0000 0000 0000 0000 1110   ��14��
// a�������䣬b������a�Ĳ�������������

//b = -7 << 1�� a = -7
//a  1111 1111 1111 1111 1111 1111 1111 1001
//b  1111 1111 1111 1111 1111 1111 1111 0010�����룩
//b  1111 1111 1111 1111 1111 1111 1111 0001�����룩
//b  1000 0000 0000 0000 0000 0000 0000 1110��ԭ�룩 -14


//����1 ��2

//���Ʋ�����
// ������λ:�ұ߶�������߲�ԭ����λ
// �߼���λ:�ұ߶�������߲�0
//���߼����ƻ�����������ȡ���ڱ�����
//�����ϼ����Ķ����������ơ�

//int main()
//{
//	int a = -7;
//	int b = a >> 1;
//	printf("a=%d\n", a); // -7
//	printf("b=%d", b);   // -4
//	return 0;
//}

//VS���õ����������ơ�
//������λ���������Ҫ�ƶ�����λ��Ҳ�����ƶ�������λ�����Ǳ�׼δ����ġ�

//λ������

// & - ��(2����)λ��
// | - ��(2����)λ��
// ^ - ��(2����)λ���
//int main()
//{
//	int a = 3; //���� 0000 0000 0000 0000 0000 0000 0000 0011
//	int b = -5;//ԭ�� 1000 0000 0000 0000 0000 0000 0000 0101
//	           //���� 1111 1111 1111 1111 1111 1111 1111 1011
//	int c1 = a & b; // & : ����ͬʱΪ1����1������Ϊ0
//	int c2 = a | b; // | : ֻҪ��1��Ϊ1������Ϊ0��Ϊ0
//	int c3 = a ^ b; // ^ : ��ͬΪ0������Ϊ1
//	printf("c1=%d\n", c1);  // 3
//	printf("c2=%d\n", c2);  // -5
//	printf("c3=%d\n", c3);  // -8
//	return 0;
//}

//��������ʱ����ʵ���������Ľ���
//ԭ���ķ���1��(������ʱ����)
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	c = a;
//	a = b;
//	b = c;
//	return 0;
//}
//��������2��
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//��Ϊ���͵��������ֵ��������ӻ������
//�������Ͻ����������

//�������ķ�3
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	return 0;
//}

//������ͬ���������Ϊ0
// 0 ^ a = 0
// a ^ a = 0
// 3 ^ 3 ^ 5 = 5
// 3 ^ 5 ^ 3 = 5
// ע�⣺��������֧�ֽ�����
// ���ԣ�	a = a ^ b; b = a ^ b; a = a ^ b; -->
//          a = 3 ^ 5  b = 3 ^ 5 ^ 5 --> 3   a = 3 ^ 5 ^ 3 = 5;
// ���������㷨�������
//�����룬������ӷ�

//��ʵ��Ӧ���У���1��������ʱ�������õ���㷺
//��3 ֻ������ ���ͣ������ٶȽ���


//��д����Ҫ��ʵ�֣���һ�������������ڴ��еĶ�������1�ĸ���
// ----> ����Ķ�������1�ĸ���

// int a = 3;
// 0000 0000 0000 0000 0000 0000 0000 0011
// 2 

// a & 1
// 0000 0000 0000 0000 0000 0000 0000 0011
// 0000 0000 0000 0000 0000 0000 0000 0001
//& �� Ϊ 0000 0000 0000 0000 0000 0000 0000 0001 �����ж����һλ����0����1
// ֻ��Ҫ���Ʋ��� �ڶ�λ�ͱ�ɵ�һλ��

//int main()
//{
//	int a = 7;
//	int amount = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a & 1 )== 1)
//			amount++;
//		a = a >> 1;
//	}
//	printf("%d", amount);
//	return 0;
//}
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ����У��ж��ٸ�λ(bit)��ͬ�� 
//
//��������:
//
//1999 2299
//
//������� : 7
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((c & 1) == 1)
//			count++;
//		c >>= 1;
//	}
//	printf("%d", count);
//	return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//#include<stdio.h>
//int main()
//{                                                // 0000 0000 0000 0000 0000 0000 0000 0101 
//	int a = 0;                                   // 1000 0000 0000 0000 0000 0000 0000 0001 
//	scanf_s("%d", &a);
//	int num = 1 << 30;
//	printf("Even digit:");
//	if (a >= 0)
//		printf("0 ");
//	else
//		printf("1 ");
//	for (int i = 0; i < 15; i++)
//	{
//		int b = (a & (num >> 1))/(num>>1);
//		printf("%d ", b);
//		num >>= 2;
//	}
//	num = 1 << 30;
//	printf("\nOdd digit: ");
//	for (int i = 0; i < 16; i++)
//	{
//		int b = (a & num)/num;
//		//b = Squ2(b);
//		printf("%d ", b);
//		num >>= 2;
//	}
//	return 0;
//}

//дһ���������ز����������� 1 �ĸ�����

//���磺 15    0000 1111    4 �� 1
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a & 1) == 1)
//			count++;
//		a >>= 1;
//	}
//	printf("count = %d", count);
//	return 0;
//}

//��ֵ������
//  �� = ��

//int main()
//{
//	int a = 3; //��ʼ��
//	a = 3;     //��ֵ
//	a = x = y + 1;//������ֵ������������ y+1��ֵ����x x����a
//	//������������ֵ���޷��������е��ԣ��ɶ��Խϲ ���鲻Ҫ�������
//	return 0;
//}

//���ϸ�ֵ����
//+= -= *= /= %=
// >>=  <<=  &= |= ^=

//��Ŀ������
//  �� �߼�������

//int main()
//{
//	int flag = 3;
//	//���flag Ϊ�棨��0����if�����������������
//	if(flag)
//	{ }
//	//���flag Ϊ�٣�0������flagΪ�棬if�����������������
//	if (!flag)
//	{ }
//	return 0;
//}

// -��ֵ +��ֵ &ȡ��ַ
//int main()
//{
//	int a = 30;
//	printf("%p\n", &a); //ȡ���Ǳ������ڴ��е���ʼ��ַ
//  int n = sizeof(a); //�������a��ռ�ڴ�Ĵ�С����λ���ֽ�
// 

//	int * p = &a; //p ����ָ����� �洢��ַ
//	return 0;
//}

//sizeof ��һ�������������Ǻ���
//������Ǳ�����������ռ�ڴ�ռ�Ĵ�С
//strlen �ǿ⺯�������������ַ����ĳ���
// 
//  �� ~ �� ������λȡ��
//eg.
//int main()
//{
//	int a = 0;
//	// 0000 0000 0000 0000 0000 0000 0000 0000 
//	printf("%d\n", ~a);
//	// 1111 1111 1111 1111 1111 1111 1111 1111 ����
//	// 1111 1111 1111 1111 1111 1111 1111 1110 ����
//	// 1000 0000 0000 0000 0000 0000 0000 0001 ԭ��
//	//     -----> -1
//	// �����м�λ���1 ������һλ��1 << ��λ�� ��1 
//	// �����м�λ���0 ���� 0 ��λ����ȥ������ȫΪ1��a & ~(1<<4) �� �Ϳ���
//	return 0;
//}

//ǰ��++  ��++ ��ʹ��
//����++  ��ʹ�ã���++

// * ȡ��ַ������
// �� p �Ǵ�� &a a�ĵ�ַ�����ͨ��Ҫͨ��p�ĵ�ַ�ҵ�a�ĵ�ַ�����ǽ�����p
// *p  --> ͨ��p�����ֵ�ҵ� �����ַ�����ڵĿռ䣬���� a  

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr)); //��ӡ��һ��ָ��Ĵ�С 4���ֽ�(x86)/8���ֽ�(x64)
//}
//void test2(int ch[])
//{
//	printf("%d\n", sizeof(ch)); //��ӡ��һ��ָ��Ĵ�С 4���ֽ�(x86)/8���ֽ�(x64)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr)); //40
//	printf("%d\n", sizeof(ch));  //10
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//��ϵ������
//  > >= < <= != ==
//ע�⣺��ֵ���ж���ȵ�����
//ע�⣺
//int main()
//{
//	if ("abc" == "abcdefg") //�ַ������������ڱȽ����ַ��ĵ�ַ
//	{                       //��Ҫ��strcmp
//	};
//	return 0;
//}

//�߼�������
//   &&�߼��� ||�߼���
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);//1
//	int d = 0;
//	c = a && d;  //��һ��0��Ϊ0
//	printf("%d\n", c);//0
//	c = a || b; //ֻҪ��һ��Ϊ����Ϊ��
//	printf("%d\n", c);//1
//	c = a || d;//1
//	printf("%d\n", c);//1
//	c = 0 || d;// ����Ϊ0��Ϊ0
//	printf("%d\n", c);//0
//	return 0;
//}


//int main()
//{                 
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++; //ֻ��a++���ˣ���Ϊ��ʹ��aΪ0 ��������
//	i = a++ || ++b || d++;  // 0 || Ҫ��ڶ���������ڶ���Ϊ�棬��������
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	//  &&1 2 3 4     ||��1 3 3 4
//	return 0;
//}
//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++; // ����ǰ���ö�++��
//	// i = a++||++b||d++;  //1 Ϊ�� ��������������ˣ��㵽Ϊ��ͺ���
// 
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	// &&2 3 3 5  ||��1 2 3 5
//	return 0;
//}

//&&���Ϊ�٣��ұ߲�����
//||���Ϊ�棬�ұ߲�����

//����������������Ŀ��������
//����ʽ1?����ʽ2:����ʽ3
//��         ��        ���� 
//��         ����      ��

//int main()
//{
//	int a = 3;
//	int b = 0;
//	int max = (a > b ? a : b);
//	if (a > 3)
//		b = 3;
//	else
//		b = -3;
//	b = (a > 3 ? 3 : -3);
//	return 0;
//}

//���ű���ʽ
//�����������μ��㣬��������ʽ�Ľ�������һ������ʽ�Ľ��

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = (a > b, a + b + 10, a, b = a + 1);//ǰ��ļ��㲻���Ժ���
//	return 0;
//}

//�±����ò�����
// []
//int main()
//{
//	int arr[10] = { 0 };
//	arr[7] = 8;   //[]Ϊ�±����ò����� []������Ϊ arr �� 7 
//	return 0;
//}
//arr[7] --->  *(arr+7) arr+7��������7��Ԫ�أ�ָ���˵ڰ˸�Ԫ�أ����ǵڰ˸�Ԫ��
// ---->*(7+arr)  ---> 7[arr]  

//�������ò��ݷ�
//// ( ) 
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);//������,������ΪAdd, a, b.
//	return 0;
//}

//����һ���ṹ�ĳ�Ա
//   .    �ṹ�� . ��Ա��
//  ->     �ṹ��ָ��->��Ա��
//struct Stu
//{
//	char name[20];
//	int age;
//	double score;
//};
//void set_stu(struct Stu*ps)
//{
//	// ���У�ss.name��һ����ַ�����ܰ��ַ����ŵ���ַ�ss.name = "zhangsan";
//	//strcpy((*ps).name, "zhangsan");
//	//(*ps).age = 20;
//	//(*ps).score = 100.0;
//	strcpy(ps->name, "zhangsan");
//	ps->age = 20;
//	ps->score = 100.0;
//}
//void print_stu(struct Stu *ps)
//{
//	printf("%s %d %.1f\n", (*ps).name, (*ps).age, (*ps).score);
//}
//
//
//int main()
//{
//	struct Stu s = { 0 };
//	set_stu(&s);
//	print_stu(&s);
//	return 0;
//}
//ʵ�δ����βε�ʱ���β���ʵ�ε�һ����ʱ������
//�����s����ȥ��ʱ��ֻ���ݵ���ʵ�ε�ֵ��Ȼ����βν��иı�
//����Ӧ�ô���s�ĵ�ַ��ȥ
// Ȼ�� *ps �ҵ�s�ĵ�ַ ������ (*ps).name �ҵ���Աname
// Ҳ������ ps -> name �ҵ�


//-> �õ��˽ṹ��ָ�롪>��Ա��   ->����Ҫ������
//����õ��˽ṹ�������. ��Ա��     ps->age �ȼ��� (*ps).age

//����ʽ��ֵ
//����ʽ �����ȼ��ͽ����

//��ʽ����ת��
//����������C���Ե�����������������������ȱʡ�������͵ľ��ȶ�������ġ�
//Ϊ�˻��������ȣ�����ʽ�е��ַ��Ͷ����Ͳ�������ʹ��֮ǰ���������͡�
//��������������
//����ʽ����������Ҫ��CPU����Ӧ�����ڼ���ִ��
//��CPU������������(ALU)�Ĳ��������ֽڳ���һ�����int���ֽڳ��ȣ�
//ͬʱҲ��CPU��ͨ�üĴ����ĳ��ȡ�
//��ˣ���ʹ����char���͵���ӣ�
//��CPUִ��ʱʵ����ҲҪ��ת��ΪCPU�����β������ı�׼���ȡ�
//ͨ��CPU(general-purpose CPU)������ֱ��ʵ������8byte�ֽ�ֱ���������
//(��Ȼ����ָ���п���������ֱ�����ָ��)��
//���ԣ�����ʽ�и��ֳ��ȿ���С��int���ȵ�����ֵ����������ת��Ϊint��unsigend int
//Ȼ���������CPU��ȥִ��

//��ν������������أ�
//���������ǰ��ձ������������͵ķ���λ�������ġ�

//int main()
//{
	//char c = -1; //-1��������32������λ
	// 1000 0000 0000 0000 0000 0000 0000 0001
	// 1111 1111 1111 1111 1111 1111 1111 1110
	// 1111 1111 1111 1111 1111 1111 1111 1111 ->  -1 �� ����
	// ��Ϊchar����ֻ��һ���ֽڣ�8����λ
	// 1111 1111
	//�ѵ�һ�������Ƿ���λ����λ�������λ��
	//char d = 1;
	// 0000 0000 0000 0000 0000 0000 0000 0001
	// 0000 0001;
	//��λ������λ0
//���Ϊ�޷�������ֱ�Ӳ�0
//return 0;
//}

//int main()
//{
//	char a = 5;
//	// 0000 0000 0000 0000 0000 0000 0000 0101
//	// 0000 0101
//	char b = 126;
//	// 0000 0000 0000 0000 0000 0000 0111 1110
//	// 0111 1110
//	char c = a + b;
//	//��������
//	// 0000 0000 0000 0000 0000 0000 0000 0101
//	// 0000 0000 0000 0000 0000 0000 0111 1110
//	// 0000 0000 0000 0000 0000 0000 1000 0011
//	//���� �˸�����λ
//	// 1000 0011
//	printf("%d", c);
//	//��������
//	// 1111 1111 1111 1111 1111 1111 1000 0011
//	// 1111 1111 1111 1111 1111 1111 1000 0010
//	// 1000 0000 0000 0000 0000 0000 0111 1101
//	// -125����
//	return 0;
//}
// char -128 - 127

//int main()
//{
//	char a = 0xb6;
//	//����������
//	//���ܻ�ı�ֵ����Ϊ����λ����Ϊ1
//	short b = 0xb600;
//	//����������
//	//���ܻ�ı�ֵ����Ϊ����λ����Ϊ1
//	int c = 0xb60000;
//	
//	return 0;
//}

//���ڱ���ʽ�У����;ͻ����������� +c
//int main()
//{
//	char c = 1;
//	printf("%d", sizeof(c)); //1
//	printf("%d", sizeof(+c)); //4
//	printf("%d", sizeof(-c));//4
//
//	return 0;
//}

//����float �� double һ�����㣬������ת��
//int ��double ������ ��int ��������double��
//��������ת����

//������������
//���ӱ���ʽ����ֵ������Ӱ������
//1.���ȼ������ڲ����������ȼ�
//2.����ԣ����ڲ��������ȼ���ͬ��ʱ�򣬽����˵����
//  L-R �������� R-L ��������
//3.�Ƿ������ֵ˳�����߼����㵽1�Ͳ�������
//
//�������һЩ����ʽ
//���ǵ�˳��û�����ƣ��ж��ֽ��ͷ���
//  c + --c
//    2  1 
//  һ���������ұߵ� --c 
// ������ߵ� c ʲôʱ��׼����
// ���c ����2�� ��--c ��׼��c ����Ϊ2
// ��� ��׼��c ��--c ����Ϊ3
// 
// a * b + c * d + e * f
//

//#include <stdio.h>
//int i;
//int main()
//{
//	i--;
//	if (i > sizeof(i))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}
// �����>

//KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵ�X��ͼ����
//����������
//�������룬һ��������2~20������ʾ�����������Ҳ��ʾ��ɡ�X���ķ�б�ߺ���б�ߵĳ��ȡ�
//���������
//���ÿ�����룬����á� * ����ɵ�X��ͼ����

//#include<stdio.h>
//void Init(char arr[20],int a)
//{
//	for (int i = 0; i < a; i++)
//	{
//		arr[i] = ' ';
//	}
//}
//void Replace(char arr[20], int a,int b)
//{
//
//	arr[a - 1] = '*';
//	arr[b] = '*';
//}
//void Print(char arr[20], int a)
//{
//	for (int i = 0; i < a; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	char arr[20] = { 0 };
//	int a = 0;
//	int b = 0;
//	scanf_s("%d", &a);
//	int a1 = a;
//	Init(arr,a);
//	for (int i = 0; i < a; i++)
//	{
//		Replace(arr, a1, b);
//		Print(arr, a);
//		Init(arr, a);
//		a1--;
//		b++;
//	}
//	return 0;
//}
//�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int row = 0;
//	scanf_s("%d", &row);
//	char arr[21][21] = { 0 };
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			if (j == i || j == row - 1 - i)
//				arr[i][j] = '*';
//			else
//				arr[i][j] = ' ';
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������

//#include<stdio.h>
//int main()
//{
//	int row = 0;
//	while (scanf_s("%d", &row) != EOF);
//	{	char arr[21][21] = { 0 };
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			if (j == i || j == row - 1 - i)
//				arr[i][j] = '*';
//			else
//				arr[i][j] = ' ';
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//	}
//	return 0;
//}

//�ҵ������ǹؼ�������һ����б�ܺͷ�б��
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	while (scanf_s("%d", &n) != EOF)
//	{
//		for (int i = 0; i < n; i++)  //��ѭ��Ϊ��
//		{
//			for (int j = 0; j < n; j++) //��ѭ��Ϊ��
//			{
//				if (i == j || i + j == n - 1)
//					//��ؼ��ĵط�����б��Ϊ[i][i]����*�� ��б��Ϊ[i][n-1-j]����*��һ�д�ӡ1����2��*
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n"); //��ӡ��һ�У�����
//		}
//	}
//	return 0;
//}
//
//����
//KiKi����ĳ��ĳ���ж����죬��������ʵ�֡�������ݺ��·ݣ�������һ��������ж����졣
//����������
//�������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
//���������
//���ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж����졣

//int is_leap_year(int x)
//{
//	if (x % 400 == 0)
//		return 1;
//	else if (x % 4 == 0 && x % 100 != 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	while (scanf_s("%d %d", &year, &month) != EOF)
//	{
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//			printf("31");
//		else if (month == 2)
//		{
//			int ret = is_leap_year(year);
//			printf("%d", ret == 1 ? 29 : 28);
//		}
//		else
//			printf("30");
//	}
//	return 0;
//}
 

//KiKi��֪���Ѿ�������������a��b��c�ܷ񹹳������Σ�����ܹ��������Σ��ж������ε����ͣ��ȱ������Ρ����������λ���ͨ�����Σ���
//����������
//��Ŀ�ж����������ݣ�ÿһ����������a��b��c(0 < a, b, c < 1000)����Ϊ�����ε������ߣ��ÿո�ָ���
//	���������
//	���ÿ���������ݣ����ռһ�У�����ܹ��������Σ��ȱ��������������Equilateral triangle!���������������������Isosceles triangle!����������������������Ordinary triangle!������֮�����Not a triangle!����

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (scanf_s("%d %d %d", &a, &b, &c) != EOF)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && b == c)
//				printf("Equilateral triangle!\n");
//			else if (a == b || b == c || a == c)
//				printf("Isosceles triangle!\n");
//			else
//				printf("Ordinary triangle!\n");
//		}
//		else
//			printf("Not a triangle!\n");
//	}
//	return 0;
//}