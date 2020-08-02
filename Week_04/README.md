# Week 04 历程总结

视频观看正常，题目练习不正常。本周班班询问三周多来有没有什么问题？我的问题是题目练习过少，编码过少。

**如何让自己能够坚持题目练习，这个是我当前最大问题。**

我应当开启每日一题训练，设定每日任务。针对薄弱环节，反复观看视频，开启多遍练习方法。手写代码，电脑上编码。

## 二分查找练习题

> 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方。

- 思路

    同样按照正常的二分查找方法进行，仅在比较和划分数组的时候变化。
    
    假设数组是有序指的递增顺序。寻找数组中间下标，先同开始下标比较，若开始下标的值小于中间下标的值，说明中间下标左侧数组有序，无序部分位于中间下标右侧；否则说明无序部分存在于中间下标左侧。对于中间下标，应当继续参与无序部分的划分比较。

    对无序的地方存在的那一半数组继续执行上述二分查找的比较方法，直到划分的那一半数组仅存在两个值，中间下标值小于左侧值，则返回中间下标。

- 代码

    ```cpp
    int findUnorderIndex(vector<int> &nums, int left, int right)
    {
        if (nums.empty())
        {
            return -1;
        }

        if (left + 1 == right && nums[left] > nums[right])
        {
            return right;
        }

        int resultIndex = -1;
        int mid = left + (right - left) / 2;
        while (left < right && (left + 1) != right)
        {
            if (nums[left] < nums[mid])
            {
                resultIndex = findUnorderIndex(nums,mid, right);
            }
            else
            {
                reultIndex = findUnorderIndex(nums, left, mid);
            }
        }

        return resultIndex;

    }
    ```


-- 20200802 --
***