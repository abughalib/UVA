class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   double median = 0.0;
   for(auto x: nums2) nums1.push_back(x);

   sort(nums1.begin(), nums1.end());

   if(nums1.size() %2 == 0){
      median =(double) (nums1[nums1.size()/2 ] + nums1[nums1.size()/2-1])/2;
   }else{
      median = (double) nums1[nums1.size()/2];
   }

    return median;
    }
};
int main(){

   vector<int> nums1 = {1, 3};
   vector<int> nums2 = {2};

   Solution sol;

   cout <<sol.findMedianSortedArrays(nums1, nums2);

   return 0;
}
