class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //vector<vector <int> > m(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        //vector<vector <int> > low(dungeon.size(), vector<int>(dungeon[0].size(), INT_MAX));
        
        if(dungeon.size() == 1 && dungeon[0].size() == 1){
            if(dungeon[0][0] < 0) return - (dungeon[0][0] - 1);
            else return 1;
        }
        int height = dungeon.size();
        int width = dungeon[0].size();
        int m[height][width];
        for(int i = height - 1; i >= 0; --i){
            for(int j = width - 1; j >= 0; --j){
                if(i == height - 1 && j == width - 1){
                    m[i][j] = max(1, - dungeon[i][j] + 1);
                }
                if(i != height - 1 && j == width - 1){
                    m[i][j] = max(1, m[i + 1][j] - dungeon[i][j]);
                }
                if(i == height - 1 && j != width - 1){
                    m[i][j] = max(1, m[i][j + 1] - dungeon[i][j]);
                }
                if(i != height - 1 && j != width - 1){
                    m[i][j] = max(1, min(m[i + 1][j], m[i][j + 1]) - dungeon[i][j]);
                }
            }
        }
        /*int i = height - 1;
        int j = width - 1;
        if(dungeon[i][j] < 0) low[i][j] = max(low[i - 1][j] + dungeon[i][j], m[i][j - 1] + dungeon[i][j]);
        else low[i][j] = max(low[i - 1][j], m[i][j - 1]);
        */
        
        return m[0][0];
    }
};