class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize) return false;
        
      
        
        unordered_map<int, int>mp;
        for(int h=0; h<hand.size(); h++){
            mp[hand[h]]+=1;
        }
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto key: mp){
            pq.push(key.first);
            cout<<key.first;
        }
        
        
            
        while(!pq.empty()){
            
            int first = pq.top();
            
            for(int num=first; num<first+groupSize; num++){
                if(mp.find(num)==mp.end() ){
                    cout<<"a1";
                    return false; 
            }
                
                mp[num]--;
                if(mp[num]==0){
                    
                    if(num != pq.top())
                    {
                                            cout<<"a2";
                            return false;


                    }
                pq.pop();
                    
                }
                    
                
            }
            
        }
        
        return true;
        
    }   
};