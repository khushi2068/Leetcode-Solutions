class Solution {
public:
int findlargest(vector<int>& nums){

    int l=INT_MIN;
    for(auto i: nums){
        if(i>l) l=i;
    }
    return l;

}
    int dominantIndex(vector<int>& nums) {
        int l=findlargest(nums);
        for(auto i:nums){
            if(i!=l && l<2*i) return -1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==l) return i;
        }
        return -1;
    }
    
};