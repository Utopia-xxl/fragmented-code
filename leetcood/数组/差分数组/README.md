# 相关参考

小而美的算法技巧[](https://labuladong.gitee.io/algo/2/19/23/)

# 整体理解

## 应用场景

**差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减**，利用差分数组可以将运算的时间复杂度从**O(n)**下降到**O(1)**。

## 操作步骤

### 1.构造差分数组

类似前缀和技巧构造的 `prefix` 数组，我们先对 `nums` 数组构造一个 `diff` 差分数组，**`diff[i]` 就是 `nums[i]` 和 `nums[i-1]` 之差**

![img](./picture/2.jpg)

```c++
// 构造差分数组
vector<int> diff(nums.size());
diff[0] = nums[0];
for(int i=1;i<nums.size();i++){
  diff[i] = nums[i] - nums[i-1];
}
```









