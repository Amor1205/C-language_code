//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
// 输入：head = [ 1, 2, 6, 3, 4, 5, 6 ], val = 6 输出：[1, 2, 3, 4, 5]
// Definition for singly-linked list.
#define NULL (void *)0
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };
// typedef struct ListNode ListNode;

//      struct ListNode *removeElements(struct ListNode *head, int val)
//  {
//      typedef struct ListNode ListNode;
//      //查找位置，并非一个，所以需要循环查找
//      ListNode *pos = head;
//      ListNode *posPrev = NULL;
//      while(pos)
//      {
//          posPrev = pos;//只有一个元素？
//          pos = pos->next;
//          if (pos->val == val)
//          {
//              return;
//          }
//      }
//      //在第一个，头删，
//      if(pos == head)
//      {
//          ListNode *tmp = pos->next;
//          free(pos);
//          head = tmp;
//      }
//      //在最后一个 尾删(need to find posPrev)
//      //在中间，需要找到posPrev
//      //所以二者可以合并
//      else
//      {

//      }
// }

//正确的解答：

//  struct ListNode *removeElements(struct ListNode *head, int val)
//  {
//      struct ListNode *prev = NULL, *cur = head;
//      while (cur)
//      {
//          if (cur->val == val)
//          {
//              //头删
//              if (cur == head)
//              {
//                  head = cur->next;
//                  free(cur);
//                  cur = head;
//              }
//              //中间删除
//              else
//              {
//                  prev->next = cur->next;
//                  free(cur);
//                  cur = prev->next;
//              }
//          }
//          else
//          {
//              //迭代，往后走
//              prev = cur;
//              cur = cur->next;
//          }
//      }
//      return head;
//  }
//写下面这段代码 可以很快地调试
//  int main()
//  {
//      ListNode *n1 = (ListNode *)malloc(sizeof(ListNode));
//      ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
//      ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
//      ListNode *n4 = (ListNode *)malloc(sizeof(ListNode));
//      n1->val = 7;
//      n2->val = 7;
//      n3->val = 7;
//      n4->val = 7;
//      n1->next = n2;
//      n2->next = n3;
//      n3->next = n4;
//      n4->next = NULL;
//  }

//   给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// struct ListNode *reverseList(struct ListNode *head)
// {
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     ListNode *n1, *n2, *n3;
//     n1 = NULL;
//     n2 = head;
//     n3 = head->next;

//     while (n2)
//     {
//         //反转
//         n2->next = n1;
//         //迭代走
//         n1 = n2;
//         n2 = n3;
//         if (n3)
//             n3 = n3->next;
//     }
//     return n1;
// }

//
// struct ListNode *reverseList(struct ListNode *head)
// {
//     ListNode *cur = head;
//     ListNode *newhead = NULL;
//     while (cur)
//     {
//         ListNode *next = cur->next;
//         //头插
//         cur->next = newhead;
//         newhead = cur;
//         //迭代
//         cur = next;
//     }
//     return newhead;
// }

// struct ListNode *middleNode(struct ListNode *head)
// {
//     ListNode *slow = head, *fast = head;
//     while(fast->next&&fast)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }

// struct ListNode *FindKthToTail(struct ListNode *pListHead, int k)
// {
//     ListNode *fast = pListHead, *slow = pListHead;
//     while(k--)//k--是走k步，--k是走k-1步，搞不清楚就带值
//     {
//         //k大于链表长度
//         if(!fast)
//         {
//             return NULL;
//         }
//         fast = fast->next;
//     }
//     while (fast)
//     {
//         fast = fast->next;
//         slow = slow->next;
//     }
//     return slow;
// }

// struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
// {
//     struct ListNode *cur1 = list1, *cur2 = list2;
//     struct ListNode *head = NULL, *tail = NULL;
//     if (cur1 == NULL)
//         return cur2;
//     if (cur2 == NULL)
//         return cur1;
//     while (cur1 && cur2)
//     {
//         //比较
//         if (cur1->val < cur2->val)
//         {
//             if (head == NULL)
//             {
//                 head = tail = cur1;
//             }
//             //尾插
//             else
//             {
//                 tail->next = cur1;
//                 tail = cur1;
//             }
//             //迭代
//             cur1 = cur1->next;
//         }
//         else
//         {
//             if (head == NULL)
//             {
//                 head = tail = cur2;
//             }
//             else
//             {
//                 tail->next = cur2;
//                 tail = cur2;
//             }
//             cur2 = cur2->next;
//         }
//     }
//     if (cur1)
//     {
//         tail->next = cur1;
//     }
//     else
//     {
//         tail->next = cur2;
//     }
//     return head;
// }

// struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
// {
//     struct ListNode *cur1 = list1, *cur2 = list2;
//     struct ListNode *head = NULL, *tail = NULL;
//     if (cur1 == NULL)
//         return cur2;
//     if (cur2 == NULL)
//         return cur1;
//     if (head == NULL)
//     {
//         if (cur1->val < cur2->val)
//         {
//             head = tail = cur1;
//             cur1 = cur1->next;
//         }
//         else
//         {
//             head = tail = cur2;
//             cur2 = cur2->next;
//         }
//     }
//     while (cur1 && cur2)
//     {
//         //比较
//         if (cur1->val < cur2->val)
//         {

//             //尾插

//             tail->next = cur1;
//             tail = cur1;

//             //迭代
//             cur1 = cur1->next;
//         }
//         else
//         {

//             tail->next = cur2;
//             tail = cur2;

//             cur2 = cur2->next;
//         }
//     }
//     if (cur1)
//     {
//         tail->next = cur1;
//     }
//     else
//     {
//         tail->next = cur2;
//     }
//     return head;
// }

// ListNode *partition(ListNode *pHead, int x)
// {
//     //开头节点和尾节点，有尾节点才方便尾插
//     ListNode *smaller = NULL, *bigger = NULL;
//     ListNode *tails = NULL, *tailb = NULL;
//     //开哨兵位，方便尾插
//     smaller = tails = (ListNode *)malloc(sizeof(ListNode));
//     tails->next = NULL;
//     bigger = tailb = (ListNode *)malloc(sizeof(ListNode));
//     tailb->next = NULL;

//     ListNode *cur = pHead;
//     while (cur)
//     {
//         if (cur->val < x)
//         {
//             //尾插到smaller里面去
//             tails->next = cur;
//             tails = cur;
//         }
//         else
//         {
//             tailb->next = cur;
//             tailb = cur;
//         }
//         cur = cur->next;
//     }
//     tails->next = bigger->next;
//     tailb->next = NULL;
//     ListNode *lista = smaller->next;
//     free(bigger);
//     free(smaller);

//     return lista;
// }
//
//
//-------------------WRONG------------------------------
// int chkPalindrome(ListNode *A)
// {
//     //找到中间节点
//     ListNode *fast = A, *slow = A;
//     while (fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     ListNode *mid = slow, *cur = slow->next, *curPrve = slow;
//     ListNode *next = cur->next;
//     //中间节点后进行逆置
//     while (cur)
//     {
//         // //指向
//         // cur->next = curPrve;
//         // //迭代
//         // cur = cur->next;
//         // curPrve = curPrve->next;
//         //这个是错误的是因为cur->next已经更改，说明cur的指向已经发生改变，我们无法找到cur的原本的下一个值了，只能提前定义了。
//         //指向
//         cur->next = curPrve;
//         //迭代
//         cur = next;
//         curPrve = curPrve->next;
//         if (next)
//             next = next->next;
//     }
//     slow = A;
//     while (slow && mid)
//     {
//         if (slow->val != mid->val)
//             return -1;
//         else
//         {
//             slow = slow->next;
//             mid = mid->next;
//         }
//     }
//     return 1;
// }
//-------------------WRONG------------------------------

//-------------------WRONG------------------------------
//  struct ListNode *reverseList(struct ListNode *head)
// {
//     ListNode *cur = head;
//     ListNode *newhead = NULL;
//     while (cur)
//     {
//         ListNode *next = cur->next;
//         //头插
//         cur->next = newhead;
//         newhead = cur;
//         //迭代
//         cur = next;
//     }
//     return newhead;
// }
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
// {
//     ListNode *newheadA = reverseList(headA);
//     ListNode *newheadB = reverseList(headB);
//     ListNode *curA = newheadA, *curB = newheadB;
//     if(curA != curB)
//     {
//         return NULL;
//     }
//     ListNode *curAPrev = newheadA, *curBPrev = newheadB;
//     while (curA && curB)
//     {
//         if(curA != curB)
//         {
//             headA = reverseList(newheadA);
//             headB = reverseList(newheadB);
//             return curAPrev;
//         }
//         curAPrev = curA;
//         curA = curA->next;
//         curBPrev = curB;
//         curB = curB->next;
//     }
// }
//-------------------WRONG------------------------------

// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
// {
//     ListNode *tailA = headA, *tailB = headB;
//     int lengthA = 1, lengthB = 1;
//     //找尾巴，求长度
//     while (tailA->next)
//     {
//         tailA = tailA->next;
//         lengthA++;
//     }
//     while (tailB->next)
//     {
//         tailB = tailB->next;
//         lengthB++;
//     }
//     //不相交
//     if(tailA != tailB)
//     {
//         return NULL;
//     }
//     // ListNode* curA = headA;
//     // ListNode* curB = headB;
//     //可以使用绝对值函数
//     //abs(lengthA - lengthB)

//     //下面这段函数太冗余了，完全是重复的代码，只是区分headA和headB
//     //可以设定一个长的和短的，如下
//     ListNode *longList = headA;
//     ListNode *shortList = headB;
//     if(lengthA < lengthB)
//     {
//         ListNode *longList = headB;
//         ListNode *shortList = headA;
//     }
//     //长的走abs步
//     int gap = abs(lengthA - lengthB);
//     while (gap--)
//     {
//         longList = longList->next;
//     }
//     while(longList!=shortList)
//     {
//         longList = longList->next;
//         shortList = shortList->next;
//     }
//     return longList;
//     // if (lengthA >= lengthB)
//     // {
//     //     int d = lengthA - lengthB;
//     //     while (d--)
//     //     {
//     //         curA = curA->next;
//     //     }
//     //     while(curA)
//     //     {
//     //         if(curA->next == curB->next)
//     //         {
//     //             return curA->next;
//     //         }
//     //         curA = curA->next;
//     //         curB = curB->next;
//     //     }
//     // }
//     // else
//     // {
//     //     int d = lengthB - lengthA;
//     //     while(d--)
//     //     {
//     //         curB = curB->next;
//     //     }
//     //     while(curB)
//     //     {
//     //         if (curA->next == curB->next)
//     //         {
//     //             return curA->next;
//     //         }
//     //         curA = curA->next;
//     //         curB = curB->next;
//     //     }
//     // }
// }

// bool hasCycle(struct ListNode *head)
// {
//     struct ListNode *fast = head, *slow = head;
//     //fast->next和fast都应该不为空才行
//     while (fast && fast->next)
//     {

//         fast = fast->next->next;
//         slow = slow->next;
//         if (fast == slow)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// struct ListNode *detectCycle(struct ListNode *head)
// {
//     struct ListNode *slow = head, *fast = head;
//     while(fast&&fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//         if(slow == fast)
//         {
//             struct ListNode *meetNode = slow;
//             while(meetNode!=head)
//             {
//                 meetNode = meetNode->next;
//                 head = head->next;
//             }
//             return meetNode;
//         }
//     }
//     return NULL;
// }
//  * Definition for a Node.
struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};
struct Node *copyRandomList(struct Node *head)
{
    //复制节点，然后插入
    struct Node *cur = head, *curCopy = head;
    //预先储存好cur的next
    struct Node *next = cur->next;
    // if(!cur)
    // {
    //     return NULL;
    // }
    while (cur)
    {
        //复制节点的值
        curCopy = (struct Node *)malloc(sizeof(struct Node));
        curCopy->val = cur->val;
        //指向
        cur->next = curCopy;
        curCopy->next = next;
        //迭代
        cur = next;
        next = next->next;
    }
    //将random的值写入curcopy
    //从头开始数，奇数为原始链表，偶数为复制的节点
    cur = head;
    while (cur)
    {
        curCopy = cur->next;
        //复制random
        if (!cur->random)
        {
            curCopy->random = NULL;
        }
        curCopy->random = cur->random->next;
        //迭代
        cur = curCopy->next;
        //什么时候中止呢？
    }
    //解开链接，然后重新形成新的链表
    //改变curcopy的next值即可。
    struct Node *copyHead = (struct Node *)malloc(sizeof(struct Node));
    copyHead = head->next;
    //为了尾插,定义tail
    struct Node *copyTail = copyHead;

    while (cur)
    {
        curCopy = cur->next;
        struct Node *next = curCopy->next;
        //尾插
        copyTail->next = curCopy;
        //恢复原节点
        cur->next = next;
        //迭代
        copyTail = curCopy;
        cur = next;
    }
    cur->next = NULL;
    return head->next;
}