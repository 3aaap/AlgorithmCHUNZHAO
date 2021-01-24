/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    862
 * Dislikes: 0
 * Total Accepted:    222.1K
 * Total Submissions: 488K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 0 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // 环状替代法
    // void rotate(vector<int>& nums, int k) {
    //     int count = gcd(k, (int)nums.size());
    //     for (size_t i = 0; i < count; ++i)
    //     {
    //         int cur = nums[i];
    //         int next = (i + k) % nums.size();
    //         while (next != i)
    //         {
    //             swap(nums[next], cur);
    //             next = (next + k) % nums.size();
    //         }
    //         swap(nums[next], cur);
    //     }
    // }
    // 

    // 翻转数组
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
};
// @lc code=end

