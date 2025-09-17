class FoodRatings {
public:
    unordered_map<string,int> food_rating; //{food,rating}
    unordered_map<string,string> food_cuisine; // {food,cuisines}
    unordered_map<string,set<pair<int,string>>> mp1; //cuisine-> {-rating,food}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0;i<n;i++){
            food_rating[foods[i]]=ratings[i];
            food_cuisine[foods[i]]=cuisines[i];
            mp1[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=food_cuisine[food];
        int rating = food_rating[food];

        food_rating[food]=newRating; //rating updated in one map

        mp1[cuisine].erase({-rating,food}); //remove the old rating
        mp1[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return mp1[cuisine].begin()->second; //return the first value in mp1 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */