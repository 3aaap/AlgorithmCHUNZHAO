/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 *
 * https://leetcode-cn.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (53.58%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 27.6K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计实现双端队列。
 * 你的实现需要支持以下操作：
 * 
 * 
 * MyCircularDeque(k)：构造函数,双端队列的大小为k。
 * insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
 * insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
 * deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
 * deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
 * getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
 * getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
 * isEmpty()：检查双端队列是否为空。
 * isFull()：检查双端队列是否满了。
 * 
 * 
 * 示例：
 * 
 * MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
 * circularDeque.insertLast(1);                    // 返回 true
 * circularDeque.insertLast(2);                    // 返回 true
 * circularDeque.insertFront(3);                    // 返回 true
 * circularDeque.insertFront(4);                    // 已经满了，返回 false
 * circularDeque.getRear();                  // 返回 2
 * circularDeque.isFull();                        // 返回 true
 * circularDeque.deleteLast();                    // 返回 true
 * circularDeque.insertFront(4);                    // 返回 true
 * circularDeque.getFront();                // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有值的范围为 [1, 1000]
 * 操作次数的范围为 [1, 1000]
 * 请不要使用内置的双端队列库。
 * 
 * 
 */

// @lc code=start

struct ListNodeNew {
    ListNodeNew* next;
    ListNodeNew* pre;
    int value;
    ListNodeNew() : value(0), next(nullptr), pre(nullptr) {}
    ListNodeNew(int val) : value(val), next(nullptr), pre(nullptr) {}
    ListNodeNew(int val, ListNodeNew* ptrNext, ListNodeNew* ptrPre) : value(val), next(ptrNext), pre(ptrPre) {}
};

class MyCircularDeque {
    int capacity;
    int curSize;
    ListNodeNew* headNode;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        headNode = nullptr;
        capacity = k;
        curSize = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (curSize == capacity)
        {
            return false;
        }
        ListNodeNew* newNode = new ListNodeNew(value);
        if (curSize++ == 0)
        {
            headNode = newNode;
            newNode->pre = newNode;
            newNode->next = newNode;
            return true;
        }
        newNode->next = headNode;
        newNode->pre = headNode->pre;
        newNode->pre->next = newNode;
        headNode->pre = newNode;
        headNode = newNode;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (curSize == capacity)
        {
            return false;
        }
        ListNodeNew* newNode = new ListNodeNew(value);
        if (curSize++ == 0)
        {
            headNode = newNode;
            newNode->pre = newNode;
            newNode->next = newNode;
            return true;
        }
        newNode->next = headNode;
        newNode->pre = headNode->pre;
        newNode->pre->next = newNode;
        headNode->pre = newNode;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (curSize-- == 0)
        {
            curSize = 0;
            return false;
        }
        if (curSize == 0)
        {
            delete headNode;
            headNode = nullptr;
            return true;
        }
        ListNodeNew* temp = headNode;
        headNode = headNode->next;
        headNode->pre = temp->pre;
        headNode->pre->next = headNode;
        delete temp;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (curSize-- == 0)
        {
            curSize = 0;
            return false;
        }
        if (curSize == 0)
        {
            delete headNode;
            headNode = nullptr;
            return true;
        }
        ListNodeNew* temp = headNode->pre;
        temp->pre->next = headNode;
        headNode->pre = temp->pre;
        delete temp;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (headNode == nullptr) return -1;
        return headNode->value;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (headNode == nullptr) return -1;
        return headNode->pre->value;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return curSize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return curSize == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

