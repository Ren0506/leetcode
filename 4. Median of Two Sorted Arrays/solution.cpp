class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0; //左邊界
        int right = m; //右邊界
        while(left <= right){
            int l1 = 0; //左半邊最大數(靠近cut)
            int r1 = 0; // 右半邊最小數
            int l2 = 0; //左半邊最小數
            int r2 = 0; //又半邊最小數
            int cut1 = (left + right) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            if(cut1 == 0){
                l1 = INT_MIN;
            }else{
                l1 = nums1[cut1 - 1];
            }
            if(cut1 == m){
                r1 = INT_MAX;
            }else{
                r1 = nums1[cut1];
            }
            if(cut2 == 0){
                l2 = INT_MIN;
            }else{
                l2 = nums2[cut2 - 1];
            }
            if(cut2 == n){
                r2 = INT_MAX;
            }else{
                r2 = nums2[cut2];
            }
            if(l1 <= r2 && l2 <= r1){
                if((m + n) % 2 != 0){
                    return max(l1, l2);
                }else{
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }      
            }
            if(l1 >= r2){
                right = cut1 - 1;
            }else if(l2 >= r1){
                left = cut1 + 1;
            }
        }
        return 0;
    }
};
