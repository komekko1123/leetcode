class BusBooking {
public:
    unordered_map<int,int> bus;
    int book;
    int total_time;
    BusBooking(int n) {   
      book = 0;
      total_time = 0;
    }
    
    void toggle(string seat) {
      int d = change(seat[0]); // 轉成abcd
      int num = atoi( seat.substr(1,seat.size()).c_str());
      if( bus[4*(num-1)+d] == 0 ){
        total_time += change_seat(4*(num-1)+d,d);
        book++;
      } //if
      
      else{
        total_time -= bus[4*(num-1)+d];
        bus[4*(num-1)+d] = 0;
        book--;
      } // else
    }
    
    int getTotalTime() { 
      if(book == 0)
        return 0;
      return total_time;
    }
    
    int getMinTime() {
      if(book == 0)
        return 0;        
      return book;
    }

    int change(char c){
      if(c == 'A') return 0;
      else if( c == 'B') return 1;
      else if( c == 'C') return 2;
      else  return 3;        
    }

    int change_seat(int index, int change_num){
      if(change_num == 0){
        if( bus[index+1] == 1){
          bus[index] = 3;
          return 3;
        }
        else {
          bus[index] = 1;
          return 1;
        } // else
      } // if
      
      else if(change_num == 1){
          bus[index] = 1;
          return 1;
      } // else if   
      
      else if(change_num == 2){
          bus[index] = 1;
          return 1;
      } // else if 
        
      else if(change_num == 3){
        if( bus[index-1] == 1){
          bus[index] = 3;
          return 3;
        }
        else {
          bus[index] = 1;
          return 1;
        }
      } // if
      return 0;
    } // change_seat


};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
