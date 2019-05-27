# [Leetcode54.螺旋矩阵](<https://leetcode-cn.com/problems/spiral-matrix/>)

- 方法分析

  根据题目意思，需要按照螺旋的方式以此打印二维数组中的元素。可以将整个螺旋过程分为四步执行：

  - 第一步为从左到右打印
  - 第二步为从上到下打印
  - 第三步为从右到左打印
  - 第四步为从下到上打印

  定义起始位置的坐标为(start, start)每打印完一圈让start+1，所以每一圈的起始位置坐标为(0, 0)$\rightarrow$(1, 1)$\rightarrow$(2, 2)$\dots\dots$

  根据二维数组的尺寸不同，打印数字的执行步骤也不太相同，可以分为以下几种情况：

  - 第一步是必须执行的
  - 第二步执行的前提条件是起始位置的行号小于终止位置的行号。如：1x3的行向量只有第一步，没有第二步。至少要有两行才会执行第二步。
  - 第三步执行的前提条件是起始位置的行号小于终止位置的行号，且起始位置的列号小于终止位置的列号。即至少要有两行两列才会执行第二步。
  - 第四步执行的前提条件是起始位置的行号比终止位置的行号小2，且起始位置的列号小于终止位置的列号。即至少要有三行两列。
  - 打印的终止条件是：rows < start x 2 && cols < start x 2。举例说明：5x5的矩阵，最后一圈的起始坐标为(2, 2)，即5 > 2 x 2 && 5 > 2 x 2成立；8x8的矩阵，最后一圈的起始坐标为(3, 3)，即8 > 3 x 2 && 8 > 3 x 2。

- 复杂度分析

  - 时间复杂度

    由于整个过程需要遍历一遍数组全部元素，所以时间复杂度为$O(n^2)$。

  - 空间复杂度

    整个过程除了传入的数组$matrix$外还需要定义一个数组来保存打印数字的顺序。所以空间复杂度为$O(n)$。