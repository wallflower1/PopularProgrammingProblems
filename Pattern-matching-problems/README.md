## Problem
All string-matching related problems and algorithms.

### KNUTH MORRIS PRATT (KMP) PATTER SEARCHING:
This algorithm majorly handles the case wherein the prefix of pattern is also a suffix till it has been matched. In such case we end up comparing the same prefix again in the naive approach. This algorithm is order of length of text string. Here we make a prefix array which stores at each index the max length of suffix till that point which is also a prefix in the pattern.

Time Complexity: O(m + n)

Space Complexity: O(m)

### RABIN KARP :
In this method, we will calculate the hash value of pattern and each m-length substring in text and compare the two only if their hash values match. This algorithm is dependent on good hash calculation which gives almost unique values for different patterns and also can be calculated in constant time. This algorithm is popular in case of multiple pattern searching since we will only require to calculate the hash values of text once. 

Time complexity: O(m+n)

Space Complexity: O(1)