#include<iostream>
#include<string>

class Solution{
    public:
        bool isValid(std::string s){
            int i, top = 0, de;
            for (i = 0;i < s.length(); ) {
                if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                    top = i;
                    i++;
                }
                else if (s[i] == '}'){
                    if (s[top] == '{') {
                        s = s.erase(top, 2);
                        top = top == 0 ?0 : top - 1; 
                        i--; 
                    }
                    else 
                        return false;
                }
                else if (s[i] == ']'){
                    if (s[top] == '[') {
                        s = s.erase(top, 2);
                        top = top == 0 ? 0 : top - 1;  
                        i--;
                    }
                    else 
                        return false;
                }
                else if (s[i] == ')'){
                    if (s[top] == '(') {
                        s = s.erase(top, 2);
                        top = top == 0 ? 0 : top - 1;  
                        i--;
                    }
                    else 
                        return false;
                }
            }
            if (s.empty()) return true;
            else return false;
        }
};
int main(){
    Solution pro;
    std::string str("[])");
    bool isit = pro.isValid(str);
    std::cout<<isit<<std::endl;
}