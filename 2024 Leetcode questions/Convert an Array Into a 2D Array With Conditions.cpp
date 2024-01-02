/* You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.
Note that the 2D array can have a different number of elements on each row.
 */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
     vector<vector<int>> ans(200);
     map<int,int> mp;
     int mx=0;
     for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
        mx=max(mx,mp[nums[i]]);
        ans[mp[nums[i]]-1].push_back(nums[i]);
     }
//The extra rows are "created" in the code due to the initialization of the ans matrix to have 200 rows, even if they are not fully utilized.
//That is why we have to remove the rows after the mx as the no of used rows will be equal to the max frequency of an element in the vector. 
     // if we don't remove the extra rows then ans will be [[1,3,4,2], [1,3], [1], [], [], ..., []]
     for(int i=mx; i<200; i++){
         ans.erase(ans.begin()+i);
     }

     return ans;
    }
};
