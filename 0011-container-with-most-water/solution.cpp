class Solution {
public:
    int maxArea(vector<int>& height) {
      int sum = 0, left = 0, right = height.size()-1;
      for(int i = 0 ; i < height.size() && left < right ; i++ ){
        if( height[left] >= height[right] ){ // 左邊柱子高，動右邊
          if( sum < (right-left) * height[right] ) // 接更多就更新
            sum = (right-left) * height[right];
          right--;
        } // if

        else { // 相反
          if( sum < (right-left) * height[left] ) // 接更多就更新
            sum = (right-left) * height[left];
          left++;
        } // else
      } // for
       
      return sum;
    }
};
