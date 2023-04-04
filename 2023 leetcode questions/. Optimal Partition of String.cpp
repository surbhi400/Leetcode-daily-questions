// Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single
// substring more than once.

// Return the minimum number of substrings in such a partition.

// Note that each character should belong to exactly one substring in a partition.

 

// Example 1:

// Input: s = "abacaba"
// Output: 4
// Explanation:
// Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
// It can be shown that 4 is the minimum number of substrings needed.
// Example 2:

// Input: s = "ssssss"
// Output: 6
// Explanation:
// The only valid partition is ("s","s","s","s","s","s").
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 class Solution {
public:
    int partitionString(string s) {
      set<int> st;
      int count=0;
  //insert elements in a set which is not present in the set while increasing the window size and once it breaks increase count and clear the set for next iteration
      for(int i=0; i<s.size(); i++){
          while(i < s.size() && st.find(s[i]) == st.end()){
              st.insert(s[i]); 
              i++;
          }
          i--;
          count++;
          st.clear();

      }
      return count;
    }
};
 
