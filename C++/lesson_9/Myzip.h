#pragma once
#include <vector>
#include <queue>
#include <iostream>

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

template <class W>
class HuffmanTree
{
    typedef HuffmanTreeNode<W> Node;

    class Compare
    {
    public:
        bool operator()(const Node *left, const Node *right) const
        {
            return left->_weight > right->_weight;
        }
    };

public:
    HuffmanTree()
        : _root(nullptr) {}
    HuffmanTree(const std::vector<W> &vw, const W &valid = HuffmanTree())
    {
        //用所有权值构造只有根节点的二叉树森林
        //森林中的二叉树应该用堆-优先级队列保存
        std::priority_queue<Node *, std::vector<Node *>, Compare> q;
        for (auto &e : vw)
        {
            if (valid != e)
            {
                q.push(new Node(e));
            }
        }

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
        //最后一个就是Huffman树
        _root = q.top();
    }
    ~HuffmanTree()
    {
        Destroy(_root);
    }

    void PreOrderPrint(Node *&root)
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
    Node *&get_rootNode() //当函数的返回值是非引用变量时，会用一个临时变量来保存该返回值；当函数的返回值是引用变量时，不使用临时变量，直接返回该引用
    {
        return _root;
    }

private:
    void Destroy(Node *&root)
    {
        if (root)
        {
            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
            root = nullptr;
        }
    }
    Node *_root;
};

// void Test()
// {
//     std::vector<int> v;
//     v.push_back(1);
//     v.push_back(3);
//     v.push_back(5);
//     v.push_back(7);
//     HuffmanTree<int> ht(v);

//     std::cout << ht.Top_weight();
// }