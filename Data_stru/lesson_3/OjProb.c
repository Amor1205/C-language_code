//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
// 输入：head = [ 1, 2, 6, 3, 4, 5, 6 ], val = 6 输出：[1, 2, 3, 4, 5]
// Definition for singly-linked list.
#define NULL (void *)0
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

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

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
}