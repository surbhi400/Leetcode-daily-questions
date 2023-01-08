/* Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     int n=points.size();
     if(n<=2) return n;// when only 1 or 2 lines are present
     int maxi=2;// let's consider minimum points on a line to be 2 as 2 points form a line.
      // chose any 2 points
     for(int i=0; i<n; i++){
         for(int j=i+1; j<n; j++){
             int total=2;
             for(int k=0; k<n; k++){// iterate in the vector again and chose any other point except the already chosen points.
                 if(k!=i && k!=j){
                   // slope calculated
                     if((points[j][1]-points[i][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[j][0]-points[i][0])) //if the slopes are equal increase total
                     total++;
                 }
             }
             maxi=max(maxi,total); 
         }
     }
     return maxi;
    }
};
