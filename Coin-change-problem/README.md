## COIN CHANGE PROBLEM

# coinChange.cpp

# Statement: 
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, what is the minimum number of coins required to do so?

# Solution:
We can solve this problem using DP with memoization in bottom up manner, solving for each value (1, 2, .. ,N).

# Analysis:
Run time complexity is O(nm) and space time complexity is O(n), since we're using a size N memo. 

# coinChange_AllWays.cpp

# A slight variation of the above problem is to find total number of unique ways to make the sum N using the given supply of change denominations. (infinite supply of each coin is available)

# Solution: 
This can be solved by DP. The number of ways we can split N value into coins is equal to count(N-change[M-1], M-1) + count(N, M-1).

# Analysis:
Run time complexity is O(nm) and space time complexity is O(nm), since we're using a size NxM memo. 


