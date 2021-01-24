/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (53.94%)
 * Likes:    1962
 * Dislikes: 0
 * Total Accepted:    186.6K
 * Total Submissions: 345.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        vector<int> assist;
        for (size_t i = 0; i < height.size(); ++i)
        {
            while (!assist.empty() && height[i] > height[assist.back()])
            {
                int ori = height[assist.back()];
                assist.pop_back();
                if (assist.empty()) continue;
                ret += (min(height[assist.back()], height[i]) - ori) * (i - assist.back() - 1);
            }
            assist.emplace_back(i);
        }
        return ret;
    }
};
// @lc code=end

