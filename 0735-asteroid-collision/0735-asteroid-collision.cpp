class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for (int ele : a) {
            if (ele > 0) {
                st.push(ele);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(ele)) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(ele)) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(ele);
                }
            }
        }

        vector<int> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
