/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int row = 0, col = 0, curr_d = 0,
            dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (head) {
            res[row][col] = head->val;
            head = head->next;

            int newRow = row + dir[curr_d][0], newCol = col + dir[curr_d][1];

            if (min(newRow, newCol) < 0 || newRow >= m || newCol >= n ||
                res[newRow][newCol] != -1) {
                curr_d = (curr_d + 1) % 4;
            }
            row += dir[curr_d][0];
            col += dir[curr_d][1];
        }
        return res;
    }
};