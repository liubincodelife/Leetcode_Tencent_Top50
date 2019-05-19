# [Leetcode016.最接近的三数之和](<https://leetcode-cn.com/problems/3sum-closest/>)

- 方法分析

  这道题目介绍两种解法：

  - 暴力法。用三个for循环遍历所有数字组合，求出所有的组合，并将三个数之和为0的数字返回。时间复杂度为$O(n^3)$。

  - **双指针法(推荐)**。首先将原数组$nums$进行排序，让数组按从小到大的顺序排序。然后计算一个三数之和的初始值$srcSum = nums[0] + nums[1] + nums[2]$。再固定一个数字$nums[i]$，并定义两个指针left和right分别指向$i$的下一个元素和最后一个元素。接着求出当前数字组合的和$curSum = nums[i]+nums[left]+nums[right] $，判断$abs(target - sumSrc)和abs(target - curSum)$的大小，如果前者小于后者则更新sumSrc的值。然后判断curSum和target的大小，当$target > curSum$将left指针右移，反之，right指针左移。移动指针时如果遇到重复数据需要剔除。循环结束之后sumSrc中保存的就是最小差的三数之和。

- 复杂度分析

  - 时间复杂度

    由于整个过程需要遍历一遍数组全部元素，而且有一次排序操作，所以时间复杂度为$O(nlogn)$。

  - 空间复杂度

    整个过程除了传入的数组$nums$外不需要额外内存，所以空间复杂度为$O(1)$。
