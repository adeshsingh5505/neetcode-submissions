class Twitter {
private:
    int cnt=0;
    unordered_map<int,set<int>> followList;
    unordered_map<int,list<pair<int,int>>> tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt,tweetId});
        cnt++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> topTen;
        for(auto i: tweets[userId]){
            topTen.push(i);
        }
        for(auto i: followList[userId]){
            for(auto j:tweets[i]){
                topTen.push(j);
        }
        }
        int c=0;
        vector<int> ans;
        while(!topTen.empty() && c<10){
            ans.push_back(topTen.top().second);
            topTen.pop();
            c++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        followList[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
        return;
    }
};
