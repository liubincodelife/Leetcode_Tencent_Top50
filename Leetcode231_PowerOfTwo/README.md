# [Leetcode231.2的幂](<https://leetcode-cn.com/problems/power-of-two/>)

- 方法分析

  有两种方法来判断一个整数是否是2的幂：

  - 数学法

    数学法是对整数n不断计算$n \% 2 $，当$n \% 2 == 0 \& \& n > 0 $时，计算$n /= 2$，并继续计算取余操作，直到$n\%2 != 0 $。

    若$n$为2的幂，则最终$n=1$，返回$true$；否则$n$不是2的幂，直接返回$false$。

  - 位运算法

    位运算法是利用当整数$n$为2的幂时，其二进制数的特点来判断的。

    当整数$n$是2的幂时，其二进制数中有且只有一位数为1，否则就不是2的幂。

    而由于当$n$ 是2的幂时，$n-1$后面所有位都为1，为1的那一位变成0，所以当$n$是2的幂时，$(n \& (n-1)) = 0$。

- 复杂度分析

  - 时间复杂度

    数学法的时间复杂度为$O(logn)$

    位运算法的时间复杂度为$O(1)$

  - 空间复杂度
  
    两种方法的空间复杂度都为$O(1)$
    
    
