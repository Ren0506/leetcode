class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // 宣告hash table
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){ // right指標一直往下走
            if(mp.count(s[right]) && mp[s[right]] >= left){ // mp.count(s[right]):確認是否出現過，mp[s[right]] >= left:確認在範圍內
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
