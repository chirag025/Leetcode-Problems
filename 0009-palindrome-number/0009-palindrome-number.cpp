class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if(x < 0) return 0;
        int ans = 0;
        while(x != 0){
            int last = x % 10;
            if(ans > INT_MAX/10) return 0;
            ans = ans*10 + last;
            x /= 10;
        }

        if(temp == ans) return 1;
        return 0;
    }
};