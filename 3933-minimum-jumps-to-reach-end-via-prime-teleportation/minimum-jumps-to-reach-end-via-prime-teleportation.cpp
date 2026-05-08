class Solution {
public:

    bool isPrime(int x){

        if(x <= 1) return false;

        for(int i=2;i*i<=x;i++){

            if(x%i==0) return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // store indices divisible by prime p
        for(int i=0;i<n;i++){

            for(int d=1; d*d<=nums[i]; d++){

                if(nums[i]%d==0){

                    if(isPrime(d))
                        mp[d].push_back(i);

                    int other = nums[i]/d;

                    if(other != d && isPrime(other))
                        mp[other].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);

        queue<pair<int,int>> q;

        q.push({0,0});

        vis[0]=1;

        while(!q.empty()){

            auto [i,steps] = q.front();
            q.pop();

            if(i==n-1) return steps;

            // left
            if(i-1>=0 && !vis[i-1]){

                vis[i-1]=1;
                q.push({i-1,steps+1});
            }

            // right
            if(i+1<n && !vis[i+1]){

                vis[i+1]=1;
                q.push({i+1,steps+1});
            }

            // teleport
            if(isPrime(nums[i])){

                int p = nums[i];

                for(int idx : mp[p]){

                    if(!vis[idx]){

                        vis[idx]=1;
                        q.push({idx,steps+1});
                    }
                }

                // important optimization
                mp[p].clear();
            }
        }

        return -1;
    }
};