// #include"Myzip.h"
#include "File_compress_huffman.h"

void menu()
{
    cout << "***************************************" << endl;
    cout << "****** 1. huffman Compress   **********" << endl;
    cout << "****** 2. huffman Decompress **********" << endl;
    cout << "******      0. exit          **********" << endl;
    cout << "***************************************" << endl;
}
int main()
{
    int input = 0;
    bool isQuit = false;
    FileCompress fc;
    string fileName;
    cin >> input;
    while (1)
    {
        menu();
        cin >> input;
        switch (input)
        {
        case 0:
            isQuit = true;
            break;
        case 1:
            cout << "Please enter the name of the zip file:>";
            cin >> fileName;
            fc.file_compression(fileName);
            break;
        case 2:
            cout << "Please enter the name of the file you want to unzip:>";
            cin >> fileName;
            fc.file_decompression(fileName);
            break;
        }
        if (isQuit)
            break;
    }

    // Test();
    // FileCompress f;
    // f.file_compression("IMG_7185.JPG");
    // f.file_decompression("IMG_7185.hz");
    return 0;
}

//问题：
// 我们无法压缩中文字符，因为其未在ASCII码表中，所以会排在128位以后。显示出来是负值，所以会造成程序崩溃，因为我们无法用_fileInfo[readBuff[i]]._count去打开负值字符的_count。我们不能用char类型去定义readBUff，用unsigned char

// 2.
//我们用大的文件进行压缩 发现只走了一部分。
// FF 全1 以r打开的文本格式的文件搜到FF就会中止，一般的文本文件的末尾是FF结尾，但如果我们打开二进制文件，压缩的文件中可能在中途出现FF。所以不能以r打开，而应该以rb打开


//优化：范式huffman树
//对于同一层节点中所有的叶子节点都调整到左边，然后对于同一层的叶子节点按照符号顺序从小到大调整，最后按照左0右1的方式分配编码。
//找huffman编码更好找了。不需要递归然后用孩子双亲法去找
//范式huffman编码可以算，同组的最左边00 然后+1 01 再+1 10
//编码长度就是从根走到叶子走过的边的个数，就是位长。
//同层走完了，先+1 再左移一位， 10 + 1 = 11 <<1 = 110
//比如说下一个就是编码长度为5，就110 + 1 = 111 <<2 => 11100
//我们有huffman树中的符号和其编码位长，就可以进行排序：编码位长为第一字段，编码大小为第二字段排序。
//这种方法比递归法更快，会让压缩的效率变高，同时它也可以提高压缩率。可以不用保存频次信息，只需要保存编码位长即可，最多保存256个字符的。



//测试
//beyondCompare
//测压缩率
//文本文件和二进制格式文件的压缩比率
//测试程序的压缩性能
//对压缩文件进行二次压缩，多次压缩给出结果。
