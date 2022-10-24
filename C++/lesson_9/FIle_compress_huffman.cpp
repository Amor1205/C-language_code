#include"File_compress_huffman.h"
#include<iostream>
using std::cout;
using std::endl;
using std::string;

//构造函数
FileCompress::FileCompress()
{
    for (int i = 0; i < 256; ++i)
    {
        _fileInfo[i]._ch = i;
    }
}

void FileCompress::file_compression(const string &filePath)
{
    //以只读形式打开
    FILE *fIn = fopen(filePath.c_str(), "r");
    if (nullptr == fIn)
    {
        cout << "File cannot be found" << endl;
        return;
    }
    //1. 统计源文件中每个字节出现的次数并记录
    //不能直接fread()1024个，因为不确定有1024个字节。

    char rdBuff[1024];
    while(true)
    {
        size_t rdSize = fread(rdBuff, 1, 1024, fIn);
        if(0==rdSize)
            break;

        for (size_t i = 0; i < rdSize;++i)
        {
            _fileInfo[rdBuff[i]]._count++;
        }
    }
    // 2. 用字节的频次来创建huffman树
    // 3. 获取每个字节的huffman编码
    // 4. 用得到的编码对源文件中的每个字节进行改写。
}
void FileCompress::file_decompression(const string &filePath)
{
}
