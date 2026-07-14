class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string o="";
        vector<string> arr;
        for(int i=0;i<strs.size()-1;i++){
            for( int j=0;j<strs[i].size();j++){
                if(strs[i][j]==strs[i+1][j]){
                    
                        o+=strs[i][j];
                }
                else{
                    break;
                }
                
            }
            arr.push_back(o);
            o.clear();
        }
        string shortest = strs[0];

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].size() < shortest.size()) {
                shortest = arr[i];
    }
}

        
        
        return shortest;
    }
};