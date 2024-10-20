class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st1;
        stack<char> st2;
        for (auto it : expression) {
            if (it == '!' || it == '&' || it == '|') {
                st2.push(it);
            } else if (it != ')') {
                st1.push(it);
            } else {
                char oper = st2.top();
                st2.pop();
                char result;
                if (oper == '&')
                    result = 't';
                else if (oper == '|')
                    result = 'f';
                while (!st1.empty() && st1.top() != '(') {
                    if (oper == '&' && st1.top() == 'f') {
                        result = 'f';
                    } else if (oper == '|' && st1.top() == 't') {
                        result = 't';
                    } else if (oper == '!') {
                        if (st1.top() == 't')
                            result = 'f';
                        else
                            result = 't';
                    }
                    st1.pop();
                }
                if (!st1.empty())
                    st1.pop();
                st1.push(result);
            }
        }
        return st1.top() == 't' ? true : false;
    }
};