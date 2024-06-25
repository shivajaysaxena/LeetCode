class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            if (i >= 0) {
                sum += (num1[i] - '0');
                i--;
            }
            if (j >= 0) {
                sum += (num2[j] - '0');
                j--;
            }
            sum += carry;
            carry = sum / 10;
            result += to_string(sum % 10);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};