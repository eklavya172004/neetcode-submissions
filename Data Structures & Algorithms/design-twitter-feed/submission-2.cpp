class Twitter {
public:
unordered_map<int, unordered_set<int>> following;
unordered_map<int, vector<pair<int,int>>> tweets;
int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 1 -> {2,3}
        // I need to get the feeds of 2,3 and also of the one
        priority_queue<pair<int,int>> pq;

        // push all the tweets of user 1
        for(auto &it : tweets[userId]){
        int t = it.first;
        int id = it.second;

            pq.push({t,id});
        }

        // push all the tweets of followers of users
        for(auto &it1 : following[userId]){
            for(auto &it : tweets[it1]){
                int t = it.first;
                int id = it.second;

                pq.push({t,id});
             }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
        following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
