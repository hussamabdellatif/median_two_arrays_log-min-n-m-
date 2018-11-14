// 
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
// Example 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5


#include<vector>
using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        double to_ret = 0;
        int w_big = 1;
         vector<int> x;
         vector<int> y;
        if(size1 < size2){
            x = nums1;
            y = nums2;
        }else{
            x = nums2;
            y = nums1;
        }
        //x is smaller, y is bigger  or both same size.....
        int start = 0;
        int end   = x.size();
        bool is_even = ( (size1+size2) %2) ? false:true;

        while(start<=end){
            int x_p = ((end + start) / 2) ;
            int y_p = (size1 + size2 +1 )/2 - x_p;

            int x_left = (x_p == 0) ? -99999999:x[x_p -1];
            int y_left = (y_p == 0) ? -99999999:y[y_p -1];

            int x_right = (x_p == x.size()) ? 999999999:x[x_p];
            int y_right = (y_p == y.size()) ? 999999999:y[y_p];

            if(x_left <= y_right && y_left <= x_right){
                //case 1:
                if(is_even)return  ((double)max(x_left, y_left) + (double) min(x_right,y_right) ) /2;
                return to_ret = max(x_left,y_left);

            }else if( x_left > y_right ){
                end = x_p - 1;
            }else{
                start = x_p + 1;
            }


        }

        return 0;







    }
};
