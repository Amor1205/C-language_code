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

//#include<stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = add(a, b);
//	printf("%d", c);
//	return 0;
//}

//Ϊʲôadd��������ȡ��ַ����swap��Ҫ�أ�
//��Ϊ add���������ı� a��b��ֵ����swap������Ҫ�ı䱾����a��b��ֵ
//ͨ��ָ��Զ���һ�a��b����Ҫ��ȡ��ַ�ٽ�ȡ*px

//3.�����Ĳ���
//3.1ʵ�ʲ��� ʵ��
//��ʵ���ݸ������Ĳ�����ʵ�Ρ�
//ʵ�ο����ǣ����������������ʽ��������
//������ʵ���Ǻ������͵������ڽ��к�������ʱ����������ȷ����ֵ���Ա����Щֵ�����ݸ��β�

//3.2��ʽ���� �β�
//��ʽ������ָ�������������еı�������Ϊ��ʽ����ֻ���ں��������õĹ����в�ʵ�����������ڴ浥Ԫ��
//���Խ���ʽ��������ʽ����ֻ�ں�����Χ����Ч�����������١�
//�β�ʵ��������ʵ�ε�һ����ʱ����

//������ʵ�κ��βε����ֿ�����ͬ��Ҳ���Բ�ͬ

//4.��������
//4.1��ֵ����
// ������ʵ�κ��βηֱ�ռ�в�ͬ���ڴ�飬��ַ������ͬ
//4.2��ַ����
//�Ѻ����ⲿ�����������ڴ��ַ���ݸ���������
//���ִ��η�ʽ�����ú����ͺ�����ߵı�����������������ϵ��Ҳ���Ǻ����ڲ�����ֱ�Ӳ��������ⲿ�ı���

//������Ӧ��
//д�������ж��ǲ�������

//#include<stdio.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("%d��������\n",x);
//			flag = 0;
//			break;
//		
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if(1 == flag)
//	{
//		printf("%d������\n", x);
//	}
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	Judge(a);
//	return 0;
//}


//100-200�е�����

//#include<stdio.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("%d��������\n", x);
//			flag = 0;
//			break;
//
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (1 == flag)
//	{
//		printf("%d������\n", x);
//	}
//}
//int main()
//{
//	int j = 100;
//	for (j = 100; j <= 200; j++)
//		Judge(j);
//	return 0;
//}

//�Ż������� m = a * bʱ��a��b��һ����һ�������� <= sqrt(m)��
//�޸ĺ�������
//#include<stdio.h>
//#include<math.h>
//void Judge(int x)
//{
//	int i;
//	int flag = 0;
//	for (i = 2; i < sqrt(x); i++)   //sqrt(x)��ѧ��������math.h
//	{
//		if (x % i == 0)
//		{
//			printf("%d��������\n", x);
//			flag = 0;
//			break;
//
//		}
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (1 == flag)
//	{
//		printf("%d������\n", x);
//	}
//}

//ż��һ���������������Կ��Դӵ��ú���ʱ������
//int main()
//{
//	int j = 100;
//	for (j = 101; j <= 200; j+=2)
//		Judge(j);
//	return 0;
//}

//��ʦ���� �ж�
//return ����breakǿ����࣬�����return ����ֱ����������

//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i < 200; i += 2)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d  ", i);
//			count += 1;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//дһ�������ж�һ���ǲ�������
//#include<stdio.h>
//int JUDGE(int x)
//{
//	if (x % 4 == 0)
//	{
//		if (x % 100 == 0)
//		{
//			if (x % 400 == 0)
//				return 1;
//			else
//				return 0;
//		}
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (JUDGE(year) == 1)
//		printf("%d ", year);
//	else
//		printf("��������\n");
//	return 0;
//}

//1000-2000��������е����꣬���Ҽ���
//#include<stdio.h>
//int JUDGE(int x)
//{
//	if (x % 4 == 0)
//	{
//		if (x % 100 == 0)
//		{
//			if (x % 400 == 0)
//				return 1;
//			else
//				return 0;
//		}
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 1000;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (JUDGE(year) == 1)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d ", count);
//	return 0;
//}

//���򵥵ģ� ��&& ||

//#include<stdio.h>
//
//int JUDGE(int x)
//{
//	if (((x % 4 == 0)&& (x % 100 != 0))||(x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 1000;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (JUDGE(year) == 1)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d ", count);
//	return 0;
//}

//������д������ʱ����ðѺ����Ĺ��ܱ䵥һ����򵥡�
//���ھ۵���ϣ��Լ�������Ҫ�ͱ��˵Ĺ������


//д����ʵ�ֶ��ֲ���

//#include<stdio.h>
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 6;
//	int sz = sizeof(arr) / sizeof(arr[0]);
	//�ҵ��ˣ������±�
	//�Ҳ���������-1
//	int ret = binary_search(arr, k,sz);
//	if (ret != -1)
//		printf("�ҵ��ˣ��±���%d\n", ret);
//	else
//		printf("�Ҳ���\n");
//	return 0;
//}

//���鴫�β������ִ洢����һ��������ڴ棬���Ǵ�����һ��ָ����� 
//��sizeof��ָ������� ��4 ���� 8 ��32λ����x86 �� 4 �� x64 �� 8��
//�����ں����ڲ�����һ�������������ֵ�����Ԫ�ظ����ǲ����׵ġ�

//�������� c99����� bool
//������ʾ��ٵı���
//����ã�  <stdbool.h>

//#include<stdbool.h>
//
//bool is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return false;
//	}
//	return true;
//}
//bool �õĲ��࣬��Ϊc99�����룬bool��һ���ֽڡ�


//дһ��������ÿ����һ������������ͻὫnum ��ֵ����1
//#include<stdio.h>
//void ADD(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	ADD(&num);
//	printf("%d\n", num);
//	ADD(&num);
//	printf("%d\n", num);
//	ADD(&num);
//	printf("%d\n", num);
//	return 0;
//}

//5Ƕ�׵��ú���ʽ����
//5.1 Ƕ�׵���
//�������Ի�����õ�
//���������ǲ�����Ƕ�׶���ġ����ܰ�һ�������Ķ������һ���������棬
//��Ϊ�����ĵ�λ����ƽ�ȵġ�

//5.2 ��ʽ����
//�������Ǻ����ķ���ֵ
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", strlen("abcdef"));
//	printf("%d\n", len);
//}
//�������ֵ��ͬ������Ϊ��strlen("abcdef")�����ķ���ֵ����Ϊ��printf�Ĳ�������ͽ���ʽ���ʡ�

//�������ʽ����
//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));  //4321
//}
//������Ϊprintf�����ķ���ֵ���ַ���ӡ�ĸ��� 
//43 �������ַ��� ����ֵ����2 �� 2 ��1���ַ� ������ֵΪ1.��4321
//��ʽ���ʵ�ǰ���� �� �����з���ֵ
//������д����ֵ��ʱ��Ĭ�Ϸ���������int��Ĭ�Ϸ������һ��ָ��ķ���ֵ��д���ǳ���׼ȷ��Ӧ����ȷ��������ֵ��
//���ǣ��� �����鲻д����ֵ

//�������Ҫtest() �ڲ��Ĳ��������ǿ�����ȷ�ܾ��� ����test()ʱ��ʹ��test(void)

//������main��������������
//int main(int argc,char* argv[], char *envp[])


//6.1 ����������
//������������ ���֣��������ͣ�
//int Add(int ,int);
//��������ں��棬�������������ļ��У���������һ��Ȼ��ȡ�����档
//��������һ�����ͷ�ļ���

//ͷ�ļ���
//����������ΪԴ�ļ�����.c�ļ�
//������Դ�ļ�ͬ����.hͷ�ļ�������������

//�ڳ�ѧ��̵�ʱ�򣬾��ð����еĴ���д��һ���ļ�����㡣
//���ǣ��ڹ�˾�в�����ôд��
//��Э���Ƕȣ�ģ�黯�Ƕȿ���

//�����Ͷ���ֿ��ĺô���

//#include<stdio.h>
//int Add(int, int);
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}

//VS�����һ� ��Ŀ���� �޸�exe��.lib ��̬��
//���뾲̬�� #pragma comment(lib,"add.lib");
// #pramga once ͷ�ļ�ֻ����һ��

//7 �����ݹ�
//�����������ı�̼��ɳ�Ϊ�ݹ� recrusion
//ֻ�������ĳ���Ϳ��������������������Ҫ�Ķ���ظ����㣬�������˳���Ĵ�������
//����˼�룺���»�С

//��������ֵ����˳���ӡ����ÿһλ
//���磺
//���룺1234�����1 2 3 4

//%d ��ӡ�з�������������������
//%u �޷�������
//#include<stdio.h>
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	for (; num != 0;)
//	{
//		int a = num % 10;
//		num = num / 10;   //num /=10;
//		printf("%d ", a); //˳���ˣ����� 4 3 2 1
//	}
//	return 0;
//}

//�õݹ�
//1234��ֳ� 123 ÿһλ + 4
//123 ��ֳ�12��ÿһλ  + 3
//12  ��ֳ�1           + 2
//#include<stdio.h>
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}
//�ݹ�ı�Ҫ����
// 
//�ݹ�һ��Ҫд��������
//�����ջ��� Stack overflow
//ÿ�εݹ����֮��Խ��Խ�ӽ������������

//��ϰ2����д��������������ʱ���������ַ����ĳ���
//ģ��strlen
// 

//int my_strlen(char* str) //��������д��ָ�����ʽ
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		 count++;
//		 str++;   //����һ���ַ�  һ���ַ�һ���ֽ�
//	}
//	return count;
//}
//#include<stdio.h>
//int main()
//{
//	char ch[20] = "arrrwrar";
//	//scanf("%d", ch); //����ȥ���ַ���ַ��������char*����
//	int len = my_strlen(ch);
//	printf("%d\n", len);
//	return 0;
//}

//�õݹ飡
//#include<stdio.h>
//my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str+1); //��+1 ���� ++ ����++ �и����õģ����str��ֵ
//	else
//		return 0;
//}
//int main()
//{
//	char ch[20] = "arrrwrar";
//	int len = my_strlen(ch);
//	printf("%d\n", len);
//	return 0;
//}

//����:��ѭ���ķ���
//��n�Ľ׳�
//������õݹ�
//#include<stdio.h>
//int fac(int x)  
//{
//	if (x != 0)
//		return x * fac(x - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("ret = %d", ret);
//	return 0;
//}

//���n��쳲�������
//1 1 2 3 5 8 .
//#include<stdio.h>
//int fib(int x)
//{
//	if (x > 2)
//		return fib(x - 1) + fib(x - 2);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = fib(n);
//	printf("%d", num);
//	return 0;
//}
//�����n = 40 ��쳲�������������Ч��ʵ�ںܵ�
//�д������ظ�����
//�ɼ����ݹ��е�ʱ��Ч�ʺܵ�

//�õ���
//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//	int c = 2;
//	int n;
//	int count = 2;
//	scanf("%d", &n);
//	while(count != n)
//	{ 
//		c = a + b; 
//		count++;   
//		a = b;     
//		b = c;     
//	}
//	printf("%d", c);
//	return 0;
//}

//������2
//#include<stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = Fib(n);
//	printf("%d", num);
//	return 0;
//}

//�ݹ�����ݹ����̫�࣬���̫����׳���ջ�������ʽ
//����취��
//1.�ݹ�ĳɷǵݹ�
//2.��̬������Ϊstatic���󣬽������ջ�ϵľ�̬������Ϊ���ھ�̬���ϵ�static����


//�ݹ�˼�� ��Ŀ
//��ŵ����Ŀ ���ش󲩸�
//������̨������  C����ˢ��ѵ��Ӫ
