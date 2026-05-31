class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long a=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto it:asteroids){
            if(a<it) return false;
            a+=it;
            if(a>=INT_MAX) return true;

        }
        return true;
    }
};