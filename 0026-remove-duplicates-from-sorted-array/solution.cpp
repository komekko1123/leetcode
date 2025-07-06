class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      for( int slow = 0, fast = 0; slow < nums.size() ; fast++ ){
        if( fast == nums.size() ){
          if( fast != slow ){
            nums.erase(nums.begin()+slow, nums.begin()+fast-1);
          } // if
          break;
        } // if 

        if(  nums[slow] != nums[fast] && slow != fast ){
          nums.erase(nums.begin()+slow, nums.begin()+fast-1 );
          fast = slow + 1 ;
          slow = fast;
        } // if
      } // for 

      return nums.size();
    }
};
