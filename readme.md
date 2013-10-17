Problems Analysis for LeetCode
==================================================

This document is to summarize the solutions of LeetCode problems.

- `3Sum`: sort the array first, then make three pointers - `i` to head, `j` to tail and `k` to pivot. `if (a[i] + a[k] + a[j]) < 0, i++ else j--`.
- `3SumCloset`: similar to 3Sum.
- `4Sum`: compute the sum of each pair of two elements in the array frist.  for each twoSum `i`, check whether another twoSum `j` exist, where `i + j = target`.
- `AddBinary`: simple problem.
- `AddTwoNumbers`: simple problem.
- `Anagrams`: simple `#hashtable` problem.
- `BalancedBinaryTree`: simple `#balance` `#tree` problem.
- `BestTimetoBuyandSellStock`: simple problem.
- `BestTimetoBuyandSellStockII`: simple problem.
- `BestTimetoBuyandSellStockIII`: `tricky `#dp` problem`. `divide and conquer`. find the max profit of `0..i` and `i+1...n`, each of them is in just one transaction. get the i for optimal profit.
- `InsertInterval`: scan the whole intervals, each time get the smallest for newInterval.start and the largest for newInterval.end.
- `LargestRectangleinHistogram`: `tricky problem`. push each area into the stack, until the current height is lower than that of the top element in the stack. Then, pop up the areas in the stack and compute them for each top element in the stack whose height is higher or equals to current height. Then, push the new area with current height and the new width into the stack again.
- `GasStation`: `tricky problem`. scan all gas stations and compute `total += gas[i] - cost[i]` and `tank += gas[i] - cost[i]`. `if tank < 0, mark i and set tank = 0`. after done, `if total > 0, then return (i+1) % gas.size() else -1`. The reason why `(i+1) % gas.size()` could be a starting point is that for every previous point `k`, `tank(k) = tank(k-1) + gas[k] - cost[k]`, where `tank(k-1) >= 0`, it could not make `tank(i) = tank(i-1) + gas[i] - cost[i] >= 0`, then it would also not make `tank(i) >= 0 if tank(k) = gas[k] - cost[k]`, which makes `k` to be the starting point.
- `GrayCode`: convert a binary to the gray code by `GrayCode(i) = (i>>1)^i`.
- `LengthofLastWord`: simple problem.
- `LetterCombinationsofaPhoneNumber`: simple problem.
- `LongestCommonPrefix`: hash the prefix of each string. `#hashtable`
- `LongestConsecutiveSequence`: `tricky problem`. put all elements into a hash first. iterate the elements in the hash, and check the length of left and right consecutive in the hash. `#hashtable`
- `LongestPalindromicSubstring`: scan the index of the string, check whether palindrome when the index k is in the middle.
- `LongestSubstringWithoutRepeatingCharacters`: `tricky problem`. use `prev[]` to keep the nearest index where `s[prev[i]] = s[i]`. if it is the first occurence of the element, `prev[i] = -1`. scan the elements, `if prev[end] >= begin, begin = prev[end] + 1`.
- `LongestValidParentheses`: `tricky problem`. `more practice`. use a struct to store the value `s[i]` and the index `i`. push `'('` into stack. each time find a match for `')'`, compute the length by `i - top(stack).index` after the matched `'('` has been popped.
- `MaximalRectangle`: `tricky problem`. use `height[]` to indicate the number of consecutive `1` appearred in each column to current line. and then, the problem would be reduced to solve `LargestRectangleinHistogram`.
- `MaximumDepthofBinaryTree`: simple problem.
- `MaximumSubarray`: simple problem.
- `MedianofTwoSortedArrays`: `tricky problem`. use `divide and conquer`. `if A[mid] < B[mid], then the value should not in A[0]...A[mid]`. Similarly, `B[mid] < A[mid], then the value should not in B[0]...A[mid]`.
- `MergeIntervals`: similar to `InsertInterval`.
- `MergekSortedLists`: simply `#linkedlist` problem.
- `MergeSortedArray`: do it in-space. pointer `k` to the last index of `A's` capacity. pointer `i` to the last index of `A's` actual values, pointer `j` to the last index of `B`. each time determine whether `A[i]` or `B[j]` will be assigned to `A[k]`.
- `MergeTwoSortedLists`: simple `linkedlist` problem.
- `MinimumDepthofBinaryTree`: simple `#binarytree` `#tree` problem.
- `MinimumPathSum`: simple `#dp` problem.
- `MinimumWindowSubstring`: `tricky problem`. two pointers - `head` and `tail`. `tail` would be increased, until find a window (a `#hashtable` is used to make such a decision). Then, shrink the window by increasing `head`.
- `MultiplyStrings`: multiply manually. `more practice`.
- `N-Queens`: simple `#dfs` problem.
- `N-QueensII`: simple `#dfs` problem.
- `NextPermutation`: `tricky problem`. First, start from the end of the sequence, find the first index i where an increasing sequence exists. Then start from the end of the sequence again, find the first index `j`, where `a[i] < a[j]` and `i < j`. swap `a[i]` and `a[j]` and `reverse(a.begin()+i+1, a.end())`.
- `PalindromeNumber`: simple problem.
- `PalindromePartitioning`: partition the string into two parts, if the first part is palindrome, then continue.
`PalindromePartitioningII`: `tricky #dp problem`. #dp to determine whether a substring, `s[i]..s[j]`, palindrome - `recs[i][j] = s[i] == s[j] && recs[i+1][j-1]`. use #dp to determine whether a cut is required - `opt[j] = min(opt[j], opt[i]+1)`, if `s[i+1]..[j]` is palindrome.