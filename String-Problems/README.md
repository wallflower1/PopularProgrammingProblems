## Interesting string related problems

### Is Permutation Palindrome?
You are given a string, you have to tell whether any permutation of the string is palindromic or not.

Solution: take a bucket of the size of the set of characters in the input string. Initialize it to zero for all values in the array. For every character in the string, set the value if it is unset before and vice versa. Finally, Count the number of set values in the bucket. If the string is even-length, then count value should be 0 and if odd-length, then it should be 1. Otherwise there are no palindromic permutations.

Time Complexity: O(n)