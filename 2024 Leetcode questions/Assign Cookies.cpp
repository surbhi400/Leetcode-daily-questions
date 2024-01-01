/* Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i],
we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1. */
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         int n=g.size();
         int k= s.size();
         int i=0,j=0;
         sort(g.begin(),g.end());
         sort(s.begin(),s.end());
        while(i<n && j<k){
            if(g[i]<=s[j]){ // At i = 0 and j = 0, g[i] = 1 (child's greed) and s[j] = 1 (cookie size). The child can be satisfied by this cookie size, so i increments to 1.
                 i++;       // Now, i = 1 and j = 1. g[i] = 2 (child's greed) and s[j] = 2 (cookie size). The child can be satisfied by this cookie size, so i increments to 2.
            }
          j++;
        }
        return i;
    }
};
