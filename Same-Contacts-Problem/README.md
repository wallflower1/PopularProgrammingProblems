## Same Contacts Problem

### statement
Given a list of contacts containing username, email and phone number in any order. Identify the same contacts (i.e., same person having many different contacts) and output the same contacts together.

Notes:
1) A contact can store its three fields in any order, i.e., phone number can appear before username or username can appear before phone number.

2) Two contacts are same if they have either same username or email or phone number.

####Example:

Input: contact[] = 
     { {"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"},
       { "Lucky", "lucky@gmail.com", "+1234567"},
       { "gaurav123", "+5412312", "gaurav123@skype.com"}.
       { "gaurav1993", "+5412312", "gaurav@gfgQA.com"}
     }
Output:
   0 2 3
   1 
Explanation:

contact[2] is same as contact[3] because they both have same contact number.
contact[0] is same as contact[3] because they both have same e-mail address.
Therefore, contact[0] and contact[2] are also same.

### Approach
This problem can be solved easily by hashing the contact fields in a single hashtable (map in this solution) and performing find-union operation on contacts which are already present in the hashtable. Result will be the individual disjoints sets created in the process.

### Complexity Analysis
Hashing can be O(n*3), Meanwhile, the union-find operation using ranks and path compression has amortized time per operation as almost constant time. Hence, we can safely say that overall time complexity will be O(n).

Space complexity will be O(n) (for both hash table(3n in worst case) and disjoint-set forest). 