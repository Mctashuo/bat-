#include <iostream>
#include <stack>
using namespace std;


/*
 * 使用一个堆栈S来模拟压栈出栈的操作,记入栈序列为A,出栈序列为B
 * 遍历B的每个元素b;
 * 情形1:若b等于栈顶元素s,恰好匹配,则检查B的下一个元素,栈顶元素s出栈;
 * 情形2:若b不等于栈顶元素s,则将A的当前元素入栈,目的是希望在A的剩余元素中找到b
 * 在情形1中,若栈s为空,则认为b无法与栈内元素匹配调用情形2
 */
bool IsPossible(const char * strIn,const char * strOut) {
    stack<char> s;
    while(*strOut) {
        if(s.empty() || *strOut != s.top()) {
            if(*strIn)  s.push(*strIn);
            else return false;
            strIn++;
        } else if(*strOut == s.top()) {
            s.pop();
        }
        strOut++;
    }
    return true;

}

int main() {
    const char *strIn = "ABCDEFG";
    const char *strOut = "BAEDFGC";
    bool b = IsPossible(strIn,strOut);
    cout<<b<<endl;
    return 0;
}
