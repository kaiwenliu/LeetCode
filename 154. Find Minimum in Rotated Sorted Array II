class Solution {
public:
    int findMin(vector<int>& nums, int high = -1, int low = 0) {
        if (high == -1) {
            high = nums.size();
        }
        while (low < high) {
            int mid = low + (high-low)/2;
            if ((mid+1 < nums.size() && nums[mid+1] < nums[mid])) {
                return nums[mid+1];
            } 
            if ((mid-1 >= 0 && nums[mid-1] > nums[mid])) {
                return nums[mid];
            }
            if (nums[mid] < nums[0]) {
                high = mid;
            }
            else if (nums[mid] > nums[0]) {
                low = mid+1;
            }
            // Check both sides
            else {
                return min(findMin(nums, mid, low), findMin(nums, high, mid+1));
            }
        }
        if (low >= nums.size()) {
            return nums[0];
        }
        return nums[low];
    }
};
