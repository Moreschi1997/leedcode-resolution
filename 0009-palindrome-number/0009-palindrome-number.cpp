class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        long reverse_number = 0;
        int original = x;
        while(x > 0)
        {
            reverse_number = (reverse_number * 10) + (x % 10);
            x /= 10;
        }

    return (reverse_number == original);
    }
};