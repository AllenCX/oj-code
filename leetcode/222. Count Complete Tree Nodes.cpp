//naive solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *node = root;
        if(!root) return 0;
        int height = 0;
        while(node->left){
            node = node->left;
            ++height;
        }
        int l = 0, r = pow(2, height) - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canGo(root, height, mid) == 0){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return pow(2, height) + l - 1;
    }
    bool canGo(TreeNode* root, int height, int path){
        while(height){
            int t = path >> (height - 1);
            t = t & 1;
            if(t == 0 && root->left){
                root = root->left;
            }else if(t == 0 && !root->left){
                return false;
            }
            if(t == 1 && root->right){
                root = root->right;
            }else if(t == 1 && !root->right){
                return false;
            }
            --height;
        }
        return true;
    }
};