class Solution {
public:
    int reverse(int x) {
        long long ans = 0; // 用long long避免超過int範圍
        int y = 0;
        while(x != 0){
            y = x % 10;
            x /= 10;
            ans = ans * 10 + y;
            if(ans < INT_MIN || ans > INT_MAX){
                return 0;
            }
        }
        return ans;
    }
};
