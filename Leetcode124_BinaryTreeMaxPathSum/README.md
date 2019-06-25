# [Leetcode124.二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

- 方法分析

  此题可利用递归法求解。

  - 当最大路径和包含根节点时，可以递归计算子节点的路径和，然后再和根节点的值相加，即为最终的路径和。如下图所示：

    ![124_gains.png](assets/45568450c1b869362937807e70ebb3c287380e9eaf78ae3600040ad83cb7a267-124_gains.png)

  - 当最大路径和可以不包含根节点时，则在计算路径和时需要将当前的最大路径和与新计算的路径和进行比较，始终保存最大的路径和。如下图所示

    ![img](assets/8915f6cc52c428db237eac63b0e413912f9e5b1b6139a4094a12059563847a29-image.png)  ![img](assets/6bb58d28c7473f622a11f02be752beefbeb1e4cd8e9d3e21d80f56143358c5e6-image-1561476838072.png)

    ![img](assets/5a8edf72814b12aa219025e90d000cbd99ff71274b292eb019877fa0b45f49c5-image.png)

    ![img](assets/aada3389f43b3c52ba29eb6dde7e323c942ec4d57f5511a589757798b5194dbc-image.png)

    ![img](assets/8051c2dc50e9e1aa913d5ea2ff59571d5b535836bb94fd44f96f63c361a751ed-image.png)

    ![img](assets/e289d02f8e8d9f35a0a25939ca44ac700d0ac76de2b5457e1fd0ef7eb7873342-image.png)

    ![img](assets/9b559438eba92bd372f95c0df32600b2502b260ffe4486ec3bef74d62e573b6c-image.png)

- 复杂度分析

  - 时间复杂度

    由于整个递归过程对每个节点的访问不超过2次，所以时间复杂度为$O(n)$。

  - 空间复杂度

    由于采用的递归方法，所以需要一个大小与树的高度相等的栈内存，所以空间复杂度为$O(logn)$。
