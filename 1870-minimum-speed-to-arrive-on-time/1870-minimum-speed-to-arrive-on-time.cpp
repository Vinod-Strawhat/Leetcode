class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right=10000000;
        int mid=0;
        int ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            double h=0;
            double fl=0.0;
            for(int i=0;i<dist.size();i++){
                fl=(double)dist[i]/mid;
                if(i==dist.size()-1){
                    h+=fl;
                }
                else{
                h+=ceil(double(dist[i])/mid);
                }

            }
            if(h<=hour){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};