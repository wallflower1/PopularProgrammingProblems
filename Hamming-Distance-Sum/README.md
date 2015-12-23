### Hamming Distance Sum (CodeForces Round #336 Problem B)

#### Problem 
The length of some string s is denoted |s|. The Hamming distance between two strings s and t of equal length is defined as , where si is the i-th character of s and ti is the i-th character of t. For example, the Hamming distance between string "0011" and string "0110" is |0 - 0| + |0 - 1| + |1 - 1| + |1 - 0| = 0 + 1 + 0 + 1 = 2.

Given two binary strings a and b, find the sum of the Hamming distances between a and all contiguous substrings of b of length |a|.

#### Input
The first line of the input contains binary string a (1 ≤ |a| ≤ 200 000).

The second line of the input contains binary string b (|a| ≤ |b| ≤ 200 000).

Both strings are guaranteed to consist of characters '0' and '1' only.

#### Output
Print a single integer — the sum of Hamming distances between a and all contiguous substrings of b of length |a|.

#### Sample 

		Input:
			01
			00111
		Output:
			3

### Solution
Solution requires a preprocessing step of calculating a prefix arrays ( size |b|), with ith value holding the count of occurrences of '0's and '1's, respectively, in the prefix (0, i) of string b. Using this we can calculate the mismatched frequency of a[i] in b, for i in (0, |a|). Overall sum of this will give the result.