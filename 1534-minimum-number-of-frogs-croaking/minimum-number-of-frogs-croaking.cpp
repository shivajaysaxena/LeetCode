class Solution {
public:
    int minNumberOfFrogs(const string& croakOfFrogs) {
        int res{0};
        int cCounter{0};
        int rCounter{0};
        int oCounter{0};
        int aCounter{0};
        int kCounter{0};
        for (char c : croakOfFrogs) {
            switch (c) {
            case 'c':
                ++cCounter;
                break;
            case 'r':
                if (++rCounter > cCounter) {
                    return -1;
                }
                break;
            case 'o':
                if (++oCounter > rCounter) {
                    return -1;
                }
                break;
            case 'a':
                if (++aCounter > oCounter) {
                    return -1;
                }
                break;
            case 'k':
                if (++kCounter > aCounter) {
                    return -1;
                }
                res = max(res, cCounter - kCounter + 1);
                break;
            }
        }
        if (cCounter != rCounter || rCounter != oCounter ||
            oCounter != aCounter || aCounter != kCounter) {
            return -1;
        }
        return res;
    }
};