# [Leetcode230.二叉搜索树中第k小的元素](<https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/>)

- 方法分析

  根据二叉搜索树的特性可知，中序遍历二叉搜索树即可得到二叉搜索树的排序结果，所以只需要将中序遍历序列中的第$k-1$个元素返回即可。

  **注意**：若二叉搜索树会被经常修改(插入/删除操作)，并且需要频繁查找第k小的值时，需要怎样优化？

- 复杂度分析

  - 时间复杂度

    

  - 空间复杂度

    
