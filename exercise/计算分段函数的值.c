#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int x = 0;
	scanf("%d", x);
	int y = 0;
	if (x < 0)
	{
		y = 2 * x - 5;
	}
	else if (x > 2)
	{
		y = -2 * x + 5;
	}
	else
	{
		y = 0;
	}
	printf("%d", y);
	return 0;
}
//2022是运行不成功的。
//警告	C6066	传递了非指针作为 _Param_(2)，而对“scanf”的调用需要指针参数，实际类型: “int”。	
//忽略了返回值scanf