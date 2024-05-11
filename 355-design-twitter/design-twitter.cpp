class Twitter {
public:
    struct compare {
        bool operator()(const vector<int> a, const vector<int> b) {
            return a[0] < b[0];
        }
    };

    int time = 0;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        auto followerList = followMap[userId];

        if (tweetMap.find(userId) != tweetMap.end()) {
            auto tweetList = tweetMap[userId];
            int len = tweetList.size();
            pair<int, int> tweet = tweetList[len - 1];
            pq.push({tweet.first, tweet.second, userId, len - 1});
        }

        for (auto it : followerList) {
            if (tweetMap.find(it) != tweetMap.end()) {
                auto tweetList = tweetMap[it];
                int len = tweetList.size();
                pair<int, int> tweet = tweetList[len - 1];
                pq.push({tweet.first, tweet.second, it, len - 1});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            auto tweet = pq.top();
            res.push_back(tweet[1]);
            int userId = tweet[2];
            int ind = tweet[3] - 1;
            pq.pop();
            if (ind >= 0) {
                if (tweetMap.find(userId) != tweetMap.end()) {
                    auto tweetList = tweetMap[userId];
                    pair<int, int> tweet = tweetList[ind];
                    pq.push({tweet.first, tweet.second, userId, ind});
                }
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].find(followeeId) !=
            followMap[followerId].end())
            followMap[followerId].erase(followeeId);
    }
};