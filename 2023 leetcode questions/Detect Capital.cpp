/* We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;// all characters re small
        if(word.size()==1)
            return true;
        
        for(int i=0; i<word.size(); i++)
            if(isupper(word[i]))
                count++;
        
        if(count==1 && isupper(word[0]))// if only one char is large and that is first character
            return true;
        if(count==0 || count==word.size()) // if all characters are small or all are capital
            return true;
        else
            return false;
       
    }
    
};
