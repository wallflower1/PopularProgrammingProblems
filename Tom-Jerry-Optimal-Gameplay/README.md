### Tom and Jerry fight

### Problem 
Tom and Jerry started fighting in the contest too, as always! As this is the INDIAHACKS Contest so this time the fight is on numbers. They ended up bringing a game to decide who is better. They have N marbles and they choose two integers M1 and M2, in each turn a player can take either M1 or M2 marbles(if available!). One who can't make any move further, loses.

Game is started with Jerry's turn always. Given N, M1 and M2, and assuming that both are playing optimally, tell us whether Jerry will win or not.

##### Input:

 T, number of test cases then T lines containing three integers N, m1 and m2
##### Output:

 1 If Jerry wins, 0 if Tom wins.
##### Constraints:

0<T<100

0< m1 <= m2, N <=1000000.    Note that m1 or m2 can be greater than N.

Test files will be such that T*N < 10000000 .

### Solution:
I solved this problem using Dynamic Programming approach. Here PlayerWins method takes input n, m1 and m2 and returns 1 if there is any case in which this player can win. The subproblems can be defined as:
	
	if n>m1 || n>m2 : 
		playerWins(n, m1, m2) = !playerWins(n-m1, m1, m2) || !playerWins(n-m2, m1, m2)   
	else :
		playerWins(n, m1, m2) = 0

This will ensure that both the players are playing optimally.  
