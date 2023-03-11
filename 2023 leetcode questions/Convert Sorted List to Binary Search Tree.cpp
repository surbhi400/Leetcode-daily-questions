/* Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: [] */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
TreeNode* createTree(vector<int> &inorder, int start, int end){
    if(start>end) return NULL;
    int middle=(start+end)/2;
    TreeNode* root=new TreeNode(inorder[middle]);
    if(start==end) return root;
    root->left =createTree(inorder,start,middle-1);
    root->right = createTree(inorder,middle+1, end);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        vector<int> inorder;
while(temp!=NULL){
    inorder.push_back(temp->val);
    temp=temp->next;

}
int k=inorder.size();
TreeNode* root=createTree(inorder,0,k-1);
return root;
    }
};
