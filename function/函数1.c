#define _CRT_SECURE_NO_WARNINGS

//����
//��һ���ӳ���
//���������������ж�����
//һ���������������з���ֵ���ṩ�Թ��̵ķ�װ��ϸ�ڵ����أ���Щ����ͨ��������Ϊ�����

//���ࣺ
//1.�⺯��
//2.�Զ��庯��

//1.1Ϊʲô���п⺯����
// 
//��һЩ�������ǻ�Ƶ����ʹ��
//���� ���ַ������� strlen
//���� �Ƚ������ַ�����С strcmp
//���� ��ӡ���� printf
//���� ȷ��������ֽ��� sizeof
//���˿⺯����������дЧ������������bug�����Լ���
// http://www.cplusplus.com/reference/
//���ܽắ������
// IO����
// �ַ�����������
// �ַ���������
// �ڴ��������
// ʱ��/���ں���
// ��ѧ����
// �����⺯��

//�磺 strcpy
// Copy string
// char * strcpy(char * destination, const char * source);
//including ������ �ַ� \0

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello bit!";
//	strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//������ȥ�ο��������վ
// ������
// ����ԭ��
// ��ϸ����
// Parameters������ʽ����
// Return Values ����ֵ
// Examples
// See also ���Ƶ������ġ�

//exm2�� memset
//void * memset (void * ptr, int value, size_t num)
//               ������                 size_t  �޷�������
// fill block of memory (memory �ڴ�)
//sets the first num bytes of the bolck of memory pionted by ptr to the specified value(interpreted as an unsigend char).


//int main()
//{
//	char arr[20] = "hello world";
//	memset(arr, 'x', 5);//��ǰ����ַ����x
//	memset(arr+6, 'y', 3);// +6 ƫ��6���ַ� ����wor���y
//	printf("%s", arr);  
//	return 0;
//}

//1.2�Զ��庯��
//�Զ��庯���Ϳ⺯��һ�����к�����������ֵ���ͺͺ�������
//�Զ��庯����Ҫ����Ա�Լ���ơ�

//ret_type fun_name(paral, *)
//{
//	stratment; //�����    {���ڲ�} �� ������
//}

//дһ���������������͵����ֵ

//#include<stdio.h>
//���� F10 ������ F11 ���뺯���ڲ�
//int get_MAX(int x, int y)     //�����Ķ���   
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_MAX(a, b);    //�����ĵ���
//	printf("%d", m);
//	return 0;
//}

//дһ������������������������
//#include<stdio.h>
//
//void Swap(int x, int y)
//{
//	int t = 0;
//	t = x;
//	x = y;
//	y = t;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ��a=%d,b=%d\n", a, b);
//	Swap(a, b);
//	printf("������a=%d,b=%d\n", a, b); //10 20
	                                     //����ǰ��a = 10, b = 20
		                                 //������a = 10, b = 20
//	return 0;
//}
//Ϊʲôû�н�����
//ʵ�ʲ��� a �� b
//��ʽ���� x �� y
//�� ʵ�� ���ݸ� �β� ��ʱ�� �β� �� ʵ�ε�һ����ʱ����
//�� �β� ���޸� ����Ӱ��ʵ�Ρ�

//int main()
//{
//	int a = 10;
//	int* p = &a;   //ָ��
//	a = 20; // ֱ�Ӹ�
//	*p = 20 // ��Ӹ�
//	return 0;
//}


//#include<stdio.h>
//
//void Swap(int *px, int *py)
//{
//	int t = 0;
//	t = *px;
//	*px = *py;
//	*py = t;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ��a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("������a=%d,b=%d\n", a, b); 
//	return 0;
//}
//�����ɹ�
// 
//�β� �� ʵ�� ��ν�����ϵ��
//�� ָ��   ȡ��ַȥ������ϵ��
// &a      &b
// int *px int *py

//����һ��ֵa ��� a * a �˷��ھ���

//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	scanf("%d", &a);
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}