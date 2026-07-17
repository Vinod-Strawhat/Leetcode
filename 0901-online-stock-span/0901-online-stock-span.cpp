class StockSpanner {
public:
    stack<pair<int,int>> s;
    int index=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=0;
        while(!s.empty() && price>=s.top().first){
            s.pop();
        }
        if(s.empty()){
            count=index+1;
        }
        else{
            count=index-s.top().second;
        }
        s.push({price,index});
        index++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */