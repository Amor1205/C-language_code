#define _CRT_SECURE_NO_WARNINGS
//����ֵ���ֵ
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


//��������
#include<stdio.h>

int main()
{
    float r;
    double p = 3.1415926;
    //float�ĸ��ֽ� ��Ϊp����Чλ����λ ��Ҫ��double
    scanf("%f", &r);
    // v�� double ͬ��   ����дr*r*r ��Ҳ��֪��Ϊʲô������^3 ��
    double V = 4.0 / 3.0 * p * r * r * r;
    printf("%.3f", V);
    return 0;
}

//���⣺����BMIָ������������ָ�������������ع����������������ƽ���ó�������
    
#include<stdio.h>

int main()
{
    int h, w;
    scanf("%d %d", &w, &h);
    float BMI = w / (h / 100.00) / (h / 100.00);
    //�������������� h/100 �ò������ս����������.00 float ��ú�������ֶ���Ϊ�����͡�
    printf("%.2f", BMI);
    return 0;
}