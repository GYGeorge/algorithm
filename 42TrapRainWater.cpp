#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height){
        stack<int> handle;
        int capcity = 0;
        for(int i = 0; i < height.size();){
            if (handle.empty() || height[i] <= height[handle.top()]){
                handle.push(i);
                i++;
            }
            else {
                int top = handle.top();
                handle.pop();
                if (handle.empty()) continue;
                capcity += min(height[handle.top()] - height[top], height[i] - height[top]) 
                           * (i - handle.top() - 1);
                
            } 
        }
    }
};
