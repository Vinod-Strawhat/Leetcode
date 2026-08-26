class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                count++;
            }

            while (count >= k) {
                while (s[left] == '0') {
                    left++;
                }

                string temp = s.substr(left, right - left + 1);

                if (ans == "" || temp.size() < ans.size() ||
                    (temp.size() == ans.size() && temp < ans)) {
                    ans = temp;
                }

                if (s[left] == '1') {
                    count--;
                }
                left++;
            }
        }

        return ans;
    }
};