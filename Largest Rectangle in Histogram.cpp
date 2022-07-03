#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>s;
        vector<int>left(n,0);
        vector<int>right(n,0);
        int maxarea=0;
        for(int i=0;i<n;i++){
            if(s.empty()){
                left[i]=0;
                s.push(i);
            }else if(heights[i]<=heights[s.top()]){
                while(!s.empty() && heights[i]<=heights[s.top()]){
                    s.pop();
                }
                if(s.empty()) left[i]=0;
                else left[i]=s.top()+1;
                s.push(i);
            }else {
                left[i]=s.top()+1;
            }
            s.push(i);
        }
            while(!s.empty()) s.pop();
            for(int j=n-1;j>=0;j--){
                if(s.empty())
                    right[j]=n-1;
                else if(heights[j]<=heights[s.top()]){
                    while(!s.empty() && heights[j]<= heights[s.top()]){
                        s.pop();
                    }
                    if(s.empty())right[j]=n-1;
                    else right[j]=s.top()-1;
                }
                
                else{
                    right[j]=s.top()-1;
                }
                s.push(j);
            }
            for(int k=0;k<n;k++){
                if(((right[k]-left[k]+1)*heights[k])>maxarea)
                    maxarea=((right[k]-left[k]+1)*heights[k]);
            
        }
        return maxarea;
        
        
    }
};