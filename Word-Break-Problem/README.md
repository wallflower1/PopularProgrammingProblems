# Word break Problem

## problem statement
Given an input string and a dictionary of words, segment the input string into a space-separated sequence of dictionary words if possible. For example, if the input string is "applepie" and dictionary contains a standard set of English words, then we would return the string "apple pie" as output. Print all such possible sequences.

## solution
This solution uses DP with memoization, store the result for solved prefixes and then solve for the suffix.

##complexity
This solution is O(n^2) since it recurses through (n) possible suffixes of every (n) possible prefixes. hence, n*n is the time complexity here.