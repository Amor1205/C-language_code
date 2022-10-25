#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Myzip.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
//保存字节的信息，对应字符串_Code的出现次数_count，并改成用char形式的_ch。
struct ByteInfo
{
public:
    unsigned char _ch;
    size_t _count; //看出现的次数
    string _code;  // Huffman编码

    ByteInfo(size_t count = 0)
        : _count(count) {}
    ByteInfo operator+(const ByteInfo &byte) const
    {
        return ByteInfo(_count + byte._count);
    }
    bool operator>(const ByteInfo &byte) const
    {
        return _count > byte._count;
    }
    bool operator==(const ByteInfo &byte) const
    {
        return _count == byte._count;
    }
    bool operator!=(const ByteInfo &byte) const
    {
        return _count != byte._count;
    }
    size_t operator->()
    {
        return _count;
    }
};

std::ostream &operator<<(std::ostream &out, const ByteInfo &byte)
{
    out << byte._count;
    return out;
}

class FileCompress
{
public:
    //声明
    // FileCompress();
    // void file_compression(const string &filePath);
    // void file_decompression(const string &filePath);

    //定义：

    //构造函数
    FileCompress()
    {
        _fileInfo.resize(256);
        for (int i = 0; i < 256; ++i)
        {
            // i是字符的ASCII码值
            //同样可以用_fileInfo['a'].ch
            _fileInfo[i]._ch = i;
            // _fileInfo[i] 是 ByteInfo类型对象，对象访问成员用.
        }
    }
    void GenerateHuffmanCode(HuffmanTreeNode<ByteInfo> *root)
    {
        if (nullptr == root)
        {
            return;
        }
        GenerateHuffmanCode(root->_left);
        GenerateHuffmanCode(root->_right);

        //找叶子节点
        if (nullptr == root->_left && nullptr == root->_right)
        {
            // root->_weight 是ByteInfo类型的root
            // root->_weight._ch是 统计频次的字符名
            string &Code = _fileInfo[root->_weight._ch]._code;
            //写&是因为写一串太麻烦。
            HuffmanTreeNode<ByteInfo> *cur = root;
            HuffmanTreeNode<ByteInfo> *parent = cur->_parent;

            while (parent) //双亲存在
            {
                if (cur == parent->_left)
                {
                    Code += '0';
                }
                else
                    Code += '1';

                cur = parent;
                parent = cur->_parent;
            }
            reverse(Code.begin(), Code.end());
        }
    }
    string get_file_suffix(const string &filePath)
    {
        return filePath.substr(filePath.find_last_of('.') + 1); //不存.
    }
    void WriteHeadInfo(const string &filePath, FILE *fout)
    {
        //获取原文件后缀
        string headInfo;
        headInfo += get_file_suffix(filePath);
        headInfo += '\n';

        //构造字符频次信息
        size_t appearLine_count = 0;
        string chInfo;
        for (auto &e : _fileInfo)
        {
            if (e._count == 0)
                continue;
            chInfo += e._ch;
            chInfo += ':';
            chInfo += std::to_string(e._count);
            chInfo += '\n'; //换行，一条信息占用一行
            appearLine_count++;
        }
        headInfo += std::to_string(appearLine_count);
        headInfo += '\n';
        fwrite(headInfo.c_str(), 1, headInfo.size(), fout);
        fwrite(chInfo.c_str(), 1, chInfo.size(), fout);
    }
    void file_compression(const string &filePath)
    {
        //以只读形式打开
        FILE *fIn = fopen(filePath.c_str(), "rb");
        if (nullptr == fIn)
        {
            cout << "File cannot be found" << endl;
            return;
        }
        // 1. 统计源文件中每个字节出现的次数并记录
        //不能直接fread()1024个，因为不确定有1024个字节。

        unsigned char readBuff[1024];
        while (true)
        {
            size_t readSize = fread(readBuff, 1, 1024, fIn);
            if (0 == readSize)
                break;

            for (size_t i = 0; i < readSize; ++i)
            {
                _fileInfo[readBuff[i]]._count++;
            }
        }
        //用来检验第一步的/或者是调试，推荐调试
        // for (int i = 0; i < 256;++i)
        // {
        //     if(_fileInfo[i]._count)
        //     {
        //         cout << (char)i << ":" << _fileInfo[i]._count << endl;
        //     }
        // }

        // 2. 用字节的频次来创建huffman树
        ;
        HuffmanTree<ByteInfo> ht(_fileInfo, ByteInfo());
        // ht.PreOrderPrint(ht.get_rootNode());//判断是否成功
        // 3. 获取每个字节的huffman编码
        //从根 左走编码0，右走编码1.
        //从叶节点，往回找，是左叶子节点则0，右1
        GenerateHuffmanCode(ht.get_rootNode());

        // 4. 用得到的编码对源文件中的每个字节进行改写。

        //我们要先把fIn放到起始位置，否则读不到输入进去的东西,改变文件指针
        fseek(fIn, 0, SEEK_SET); //起始位置偏移0个字节
        string file_name(get_file_name(filePath));
        file_name += "hz";
        FILE *fout = fopen(file_name.c_str(), "wb");

        // 3.5 用来解压缩的数据的录入
        WriteHeadInfo(filePath, fout);

        //需要一个char类型来接收
        unsigned char sin_ch = '0'; // 0000 0000
        //不知道八个bit位是否填满
        int sin_ch_count = 0;
        while (true)
        {

            size_t readSize = fread(readBuff, 1, 1024, fIn);
            if (0 == readSize)
                break;
            for (size_t i = 0; i < readSize; ++i)
            {
                //引用为了简化名称
                string &strCode = _fileInfo[readBuff[i]]._code;
                for (size_t j = 0; j < strCode.size(); ++j)
                {

                    sin_ch <<= 1;          //因为只有左移1个0，才能在右边添加一个0
                    if ('1' == strCode[j]) //如果要添加的是1 才需要改变
                    {
                        sin_ch |= 1; // 最后一位 |1 就把0变成1了
                    }
                    sin_ch_count++;
                    if (8 == sin_ch_count)
                    {
                        fputc(sin_ch, fout); //写到文件中
                        sin_ch = '0';
                        sin_ch_count = 0;
                    }
                }
            }
        }
        //如果最后一次的8个bit位没全满，
        if (sin_ch_count > 0 && sin_ch_count < 8)
        {
            sin_ch <<= (8 - sin_ch_count); //移到最左边
            fputc(sin_ch, fout);
        }
        fclose(fIn);
        fclose(fout);
    }
    //解压缩很多方式，比如利用unorder_map<string,char> 建立编码和字符的关系，查压缩文件的头一个bit位在string有无对应，如无，查头2个bit在string中有无对应，直到有对应后，替换为char。但是这种需要频繁对比，非常麻烦。
    //我们可以用huffman树解压缩，非常方便：取一个字节，1往右走，0往左走，走到叶子节点为止，我们就可以查到对应字符了。随后让指针回到根节点继续走，直到比特流结束
    //但是我们要保存一棵树。我们当初创建一棵树是通过字符和它出现的频次，所以我们保存就是保存字符与其对应的出现频次。
    //但是仅仅保存字符和频次不行，因为如何区分他们与我们压缩的bit流呢？先提供这些字符的个数，比如文件中只有abcde五个字符，那么我们先在文件中录入5，表示我们会读取到5个字符及其出现频次。
    //此外我们还需要保存原文件的格式，也就是后缀，否则无法还原。

    //所以我们需要录入的信息有：
    //解压缩需要用到的信息(原文件后缀，字符个数，字符及字符出现频次)+压缩数据
    //注意，我们不需要解压缩的bit位个数readSize，因为huffman树根节点的权值就是我们需要解压出来的字符的个数。
    //
    string get_file_name(const string &filePath)
    {
        size_t pos = filePath.find_last_of('.');
        size_t curpos = 0;
        string file_name;
        for (; curpos <= pos; curpos++)
        {
            file_name += filePath[curpos];
        }
        return file_name;
    }
    void get_line(FILE *fIn, string &strInfo)
    {
        while (!feof(fIn))
        {
            char ch = fgetc(fIn);
            if (ch == '\n')
                break;
            strInfo += ch;
        }
    }
    void file_decompression(const string &filePath)
    {
        // 1. 看是否非法
        if (get_file_suffix(filePath) != "hz")
        {
            cout << "invalid compressend file formats" << endl;
            return;
        }
        FILE *fIn = fopen(filePath.c_str(), "rb");
        if (nullptr == fIn)
        {
            cout << "invalid pathway of file" << endl;
            return;
        }

        // 2. 读取解压缩需要用到的信息
        // a. 读取文件名+后缀
        string deCompressFile(get_file_name(filePath));
        string suffix;
        get_line(fIn, suffix);
        deCompressFile += suffix;
        // b. 读取频次信息总行数
        string strInfo;
        get_line(fIn, strInfo);
        size_t lineCount = atoi(strInfo.c_str());
        for (size_t i = 0; i < lineCount; ++i)
        {
            strInfo = "";
            get_line(fIn, strInfo); //没有考虑要读取的字符是换行的情况。
            //对换行进行单独处理
            if ("" == strInfo)
            {
                strInfo += '\n';
                get_line(fIn, strInfo);
            }

            // _char : _fequency
            //_fileInfo[strInfo[0]]._ch = strInfo[0];//_ch可以不用管，因为构造函数已经构造好了。这里只是重复
            unsigned char ch = strInfo[0];
            _fileInfo[ch]._count = atoi(strInfo.c_str() + 2);
        }

        //用来检查结果
        // for (size_t i = 0; i < 256;++i)
        // {
        //     if(_fileInfo[i]._count != 0)
        //         cout << _fileInfo[i]._ch << " : " << _fileInfo[i]._count << endl;
        // }

        // 3. 还原huffman树
        HuffmanTree<ByteInfo> ht(_fileInfo, ByteInfo());

        // 4. 解压缩
        FILE *fout = fopen(deCompressFile.c_str(), "wb");
        unsigned char readBuff[1024];
        size_t fileSize = 0;
        HuffmanTreeNode<ByteInfo> *cur = ht.get_rootNode();
        while (true)
        {
            size_t readSize = fread(readBuff, 1, 1024, fIn);
            if (0 == readSize)
                break;
            for (size_t i = 0; i < readSize; ++i)
            {
                char ch = readBuff[i];
                for (int j = 0; j < 8; ++j)
                {
                    if (ch & 0x80) // 1000 0000
                        cur = cur->_right;
                    else
                        cur = cur->_left;
                    ch <<= 1;                                            //左移
                    if (nullptr == cur->_left && nullptr == cur->_right) //找到叶子
                    {
                        fputc(cur->_weight._ch, fout); //写入
                        cur = ht.get_rootNode();       //恢复到根节点
                        fileSize++;
                        if (fileSize == cur->_weight._count) //读取够fileSize了
                            break;
                    }
                }
            }
        }
        fclose(fIn);
        fclose(fout);
    }
    //成员变量
    std::vector<ByteInfo> _fileInfo;
    //创建一个名为_fileInfo，类型为ByteInfo的vector
    // std::vector<ByteInfo> _fileInfo[256];错误！！！没有这种定义方法。
    // char是-128 ~ 127

    // vector<int> v
    // v[1]
};