#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "huffman.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
// Save information on the bytes, corresponding to the number of occurrences of the string (_count), and change it to _ch in char form.
struct ByteInfo
{
public:
    unsigned char _ch;
    size_t _count; // Number of occurrences
    string _code;  // Huffman encoding

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
    // Constructor
    FileCompress()
    {
        _fileInfo.resize(256);
        for (int i = 0; i < 256; ++i)
        {
            _fileInfo[i]._ch = i;
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
            string &Code = _fileInfo[root->_weight._ch]._code;
            HuffmanTreeNode<ByteInfo> *cur = root;
            HuffmanTreeNode<ByteInfo> *parent = cur->_parent;

            while (parent) // if parent node exists
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
        return filePath.substr(filePath.find_last_of('.') + 1); //'.' is not saved
    }
    void WriteHeadInfo(const string &filePath, FILE *fout)
    {
        // Get the source file suffix
        string headInfo;
        headInfo += get_file_suffix(filePath);
        headInfo += '\n';

        // Constructing character frequency information
        size_t appearLine_count = 0;
        string chInfo;
        for (auto &e : _fileInfo)
        {
            if (e._count == 0)
                continue;
            chInfo += e._ch;
            chInfo += std::to_string(e._count);
            chInfo += '\n'; // Line feed, one message occupies one line
            appearLine_count++;
        }
        headInfo += std::to_string(appearLine_count);
        headInfo += '\n';
        fwrite(headInfo.c_str(), 1, headInfo.size(), fout);
        fwrite(chInfo.c_str(), 1, chInfo.size(), fout);
    }
    void file_compression(const string &filePath)
    {
        // Open in read-only form
        FILE *fIn = fopen(filePath.c_str(), "rb");
        if (nullptr == fIn)
        {
            cout << "File cannot be found" << endl;
            return;
        }
        // 1. Count the number of occurrences of each byte in the source file and record them

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

        // 2. Creating huffman trees with byte frequencies
        HuffmanTree<ByteInfo> ht(_fileInfo, ByteInfo());
        // 3. Get the huffman encoding of each byte

        GenerateHuffmanCode(ht.get_rootNode());

        // 4. Rewrite each byte in the source file with the resulting encoding

        // We need to put fIn in the start position first, otherwise we won't be able to read the input, change the file pointer
        fseek(fIn, 0, SEEK_SET); // Start position offset by 0 bytes
        string file_name(get_file_name(filePath));
        file_name += "hz";
        FILE *fout = fopen(file_name.c_str(), "wb");

        // 3.5 Entering of data for decompression
        WriteHeadInfo(filePath, fout);

        // Need a char type to receive
        unsigned char sin_ch = '0'; // 0000 0000
        // Don't know if the eight bits are filled, use sin_ch_count to count
        int sin_ch_count = 0;
        while (true)
        {

            size_t readSize = fread(readBuff, 1, 1024, fIn);
            if (0 == readSize)
                break;
            for (size_t i = 0; i < readSize; ++i)
            {
                // Quote for name simplification
                string &strCode = _fileInfo[readBuff[i]]._code;
                for (size_t j = 0; j < strCode.size(); ++j)
                {

                    sin_ch <<= 1;          // Because the only way to add a 0 to the right is to shift a 0 to the left
                    if ('1' == strCode[j]) // Only change if you want to add 1
                    {
                        sin_ch |= 1; // The last bit of '|1' turns a 0 into a 1
                    }
                    sin_ch_count++;
                    if (8 == sin_ch_count)
                    {
                        fputc(sin_ch, fout); // Write to a file
                        sin_ch = '0';
                        sin_ch_count = 0;
                    }
                }
            }
        }
        // If the last 8 bits are not all full.
        if (sin_ch_count > 0 && sin_ch_count < 8)
        {
            sin_ch <<= (8 - sin_ch_count); // Move to far left
            fputc(sin_ch, fout);
        }
        fclose(fIn);
        fclose(fout);
    }

    // The information we need to enter is.
    // Information needed for decompression (original file suffix, number of characters, characters and frequencies of chars) + Compressed data
    // Note that we don't need to decompress the number of bits readSize, because the weight of the root node of the huffman tree is the number of characters we need to decompress.

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
        // 1. See if it's invalid
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

        // 2. Read the information needed to decompress
        // a. Read file name + suffix
        string deCompressFile(get_file_name(filePath));
        string suffix;
        get_line(fIn, suffix);
        deCompressFile += suffix;
        // b. Total number of lines of frequency information read
        string strInfo;
        get_line(fIn, strInfo);
        size_t lineCount = atoi(strInfo.c_str());
        for (size_t i = 0; i < lineCount; ++i)
        {
            strInfo = "";
            get_line(fIn, strInfo);
            // Separate treatment of line feeds
            if ("" == strInfo)
            {
                strInfo += '\n';
                get_line(fIn, strInfo);
            }

            //_fileInfo[strInfo[0]]._ch = strInfo[0];
            unsigned char ch = strInfo[0];
            _fileInfo[ch]._count = atoi(strInfo.c_str() + 1);
        }

        // 3. Restoring the huffman tree
        HuffmanTree<ByteInfo> ht(_fileInfo, ByteInfo());

        // 4. Decompression
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
                    ch <<= 1;
                    if (nullptr == cur->_left && nullptr == cur->_right) // find leaf nodes
                    {
                        fputc(cur->_weight._ch, fout); // write in
                        cur = ht.get_rootNode();       // Restore to the root node
                        fileSize++;
                        if (fileSize == cur->_weight._count)
                            break;
                    }
                }
            }
        }
        fclose(fIn);
        fclose(fout);
    }

private:
    std::vector<ByteInfo> _fileInfo; // Member variable
};
