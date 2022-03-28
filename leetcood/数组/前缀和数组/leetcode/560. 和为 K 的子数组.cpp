class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // vector<int> preSum(nums.size()+1,0);
        unordered_map<int,int> map;
        // 如果当前元素本身就是k，那么ans++
        map[0]=1; // 子数组正好是当前元素的情况
        int ans=0;
        // 可以如果是顺序访问前缀和数组，可以简化掉数组，仅使用一个变量维护当前的前缀和即可
        // for(int i=1;i<=nums.size();i++){
        //     preSum[i] = preSum[i-1] + nums[i-1];
        // }
        
        // for(int i=1;i<=nums.size();i++){
        //     if(map.find(preSum[i]-k)!=map.end()){
        //         ans += map[preSum[i]-k];
        //     }
        //     map[preSum[i]]++;
        // }

        // 优化版本
        int preSum = 0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            if(map.find(preSum-k)!=map.end()){
                ans += map[preSum-k];
            }
            map[preSum]++;
        }
        return ans;
    }
};