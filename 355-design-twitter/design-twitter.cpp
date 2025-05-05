class Twitter {
public:
    unordered_map<int,unordered_set<int>> following; // UserID -> FolloweeId
    unordered_map<int,vector<pair<int,int>>> IdNews; // UserID -> {(TimeStamp,tweet)}
    int timeStamp=0;
    
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        IdNews[userId].push_back({timeStamp++,tweetId});
        following[userId].insert(userId); //A user follows himself
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> sol;
        
        using T=tuple<int,int,int>;
        priority_queue<T> myNews; 
        // <Time,id,index>

        for(int id:following[userId]){
            const auto& tweets=IdNews[id];
            if(!tweets.empty()){
                int index=tweets.size()-1;
                myNews.push({tweets[index].first,id,index});
            }
        }

        while(!myNews.empty() && sol.size()<10){
            const auto [time,id,index]=myNews.top(); myNews.pop();
            sol.push_back(IdNews[id][index].second);
            if(index>0)
                myNews.push({IdNews[id][index-1].first,id,index-1});
        }
        
        return sol;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) // Optional: prevent redundant self-follow
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) // Optional: prevent self-unfollow
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