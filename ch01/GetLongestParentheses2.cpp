#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
/*
 * 初始化空栈
 * 顺序处理字符串
 * 记录匹配位置start = -1;最大匹配长度ml = 0;
 * 考虑第i位,
 * 如果是左括号类型则入栈
 * 如果是右括号类型,则一定和栈顶左括号匹配
 *  1.栈空,表示没有匹配的左括号,start = i,为下一次做准备
 *  2.栈不空,出栈(已匹配)
 * 如果栈为空,i-start即为当前找到的匹配长度,检查i-start是否比ml更大,使得ml更新
 * 如果栈不空,则当前栈顶元素t是上次匹配的最后位置,检查i-t是否比ml更大,使得ml得以更新.,
 *
 *  匹配完成,栈空匹配成功,栈不空则匹配失败.

 */

int GetLongestParentheses (const char * p) {
    stack<int> s;    
    const char * pchar = p;
    string matched;
    int cur = 0;
    int start = -1,ml = 0;
    while(*p) {
        if(*p == '(')  {
            s.push(cur);
        }else if(*p == ')' ) {
            if(s.empty()) {
                start = cur;
            } else {
                s.pop();
                if(s.empty()) {
                    if(cur - start > ml){ 
                        ml = cur-start;
                        matched = string(pchar + start + 1,pchar + ml + start + 1);
                    }
                }
                else {
                    int t = s.top();
                    if(cur - t > ml) {
                        ml = cur - t;        
                        matched = string(pchar + t + 1,pchar + ml + t + 1);
                    }
                }
            }
        }
        cur++;
        p++;
    }
    cout<<matched<<endl;
    return ml;
}
int main() {


    const char *p = "(()";
    const char *s = "()()";
    cout<<GetLongestParentheses(p)<<endl;;
    cout<<GetLongestParentheses(s)<<endl;;

    return 0;
}
