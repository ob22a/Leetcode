class Twitter {
public:
    unordered_map<int,unordered_set<int>> following;
    vector<pair<int,int>> news;
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        news.push_back({userId,tweetId});
        following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> sol;
        int count=0;
        for(int i=news.size()-1;count<10 && i>=0;--i){
            if(following[userId].count(news[i].first)){
                sol.push_back(news[i].second);
                ++count;
            }
        }
        return sol;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */