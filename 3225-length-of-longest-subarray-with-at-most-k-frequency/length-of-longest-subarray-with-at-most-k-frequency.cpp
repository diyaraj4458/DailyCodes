class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        unordered_map<int,int> freq;
        
        for(int i=0,j=0; j<n; j++){
            int &count = freq[nums[j]];  // Reference to avoid multiple lookups
            count++;
            
            while(count > k){
                freq[nums[i++]]--;
            }
            
            maxlen = max(maxlen, j-i+1);
        }
        
        return maxlen;
    }
};