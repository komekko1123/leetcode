class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int glb = 0; // go left bit
      while(right > left){
        right = right >>1;
        left = left >> 1;
        glb++;
      } 
      return left << glb;
    }
};
