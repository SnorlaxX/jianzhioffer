# 链表中环的入口结点
## 题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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