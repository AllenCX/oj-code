class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.size() < 2) return res;
        for(int i = 0; i < numbers.size(); ++i){
            int tmp = target - numbers[i];
            // binary search for tmp
            int r = numbers.size() - 1;
            int l = i + 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(numbers[mid] < tmp){
                    l = mid + 1;
                }else if(numbers[mid] > tmp){
                    r = mid - 1;
                }else{
                    res.push_back(i + 1);
                    res.push_back(mid + 1);
                    return res;
                }
            }
        }
        return res;
    }
};