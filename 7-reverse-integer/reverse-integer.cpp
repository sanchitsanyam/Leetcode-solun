class Solution {
public:
    int reverse(int x) {
        int reverse_num = 0;
        int flag=0;
        if(x<0)flag=1;
        x=abs(x);
        while (x != 0) {
            int last_num = x % 10;
            x=x/10;
            if((reverse_num>(INT_MAX/10))||(reverse_num<(INT_MIN/10))){
                return 0;
            }
            else{
                reverse_num = reverse_num * 10 + last_num; 
            }
           
        }

        return(flag==1)? -1*reverse_num:reverse_num ;
    }
};
