class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> s;
        for (auto x : obstacles) {
            s.insert(x);
        }
        vector<int> dir(4);
        dir[0] = 0, dir[1] = 1, dir[2] = 2, dir[3] = 3;
        int startX = 0, startY = 0, direction = dir[0], ans = 0;
        for (auto x : commands) {
            if (x == -1) {
                direction = dir[(direction + 1) % 4];
            } else if (x == -2) {
                if (direction == 0) {
                    direction = 3;
                } else
                    direction--;
            } else {
                int temp = x;
                if (direction == 0) {
                    while (temp--) {
                        if (s.count({startX, startY + 1}) == 0) {
                            startY++;
                        } else
                            break;
                    }
                } else if (direction == 1) {
                    while (temp--) {
                        if (s.count({startX + 1, startY}) == 0) {
                            startX++;
                        } else
                            break;
                    }
                } else if (direction == 2) {
                    while (temp--) {
                        if (s.count({startX, startY - 1}) == 0) {
                            startY--;
                        } else
                            break;
                    }
                } else {
                    while (temp--) {
                        if (s.count({startX - 1, startY}) == 0) {
                            startX--;
                        } else
                            break;
                    }
                }
            }
            int distance = pow(startX, 2) + pow(startY, 2);
            ans = max(ans, distance);
        }
        return ans;
    }
};