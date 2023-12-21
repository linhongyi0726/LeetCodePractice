// First time
/*
    Use heap with customized comparison function (need to declare const)
    *Notice the difference with comparison function between set and priority queue

    T: O(nlogn)/S: O(n)
*/
struct comp {
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) const {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        else
            return p1.second > p2.second;
    }
};
class FoodRatings {
public:
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>> cui2food;
    unordered_map<string, pair<string, int>> food2cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cui2food[cuisines[i]].push({ratings[i], foods[i]});
            food2cui[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        cui2food[food2cui[food].first].push({newRating, food});
        food2cui[food] = {food2cui[food].first, newRating};
    }
    
    string highestRated(string cuisine) {
        auto [rating, food] = cui2food[cuisine].top();
        while (food2cui[food].second != rating) {
            cui2food[cuisine].pop();
            rating = cui2food[cuisine].top().first;
            food = cui2food[cuisine].top().second;
        }
        return food;
    }
};

/*
    Use min heap and negative rating

    T: O(nlogn)/S: O(n)
*/
class FoodRatings {
public:
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>> cui2food;
    unordered_map<string, pair<string, int>> food2cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cui2food[cuisines[i]].push({-ratings[i], foods[i]});
            food2cui[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        cui2food[food2cui[food].first].push({-newRating, food});
        food2cui[food] = {food2cui[food].first, newRating};
    }
    
    string highestRated(string cuisine) {
        auto [rating, food] = cui2food[cuisine].top();
        while (food2cui[food].second != -rating) {
            cui2food[cuisine].pop();
            rating = cui2food[cuisine].top().first;
            food = cui2food[cuisine].top().second;
        }
        return food;
    }
};

/*
    Use set with customized comparison function (need to declare const)
    *Notice the difference with comparison function between set and priority queue

    T: O(nlogn)/S: O(n)
*/
struct comp {
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) const {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        else
            return p1.second < p2.second;
    }
};
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>, comp>> cui2food;
    unordered_map<string, pair<string, int>> food2cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cui2food[cuisines[i]].insert({ratings[i], foods[i]});
            food2cui[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        cui2food[food2cui[food].first].erase({food2cui[food].second, food});
        cui2food[food2cui[food].first].insert({newRating, food});
        food2cui[food] = {food2cui[food].first, newRating};
    }
    
    string highestRated(string cuisine) {
        return (*cui2food[cuisine].begin()).second;
    }
};

/*
    Use one hash map to record the relationship with cuisine and {rating, food} in set
    Another hash map to record the relationship with food and {cuisine, rating},
    this hash map is used to record the food's old rating and its cuisine,
    in order to erase the old rating at first hash map

    T: O(nlogn)/S: O(n)
*/
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cui2food;
    unordered_map<string, pair<string, int>> food2cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            cui2food[cuisines[i]].insert({-ratings[i], foods[i]});
            food2cui[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        cui2food[food2cui[food].first].erase({-food2cui[food].second, food});
        cui2food[food2cui[food].first].insert({-newRating, food});
        food2cui[food] = {food2cui[food].first, newRating};
    }
    
    string highestRated(string cuisine) {
        return (*cui2food[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */