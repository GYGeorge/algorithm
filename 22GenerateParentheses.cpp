#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str("");
        generating(res, n, n, str);
        for (int i = 0; i < res.size(); i++)
            cout<<res.at(i)<<endl;
    }
    void generating(vector<string> &res, int l, int r, string substr) {
        if (l > r) return;
        if (!l && !r) {
            res.push_back(substr);
            return;
        }
        if (l) {
            generating(res, l-1, r, substr+"(");
        }
        if (r) {
            generating(res, l, r-1, substr+")");
        }
    }
};        
int main()
{
    Solution s;
    s.generateParenthesis(3);
}