#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>

//int main()
//{
//	if (3 == 5)
//		printf("hehe\n");
//	return 0;
//}
// 
//  ����֧
//int main()
//{
//	int a = 10;
//	if (a = 3)
//		printf("hehe\n");
//	return 0;
//}
// 
// 
//˫��֧
//int main()
//{
//	int age = 10;
//	scanf("%d", &age);
//	if (age > 18)
//		printf("����\n");
//	else
//		printf("δ����\n");
//	return 0;
//}


//����  ����д������������ ʾ��
//int main()
//{
//	int age = 10;
//	if (18 <= age < 28)
//		printf("����\n");    //��ӡ�ɹ�
//	return 0;
//}
//int main()
//{
//	int age = 10;
//	if (18 <= age && age < 28)
//		printf("����\n");  
//	return 0;
//}

//�ж�һ�����Ƿ�Ϊ����
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	if (num % 2 == 1)
//		printf("����\n");
//	else
//		printf("ż��\n");
//	return 0;
//}

//���1 - 100 ֮�������

//int main()
//{
//	int num = 0;
//	for (num = 0; num < 100; num++)
//	{
//		if (num % 2 == 1)
//			printf("%d\n", num);
//	}
//	return 0;
//}


//switch
//int main()
//{
//	int date;
//	scanf("%d", &date);
//	switch (date)
//	{
//	case 1:
//		printf("����1\n");
//		break;
//	case 2:
//		printf("����2\n");
//		break;
//	case 3:
//		printf("����3\n");
//		break;
//	case 4:
//		printf("����4\n");
//		break;
//	case 5:
//		printf("����5\n");
//		break;
//	case 6:
//		printf("����6\n");
//		break;
//	case 7:
//		printf("����7\n");
//		break;
//	}
//	return 0;
//}


//����1-5 ���weekday
//���6-7 ���weekend

//int main()
//{
//	int d;
//	scanf("%d", &d);
//	switch (d)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("weekday\n");
//			break;
//		case 6:
//		case 7:
//			printf("weekend\n");
//			break;
//		default:
//			printf("����\n");
//	}
//	return 0;
//}

//while  ��ӡ1����10

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d\n", i);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar())!= EOF)   //getchar() ��������һ�� ���� ���ַ�Ҳ�����ͣ�
//	{                                // =EOF ���ǰ�ctrl + Z ����ֹ 
//		                             // ��=EOF ���ǲ����� EOF 
//		                             // Ҳ����ֻҪ����Ctrl z �ͻ�һֱѭ��
//		putchar(ch);   //putchar(ch) ������� ch 
//	}
//	return 0;
//}
//
//int ch = 0;
//while ((ch = getchar()!= '\n'))
//{
//	;           //ֻ��һ���ֺŵ���˼�� ִ��while �����ڵĳ���
//}


//����

//int main()
//{
//	char password[20]= { 0 };
//	printf("����������-->");
//	scanf("%s", password);  //�ַ���������ǵ�ַ ����ȡ��ַ�� ��%s��ӡ��
//
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("��ȷ������(Y/N):>");
//	int ret = getchar();
//	if ('Y' == ret)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}


//int main()
//{
//	char ch = '\0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')  //ch ��ASCIIֵС�� 0 ��ֵ ���� ����9��
//			continue;
//		putchar(ch);
//	}
//	//ֻ��ӡ�����ַ�
//	return 0;
//}


//д���뽫�����������Ӵ�С�����
//���磺
//���룺2 3 1
//�����3 2 1

//try 1  ̫����������

//#include<stdio.h>
//
//int main()
//{
//	int arr[3];
//	scanf("%d %d %d", &arr[0], &arr[1], &arr[3]);
//	int a = arr[0] > arr[1] ? arr[0] : arr[1];
//	int a1 = arr[0] > arr[1] ? arr[1] : arr[0];
//	//a ��  0 �� 1 ��ϴ��,a1�� 0 �� 1 ���С�ģ�a > a1
//	int b = a > arr[2] ? a : arr[2];
//	int b1 = a > arr[2] ? arr[2] : a;
//	int c = b1 > a1 ? b1 : a1;
//	//b �� �������ֵ, b1��a�� arr[2]��Сֵ
//	printf("%d %d %d",b,c,a)
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if(a>b)
//	{
//		t = a; 
//		a = b;
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", c,b,a)
//		;	return 0;
//}


//дһ�������ӡ1-100֮������3�ı���������



//int main()
//{
//	int i = 1;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
// 
// 
//���������������������������Լ��

//#include<stdio.h>
 //ŷ������㷨
//int main()
//{
//	int a, b, t;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}   //a > b 
//	int i = a % b;
//	while (i>0)
//	{
//		a = b;
//		b = i;
//		i = a % b;
//		printf("%d", b);
//	}
//
//	return 0;
//}


//#include<stdio.h>
//
//int main()
//{
//	int a, b, t;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	while (t = a % b)
//	{
//		a = b;
//		b = t;
//	}
//	printf("%d\n", b);
//	return 0;
//}
//��ӡ���� 1000 - 2000
//��������������N�ܹ���4���������Ҳ��ܱ�100��������������
//���ߣ�N�ܱ�400������Ҳ������
//����4��һ���Ұ��겻��ÿ400������һ��
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	for (a = 1000; a < 2000; a++)
//	{
//		if (a % 4 == 0)
//		{
//			if (a % 100 != 0)
//			{
//				printf("%d ", a);
//			}
//		}
//		if (a % 400 == 0)
//		{
//			printf("%d ", a);
//		}
//	}
//		
//	return 0;
//}

//��ӡ����
//#include<stdio.h>
//
//int main()
//{
//	int a, j;
//	int i = 0;
//	for (a = 100; a <= 200; a++)
//	{
//		for (j = 2; j < a; j++)
//		{ 
//			if (a % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == a)
//		{
//			printf("%d ", a);
//			i++;
//		}
//	}
//	printf("\ncount=%d ", i);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int year = 1001;
//	int count = 1;
//	for (year = 1001; year <= 2000; year++)
//	{
//		if (year % 4 == 0)
//		{
//			if (year % 100 != 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//			if (year % 400 == 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//		}
//
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//���������򷽷�����һ����ʱ��������
//������Ҫ����a �� b

//int main()
//{
//	int a, b, t;
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}    // ʵ��a��b��λ��
//	return 0;
//}

//�����Լ����շת�������
//a%b = t
//a = b   b = t 
//a%b = t
//һֱ����ѭ����ȥ��Ȼ�����t��0 ��0��ʱ���b��������Ҫ�Ĺ�Լ��
