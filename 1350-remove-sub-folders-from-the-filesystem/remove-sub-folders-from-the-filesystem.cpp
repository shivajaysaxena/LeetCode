class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> fin;
        string prev = folder[0];
        fin.push_back(prev);
        for (int i = 1; i < folder.size(); i++) {
            if (folder[i].size() >= prev.size()) {
                if (folder[i].size() == prev.size() &&
                    folder[i].substr(0, prev.size()) == prev)
                    continue;
                else {
                    if (folder[i].substr(0, prev.size() + 1) == (prev + "/"))
                        continue;
                }
            }
            fin.push_back(folder[i]);
            prev = folder[i];
        }

        return fin;
    }
};