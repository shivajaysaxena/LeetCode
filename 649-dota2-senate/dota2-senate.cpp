class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr;
        queue<int> qd;
        int len = senate.length();
        for (int i = 0; i < len; i++) {
            senate[i] == 'R' ? qr.push(i) : qd.push(i);
        }
        while (!qr.empty() && !qd.empty()) {
            int q1 = qr.front(), q2 = qd.front();
            qr.pop();
            qd.pop();
            q1 < q2 ? qr.push(q1 + len) : qd.push(q2 + len);
        }
        if(qr.size() > qd.size()){
            return "Radiant";
        }
        return "Dire";
    }
};