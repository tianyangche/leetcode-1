Problems Analysis for LeetCode
==================================================

This document is to summarize the solutions of LeetCode problems.

- `3Sum`: sort the array first, then make three pointers - `i` to head, `j` to tail and `k` to pivot. `if (a[i] + a[k] + a[j]) < 0, i++ else j--`.
- `3SumCloset`: similar to 3Sum.
- `4Sum`: compute the sum of each pair of two elements in the array frist.  for each twoSum `i`, check whether another twoSum `j` exist, where `i + j = target`.
- `LargestRectangleinHistogram`: push each area into the stack, until the current height is lower than that of the top element in the stack. Then, pop up the areas in the stack and compute them for each top element in the stack whose height is higher or equals to current height. Then, push the new area with current height and the new width into the stack again.
- `GasStation`: `tricky problem`. scan all gas stations and compute `total += gas[i] - cost[i]` and `tank += gas[i] - cost[i]`. `if tank < 0, mark i and set tank = 0`. after done, `if total > 0, then return (i+1) % gas.size() else -1`. The reason why `(i+1) % gas.size()` could be a starting point is that for every previous point `k`, `tank(k) = tank(k-1) + gas[k] - cost[k]`, where `tank(k-1) >= 0`, it could not make `tank(i) = tank(i-1) + gas[i] - cost[i] >= 0`, then it would also not make `tank(i) >= 0 if tank(k) = gas[k] - cost[k]`, which makes `k` to be the starting point.
- `GrayCode`: convert a binary to the gray code by `GrayCode(i) = (i>>1)^i`.
- `LengthofLastWord`: simple problem.
- `LetterCombinationsofaPhoneNumber`: simple problem.
- `LongestCommonPrefix`: hash the prefix of each string.
- `LongestConsecutiveSequence`: `tricky problem`. put all elements into a hash first. iterate the elements in the hash, and check the length of left and right consecutive in the hash.
- `LongestPalindromicSubstring`: scan the index of the string, check whether palindrome when the index k is in the middle.
- `LongestSubstringWithoutRepeatingCharacters`: `tricky problem`. use `prev[]` to keep the nearest index where `s[prev[i]] = s[i]`. if it is the first occurence of the element, `prev[i] = -1`. scan the elements, `if prev[end] >= begin, begin = prev[end] + 1`.
- `LongestValidParentheses`: `tricky problem`. `more practice`. use a struct to store the value `s[i]` and the index `i`. push `'('` into stack. each time find a match for `')'`, compute the length by `i - top(stack).index`.