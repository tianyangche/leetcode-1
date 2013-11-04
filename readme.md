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
- `BestTimetoBuyandSellStockIII`: `tricky #dp problem`. `divide and conquer`. find the max profit of `0..i` and `i+1...n`, each of them is in just one transaction. get the i for optimal profit.
- `BinaryTreeInorderTraversal`: simple `#tree` `binarytree` problem. recursive method is trival. iterative method is as follows. one stack `recs` is used to store each node. if the left node is NULL, pop up the top node `i` in the stack `recs`, and then traversal the node `i->right`.
- `BinaryTreeLevelOrderTraversal`: simple `#tree` `#binarytree` `#bst` problem. `#bst` the tree level by level.
- `BinaryTreeLevelOrderTraversalII`: simple `#tree` `#binarytree` `#bst` problem. the same method used in `BinaryTreeLevelOrderTraversal`, and then reverse the result.
- `BinaryTreeMaximumPathSum`: simple `#tree` `#binarytree` problem. for each node `i`, `max(leftPathSum+i->val, rightPathSum+i->val, leftPathSum+rightPathSum+i->val)` and return `max(leftPathSum+i->val, rightPathSum+i->val)` to parent.
- `BinaryiTreeZigzagLevelOrderTraversal`: simple `#tree` `#binarytree` problem. use odd and even level to control whether reverse the vector.
- `Candy`: tricky problem. scan from beginning, `if ratings[i] > ratings[i-1]` `num[i] = num[i-1] + 1`. It can assign the candy to each increasing interval. Then, scan from the end, if `num[i]` is already assigned by a number, if `ratings[i] > ratings[i+1]`, then `i` is at the peak, make sure `num[i] > num[i+1]`, otherwise, `num[i] = num[i+1] + 1`. if `num[i]` is not assigned yet, make it to be 1.
- `ClimbingStairs`: simple `#dp` problem. `steps[i] = steps[i-1] +steps[i-2]`.
- `CloneGraph`: `#hashtable` problem. use a `#hash` to store the nodes already created. Every time, first check whether the node is already created.
- `CombinationSum`: simple knapsack problem. `#dp`. The numbers can be reused. Scan from the beginning. Use `unordered_map<int, <vector<int> > path` to store the previous number that can reach this number. Use recussive method to retrieve the path.
- `CombinationSumII`: simple knapsack problem. `#dp`. The numbers could not be reused. Scan from the end. Use `unordered_map<int, <vector<int> > path` to store the previous number's index that can reach this number. Use recussive method to retrieve the path.
- `Combinations`: simple `#dfs` problem.
- `ConstructBinaryTreefromInorderandPostorderTraversal`: simple `#tree` `#binarytree` problem. The last elemeent in postorder traversal is the root node which can be used to split the inorder traversal.
- `ConstructBinaryTreefromPreorderandInorderTraversal`: simple `#tree` `#binarytree` problem. The first elemeent in preorder traversal is the root node which can be used to split the inorder traversal.
- `ContainerWithMostWater`: tricky problem. Two pointers, `i` to the frist, `j` to the end. Compute `max(res, min(height[i], height[j])*(j-i))`, Then `i++` if `height[i] < height[j]`, otherwise, `j--`.
- `ConvertSortedArraytoBinarySearchTree`: simple `#tree` `#binarytree` `#binarysearch` `#recussive` problem. Use element in the middle as the root each time. and build left subtree and right subtree using left section and right section in the array.
- `ConvertSortedListtoBinarySearchTree`: simple `#tree` `#binarytree` `#linkedlist` `#recussive` problem. The same method used in `ConvertSortedArraytoBinarySearchTree`, but need a function to compute the length of list and find the element in list by index.
- `CopyListwithRandomPointer`: `#hashtable`. The same method used in `CloneGraph`. A `#hashtable` is used to store the node already created.
- `CountandSay`: simple problem. Just simple use the rule described in the problem to generate the string.
- `DecodeWays`: simple `#dp` problem. `opt[i] = opt[i-2] + opt[i-1]` if `s[i-1]..s[i]` can be decoded, otherwise, `opt[i] = opt[i-1]`.
- `DistinctSubsequences`: simple `#dp` problem. `opt[i][j]` represents the number of distinct subsequences for `T[0]..T[i-1]` and `S[0]..S[j-1]`. `opt[i+1][j+1] = opt[i][j] + opt[i+1][j]` if `T[i] == S[j]`, otherwise, `opt[i+1][j+1] = opt[i+1][j]`.
- `DivideTwoIntegers`: trick `#bitshift` problem. `b << 1` until `b` is larger than `a` with `i` times shift and record the result after each shift in `inc[i]`. Then, `a -= inc[i]` and `res += 1 << i` until `a <= 0` or `i < 0`.
- `EditDistance`: classic `#dp` problem.
- `FirstMissingPositive`: `trick problem`. swap elements to put positive number `i` into the position `i-1`. scan from the beginning, find the first position `i` where `a[i] != i+1`, then return `i+1`.
- `FlattenBinaryTreetoLinkedList`: `#tree` `#binarytree` problem. for each node `i`, find the right most node `j` for `i->left`, then make `j->right = i->right`, `i->right = i->left` and `i->left = NULL`.
- `GasStation`: `tricky problem`. scan all gas stations and compute `total += gas[i] - cost[i]` and `tank += gas[i] - cost[i]`. `if tank < 0, mark i and set tank = 0`. after done, `if total > 0, then return (i+1) % gas.size() else -1`. The reason why `(i+1) % gas.size()` could be a starting point is that for every previous point `k`, `tank(k) = tank(k-1) + gas[k] - cost[k]`, where `tank(k-1) >= 0`, it could not make `tank(i) = tank(i-1) + gas[i] - cost[i] >= 0`, then it would also not make `tank(i) >= 0 if tank(k) = gas[k] - cost[k]`, which makes `k` to be the starting point.
- `GenerateParentheses`: `#dfs` `#recusive` problem. generate `(` frist, then genrate `)`.
- `GrayCode`: convert a binary to the gray code by `GrayCode(i) = (i>>1)^i`.
- `ImplementstrStr()`: simple problem.
- `InsertInterval`: scan the whole intervals, each time get the smallest for newInterval.start and the largest for newInterval.end.
- `IntegertoRoman`: simple problem. check from the largest number represents in Roman.
- `InterleavingString`: `tricky` `#dp` problem. `opt[i+1][j+1]` represents whether `s1[0]...s1[i]` and `s2[0]...s2[j]` can be interleaved to construct s3. check `s1[i] == s3[i+j+1]` and `s2[j] == s3[i+j+1]` to make `opt[i+1][j+1] = opt[i][j+1] || opt[i+1][j]`.
- `JumpGame`: simple problem. each time check wehther this position can be reached by previuos position.
- `JumpGameII`: find the further position for each step.
- `LargestRectangleinHistogram`: `tricky problem`. push each area into the stack, until the current height is lower than that of the top element in the stack. Then, pop up the areas in the stack and compute them for each top element in the stack whose height is higher or equals to current height. Then, push the new area with current height and the new width into the stack again.
- `LengthofLastWord`: simple problem.
- `LetterCombinationsofaPhoneNumber`: simple problem.
- `LinkedListCycle`: classic problem. two nodes, one moves forward one step, another moves forward two step, check wether thes two nodes would be overlapped.
- `LinkedListCycleII`: classic problem. after detect the cycle using the method in `LinkedListCycle`. Go through from head and the intersected node, if they meet, then return that node.
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
- `PartitionList `: simple `#linkedlist` problem. use one `#linkedlist` to keep tracking the first part, use another `#linkedlist` to keep tracking the second part. concatenate these two parts in the end.
- `Pascal'sTriangle`: simple problem.
- `Pascal'sTriangleII`: simple problem. `a[i] += a[i+1]`, `a.insert(a.begin(), 1)`.
- `PathSum`: simple `#tree` `#binarytree` problem.
- `PathSumII`: simple `#tree` `#birnarytree` problem.
- `PermutationSequence`: `tricky problem`. The number in the `1st` position, should repeate `(n-1)!` times. So, we could use `k/(n-1)!` to calcualte which number should be located in `1st` position. Then, `k %= (n-1)!`. Use the same method to cacluate the number in `2nd`, `3rd`, ..., positions.
- `Permutations`: simple problem. swap `a[i]` and `a[j]` where `i <= j` and recussively do it on `i+1`.
- `PermutationsII`: `tricky problem`. Each iteration, use the method in `NextPermutation` to generate the next permutation for num and then add it into the result. It wwill end when num comes to be the same value as that is at the beginning.
- `PlusOne`: simple problem.
- `PopulatingNextRightPointersinEachNode`: simple `#tree` `#binarytree` problem. `node->left->next = node->right ? node->right : NULL`. `node->right->next = node->next->left`.
- `PopulatingNextRightPointersinEachNode`: simple `#tree` `#binarytree` problem. `node->left->next = node->right ? node->right : getNext(node)`. `node->right->next = getNext(node)`. In `getNext(node)`, get the next sibling by iterating all `node = node->next` and return `node->left` or `node->right`. After one node finished, go further to `node->right` first, since it can build the next pointer which may be used in the left node.
- `RecoverBinarySearchTree`: `#tree` `binarytree` problem. inorder traversal the tree. first found `prev->val > node(j)->val` then `prev` would be the first node in wrong position. the second time found `prev->val > node(j)->val` then `j` woudl be the second node.
- `Pow(x, n)`: tricky `#bitshift` problem. say, `3^5 = (3^1)*(3^4) = (3^(2^0))*(3^(2^2))` and `5` in binary is `101`. make `n` in binary, if the bit `i` in `n` is `1`, then we can have `x^(2^i)`.
- `RegularExpressionMatching`: `tricky problem`. one pointer `i` to the first string `s1`, one pointer `j` to the second string `s2`. Each time if `s2[j+1] == '*'`, we need to check `isMatch(s1[i]...s1[n], s2[j+2]...s2[m])` and increase `i` until `s1[i] != s2[j]`. Then, we need to check `isMatch(s1[i]...s1[n], s2[j+2]...s2[m])` for next segment. if `s2[j+1] != '*'`, if `s1[i] == s2[j]` then check `isMatch(s1[i+1]...s1[n], s2[j+1]...s2[m])`, otherwise, return false. `'.'` would be treated as the same to any `s1[i]`.
- `RemoveDuplicatesfromSortedArray`: simple problem.
- `RemoveDuplicatesfromSortedArrayII`: simple problem.
- `RemoveDuplicatesfromSortedList`: simple `#linkedlist` problem. Try with `double pointer`.
- `RemoveDuplicatesfromSortedListII`: simple `#linkedlist` problem. Try with `double pointer`.
- `RemoveElement`: simple problem. Two pointers, `i` to head, `j` to tail. each time `A[i] == elem`, `swap(A[i], A[j--])`, otherwise `i++`.
- `RemoveNthNodeFromEndofList`: simple `#linkedlist` problem. Try with `double pointer`.
- `ReverseInteger`: simple problem.
- `ReverseLinkedListII`: simple problem. try 'double pointer'. Each time change the tail node to the head.
- `ReverseNodesink-Group`: simple problem. similar to `ReverseLinkedListII`. try `double pointer`.
- `ReorderList`: `#linkedlist` problem. use `emplace_back()` to push all elements into a `vector`. Use two pointers `i`, `j` to add elements from `i` or `j`.
- `RestoreIPAddresses`: simple `#dfs` problem. check `0 <= each segment <= 255`.
- `RomantoInteger`: simple problem.
- `RotateImage`: `tricky problem`. need more practice. rotate by layer. think about the swap.
- `RotateList`: simple `#linkedlist` problem.
- `SameTree`: simple `#tree` `#binarytree` problem.
- `ScrambleString`: `tricky problem`. `#dp`. for each `s1[i1]..s1[j1]` and `s2[i2]..s2[j2]`, check `isScramble(s1[i1], s1[i1+i], s2[i2], s2[i2+i]) && isScramble(s1[i1+i+1], s1[j1], s2[i2+i+1], s2[j2])` and `isScramble(s1[i1], s1[i1+i], s2[j2-i+1], s2[j2]) && isScramble(s1[i1+i+1], s1[j1], s2[i2], s2[j2-i])`.
- `Searcha2DMatrix`: simple problem. `#binarysearch`.
- `SearchforaRange`: simple problem. `#binarysearch`.
- `SearchinRotatedSortedArray`: `tricky #binarysearch problem`. `more practice`. if `A[mid] >= A[begin]`, then check `A[mid] > target && target >= A[begin]`; otherwise, check `A[mid] > target || target >= A[begin]`.
- `SearchinRotatedSortedArrayII`: `tricky #binarysearch problem`. `more practice`. similar to `SearchinRotatedSortedArray`, except if `A[mid] == A[begin]`, `begin++`.
- `SearchInsertPosition`: simple `#binarysearch` problem.
- `SetMatrixZeroes`: `tricky problem`. if `matrix[i][j] == 0`, set `matrix[i][0] = 0` and `matrix[0][j] = 0`. Then, check `matrix[i][0]` and `matrix[0][i]` to set 0 on the whole row or column.
- `SimplifyPath`: consider the rule. `more practice`.
- `SingleNumber`: `tricky problem`. `XOR` to all the elements.
- `SingleNumberII`: `tricky problem`. `#bit`problem. calculate the occurrences of each number in each bit and mod `3`.
- `SortColors`: simple problem. three pointers, `i, k, j` to `0, 1, 2`, respectively. move `k` to determine `swap(A[i], A[k])` or `swap(A[k], A[j])` or `k++`.
- `SpiralMatrix`: `tricky problem`. four pointer `beginX, endX, beginY, endY`. each time move `beginY++, endX--, endY--, beginX++`.
- `SpiralMatrixII`: the same method as that of `SpiralMatrix`.
- `Sqrt(x)`: `#binarysearch`. use `long long` to avoid overflow, since multiplication may cause overflow.
- `StringtoInteger(atoi)`: consider all the possible inputs.
- `Subsets`: `#dfs` problem. each time the element can be added to the subset or not.
- `SubsetsII`: `#dfs` problem. for each duplicated elements, just find the end position of the duplicated element, and add them once.
- `SubstringwithConcatenationofAllWords`: `tricky problem`. `#hashtable` to record all strings in L. for each position in S, check whether it is a good start using another `#hashtable` to record the strings matched in S.
- `SudokuSolver`: find each `'.'` and try `1-9` on it.
- `SumRoottoLeafNumbers`: simple problem. `#tree` `#binarytree`.
- `SurroundedRegions`: `#dfs`. first check all `'O'` on the margin and mark them and `'O's` surrounded them. then modify all `'O's` which are not marked.
- `SwapNodesinPairs`: `#linkedlist`. try `double pointers` on it.
- `SymmetricTree`: `#tree` `#binarytree` problem. try recursive and iterative method. recursive method: each time check two nodes - `i`, `j` - and check `isSymmetric(i->left, j->right)` and `isSymmetric(i->right, j->left)`. iterative method, check by level.
- `TextJustification`: consider the number of space.
- `TrappingRainWater`: How mach water can be contained in index `i` is determined by the heighest one on the left and right.
- `Triangle`: calculate buttom-up.
- `TwoSum`: `#hashtable` to record the position.
- `UniqueBinarySearchTrees`: `tricky` `#tree` #binarytree` problem. iterate the root node `i` then `result += numTrees(left(i)) * numTrees(right(i))`.
- `UniqueBinarySearchTreesII`: The same method as that of `UniqueBinarySearchTrees`. recursively generate the tree by iterating the node as root. Generate all leftChildTrees and rightChildTrees, and then generate them by making the node as root.
- `UniquePaths`: simple `#recursion` problem.
- `UniquePathsII`: simple `#recursion` problem. when Obstacles exists, not go through with it.
- `ValidateBinarySearchTree`: `#tree` `#binarytree` problem. check lower bound and upper bound for each node.
- `ValidNumber`: need more practice.
- `ValidPalindrome`: two pointers - `i, j` - to head and tail. just check when `s[i]` and `s[j]` are alphanumeric.
- `ValidParentheses`: simple `#stack` problem.
- `ValidSudoku`: check whether valid for each row, column and square.
- `WildcardMatching`: `trick` `#dp` problem. `#recursive` will be `TLE`. `opt[i][j]` represents whether `s[0]...s[i]` will match `p[0]...p[j]`.
- `WordBreak`: `#dp` problem. `opt[j]` represents whether `s[0]...s[j]` could be combined in dictionary. `opt[j] = opt[i]` if `substring(i+1, j)` exists in dictionary.
- `WordBreakII`: `#dp` problem. same method in `WordBreak`. Need a `#hashtable` to record the path.
- `WordLadder`: `#bfs` problem. iterate `a` to `z` for each position of each word.
- `WordLadderII`: `#bfs` problem. need more practice. need to handle overlapping when add path. use another `#hashtable` to store which values have been reached before this level.
- `WordSearch`: `#dfs` problem.
- `ZigZagConversion`: `j += 2*nRows-2`, `k = j + 2 * (nRows - i - 1)`.