# [Leetcode557.反转字符串中的单词III](<https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/>)

- 方法分析

  根据题目意思，字符串中的每个单词都是由空格分隔的，并且字符串中不会有任何额外的空格。

  反转单词的方法是从头到尾遍历字符串，并在遇到空格和字符串结尾时记录之前遍历到的字符并进行反转即可。

- 复杂度分析

  - 时间复杂度

    时间复杂度为$O(n)$。

  - 空间复杂度

    空间复杂度为$O(1)$。