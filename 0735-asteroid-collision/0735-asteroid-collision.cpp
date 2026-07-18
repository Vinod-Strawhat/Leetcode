class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        
        for(int i=0;i<nums.size();i++){
            bool can=true;
            while(!s.empty() && nums[i]<0 && s.top()>0){
                if(abs(nums[i])>s.top()){
                    s.pop();
                }
                else if(abs(nums[i])==s.top()){
                    s.pop();
                    can=false;
                    break;
                }
                else{
                    can=false;
                    break;
                }
            }
            if(can){
            s.push(nums[i]);}
            
        }
        int n=s.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;

    }
};