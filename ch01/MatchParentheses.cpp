#include <iostream>
#include <stack>
using namespace std;
/*
 * 初始化空栈
 * 顺序处理字符串
 * 如果是左括号类型则入栈
 * 如果是右括号类型:
 *      1.栈不空,查询其所匹配的左括号,匹配成功则弹栈,处理下一个字符,如果失败则返回false;
 *      2.栈空,返回false
 *
 *  匹配完成,栈空匹配成功,栈不空则匹配失败.

 */


bool isLeftParentheses(char c) {
    return (c == '[' || c == '(' || c== '{');
}

bool isMatch(char left,char c) {
    if(left == '(') return (c == ')');
    else if(left == '[') return (c == ']');
    else if(left == '{') return (c == '}');
}


bool MatchParentheses(const char * p) {
    stack<char> s;    
    char cur;
    while(*p) {
        cur = *p;
        if(isLeftParentheses(cur)) {
            s.push(cur);
        }else {
            if(!s.empty() && isMatch(s.top(),cur)) {
               s.pop(); 
            }else {
                return false;
            }
        }
        p++;
    }
    return s.empty();
}
int main() {


    const char *p = "(({})[])[()]";
    const char *s = "(({)[])[()]";
    bool bmatch = MatchParentheses(p);
    if(bmatch) cout<<"匹配成功"<<endl;
    else cout<<"匹配失败"<<endl;
    bmatch = MatchParentheses(s);
    if(bmatch) cout<<"匹配成功"<<endl;
    else cout<<"匹配失败"<<endl;
    return 0;
}
