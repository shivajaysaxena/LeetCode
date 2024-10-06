class Solution {
public:
    bool areSentencesSimilar(string st1, string st2) {
        if (st1 == " " || st2 == " ")
            return true;
        if (st1 == st2)
            return true;
        vector<string> v1, v2;
        string s1, s2;
        stringstream ss1(st1);
        while (getline(ss1, s1, ' ')) {
            v1.push_back(s1);
        }
        stringstream ss2(st2);
        while (getline(ss2, s2, ' ')) {
            v2.push_back(s2);
        }
        if (v1.size() == v2.size())
            return false;

        int first1 = 0, first2 = 0, last1 = v1.size(), last2 = v2.size();
        if ((v1[0] == v2[0] || v1[last1 - 1] == v2[last2 - 1]) &&
            (last1 == 1 || last2 == 1))
            return true;
        while (first1 < last1 && first2 < last2) {
            string f1 = v1[first1], f2 = v2[first2], l1 = v1[last1 - 1],
                   l2 = v2[last2 - 1];
            if (f1 == f2 && l1 == l2) {
                if (last1 - 1 - first1 - 1 == 0 ||
                    last2 - 1 - first2 - 1 == 0 || first1 == last1 - 1 ||
                    first2 == last2 - 1)
                    return true;
                first1++;
                first2++;
            } else {
                if (f1 == f2 && l1 != l2) {
                    if (first1 == last1 - 1 || first2 == last2 - 1)
                        return true;
                    first1++;
                    first2++;
                } else {
                    if (f1 != f2 && l1 == l2) {
                        if (first1 == last1 - 1 || first2 == last2 - 1)
                            return true;
                        last1--;
                        last2--;
                    } else {
                        if (first1 == 0 && first2 == 0)
                            return false;
                        first1++;
                        first2++;
                    }
                }
            }
        }
        return false;
    }
};