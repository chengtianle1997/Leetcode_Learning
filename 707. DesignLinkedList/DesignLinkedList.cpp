#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyHead = new ListNode();
        tailNode = dummyHead;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= m_size)
            return -1;
        ListNode* pHead = dummyHead;
        for (int i = 0; i <= index; i++)
        {
            pHead = pHead->next;
        }
        return pHead->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        bool tail_sign = false;
        // check if tail is not initialized
        if (tailNode == dummyHead)
            tail_sign = true;
        m_size += 1;
        ListNode* node = new ListNode(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
        // if tail is not initialized, assign it with real head.
        if (tail_sign)
            tailNode = dummyHead->next;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        m_size += 1;
        // check if this is the first value
        if (tailNode == dummyHead)
            addAtHead(val);
        // if this it not the first value
        else
        {
            // add value behind the tail
            ListNode* node = new ListNode(val);
            tailNode->next = node;
            tailNode = node;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > m_size)
            return;
        // index == m_size means add at tail
        else if (index == m_size)
        {
            addAtTail(val);
            return;
        }
        m_size += 1;
        ListNode* pHead = dummyHead;
        for (int i = 0; i < index; i++)
        {
            pHead = pHead->next;
        }
        // the new node is inserted behind pHead
        ListNode* temp = pHead->next;
        ListNode* node = new ListNode(val);
        pHead->next = node;
        node->next = temp;
        // check if it is the tail node
        if (index == m_size - 1)
            tailNode = node;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= m_size)
            return;
        m_size -= 1;
        ListNode* pHead = dummyHead;
        for (int i = 0; i < index; i++)
        {
            pHead = pHead->next;
        }
        // pHead is the index - 1 node
        ListNode* temp = pHead->next;
        pHead->next = temp->next;
        delete temp;
        // check if it is the tail node
        if (index == m_size)
            tailNode = pHead;
    }
private:
    int m_size = 0;
    ListNode* dummyHead;
    ListNode* tailNode;
};

int main()
{
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    int val = myLinkedList.get(1);
    std::cout << val << std::endl;
    myLinkedList.deleteAtIndex(1);
    val = myLinkedList.get(1);
    std::cout << val << std::endl;
}