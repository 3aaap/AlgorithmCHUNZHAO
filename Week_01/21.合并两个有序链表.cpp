/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (65.12%)
 * Likes:    1493
 * Dislikes: 0
 * Total Accepted:    456.1K
 * Total Submissions: 700K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 遍历
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* curNode = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* l1Temp = l1, * l2Temp = l2;
        while (l1Temp && l2Temp)
        {
            if (l1Temp->val < l2Temp->val)
            {
                nextNode = l1Temp; 
                l1Temp = l1Temp->next;
            }
            else
            {
                nextNode = l2Temp;
                l2Temp = l2Temp->next;
            }
            if (curNode) curNode->next = nextNode;
            curNode = nextNode;
        }
        curNode->next = l1Temp ? l1Temp : l2Temp;
        return l1->val < l2->val ? l1 : l2;
    }

    // 递归
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if (l1 == nullptr) return l2;
    //     if (l2 == nullptr) return l1;
    //     ListNode* nextNode;
    //     if (l1->val < l2->val)
    //     {
    //         nextNode = l1;
    //         nextNode->next = mergeTwoLists(l1->next, l2);
    //     }
    //     else
    //     {
    //         nextNode = l2;
    //         nextNode->next = mergeTwoLists(l1, l2->next);
    //     }
    //     return nextNode;
    // }
};
// @lc code=end

