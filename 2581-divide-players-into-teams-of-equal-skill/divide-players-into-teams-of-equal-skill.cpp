class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int skill_single = skill[0] + skill[skill.size() - 1];
        int l = 1, r = skill.size() - 2;
        long long sum = 0;
        while (l < r) {
            if (skill[l] + skill[r] != skill_single) {
                return -1;
            } else {
                sum += (skill[l] * skill[r]);
                l++;
                r--;
            }
        }
        return sum + (skill[0] * skill[skill.size() - 1]);
    }
};