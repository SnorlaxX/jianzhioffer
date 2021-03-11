# 从尾到头打印链表
## 题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
## 示例1
### 输入
> {67,0,24,58}
### 返回值
> [58,24,0,67]
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