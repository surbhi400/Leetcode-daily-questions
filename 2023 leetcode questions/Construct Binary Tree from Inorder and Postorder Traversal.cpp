/* Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]  
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
  */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
TreeNode* constructTree(vector<int> &inorder, int instart,int inend,vector<int> &postorder, int posstart,int posend,unordered_map<int,int> &mp){
            if(instart>inend|| posstart>posend) return NULL;
            TreeNode* root=new TreeNode(postorder[posend]);
            int rootpos=mp[root->val];
            int numsleft=rootpos-instart;

            root->left =  constructTree(inorder,instart,rootpos-1,postorder,posstart,posstart+numsleft-1,mp);
       
        root->right = constructTree(inorder,rootpos+1,inend,postorder,posstart+numsleft,posend-1,mp); 
        return root;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
       int instart=0, inend=n-1, posstart=0,posend=m-1;
        return constructTree(inorder,instart,inend,postorder,posstart,posend,mp);

       
       
        
    }
};
