class Twitter {
public:
    int timer = 0;

    // user -> users they follow
    unordered_map<int, unordered_set<int>> followMap;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<
            tuple<int, int, int>
        > pq;

        // Own tweets
        followMap[userId].insert(userId);

        // Add latest tweet of each followed user
        for (int followee : followMap[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                auto [time, tweetId] = tweets[followee][idx];
                pq.push({time, followee, idx});
            }
        }

        vector<int> result;

        // Get 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {
            auto [time, user, idx] = pq.top();
            pq.pop();

            result.push_back(tweets[user][idx].second);

            if (idx > 0) {
                auto [nextTime, nextTweet] = tweets[user][idx - 1];
                pq.push({nextTime, user, idx - 1});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};

