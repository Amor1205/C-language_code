#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	//ָ������
//	int* arr[4];
//	char* ch[5];
//
//	int** p = arr;
//	//����ָ����ָ�������е���Ԫ�ص�ַ��
//
//	//����ָ��
//	int arr2[5];
//	int(*pa)[5] = &arr2;
//	//paָ����5��Ԫ�أ������������int
//	//
//	char* arr3[6];
//	char(*p3)[6] = &arr3;
//
//	return 0;
//}
//int test(const char* str)
//{
//	return 0;
//}
//int main()
//{
//	//����ָ�� - Ҳ��һ��ָ�룬��ָ������ָ��
//	//�����ĵ�ַ�ú�������ȡ��ַ������
//	int(*pf)(const char*) = test;
//	//ʹ�ú��� -- 3�ַ���
//	(*pf)("abc");
//	pf("abcd");
//	test("abcde");
//	return 0;
//}

//int main()
//{
//	//(*( void(*)() ) 0 )();
//	// 0 ��ʲô��
//	// void(*p)()  p�Ǻ���ָ��
//	// ����viod (*)()�Ǻ���ָ������
//	// 0 ������һ������
//	// �����ͣ���ʵ��ǿ������ת��
//	//  ��Ϊ0�� ��ǿ������ת��Ϊ���޲�������������Ϊviod�ĺ����ĵ�ַ
//	//  * ������ ������0��ַ�����������
// 
//	void(*signal(int, void(*)(int)))(int);
//	// ��� void ( * ) (int) ������signal 
//	// signal�϶��Ǻͺ����������ϣ����Ծ��Ǻ�����
//	// ��Ϊָ��ĺ��治�����(int,void.....)
//	// 
//	// ���ϴ�����һ�κ�������
//	// ������signal�����ĵ�һ��������������int��
//	// �ڶ��������������Ǻ���ָ�룬�ú���ָ��ָ��ĺ���������int������������void
//	// signal�����ķ���������һ������ָ�롣
//	// ���Լ�  typedef --- ������������
//	typedef void(*pf_t)(int);  //��viod(*)(int)����������Ϊpf_t
//
//	return 0;
//}


//����ָ�����;
//
//дһ��������
//�ӷ����������˷�������
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// float Div(float x, float y)
//{
//	 return (float)x / (float)y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	float m = 0.0;
//	float n = 0.0;
//	float retu = 0.0;
//	do {
//		menu();
//		printf("ѡ��--->\n");
//		scanf("%d", &input);
//		if (1 == input || 2 == input || 3 == input)
//		{
//			printf("���������--->\n");
//			scanf("%d %d", &x, &y);
//		}
//		else if (4 == input)
//		{
//			printf("���������--->\n");
//			scanf("%f %f", &m, &n);
//		}
//		switch (input)
//		{
//		case 1:
//			ret = Add(x,y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			ret = Sub(x,y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			ret = Mul(x,y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			retu = Div(m, n);
//			printf("%.2f\n", retu);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("���ݷǷ�������������:>\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//��������
//
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// float Div(float x, float y)
//{
//	 return (float)x / (float)y;
//}
// void calc(int(*pf)(int x, int y))
//{
//	 int x = 0;
//	 int y = 0;
//	 printf("���������--->\n");
//	 scanf("%d %d", &x, &y);
//	 int ret = 0;
//	 ret = pf(x, y);
//	 printf("%d\n", ret);
//}
//int main()
//{
//	int input = 0;
//
//	float m = 0.0;
//	float n = 0.0;
//	float retu = 0.0;
//	do {
//		menu();
//		printf("ѡ��--->\n");
//		scanf("%d", &input);
//
//		if (4 == input)
//		{
//			printf("���������--->\n");
//			scanf("%f %f", &m, &n);
//		}
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			retu = Div(m, n);
//			printf("%.2f\n", retu);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("���ݷǷ�������������:>\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


////����ָ������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	 return x / y;
//}
//int main()
//{
//	int(*pf)(int,int) = Add;
//	int(*arr[4])(int, int) = { Add,Sub,Mul,Div };
//	//arr���Ǻ���ָ�������
//	//Ҫ�����ķ���ֵ��ͬ������ͬ
//	//����
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d  ",arr[i](8,4));
//	}
//	return 0;
//}


//����ָ�������ʹ��
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************1.ADD 2.SUB **************\n");
//	printf("***************3.MUL 4.DIV **************\n");
//	printf("**************** 0.EXIT *****************\n");
//	printf("*****************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	 return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int (*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//
//	do 
//	{
//		menu();
//		printf("ѡ��--->\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�������\n");
//		}
//		else if (input>=1&&input<=4)
//		{
//			printf("���������--->\n");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("�Ƿ�����������\n");
//		}
//	} while (input);
//	return 0;
//}

//ָ����ָ�������ָ��

//int main()
//{
//	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	//ָ����ָ�������ָ��
//	&pfArr;
//	int(*(*ppfArr)[5])(int, int) = &pfArr;
//
//	return 0;
//}

//�ص�����
//�ص���������һ��ͨ������ָ����õĺ���
//�����Ѻ�����ָ�루��ַ����Ϊ�������ݸ�����һ������
//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�������
// �ص����������иú�����ʵ�ַ�ֱ�ӵ���
//

//ð������
//ֻ��������������
//void bubble_sort(int arr[], int sz)
//{	
//	int flag = 1;
//	//��������������ġ����Ѿ��ź����ˣ�
//	// 
//	//ð�����������
//	for (int i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������Ĺ���
//		//���ڵ�����Ԫ�صıȽ�
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			//��˳��
//			if (arr[j] > arr[j + 1])
//			//���Ͳſ����ô��ں�С�ںűȽ�
//			//��ͬ���ݵıȽϷ�����ͬ ������cmp�����Ƚ�
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}

//qsort �⺯��
//����������������������͵�����
//
//
//void qsort(
//	void* base,//��Ҫ��������ݵ���ʼλ��
//	size_t num,//�����������Ԫ�صĸ���
//	size_t width,//�����������Ԫ�صĴ�С����λ���ֽڣ�
//	int(*cmp)(cosnt void* e1, cosnt void* e2));������ָ�� -- �ȽϺ�����
//  ��ͬ���ݵıȽϺ�����cmp�����������Ҫ����Ա�Լ��ṩ
// ���e1����e2���������0����
// ������ڣ����0
// ���С�ڣ����С��0����

//��Ƚ�����intԪ��
//e1��e2ָ����������
//int cmp_int(const void* e1, const void* e2)
//{
//	//����������if(*e1>*e2)
//	//void*�������ǲ�����ֱ�ӽ����õġ�
//	//void* ���޾������͵�ָ�룬���Բ��ܽ����ò�����Ҳ���ܼӼ�����
//	// ������Ҫǿ������ת��Ϊint*
//	return (*(int*)e1 - *(int*)e2);
//}
//
//void test1()
//{
//	int arr[] = { 8,7,5,4,3,1,2,9,10,0 };
//	//�������ų�����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test2()
//{
//	//��qsort����ṹ������
//	struct Stu s[] = { {"zhangsan",15},{"wangwu",29} ,{"lisi",19} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//}
//int main()
//{
//	//test1();
//	test2();
//}

void swap(char*e1, char*e2,int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int flag = 1;
	//��������������ġ����Ѿ��ź����ˣ�
	// 
	//ð�����������
	for (int i = 0; i < sz - 1; i++)
	{
		//һ��ð������Ĺ���
		//���ڵ�����Ԫ�صıȽ�
		for (int j = 0; j < sz - i - 1; j++)
		{
			//��˳��
			if (cmp((char*)base + j * width), (char*)base + (j + 1) * width > 0)
				//ת����char*����ϸ������int*��1����4���ֽ�
				//
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}