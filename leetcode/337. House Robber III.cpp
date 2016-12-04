// solution with pair
class Solution {
public:
    int rob(TreeNode* root) {
        return gain(root).first;
    }
    pair<int, int> gain(TreeNode* node){
        pair<int, int> dp = make_pair(0, 0);
        if(node){
            pair<int, int> dp_L = gain(node->left);
            pair<int, int> dp_R = gain(node->right);
            dp.second = dp_L.first + dp_R.first;
            dp.first = max(dp.second, dp_L.second + dp_R.second + node->val);
        }
        return dp;
    }
};

// solution with vector, almost the same, but slower than above
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp = dfs(root);
        return max(dp[0], dp[1]);
    }
    vector<int> dfs(TreeNode* node){
        vector<int> dp(2, 0);
        if(!node) return dp;
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        dp[1] = node->val + left[0] + right[0];
        return dp;
    }
};