#include<stdio.h>

//下列程序的输出结果为（ ）

int main() {
    int m = 7, n = 4;
    float a = 38.4, b = 6.4, x;
    x = m / 2 + n * a / b + 1 / 2;
    printf("%f\n", x);
    return 0;
}
//27.00000000  
//答错了，计算的逻辑先是以各自的类型进行计算，m/2为3, n*a/b=24.000000 1/2=0，然后转成float型。    