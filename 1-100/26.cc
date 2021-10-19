class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        nums.assign(st.begin(), st.end());
        sort(nums.begin(), nums.end());
        return st.size();
    }
};