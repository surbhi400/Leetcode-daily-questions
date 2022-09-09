/* you are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array
properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally,
a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

 

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other. */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
     static bool compare(vector<int>& A, vector<int>& B)
    {
        if(A[0] == B[0])
            return A[1] > B[1];
        else
            return A[0] < B[0];
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int size = properties.size();
        
       
        
        sort(properties.begin(),properties.end(), compare);
        
        int count = 0;
        
       
        
        int max_defence = properties[size - 1][1];
        
        for(int i = size - 2; i >= 0; i--)
        {
		   
			
            if(properties[i][1] < max_defence)
            {
                count++;
            }
            
      
            
            max_defence = max(max_defence, properties[i][1]);
        }
        
        return count;
    }
};
