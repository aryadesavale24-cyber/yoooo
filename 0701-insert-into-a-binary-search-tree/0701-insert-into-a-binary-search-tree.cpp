/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x=new TreeNode();
        x->val=val;
        if(root==NULL) return x;
        TreeNode*p=root;
        while(true){
            if(x->val>p->val){
                if(p->right==NULL)
                { p->right=x;
                break;
                }
                p=p->right;
            }
            else{
                if(p->left==NULL){
                    p->left=x;
                break;}
                p=p->left;
        }
    }
        return root;
        
    }
};