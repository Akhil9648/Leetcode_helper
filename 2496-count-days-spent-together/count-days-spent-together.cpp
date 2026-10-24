class Solution {
public:
    int daysInMonth[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int convd(string &s){
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < m - 1; ++i) {
            totalDays += daysInMonth[i];
        }
        return totalDays + d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa=convd(arriveAlice);
        int la=convd(leaveAlice);
        int ab=convd(arriveBob);
        int lb=convd(leaveBob);
        int laa=max(aa,ab);
        int ed=min(la,lb);
        int ans=ed-laa+1;
        return ans<=0?0:ans;
    }
};