#include <iterator>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class FoodRatings { // Sep 17, 2025
private:
  struct Food {
    std::string name;
    int rating;

    bool operator<(const Food& other) const {
      return rating != other.rating ? rating > other.rating : name < other.name;
    }
  };

  std::unordered_map<std::string, std::set<Food>> cuisine_to_foods;
  std::unordered_map<std::string, std::string> food_to_cuisine;
  std::unordered_map<std::string, int> food_to_rating;
public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    for(int i = 0; i < foods.size(); i++) {
      food_to_cuisine[foods[i]] = cuisines[i];
      food_to_rating[foods[i]] = ratings[i];
      Food ifood;
      ifood.name = foods[i];
      ifood.rating = ratings[i];
      cuisine_to_foods[cuisines[i]].insert(ifood);
    }
  }
  
  void changeRating(std::string food, int newRating) {
    // Find the current cuisine from food_to_cuisine[food].
    // Remove the old Food from cuisine_to_foods[cuisine].
    // Update the rating in food_to_rating[food].
    // Re-insert the new Food object into cuisine_to_foods[cuisine].
    std::string cuisine = food_to_cuisine[food];
    int oldRating = food_to_rating[food];
    Food foodObj;
    foodObj.name = food;
    foodObj.rating = oldRating;
    cuisine_to_foods[cuisine].erase(foodObj);
    food_to_rating[food] = newRating;
    foodObj.rating = newRating;
    cuisine_to_foods[cuisine].insert(foodObj);
  }
  
  std::string highestRated(std::string cuisine) {
    return std::begin(cuisine_to_foods[cuisine])->name;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

class FoodRatingsOld { // Dec 17, 2023
private:
  struct myComp {
    bool operator()(std::pair<int, std::string>& a, std::pair<int, std::string>& b) {
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    }
  };

  std::unordered_map<std::string, std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, myComp>> foodsRatedByCuisine;
  std::unordered_map<std::string, int> latestVal;
  std::unordered_map<std::string, std::string> foodInCuisine;

public:
  FoodRatingsOld(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
    for(int i = 0; i < foods.size(); i++) {
      std::pair<int, std::string> currP = make_pair(ratings[i], foods[i]);
      foodsRatedByCuisine[cuisines[i]].push(currP);
      latestVal[foods[i]] = ratings[i];
      foodInCuisine[foods[i]] = cuisines[i];
    }
  }
  
  void changeRating(std::string food, int newRating) {
    latestVal[food] = newRating;
    foodsRatedByCuisine[foodInCuisine[food]].push(make_pair(newRating, food));
  }
  
  std::string highestRated(std::string cuisine) {
    while(foodsRatedByCuisine[cuisine].top().first != latestVal[foodsRatedByCuisine[cuisine].top().second]) {
      foodsRatedByCuisine[cuisine].pop();
    };
    return foodsRatedByCuisine[cuisine].top().second; 
  }
};
