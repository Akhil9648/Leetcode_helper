class Solution {
public:
    string fractionAddition(string expression) {
        int num=0,den=1;
        int currnum=0,currden=0;
        int opr=1,flag=0;
        for(auto it:expression){
            if(flag==0){
                if(it=='-'){
                    opr=-1;
                    continue;
                }
                else if(it=='/'){
                    flag=1;
                    continue;
                }
                else currnum=currnum*10+it-'0';
            }
            else{
                if(it=='+'){
                    flag=0;
                    currnum*=opr;
                    num=(num*currden+currnum*den);
                    den=(currden*den);
                    currnum=0;
                    currden=0;
                    opr=1;
                }
                else if(it=='-'){
                    flag=0;
                    currnum*=opr;
                    num=(num*currden+currnum*den);
                    den=(currden*den);
                    currnum=0;
                    currden=0;
                    opr=-1;
                }
                else currden=currden*10+(it-'0');
            }
        }
        currnum *= opr;
        num = num*currden + currnum*den;
        den = den*currden;
        int g = gcd(abs(num), den);
        num /= g;
        den /= g;
        return to_string(num)+"/"+to_string(den);
    }
};