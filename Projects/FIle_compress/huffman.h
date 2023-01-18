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
    HuffmanTree(const std::vector<W> &vw, const W &valid = W())
    {
        // Constructing a binary tree forest with only the root node using all ownership values
        //  Binary trees in a forest should be kept in a heap/ priority queue
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

            // left and right as the left and right subtrees of the new node
            Node *parent = new Node(left->_weight + right->_weight);
            parent->_left = left;
            parent->_right = right;
            left->_parent = parent;
            right->_parent = parent;
            // Parent node into the forest
            q.push(parent);
        }
        // The last one is the Huffman tree
        _root = q.top();
    }
    ~HuffmanTree()
    {
        Destroy(_root);
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
    Node *&get_rootNode()
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
