### Longest Common Subsequence Problem

The question is to find the longest common subsequence between two strings. For example, for strings "abcabd" and "xaabcbad" the longest common subsequence will be "abcbd".

#### Solution

The solution uses Dynamic programming to solve it in O(mn) for strings of length m and n respectively. The overlapping subproblems can be expressed as:
		
		if (a[m] == b[n]) :
			LCS(m, n) = 1 + LCS(m-1, n-1)
		else :
			LCS(m, n) = max(LCS(m-1, n), LCS(m, n-1))

Time Complexity: O(mn)
Space Complexity: O(mn)
