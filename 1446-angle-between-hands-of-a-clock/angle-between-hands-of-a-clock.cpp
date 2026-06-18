class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=abs((double)(minutes*11)/2-30*hour);
        double a=360-ans;
        return min(a,ans);
    }
};