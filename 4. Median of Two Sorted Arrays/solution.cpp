class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){ //保證 Binary Search 永遠在較短的陣列上進行
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        while(left <= right){
            int cut1 = (left + right) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            int l1 = 0;
            if(cut1 == 0){
                l1 = INT_MIN;
            }else{
                l1 = nums1[cut1 - 1];
            }
            int r1 = 0;
            if(cut1 == m){
                r1 = INT_MAX;
            }else{
                r1 = nums1[cut1];
            }
            int l2 = 0;
            if(cut2 == 0){
                l2 = INT_MIN;
            }else{
                l2 = nums2[cut2 - 1];
            }
            int r2 = 0; 
            if(cut2 == n){
                r2 = INT_MAX;
            }else{
                r2 = nums2[cut2];
            }
            if (l1 <= r2 && l2 <= r1) { //切的好
                if ((m + n) % 2){
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            if(l1 > r2){
                right = cut1 - 1;
            }else{
                left = cut1 + 1;
            } 
        }
        return 0;
    }
};
