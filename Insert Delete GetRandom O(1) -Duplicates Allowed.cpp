#include<bits/stdc++.h>
using namespace std;


class RandomizedCollection {
        vector<int>nums;
    unordered_map<int,unordered_set<int>>Map;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag=Map.find(val)==Map.end();
        nums.push_back(val);
        Map[val].insert(nums.size()-1);
        return flag;
    }
    
    bool remove(int val) {
        bool flag=Map.find(val)!=Map.end();
        if(flag==false) return false;
        if(val==nums.back()){
            Map[val].erase(nums.size()-1);
            nums.pop_back();
            if(Map[val].size()==0)
                Map.erase(val);
            
        }else{
            int pos=nums.size()-1;
            int val2=nums.back();
            
            int pos2=*(Map[val].begin());
            Map[val].erase(pos2);
            Map[val2].erase(pos);
            Map[val2].insert(pos2);
            nums[pos2]=val2;
            nums.pop_back();
            if(Map[val].size()==0)
                Map.erase(val);
            
        }
        return flag;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
        
    }
};
