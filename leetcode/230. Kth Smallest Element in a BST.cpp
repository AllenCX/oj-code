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
    int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root->left);
        if(k <= count){
            return kthSmallest(root->left, k);
        }else if(k > count + 1){
            return kthSmallest(root->right, k - 1 - count);
        }
        return root->val;
    }
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// inorder iteratively
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *node = root;
        while(node != NULL || k){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                node = st.top();
                st.pop();
                --k;
                if(k == 0) return node->val;
                node = node->right;
            }
        }
        return -1;
    }
};

// inorder recursively

class Solution {
private:
    int number;
    int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        helper(root);
        return number;
    }
    void helper(TreeNode* root){
        if(root->left != NULL) helper(root->left);
        --count;
        if(count == 0){
            number = root->val;
            return;
        }
        if(root->right != NULL) helper(root->right);
    }
};