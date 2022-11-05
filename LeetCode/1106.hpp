#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1106. 解析布尔表达式
https://leetcode.cn/problems/parsing-a-boolean-expression/
*/

////方法一 还有问题
//class Solution {
//public:
//    int index = 0;
//    bool dealNotExpression(string& expression) {
//        bool result = true;
//        while (expression[index] != ')') {
//            switch (expression[index++]) {
//            case 't': {
//                result = false;
//                break;
//            }
//            case 'f': {
//                result = true;
//                break;
//            }
//            case '!': {
//                result = !dealNotExpression(expression);
//                break;
//            }
//            case '&': {
//                result = !dealAndExpression(expression);
//                break;
//            }
//            case '|': {
//                result = !dealOrExpression(expression);
//                break;
//            }
//            }
//        }
//        ++index;//跳过当前层级的右括号
//        return result;
//    }
//    bool dealAndExpression(string& expression) {
//        bool result = true;
//        bool isFirst = true;
//        while (expression[index] != ')') {
//            switch (expression[index++]) {
//            case 't': {
//                if (isFirst) {
//                    result = true;
//                    isFirst = false;
//                }
//                else {
//                    //result = result && true;
//                }
//                break;
//            }
//            case 'f': {
//                // result = false;
//                // 结束表达式
//                int cnt = 1;
//                for (; cnt > 0 && index < expression.size(); ++index) {
//                    if (expression[index] == '(') {
//                        ++cnt;
//                    }
//                    else if (expression[index] == ')') {
//                        --cnt;
//                    }
//                }
//                return false;
//                break;
//            }
//            case '!': {
//                if (isFirst) {
//                    result = dealNotExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result && dealNotExpression(expression);
//                }
//                break;
//            }
//            case '&': {
//                if (isFirst) {
//                    result = dealAndExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result && dealAndExpression(expression);
//                }
//                break;
//            }
//            case '|': {
//                if (isFirst) {
//                    result = dealOrExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result && dealOrExpression(expression);
//                }
//                break;
//            }
//            }
//        }
//        ++index;//跳过当前层级的右括号
//        return result;
//    }
//    bool dealOrExpression(string& expression) {
//        bool result = true;
//        bool isFirst = true;
//        while (expression[index] != ')') {
//            switch (expression[index++]) {
//            case 't': {
//                // result = true;
//                // 结束表达式
//                int cnt = 1;
//                for (; cnt > 0 && index < expression.size(); ++index) {
//                    if (expression[index] == '(') {
//                        ++cnt;
//                    }
//                    else if (expression[index] == ')') {
//                        --cnt;
//                    }
//                }
//                return true;
//                break;
//            }
//            case 'f': {
//                if (isFirst) {
//                    result = false;
//                    isFirst = false;
//                }
//                else {
//                    //result = result || false;
//                }
//                
//                break;
//            }
//            case '!': {
//                if (isFirst) {
//                    result = dealNotExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result || dealNotExpression(expression);
//                }
//                break;
//            }
//            case '&': {
//                if (isFirst) {
//                    result = dealAndExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result || dealAndExpression(expression);
//                }
//                break;
//            }
//            case '|': {
//                if (isFirst) {
//                    result = dealOrExpression(expression);
//                    isFirst = false;
//                }
//                else {
//                    result = result || dealOrExpression(expression);
//                }
//                break;
//            }
//            }
//        }
//        ++index;//跳过当前层级的右括号
//        return result;
//    }
//    bool parseBoolExpr(string expression) {
//        bool result = true;
//        index = 0;
//        switch (expression[index++]) {
//        case '!': {
//            result = dealNotExpression(expression);
//            break;
//        }
//        case '&': {
//            result = dealAndExpression(expression);
//            break;
//        }
//        case '|': {
//            result = dealOrExpression(expression);
//            break;
//        }
//        }
//        return result;
//    }
//};

//方法二
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> oprs;
        stack<bool> exps;
        stack<char> nums;//处理不定长参数
        for (auto ch : expression) {
            switch (ch) {
            case '!': {
                oprs.push('!');
                nums.push(1);
                break;
            }
            case '&': {
                oprs.push('&');
                nums.push(1);
                break;
            }
            case '|': {
                oprs.push('|');
                nums.push(1);
                break;
            }
            case ',': {
                ++nums.top();//当前层级参与运算数的数量+1
                break;
            }
            case 't': {
                exps.push(true);
                break;
            }
            case 'f': {
                exps.push(false);
                break;
            }
            case ')': {
                //结束当前层级运算 运算符出栈结算
                char op = oprs.top();
                oprs.pop();
                switch (op) {
                case '!': {
                    nums.pop();//只有一个操作数,不需要处理
                    exps.top() = !exps.top();
                    break;
                }
                case '&': {
                    bool _ = exps.top();
                    exps.pop();
                    nums.top()--;//已经取出了一个操作数
                    while (nums.top()--) {
                        _ = _ && exps.top();
                        exps.pop();
                    }
                    exps.push(_);
                    nums.pop();
                    break;
                }
                case '|': {
                    bool _ = exps.top();
                    exps.pop();
                    nums.top()--;//已经取出了一个操作数
                    while (nums.top()--) {
                        _ = _ || exps.top();
                        exps.pop();
                    }
                    exps.push(_);
                    nums.pop();
                    break;
                }
                }
            }
            }
        }
        return exps.top();
    }
};
