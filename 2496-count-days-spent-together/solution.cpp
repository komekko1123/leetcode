class Solution {
public:
    vector<int> mouth_to_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      int alice_arr = parsing(arriveAlice);
      int alice_lev = parsing(leaveAlice);
      int bob_arr = parsing(arriveBob);
      int bob_lev = parsing(leaveBob);
      int start = max(alice_arr, bob_arr);
      int end = min(alice_lev, bob_lev);
      return max(0 ,  end - start + 1);
    }

    int parsing(string str){
      string sub_mouth = str.substr(0,2);
      string sub_days = str.substr(3,2);
      int date = stoi(sub_days);
      for (int i = 0; i < stoi(sub_mouth)-1; i++) {
        date += mouth_to_day[i];
      }
      return date;
    } // pair
};
