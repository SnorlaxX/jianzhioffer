# 链表中倒数第k个结点
## 题目描述
输入一个链表，输出该链表中倒数第k个结点。
## 示例1
### 输入
> {1,2,3,4,5},1
### 返回值
> {5}
## 链表数据结构
```C++
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(nullptr) {
        }
  };
```