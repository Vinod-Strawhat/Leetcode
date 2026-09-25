class Solution {
public:
    vector<string> braceExpansionII(string expression) 
    {
        set<string> s; 
        queue<string> q;
        q.push(expression);

        while (!q.empty()) 
        {
            string temp = q.front();
            q.pop();
            int left = -1, right = 0; 
            while (right < temp.length() && temp[right] != '}') 
            {
                if (temp[right] == '{') left = right;
                right++;
            }
            if (left == -1) 
            {
                s.insert(temp);
                continue; 
            }
            string start = temp.substr(0, left);
            string end = temp.substr(right + 1);
            string mid = temp.substr(left + 1, right - left - 1);
            vector<string> words;
            stringstream ss(mid);
            string tmp;
            while(getline(ss, tmp, ','))
            {
            	words.push_back(tmp);
			}
            for (string middle : words) {
                q.push(start + middle + end);
            }
        }
        vector<string> result(s.begin(), s.end());
        return result;
    }
};