// recursive solution
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0, inEnd = inorder.size() - 1;
        int postStart = 0, postEnd = postorder.size() - 1;
        return helper(inorder, inStart, inEnd, postorder, postStart, postEnd);
    }
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
        if(inorder.size() == 0 || inStart > inEnd || postStart > postEnd){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int index = inStart;
        for(int i = inStart; i <= inEnd; ++i){
            if(inorder[i] == postorder[postEnd]){
                index = i;
                break;
            }
        }
        node->left = helper(inorder, inStart, index - 1, postorder, postStart, postStart + index - inStart - 1);
        node->right = helper(inorder, index + 1, inEnd, postorder, postStart + index - inStart, postEnd - 1);
        return node;
    }
};

// iterative solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // iterative solution
        stack<TreeNode *> st;
        TreeNode *root = new TreeNode(INT_MIN);
        st.push(root);
        TreeNode *ptr = root, *pp = NULL;
        int j = inorder.size() - 1;
        int i = postorder.size() - 1;
        while(j >= 0){
            if(st.top()->val == inorder[j]){
                pp = st.top();
                st.pop();
                --j;
            }else if(pp){
                ptr = new TreeNode(postorder[i]);
                pp->left = ptr;
                pp = NULL;
                st.push(ptr);
                --i;
            }else{
                ptr = new TreeNode(postorder[i]);
                st.top()->right = ptr;
                st.push(ptr);
                --i;
            }
        }
        return root->right;
    }
};