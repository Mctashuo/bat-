#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cstring>
using namespace std;
/*
 * 计算给定的逆波兰表达式的值.有效操作只有+-*/   /*,每个操作
    数都是整数
    abc-d*+
    若当前字符是操作数,则压栈
    若当前字符是操作符,则弹出栈中的两个操作数,计算后仍然压入栈中.
        若某次操作,栈内无法弹出两个操作数,则表达式有误
 */
bool isOperator(const char * p) {
    return (*p == '+' || *p == '-' || *p == '*' || *p == '/' );
}

int ReversePolishNotation(const char * str) {
    const char * pre = str;
    stack<int> s;
    int size = strlen(str);
    while(*str) {
        if(!isOperator(str)) {
            string pstr(str,str + 1);
           s.push(atoi(pstr.c_str()));
           cout<<s.top()<<"入栈"<<endl;
        } else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            if(*str == '+') {
                s.push(op1 + op2);
                //cout<<s.top()<<endl;
            } else if(*str == '-') {
                s.push(op1 - op2);
            } else if(*str == '*') {
                s.push(op1 * op2);
            } else {
                s.push(op1 / op2);
            }
        }
        str++;
    }

    return s.top();
}

int main() {
    const char * str = "21+3*";
    int res = ReversePolishNotation(str);
    cout<<res<<endl;
    return 0;
}

