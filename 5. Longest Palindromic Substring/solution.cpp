class Solution {
public:
    string expand(string s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);// substr(起始位置，長度)
    }
    string longestPalindrome(string s) {
        string ans = "";
        string odd = "";
        string even = "";
        for(int i = 0; i < s.size(); i++){ //不知道s為奇或偶，都試
            odd = expand(s, i, i);
            even = expand(s, i, i + 1);
            if(odd.size() > ans.size()){
                ans = odd;
            }
            if(even.size() > ans.size()){
                ans = even;
            }
        }
        return ans;
    }
};
