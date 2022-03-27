class Difference {
    // 设计一个差分数组的class
    // 差分数组
private:
    vector<int> diff;
public:
    /* 输入一个初始数组，区间操作将在这个数组上进行 */
    Difference(vector<int>& nums){
        diff.resize(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            diff[i] = nums[i] - nums[i-1];
        }
    }
    /* 给闭区间 [i,j] 增加 val（可以是负数）*/
    void increment(int i, int j, int val){
        diff[i]+=val;
        if(j+1<diff.size()){
            // 防止数组越界
            diff[j+1]-=val;
        }
    }

    vector<int> result(){
        // 返回结果数组, 还原diff数组
        vector<int> res(diff.size());
        res[0] = diff[0];
        for(int i=1;i<diff.size();i++){
            res[i] = res[i-1] + diff[i];
        } 
        return res;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ret(1001,0);
        Difference Diff(ret);
        for(vector<int> onetrip:trips){
            Diff.increment(onetrip[1],onetrip[2]-1,onetrip[0]);
        }
        vector<int> ans = Diff.result();
        for(int x:ans){
            if(x>capacity){
                return false;
            }
        }
        return true;
    }
};