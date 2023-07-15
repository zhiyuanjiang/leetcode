* lc_18 [medium]
真是艰难的一题呀，需要注意两个点
1 怎么有效的在O(n^3)时间内枚举出所有的数据
2 怎么有效的去重
首先关于怎么降低时间复杂度，**先对数组进行排序，枚举前两个数值，然后用双指针的方式枚举剩下的两个数值**（一点没想到）
先枚举nums[i]和nums[j]，然后令p=j+1，q=n-1。
如果nums[i]+nums[j]+nums[p]+nums[q]=target，p向右移动，直到nums[p+1]!=nums[p]；q向左移动，直到nums[q-1]!=nums[q]。
如果nums[i]+nums[j]+nums[p]+nums[q]< target, p向右移动。
如果nums[i]+nums[j]+nums[p]+nums[q] > target, q向左移动。
如何保证有效去重呢，此时只要关注i和j的选取。只需要保证nums[i+1]!=nums[i], nums[j+1]!=nums[j]。
这里需要注意，第一个i或j一定要选取，不要也去冗余了。