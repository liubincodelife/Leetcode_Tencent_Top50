# [Leetcode206.反转链表](<https://leetcode-cn.com/problems/reverse-linked-list/>)

- 方法分析

  反转链表的步骤如下：

  - 保存当前节点的下一节点
  - 将当前节点指向上一节点
  - 将上一节点更新为当前节点
  - 将当前节点更新为下一节点

- 复杂度分析

  - 时间复杂度

    由于整个过程需要遍历一遍链表，所以时间复杂度为$O(n)$。

  - 空间复杂度

    空间复杂度为$O(1)​$。