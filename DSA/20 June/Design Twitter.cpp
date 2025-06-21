class Twitter {
    int time = 0;

    unordered_map<int, deque<pair<int, int>>> feed;
    unordered_map<int, unordered_set<int>> follow_list;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed[userId].push_front({time++, tweetId});
        if(feed[userId].size() > 10) feed[userId].pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for(auto &i:feed[userId]) pq.push(i);

        for(int i:follow_list[userId]){
            for(auto &j:feed[i]) pq.push(j);
        }
        
        vector<int> news;

        while(!pq.empty() && news.size() < 10){
            news.push_back(pq.top().second);
            pq.pop();
        }

        return news;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follow_list[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follow_list[followerId].erase(followeeId);
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