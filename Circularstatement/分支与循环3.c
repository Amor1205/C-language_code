#define _CRT_SECURE_NO_WARNINGS

//���ֱȽ� �۰���ң��������飩
// left ��Ϊ���±꣬right ��Ϊ���±꣬mid��Ϊ�м�Ԫ���±�
// �Ƚ� input �� midԪ�صĴ�С��
// ��С��Χ  ��input �� ���±� ��� mid + 1 
//           ��input С ���±� ��� mid - 1
// 
// 

//#include<stdio.h>
//
//int main()
//{
//	int arr[10]= { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("%d ", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("�Ҳ���\n");
//	return 0;
//}


//�Լ�д��:
// 
//#include<stdio.h>
//
//int main()
//{
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int r = sz - 1;
//	int right = r;
//	int input = 11 ;
//	int mid = (left + right) / 2;         // ( left + right )/2 ���ܼ������������͵����ֵ
//	int i;                                // ������� left + (right - left)/2  ����Խ��
//	int flag = 0;                         // ���ֱܷ���Զ���ӣ�����ֻ�ܳ�һ�Ρ�
//	while (0 == flag)
//	{
//		if (input == arr[mid])
//		{
//			flag = 1;
//			printf("%d\n",mid);
//			break;
//		}
//		else if (input > arr[mid])
//		{
//			left = mid;
//			mid = (left + right) / 2;
//		}
//		else
//		{
//			right = mid;
//			mid = (left + right) / 2;
//		}
//		if (mid == left)
//			break;
//	}
//	if (0 == flag)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}
// 
//�ַ���Ծ


//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "hello world!!!!!";                     //�ַ����� �� �������������
//	char arr2[] = "################";                     //�ַ�������Ԫ�ظ����� sz - 2����Ҫ��һ��\0������ strlen - 1
//											              //����������Ԫ�ظ����� sz - 1
//	int r = strlen(arr1) - 1 ;
//	int l = 0;
//	while(l<=r+1)
//	{
//
//		printf("%s\n", arr2);
//		arr2[r] = arr1[r];
//		arr2[l] = arr1[l];
//		l++;
//		r--;
//		Sleep(1000);                     //Sleep(1000) ����1000ms   ��windows.h ͷ�ļ�
//		system("cls");                   //system�⺯��  cls---���� ��stdlib.h ͷ�ļ� 
//	}
//	
//
//	return 0;
//}
//��д����ʵ�ֵ�¼�龰

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20];
//	int flag = 0;
//	//�����������ַ�����abcdef
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n����������:>");
//		scanf("%s", password);
//		if (strcmp(password,"abcdef") == 0)    //�ַ�������ַ���������ַ����Ƚ�����strcmp
//	    										//ͷ�ļ���string.h
//		{
//			printf("\n��½�ɹ�");
//			flag = 1;
//			break;
//		}
//		else
//			printf("\n��½ʧ�ܣ���������������");
//	}
//	if (flag = 0)
//		printf("��½ʧ��");
//	return 0;
//}

//���Բ���һ���������1-100��
//������ ����˵�´��ˣ�С��˵��С��

//������ؼ��㣺
// ʱ�����ʹ�ã���timeͷ�ļ��������ʱ����Ļ�����Ҫ(unsigned int)time(NULL)  ǰ����ǿ��ת����int���� ��Ϊtime��������ֵ��time_t
// �������ȡ�ã���stdlibͷ�ļ���rand(),srand()������Ϊ����srand�м����һֱ�仯��ʱ�����srand((unsigned int)time(NULL))
// do while(input)������ʹ�ã� input ֻ������ 0 �� 1�� 0��ʱ��ѭ����������Ϸ����
// ���ӵĴ�����Ҫ��д������д֦��

//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("**************************\n");
//	printf("********* 1. play ********\n");
//	printf("********* 0. exit ********\n");
//	printf("**************************\n");
//}
//void game()
//{
//	//1.���������
//	//2.������
//	int r = rand();//����������ĺ���   ��Χ�� 0 - RAND_MAX ��32767��
//	                 //��rand ����srand    
//					 //��<stdlib.h>
//	int ret = r % 100 + 1;
//	printf("%d\n", ret);
//	int guess;
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));  //��Ϊtime��������ֵ��time_t���͵� ��Ҫ��unsigned intǿ��ת��
//	do
//	{
//		menu();
//		printf("��ѡ��:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������\n");
//			game();
//			
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������ѡ��\n");
//			break;
//		}
//	}
//	while (input);
//	return 0;
//}


//ʱ�����ÿ��ÿ�붼�ڷ����仯����ֵ
//��ε���ʱ�����
//time(NULL --- ��ָ��)  ����ֵ�� time_t
//���ǰ���ǿ��ת��Ϊunsigned int���;Ϳ��������ֵ��
//����time.hͷ�ļ�


//���������   
//srand((unsigned int)time(NULL));  һ�γ�����ֻ��Ҫ����һ�Σ��ʷ�����������
//int ret = rand();
//NULL��ָ�� ��˼�ǲ������ֵ (define NULL = 0)
//  ����������ȷ����Χ��
//  ��õ�0-100������ rand % 100 + 1 ���� 1- 100������


//���Թػ���
//system(shutdown -s -t 60)  
//ֹͣ�ػ�shutdown -a

//��ʾgoto

//#include<stdio.h>
//#include<string.h>

//int main()
//{
//	char input[20] = { 0 };
//again:
//	system("shutdown -s -t 60");
//	printf("��60s��ػ�������������\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//�������goto��Ҳ�ǿ���д�ܺõĴ��롣

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("��60s��ػ�������������\n");
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			printf("ȡ���ػ�\n");
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

#include<stdio.h>

#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("*****************************\n");
	printf("********** 1.play ***********\n");
	printf("********** 0.exit ***********\n");
	printf("*****************************\n");
}
void game()
{
	int rad = rand();
	int r = rad % 100 + 1;
	int guess;
	while (1)
	{
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("��С�ˣ�\n");
			printf("����������:>");
		}
		else if (guess > r)
		{
			printf("�´��ˣ�\n");
			printf("����������:>");
		}
		else
		{
			printf("�¶��ˣ�\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ʼ��Ϸ?(1/0):>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			break;
		default:
			printf("�����������������:>");
			break;
		}
	} while (input);
	return 0;
}