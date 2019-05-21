# [Leetcode33.搜索旋转排序数组](<https://leetcode-cn.com/problems/search-in-rotated-sorted-array/>)

- 方法分析

  根据题目意思，需要采用时间复杂度为O(logn)的方法，所以首先想到使用**二分法**进行查找。

  首先采用二分法对数据进行分区，若$nums[mid] == target$，则直接返回；首先在左半分区查找，即$nums[left] \leq nums[mid]$ ，然后判断$nums[left] \leq target \&\& nums[mid] > target$，则令$right  = mid - 1$，否则跳到右半区域继续查找，即$left = mid + 1$。在右半分区先判断后半区域是否有target ，即判断区间 $nums[mid] < target \&\& nums[right] \geq target$，如果在这个区间，则令$left = mid + 1$，否则跳到左半区域继续查找，即$right = mid - 1$。最终判断$left$指向的元素是否为要查找的元素即可。

- 复杂度分析

  - 时间复杂度

    查找过程中使用的是二分查找，所以时间复杂度为$O(logn)$。

  - 空间复杂度

    整个过程除了传入的数组$nums$外没有分配额外的内存，所以空间复杂度为$O(1)$。
