#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//typedef ���԰Ѹ��ӵļ򻯣���������������������֡�
//typedef unsigned int uint;
//
//int main()
//{
//	unsigned int num = 0;
//	uint num2 = 1;
//	return 0;
//}
//

//static ���Σ��ֲ����� ȫ�ֱ��� ������
// ����1�����ξֲ�����
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//		i++;           //ѭ��ʮ�Ρ�
//	}
//	return 0;
//}           

//����2 ����ȫ�ֱ���

//extern int a //�����ⲿ���ţ������ļ��ı�����



//#define num 100
//int main()
//{
//	printf("%d", num);
//	return 0;
//}


//add����
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//#define add(x,y) x+y
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//& ��ȡ��ַ������
//	//printf("%p", &a);
//	int* p = &a;
//	//p ����ָ����� 
//	*p = 20; //*p �����ò���������˼����ͨ��p�д�ŵĵ�ַ�ҵ�p��ָ��Ķ���*p����pָ��Ķ���
//	printf("%d\n", a);
//	return 0;
//

//int main()
//{
//	//������ʲô���͵�ָ�룬�����ڴ���ָ�����
//	//ָ���������������ŵ�ַ�ġ�
//	//ָ������Ĵ�Сȡ����һ����ַ��ŵ�ʱ����Ҫ���Ŀռ�
//	//32λ������ 32bitλ 4byte ָ�������С���ĸ��ֽ�
//	//64λ������ 8byte
//	// x86����32λƽ̨
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	printf("%d\n", sizeof(short*));
//
//	return 0;
//}

//�ṹ��

//ѧ��
struct Stu
{
	char name[20];
	int age;
	char sex[10];
	char tel[12];

};

void print(struct Stu* ps)
{
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tel);

	//������ ->
	//�ṹ��ָ����� -> ��Ա��

	printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tel);
}
int main()
{
	struct Stu a = { "zhangsan", 20 ,"male" , "1232132333" };

	//printf("%s %d %s %s", a.name, a.age, a.sex, a.tel);
	print(&a);
	return 0;
}
