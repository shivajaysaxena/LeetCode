class Solution {
public:
    char maxOfThree(int& a, int& b, int& c) {
        if (a >= b && a >= c) {
            return 'a';
        } else if (b >= c && b >= a) {
            return 'b';
        }
        return 'c';
    }

    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        while (a > 0 || b > 0 || c > 0) {
            if (ans.size() >= 2 && (ans.substr(ans.size() - 2) == "aa" ||
                                    ans.substr(ans.size() - 2) == "bb" ||
                                    ans.substr(ans.size() - 2) == "cc")) {
                char lastChar = ans.back();

                if (lastChar == 'a') {
                    if (b > 0) {
                        ans += 'b';
                        b--;
                    } else if (c > 0) {
                        ans += 'c';
                        c--;
                    } else {
                        break;
                    }
                } else if (lastChar == 'b') {
                    if (a > 0) {
                        ans += 'a';
                        a--;
                    } else if (c > 0) {
                        ans += 'c';
                        c--;
                    } else {
                        break;
                    }
                } else if (lastChar == 'c') {
                    if (a > 0) {
                        ans += 'a';
                        a--;
                    } else if (b > 0) {
                        ans += 'b';
                        b--;
                    } else {
                        break;
                    }
                }
            } else {
                char nextChar = maxOfThree(a, b, c);
                if (nextChar == 'a') {
                    ans += 'a';
                    a--;
                } else if (nextChar == 'b') {
                    ans += 'b';
                    b--;
                } else {
                    ans += 'c';
                    c--;
                }
            }
        }

        return ans;
    }
};