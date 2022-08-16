class Solution {
public:
    const long mod = pow(10,9) + 7;
    int backTrack(vector<int>& nums) {
        long a = nums[0];
        long e = nums[1];
        long i = nums[2];
        long o = nums[3];
        long u = nums[4];
        
        nums[0] = e % mod;
        nums[1] = (a+i) % mod;
        nums[2] = (a + e + o + u) % mod;
        nums[3] = (i+u) % mod;
        nums[4] = a % mod;
        return (2*e+3*a+2*i+o+2*u) % mod;
    }
    
    int countVowelPermutation(int n) {
        // Each index represents a, e, i, o, u respectively.
        vector<int> nums(5, 1); 
        int permutations = 5;
        for (int i = 1; i < n; i++) {
            permutations = backTrack(nums);
        }
        return permutations;
    }
};
