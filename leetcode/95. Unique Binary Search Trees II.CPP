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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode *>(0) ;
        else return *generate(1, n);
    }
    vector<TreeNode *> *generate(int start, int end){
        vector<TreeNode *> *subTree = new vector<TreeNode *>();
        if(start > end){
            subTree->push_back(NULL);
            return subTree;
        }
        for(int i = start; i <= end; ++i){
            vector<TreeNode *> *leftTree = generate(start, i-1);
            vector<TreeNode *> *rightTree = generate(i+1, end);
            for(int j = 0; j < leftTree->size(); ++j){
                for(int k = 0; k < rightTree->size(); ++k){
                    TreeNode * node = new TreeNode(i);
                    node->left = (*leftTree)[j];
                    node->right = (*rightTree)[k];
                    subTree->push_back(node);
                }
            }
        }
        return subTree;
    }
};