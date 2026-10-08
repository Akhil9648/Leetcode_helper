class Solution {
public:
    string removeOuterParentheses(string s) {
        string an;
        int opened=0;
        for(const char c:s)
        {
            if(c=='(')
            {
                if(++opened>1)
                {
                    an+=c;
                }
            }
                else if(--opened>0)
                {
                    an+=c;
                }
        }
        return an;
    }
};