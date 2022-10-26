# huffman压缩

文件压缩是什么：

> 文件压缩是不丢失有用信息的前提下，缩减数据量以减少存储空间，提高其传输、储存和处理效率，或按照一定的算法对文件中数据进行组织，减少数据的冗余和存储的空间的一种技术方法。

为什么压缩：

> 1. 紧缩数据存储容量，减少存储空间。
> 2. 可以提高数据传输的速度，减少带宽占用量，提高通讯效率
> 3. 对数据的一种加密保护，增强数据在传输过程中的安全性。

压缩的分类：

> - 有损压缩
>
>   有损压缩是允许压缩过程中损失一定的信息，虽然解压缩的时候不能完全恢复原始数据，但是所损失的部分对理解原始图像的影响比较小，却换来了大的多的压缩比。即指使用压缩后的数据进行重构，冲欧后的数据与原来的数据有所不同，但不影响人对原始资料表达的信息造成误解。
>
> - 无损压缩
>
>   对文件中数据按照特定的编码格式进行重新组织，压缩后的压缩文件可以被还原成于源文件完全相同的格式，不会影响文件内容，对于数码图像而言，不会使图像细节有任何损失。

> **lz77**的原理：将重复出现的内容采用更短的长度距离对来进行替换
>
> 在文件中的局部范围内，有些语句可能会重复出现，对于重复出现得于能否想办法让其变短，如果可以，能够起到压缩的目的。如：
>
> ```ASN.1
> abcdef123abcd456abcdef789
> ```
>
> 对于文件中重复出现的词语，可以使用<长度, 距离>对其进行替换，长度是重复文件所占的字节。距离是后文中重复出现词语的首字节与前文中重复的词语的首字节的位置差。如果有出现多次的，看是否有重复度更高的，没有再取最近的。
>
> ```asp
> abcd123<4,7>456<6,16>789
> ```

但是如果是没有较长语句的重复，只是在字节层面上有些重复。一个字节占八个比特位，如果能够给每个字节找一个小于8bit位的编码，来替换文件中的字节，比如：

> - 定长编码：如果对四个字符ABCD进行编码，只需要用两个bit位
>
>   A: 00 B: 01 C: 10 D: 11
>
>   用找到的编码对文件中的每个字节来进行替换：11110001就代表ddac，11110110就代表着ddbc。
>
>   但是字节重复出现的次数不一样，能否让出现次数多的字节对应的编码位数少一些，这样就会让占用的空间少一些。
>
> - 动态不等长编码：A： 100 B 101 C 11 D 0
>
>   要求：一个编码不能是另外编码的前缀。否则解码会错误。
>
>   用huffman树，所有字符对应编码都在叶子节点的位置，因此不可能出现某个字符编码是其他字符编码前缀的情况，
>
> 这是**基于huffman树编码的压缩**

GZIP的第一步时使用LZ77快速的对文件中的重复的短语进行压缩，随后进行huffman树压缩。

> huffman树
>
> 从二叉树的根节点到二叉树中所有叶子节点的路径长度（边的个数）与相应权值的乘积之和为该二叉树的带权路径长度WPL。
>
> 叶子节点的权值不同，带权路径长度不同。
>
> **huffman树就是带权路径最小的二叉树。**
>
> 我们需要让权值大的靠近根。

3. 

huffman编码压缩过程：

1. 统计源文件中每个字节出现的次数并记录
2. 用字节的频次来创建huffman树
3. 获取每个字节的huffman编码
4. 用得到的编码对源文件中的每个字节进行改写。





## 项目过程

### 哈夫曼树的构建

#### 树节点的构建

哈夫曼树是带权路径最小的二叉树，所以我们构建哈夫曼树节点时，需要：左右孩子和权重，至于父亲要不要我们不确定，所以先不写。

```c++
template <class W>
struct HuffmanTreeNode
{

    HuffmanTreeNode<W> *_left;
    HuffmanTreeNode<W> *_right;
    W _weight;

    HuffmanTreeNode(const W &weight = W())
        : _left(nullptr), _right(nullptr), _weight(weight)
    {
    }
};
```

#### 树的构建

根节点的指针Node* 作为私有成员变量。先写好

```c++
template<W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	huffmanTree() :_root(nullptr){}
private:
	Node* _root;
}
```

huffman树的构建：

1. 由给定的n个权值[w1, w2, w2...., wn]构造n个节点，叫二叉树森林。

2. 取出两个**最小的权值节点**，分别作为新节点的左右子树，然后把构造的新节点加到森林中。

   如何取两个最小权值节点？用堆来保存，也就是用优先级队列，优先级队列默认生成大堆，而我们需要最小的权值节点，所以我们要构造小堆。自己写Compare类。

   ```c++
   class Compare
   {
   pubilc:
   	bool operator()(const Node*left, const Node* right) const
   	{
   		return left->_weight > right->_weight;
   	}
   }
   ```

3. 最终森林中只有一棵树时，结束。

```c++
HuffmanTree(const std::vector<W> &v)
{
	//构建类似小堆的优先级队列
	std::priority_queue<Node*, std::vector<Node*>, Compare> q;
	//用所有权值构造只有根节点的二叉树森林
	for(auto& e : v)
	{
		q.push(new Node(e));
	}
  while(q.size()>1)
  {
    //存左孩子
    Node* left = q.top();
    q.pop();
    //存右孩子
    Node* right = q.top();
    q.pop();
    //left和right作为新节点的左右子树。新节点的权重为左右子树之和。
    Node* parent = new Node(left->_weight + right->_weight);
    //建立链接
    parent->_left = left;
    parent->_right = right;
    //父节点放入森林
    q.push(parent);
  }
  //q.size()此时为1，top即huffman树
  _root = q.top();
}
```

#### 树的销毁

因为我们的节点都是new出来的，所以使用完成之后必须要调用析构函数进行析构。常规操作，利用递归销毁树，记得把Destroy设置为私有成员函数，否则可能会调用。

```c++
~HuffmanTree()
{
	Destroy();
}
private:
	//利用递归
	void Destroy(Node*& root)
	{
		if(root)
		{
			//先销毁左孩子
			Destroy(root->_left);
			//再销毁右孩子
			Destroy(root->_right);
			//删除根节点并且置空
			delete root;
			root = nullptr;
		}
	}	
```

### 压缩

#### ByteInfo的构建

我们需要统计一个文件中每个字符出现的次数，还需要记录它的huffman编码，因为我们需要用huffman编码去压缩和解压缩。其余的应该不需要，只需要它定义成员变量即可。

```c++
struct ByteInfo
{
public:
	unsigned char _ch;
	size_t _count;//the count of appearence of _ch
	string _code;// huffman_code
    
  ByteInfo(size_t count = 0)
     : _count(count) {}
}
```

#### FileCompress类

我们定义FileCompress类，里面包含着最主要的文件压缩函数和构造函数等等。

##### 设定成员对象和构造函数

最需要注意的是FileCompress的成员变量，我们需要创建成员变量为<ByteInfo>类型的vector，这是因为我们创建Huffman树就需要一个vector，因为我们需要存放file里面每个字符的信息，所以取名为_fileInfo。相应的，我们需要构造函数需要做的事情是把每个字符的 _ch构造好。

```c++
class FileCompress
{
public:
	FileCompress()
	{
		_fileInfo.resize(256);
		for(int i = 0;i < 256; ++i)
		{
			_fileInfo[i]._ch = i;
      
//需要字符全部用unsigned char类型，因为有的字符不在ASCII码表中，如果用char，如果 i>128 会有负数，负数在ASCII码表中没有，会报错。
		}
	}
private:
	std::vector<ByteInfo> _fileInfo;
	
}
```

##### 写压缩函数

我们需要做的就是，统计源文件中每个字节出现的次数并且记录，用字节的频次创建huffman树，获取每个字节的huffman编码，用得到的编码对源文件中的每个字节进行改写并写入文件。

```c++
void file_compress(const string& fileName)//传入名称
{
	//只读形式打开
	FILE* fIn = fopen(fileName.c_str(),"rb");
	//我们要以二进制的方法读和写，否则会遇到FF中止。
	if(nullptr == fIn)
	{
		cout<<"File cannot be found"<<endl;
		return;
	}
	
	//1.统计源文件中每个字节出现的次数并记录
	
	unsigned char readBuff[1024];//一次读1kb大小
	while(1)
	{
		size_t readSize = fread(readBuff,1,1024,fIn);
		if( 0 == readSize)//无字节可读，中止
			break;
    //计数读取的1024个字节。
		for(size_t i = 0;i<readSize;++i)
    {
      _fileInfo[readBuff[i]]._count ++;
    }
	}
  
  
}
```

##### 创建哈夫曼树

```c++
HuffmanTree<ByteInfo> ht(_fileInfo,ByteInfo());
 	//在这里打印一下huffman树来验证。

ht.PreOrderPrint(ht.get_rootNode());//判断是否成功
```

```c++
Node *&get_rootNode() //当函数的返回值是非引用变量时，会用一个临时变量来保存该返回值；当函数的返回值是引用变量时，不使用临时变量，直接返回该引用
{
    return _root;
}      
void PreOrderPrint(Node *&root) const
    {
        if (!root)
        {
            printf("NULL ");
            return;
        }
        std::cout << root->_weight << " ";
        PreOrderPrint(root->_left);
        PreOrderPrint(root->_right);
    }
```

可以发现，我们打印了256个字符的_weight数据，这并非我们想要的，我们只需要256个里面count不为0的字符，所以我们在HuffmanTree里引入invalid，这个invalid用来检测是否是我们需要的数据，如下所示

```c++
 HuffmanTree(const std::vector<W> &vw, const W &invalid = W())
    {
        //用所有权值构造只有根节点的二叉树森林
        //森林中的二叉树应该用堆-优先级队列保存
        std::priority_queue<Node *, std::vector<Node *>, Compare> q;
        for (auto &e : vw)
        {
            if (invalid != e)
            {
                q.push(new Node(e));
            }
        }
```

因为我们不需要_count为0的char数据，所以我们创建ByteInfo临时变量，临时变量会调用构造函数构造出 _count=0的对象，作为invalid传给HuffmanTree的构造。

```c++
HuffmanTree<ByteInfo> ht(_fileInfo,ByteInfo());
```

##### 获取每个字节的Huffman编码

```c++
        GenerateHuffmanCode(ht.get_rootNode());
```

我们既可以从根节点往下找，左走编码加0，右走编码加1，走到叶子节点中止。但是这样操作起来非常麻烦。我们尝试从叶子节点往上走，左孩子找到父亲节点加0，右孩子找到父亲节点加1。但是这样的话需要用父亲孩子定义法，重新定义HuffmanTreeNode

```c++
template <class W>
struct HuffmanTreeNode
{

    HuffmanTreeNode<W> *_left;
    HuffmanTreeNode<W> *_right;
    HuffmanTreeNode<W> *_parent;
    W _weight;

    HuffmanTreeNode(const W &weight = W())
        : _left(nullptr), _right(nullptr), _parent(nullptr), _weight(weight)
    {
    }
};
```

并且需要在HuffmanTree的构造函数中链接父子关系

```c++
while (q.size() > 1)
{
    Node *left = q.top();
    q.pop();
    Node *right = q.top();
    q.pop();

    // left 和 right作为新节点的左右子树
    Node *parent = new Node(left->_weight + right->_weight);
    parent->_left = left;
    parent->_right = right;
    left->_parent = parent;
    right->_parent = parent;
    //父节点放入森林
    q.push(parent);
}
```

```c++
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
        //Code是逆置的，需要reverse一下。
        reverse(Code.begin(), Code.end());
    }
}
```

#### 改写字节

```c++
      // 4. 用得到的编码对源文件中的每个字节进行改写。

      //我们要先把fIn放到起始位置，否则读不到输入进去的东西,改变文件指针
      fseek(fIn, 0, SEEK_SET); //起始位置偏移0个字节
      string file_name(get_file_name(filePath));
      file_name += "hz";
      FILE *fout = fopen(file_name.c_str(), "wb");
       //需要一个char类型来接收
        unsigned char sin_ch = '0'; // 0000 0000
        //不知道八个bit位是否填满，用count计数
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
```

### 解压缩

>   解压缩很多方式，比如利用unorder_map<string,char> 建立编码和字符的关系，查压缩文件的头一个bit位在string有无对应，如无，查头2个bit在string中有无对应，直到有对应后，替换为char。但是这种需要频繁对比，非常麻烦。
>
> 我们可以用huffman树解压缩，非常方便：取一个字节，1往右走，0往左走，走到叶子节点为止，我们就可以查到对应字符了。随后让指针回到根节点继续走，直到比特流结束
>
> 但是我们要保存一棵树。我们当初创建一棵树是通过字符和它出现的频次，所以我们保存就是保存字符与其对应的出现频次。
>
> 但是仅仅保存字符和频次不行，因为如何区分他们与我们压缩的bit流呢？先提供这些字符的个数，比如文件中只有abcde五个字符，那么我们先在文件中录入5，表示我们会读取到5个字符及其出现频次。
>
> 此外我们还需要保存原文件的格式，也就是后缀，否则无法还原。
>
> >    所以我们需要录入的信息有： 解压缩需要用到的信息(**原文件后缀，字符个数，字符及字符出现频次)+压缩数据**
>
> ​    注意，我们不需要解压缩的bit位个数readSize，因为huffman树根节点的权值就是我们需要解压出来的字符的个数。
>
> 由于我们之前只写入了压缩数据，所以我们应该对前面做一些修改，添加我们需要的这些信息。
>
> ```c++
> //找文件的后缀 不包括.
> string get_file_suffix(const string &filePath)
> {
>     return filePath.substr(filePath.find_last_of('.') + 1); //不存.
> }
> //找文件的前缀 包括.
> string get_file_name(const string &filePath)
> {
>     size_t pos = filePath.find_last_of('.');
>     string file_name;
>     for (size_t curpos = 0; curpos <= pos; curpos++)
>     {
>         file_name += filePath[curpos];
>     }
>     return file_name;
> }
> 
> void WriteHeadInfo(const string &filePath, FILE *fout)
> {
>     //获取原文件后缀
>     string headInfo;
>     headInfo += get_file_suffix(filePath);
>     headInfo += '\n';
> 
>     //构造字符频次信息
>     size_t appearLine_count = 0;//字符信息所用的行数
>     string chInfo;
>     for (auto &e : _fileInfo)
>     {
>       	//判断_count为0的字符，不用写入。
>         if (e._count == 0)
>             continue;
>         chInfo += e._ch;
>         chInfo += std::to_string(e._count);
>         chInfo += '\n'; //换行，一条信息占用一行
>         appearLine_count++;
>     }
>     headInfo += std::to_string(appearLine_count);
>     headInfo += '\n';
>     fwrite(headInfo.c_str(), 1, headInfo.size(), fout);
>     fwrite(chInfo.c_str(), 1, chInfo.size(), fout);
> }
> ```
>
> 在压缩函数中添加        WriteHeadInfo(filePath, fout);即可。

#### 1. 看所传递路径是否非法

```c++
void file_decompression(const string& filePath)
{
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
    
    
    ...
}
```

#### 2.读取解压缩需要的信息

```c++
    // a. 读取文件名+后缀
    string deCompressFile(get_file_name(filePath));
    string suffix;
    get_line(fIn, suffix);
    deCompressFile += suffix;
    // b. 读取频次信息总行数
    string strInfo;
    get_line(fIn, strInfo);
    size_t lineCount = atoi(strInfo.c_str());//需要把string类型转换成const char*类型再用atoi转换成int类型。
    for (size_t i = 0; i < lineCount; ++i)
    {
        strInfo = "";//重置
        get_line(fIn, strInfo); //没有考虑要读取的字符是换行的情况。
        //对换行进行单独处理，因为文档中'\n'会直接另起一行，下一行是数字
        if ("" == strInfo)
        {
            strInfo += '\n';
            get_line(fIn, strInfo);
        }

        // _char : _fequency
        //_fileInfo[strInfo[0]]._ch = strInfo[0];//_ch可以不用管，因为构造函数已经构造好了。这里只是重复
        unsigned char ch = strInfo[0];
        _fileInfo[ch]._count = atoi(strInfo.c_str() + 1);//字符本位不需要再读，+1读取数字即可。
    }
```

#### 3.还原哈夫曼树

```c++
Huffmantree<ByteInfo> ht(_fileInfo,ByteInfo());
```

同样的，我们创建临时变量，作为invalid。

#### 4.解压缩

```c++
// 4. 解压缩
FILE *fout = fopen(deCompressFile.c_str(), "wb");
unsigned char readBuff[1024];
size_t fileSize = 0;//
HuffmanTreeNode<ByteInfo> *cur = ht.get_rootNode();
while (true)
{
    size_t readSize = fread(readBuff, 1, 1024, fIn);
    if (0 == readSize)
        break;
    for (size_t i = 0; i < readSize; ++i)
    {
        unsigned char ch = readBuff[i];
        for (int j = 0; j < 8; ++j)
        {
            if (ch & 0x80) // 1000 0000
                cur = cur->_right;
            else
                cur = cur->_left;
            ch <<= 1;   //左移
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
```



### f开头的函数

#### fopen

Open file:
Opens the file whose name is specified in the parameter filename and associates it with a stream that can be identified in future operations by the FILE pointer returned.

```c++
FILE* fopen(const char* filename, const char* mode);

//OPEN FILE
```

一般的用法是**，要加检查，因为可能打不开文件。**

```c++
FILE* fIN = fopen(_file_name,"r");//只读，文件必须存在
FILE* fIN = fopen(_file_name,"w");//读/写，文件如没有会自动创建。
FILE* fIN = fopen(_file_name,"a");//append，在文件结尾追加。

FILE *fIn = fopen(filePath.c_str(), "rb");
if (nullptr == fIn)
{
    cout << "File cannot be found" << endl;
    return;
}

// rb，wb是用二进制形式打开文件。
// 区别就在于一般用r w打开的文件遇到0xFF会中止，而用rb、wb打开的文件则不会。
```

> **注意：fopen的filename是const char*类型的，如果我们用string类创建的对象s，需要s.c_str( ).**

#### fclose

有开文件就必须有关文件，我们需要配合fopen来使用。参数用fopen的返回值。

```c++
fclose(fIn);
```

#### fread

```C++
size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
```

**Read bolck of data from stream**

Reads an array of **count** elements, eah once with a size of **size** bytes, from the **stream** and stores them in the block of memory specified by ptr.

| parameters   | explanation                                                  |
| ------------ | ------------------------------------------------------------ |
| ptr          | pointer to a block of memory with a size of at least(size* count) bytes, converted to a void*. |
| size         | Size, in bytes, of each element to be read.                  |
| count        | number of elements, each once with a size of size bytes.     |
| stream       | Pointer to a FILE object that specifies an input stream      |
| Return value | the total number of elements successfully read is returned.  |

一般使用一个size_t类型的变量来接收fread的返回值，必须用一个数组来接收读取到的信息，比如我们每次读取1024个1个字节的char类型数据，这么写：

```c++
unsigned char readBuff[1024];
while(1)
{
	size_t readSize = fread(readBuff,1,1024,fIn);
	if(0==readSize)
		break;
}
```

#### fwrite

```c++
size_t fwrite (const void* ptr, size_t size, size_t count, FILE* stream);
```

**Write block of data to stream**

Writes an array of *count* elements, each one with a size of *size* bytes, from the block of memory pointed by *ptr* to the current position in the *stream*.

| parameters       | explanation                                                  |
| ---------------- | ------------------------------------------------------------ |
| ptr              | Pointer to the array of elements to be written, converted to a **const void***. |
| size             | Size in bytes of each element to be written.                 |
| count            | Number of elements, each one with a size of *size* bytes.    |
| stream           | Pointer to a FILE object that specifies an output stream.    |
| **return value** | **The total number of elements successfully written is returned.** |

同样的，我们需要先打开一个文件再开始进行fwrite。

```c++
FILE* fOut = fopen(filename,"wb");
if (nullptr == fOut)
{
    cout << "File cannot be found" << endl;
    return;
}
//假设有一个string字符串来进行fwrite
fwrite(string.c_str(),1,1024,fOut);
```

#### fseek

FILE* 指针的偏移。

```c++
int fseek ( FILE * stream, long int offset, int origin );
```

总共有三个origin 

| Constant | Reference position                   |
| -------- | ------------------------------------ |
| SEEK_SET | Beginning of the file                |
| SEEK_CUR | Current position of the file pointer |
| SEEK_END | End of the file*                     |

*(Library implementations are allowed to not meaningfully support `SEEK_END` (therefore, code using it has no real standard portability).)

#### feof

```c++
int feof ( FILE * stream );
```

**Check end-of-file indicator**

Checks whether the *end-of-File indicator* associated with *stream* is set, returning a value different from zero if it is.

我们fgetc、fputc等操作会让FILE*指针往后移动，可以用feof来检查是否到文件末尾。





## 测试结果

txt文件压缩![CleanShot 2022-10-26 at 19.49.13@2x](/Users/amor/Library/Application Support/CleanShot/media/media_01FiXSxXeo/CleanShot 2022-10-26 at 19.49.13@2x.png)

![CleanShot 2022-10-26 at 20.00.52@2x](/Users/amor/Library/Application Support/CleanShot/media/media_hj6SUGUFZQ/CleanShot 2022-10-26 at 20.00.52@2x.png)

![CleanShot 2022-10-26 at 20.04.58@2x](/Users/amor/Library/Application Support/CleanShot/media/media_DNNmPMaTrC/CleanShot 2022-10-26 at 20.04.58@2x.png)

可以重复压缩，但是重复后压缩率并未显著提升

pdf文件压缩![CleanShot 2022-10-26 at 19.51.09@2x](/Users/amor/Library/Application Support/CleanShot/media/media_LnkW5C5g9R/CleanShot 2022-10-26 at 19.51.09@2x.png)

png文件压缩

![CleanShot 2022-10-26 at 19.55.28@2x](/Users/amor/Library/Application Support/CleanShot/media/media_gpflMMFQmC/CleanShot 2022-10-26 at 19.55.28@2x.png)

