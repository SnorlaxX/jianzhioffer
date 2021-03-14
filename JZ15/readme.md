# 反转链表
## 题目描述
输入一个链表，反转链表后，输出新链表的表头。
## 示例1
### 输入
> {1,2,3}
### 返回值
> {3,2,1}
## 链表数据结构
```C++
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };
```