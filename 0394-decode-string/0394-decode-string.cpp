class Solution {
public:
    string decodeString(string s) {
        stack<string> s1;
        stack<int> s2;
        int i=0;
        string ans="";
        while(i<s.size()){
            if(isdigit(s[i])){
            string num="";
            int nums=0;
            while(isdigit(s[i])){
                num+=s[i];
                i++;
            }
            nums=stoi(num);
            s2.push(nums);
            }
            else{
                string t="";
                if(s[i]==']'){
                    while(s1.top()!="["){
                        t.insert(0,s1.top());
                        s1.pop();
                        
                    }
                    s1.pop();
                    int cnt = s2.top();
                    s2.pop();

                    string k = "";
                    for (int j = 0; j < cnt; j++) {
                            k += t;
                            }

                    s1.push(k);
                    i++;
                }
                else {
    s1.push(string(1, s[i]));
    i++;
}
}
        }

while (!s1.empty()) {
    ans.insert(0, s1.top());
    s1.pop();
}
return ans;
    }
};