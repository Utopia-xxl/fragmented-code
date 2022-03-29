class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // 分别计算T和R的最大连续次数，然后取最大值
        return max(countChar(answerKey,k,'T'),countChar(answerKey,k,'F'));
    }
    int countChar(string answerKey, int k, char ch){
        // 滑动窗口
        // 维护区间内不相同字符的数量，没超过就右指针右移，超过就左指针右移
        int l=0,r=0,cnt=0;
        while(r<answerKey.size()){
            // 右指针右移
            if(answerKey[r]!=ch){
                k--;
            }
            // 左指针右移 
            while(k<0){
                if(answerKey[l]!=ch){
                    k++;
                }
                l++;
            }
            r++;
            cnt = max(cnt,r-l);
        }
        return cnt;
    }
};