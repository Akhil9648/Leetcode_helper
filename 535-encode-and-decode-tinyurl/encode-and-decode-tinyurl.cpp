class Solution {
public:
    // Encodes a URL to a shortened URL.
    unordered_map<string,string>mp;
    string encode(string longUrl) {
        string s="";
        int n=longUrl.size();
        s+=(to_string(n));
        int i=n-1;
        while(i>=0){
            if(longUrl[i]=='/') break;
            i--;
        }
        i++;
        int k=i;
        int vowel=0,cons=0,sym=0;
        while(i<n){
            if(longUrl[i]=='a' || longUrl[i]=='e' || longUrl[i]=='i' || longUrl[i]=='o' || longUrl[i]=='u') vowel++;
            else if(longUrl[i]>='a' && longUrl[i]<='z') cons++;
            else sym++;
            i++;
        }
        s+=(to_string(vowel)+to_string(cons)+to_string(sym));
        s+=(longUrl[k]+longUrl[n-1]);
        mp[s]=longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));