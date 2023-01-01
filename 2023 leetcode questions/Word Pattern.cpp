/* Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool wordPattern(string pattern, string s) {
       vector<string> words;
      
       int i=0;
        string temp="";
       while(i<s.size()){
           if(s[i]==' '){
               words.push_back(temp);
               temp="";
           }
           else{
               temp+=s[i];
           }
           i++;
       } 
       words.push_back(temp);
       if(words.size()!=pattern.size()){
           return false;
       }
       unordered_map<char,string> m;
       set<string> st;
       for(int i=0; i<pattern.size(); i++){
           if(m.find(pattern[i])!=m.end()){
               if(m[pattern[i]]!=words[i]){
                   return false;
               }
           }
           else{
               if(st.count(words[i])>0){
                   return false;
               }
               m[pattern[i]]=words[i];
               st.insert(words[i]);
           }
       }
       return true;
    }
};
