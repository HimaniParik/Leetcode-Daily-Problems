class MovieRentingSystem {
public:
    // Maps (shop,movie) -> price
    unordered_map<long long, int> priceMap;
    
    // Available movies per movie id: {price, shop}
    unordered_map<int, set<pair<int,int>>> available;
    
    // All rented movies: {price, shop, movie}
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            long long key = ((long long)shop << 32) | movie;
            priceMap[key] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        auto &s = available[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; it++, count++) {
            result.push_back(it->second);
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int price = priceMap[key];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto it = rented.begin(); it != rented.end() && count < 5; it++, count++) {
            auto [price, shop, movie] = *it;
            result.push_back({shop, movie});
        }
        return result;
    }
};


/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */