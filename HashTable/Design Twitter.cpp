class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        count = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        postTweetMap[userId].push_back({tweetId, count++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        follow(userId, userId);
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) ->bool {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto it = followMap[userId].begin(); it != followMap[userId].end(); ++it) {
            int len = postTweetMap[*it].size();
            for (int i = len-1; i >= max(0, len-10); --i) {
                pq.push(postTweetMap[*it][i]);
                if (pq.size() > 10) pq.pop();
            }
        }
        unfollow(userId, userId);
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
         if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
         }
    }
private:
    int count;
    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> postTweetMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */