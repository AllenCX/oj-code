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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd){
        if(preStart > preorder.size() - 1 || inStart > inEnd){
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preStart]);
        int index = 0;
        for(int i = inStart; i <= inEnd; ++i){
            if(inorder[i] == node->val) index = i;
        }
        node->left = helper(preorder, inorder, preStart + 1, inStart, index - 1);
        node->right = helper(preorder, inorder, preStart + index - inStart + 1, index + 1, inEnd);
        return node;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode *> st;
        TreeNode *root = new TreeNode(INT_MIN); // guard
        st.push(root);
        TreeNode *ptr = root, *pp = NULL;
        int j = 0, i = 0;
        while(j < inorder.size()){
            if(st.top() -> val == inorder[j]){
                pp=st.top();
                st.pop();
                ++j;
            }else if(pp){
                ptr = new TreeNode(preorder[i]);
                pp->right = ptr;
                pp = NULL;
                st.push(ptr);
                ++i;
            }else{
                ptr = new TreeNode(preorder[i]);
                st.top()->left = ptr;
                st.push(ptr);
                ++i;
            }
        }
        ptr = root->left;
        delete root;
        return ptr;
    }
};