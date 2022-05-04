#define _CRT_SECURE_NO_WARNINGS
//求四值最大值
//#include<stdio.h>
//int MAX(int x, int y, int z, int u)
//{
//    int q = x > y ? x : y;
//    int w = z > u ? z : u;
//    int v = q > w ? q : w;
//    return v;
//}
//int main()
//{
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    int m = MAX(a, b, c, d);
//    printf("%d", m);
//    return 0;
//}


//求球的体积
#include<stdio.h>

int main()
{
    float r;
    double p = 3.1415926;
    //float四个字节 因为p的有效位数八位 需要用double
    scanf("%f", &r);
    // v用 double 同理   这里写r*r*r 我也不知道为什么不能用^3 ！
    double V = 4.0 / 3.0 * p * r * r * r;
    printf("%.3f", V);
    return 0;
}

//问题：计算BMI指数（身体质量指数）。是用体重公斤数除以身高米数平方得出的数字
    
#include<stdio.h>

int main()
{
    int h, w;
    scanf("%d %d", &w, &h);
    float BMI = w / (h / 100.00) / (h / 100.00);
    //这里我首先用了 h/100 得不到最终结果，最后加了.00 float 最好后面的数字都变为浮点型。
    printf("%.2f", BMI);
    return 0;
}