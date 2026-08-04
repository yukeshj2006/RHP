class Solution {
public:
    vector<int> ad(vector<int> v,int num){
        vector<int> out;
        for(int i=0;i<v.size();i++){
            out.push_back(v[i]+num);
            out.push_back(v[i]-num);
        }
        return out;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> out;
        int count = 0;
        out.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            out=ad(out,nums[i]);
        }
        for(int i=0;i<out.size();i++){
            if(out[i]==target){
                count++;
            }
        }
        return count;
    }
};
