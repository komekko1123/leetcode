class Solution {
public:
    int myAtoi(string s) {
      int sign = 1;
      long long sum = 0;
      int i = 0;
      while(s[i] == ' '){
        i++;
      } // while
      if(s[i]=='-'){
        sign = -1;
        i++; 
      } // if
      else if(s[i]=='+')
        i++;
      for ( ; s[i] >= '0' && s[i]<='9' ; i++ ){
       sum = sum*10 + ( s[i] - '0' );
       if( sum * sign < INT_MIN ) 
         return INT_MIN;
       else if( sum * sign > INT_MAX )
         return INT_MAX;
      } // for
      return sum * sign;
    }
    
    /*
    int myAtoi(string s) { 寫得不錯的1
        int i = 0;
        int sign = 1;
        long result = 0;
        
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+' || s[i]=='-'){
            sign = s[i]=='-'?-1:1;
            i++;
        }
        while(s[i]>='0' && s[i]<='9'){
            result = result*10 + (s[i]-'0');

            if(result*sign<INT_MIN) return INT_MIN;
            if(result*sign>INT_MAX) return INT_MAX;

            i++;
        }
        return result*sign;
    }

     int myAtoi(string s) {  寫得不錯的2
        int flag=0;
        int i=0;
        while(s[i]==' ')i++;
        if(s[i]=='-'){ flag=1;i++; }
        else if(s[i]=='+')i++;
        int o=s[i]-'0';if(o<0 || o>9) return 0;
        long long sum=0;
        while(s[i]=='0') i++;
        for(;i<s.size();i++){
            int a=s[i]-'0';
            if(a<0 || a>9) break;
            sum+=a;
            sum*=10;
            if(flag){
               if((-sum/10)<=INT_MIN) return INT_MIN;
            }
            else{
               if((sum/10)>=INT_MAX) return INT_MAX;
            }
        }
        if(flag) return -sum/10;
        return sum/10;
    }

  */
};
