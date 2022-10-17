/* A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int> mp;// create a map and push all the elements of the string in the map.
        for(int i=0; i<sentence.length(); i++)
            {
               mp[sentence[i]]++; 
            }
      // create a vector and push the elements of the map to the vector.
      
        vector<int> letters;
        for(auto x:mp){
            letters.push_back(x.first);
        }
      // if the size of vector is 26 then return true otherwise false.
        if(letters.size()==26){
            return true;
        }
        return false;
        
}
};
