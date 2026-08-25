class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>cousine;
    unordered_map<string,pair<int,string>>foodmap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            cousine[cuisines[i]].insert({-ratings[i],foods[i]});
            foodmap[foods[i]]={ratings[i],cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it=foodmap[food];
        string s=it.second;
        cousine[s].erase({-it.first,food});
        cousine[s].insert({-newRating,food});
        foodmap[food].first=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cousine[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */