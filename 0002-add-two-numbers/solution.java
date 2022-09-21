/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      int digitinten = 0, sum = 0, check = 0;
      ListNode temp1 = new ListNode(0,l1);
      ListNode temp2 = new ListNode(0,l2); 
      ListNode temp3 = new ListNode(0);
      ListNode ans = new ListNode(0);
      temp1 = l1;
      temp2 = l2;   
      ans = temp3;
      while ( temp1 != null || temp2 != null ) {
        if( temp1 != null && temp2 != null ){
          sum = temp1.val + temp2.val + check;
          check = 0;
          if( sum >= 10 ) {
            sum -= 10;
            check += 1;  
          } // if
          temp3.val = sum;
          temp3.next = new ListNode(0); 
        } // if      
          
        else if( temp1 == null && temp2 != null ){
          sum = temp2.val + check;
          check = 0;
          if( sum >= 10 ) {
            sum -= 10;
            check += 1;  
          } // if  
          temp3.val = sum;
          temp3.next = new ListNode(0);   
        } // if  
        else if( temp1 != null && temp2 == null ){
          sum = temp1.val + check;
          check = 0;
          if( sum >= 10 ) {
            sum -= 10;
            check += 1;  
          } // if  
          temp3.val = sum;
          temp3.next = new ListNode(0);   
        } // if            
        digitinten = 1 ;  
        if ( temp1 != null )
          temp1 = temp1.next;
        if ( temp2 != null )
          temp2 = temp2.next;  
        if( temp1 == null && temp2 == null && check == 0)  
          temp3.next = null ;  
        else if ( temp1 == null && temp2 == null && check == 1 )  
          temp3.next = new ListNode(1) ;
        else  
          temp3 = temp3.next;
      } // while
       return ans;      
    }  //           
}  
