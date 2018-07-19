#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
/*
   只有右括号和左括号发生匹配时,才有可能更新最终解
   取一个x记录左括号和右括号的差,当x为0时,更新最终解
   由于可能出现左右括号不匹配的问题
   为左括号的数目大于右括号的数目,所以,再从右向前扫描一次

   空间复杂度从O(n)降到O(1)
   */

int GetLongestParentheses (const char * p) {
    int start = -1,ml = 0;
    int deep = 0;
    const char * pre = p;
    int cur = 0;
    string matched;
    while(*p) {
        if(*p == '(') {
            deep++;
        }else {
            deep--;
            if(deep == 0) {
                if( cur - start > ml ) {
                    ml = cur - start;
                    matched = string(pre + start + 1, pre + cur + 1);
                }
            }
            if(deep < 0) {
                start = cur;
                deep = 0;
            }
        }
        cur++;
        p++;
    }
    deep = 0;
    start = cur;
    cur--;
    while(cur) {

        if(*p == ')') {
            deep++;
        }else {
            deep--;
            if(deep == 0) {
                if(start - cur > ml) {
                    ml = start - cur;
                    matched = string(pre + cur + 1,pre + start + 1);
                }
            }
            if(deep < 0) {
                start = cur;
                deep = 0;
            }
        }

        p--;
        cur--;
    }
    cout<<matched<<endl;
    return ml;
}
int main() {


    const char *p = "(()()";
    const char *s = "(()())))";
    cout<<GetLongestParentheses(p)<<endl;;
    cout<<GetLongestParentheses(s)<<endl;;

    return 0;
}
