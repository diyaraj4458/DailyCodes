class FoodRatings {
public:
	map<string,string> foodToCuisine;
	map<string,set<pair<int,string>>> Cuisine;
	map<string,int> rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
		for(int i=0;i<n;i++){
        	foodToCuisine[foods[i]]=cuisines[i];
        	Cuisine[cuisines[i]].insert({-ratings[i],foods[i]});
        	rating [foods[i]]=ratings[i];
		}
    }
    
    void changeRating(string food, int newRating) {
        string cuisineName=foodToCuisine[food];
        Cuisine[cuisineName].erase({-rating[food],food});
        rating[food]=newRating;
        Cuisine[cuisineName].insert({-rating[food],food
		});
    }
    
    string highestRated(string cuisine) {
        return Cuisine[cuisine].begin()->second;
    }
};