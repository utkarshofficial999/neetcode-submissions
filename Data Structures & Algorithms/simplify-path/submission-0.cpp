class Solution {
   public:
    string simplifyPath(string path) {
        stack<string> st;
        string word = "";

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (word == ".") {
                    // do nothing
                } else if (word == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else if (!word.empty()) {
                    st.push(word);
                }

                word = "";
            } else {
                word += path[i];
            }
        }
        if (word == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (!word.empty() && word != ".") {
            st.push(word);
        }
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};