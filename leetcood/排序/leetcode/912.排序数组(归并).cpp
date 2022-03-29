class Solution {
public:
    vector<int> temp; // 辅助数组
    void sort(vector<int>& nums, int l,int r){
        if(l==r){
            // 单个元素不用排序
            return;
        }
        int mid = l+(r-l)/2;
        sort(nums,l,mid);
        sort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }

    void merge(vector<int>& nums, int l, int mid, int r){
        // 存入辅助数组
        for(int i=l;i<=r;i++){
            temp[i] = nums[i];
        }
        // nums[l..mid] 和nums[mid+1..r]
        // 利用双指针合并两个有序数组

        int i=l,j=mid+1;
        for(int p=l;p<=r;p++){
            if(i==mid+1){
                nums[p] = temp[j++];
            }else if(j==r+1){
                nums[p] = temp[i++];
            }else if(temp[i]>temp[j]){
                nums[p] = temp[j++];
            }else{
                nums[p] = temp[i++];
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(),0);
        sort(nums,0,nums.size()-1);
        return nums;
    }
};