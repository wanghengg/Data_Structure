//
// Created by wangheng on 2020/5/31.
//

#include "Stack.h"
#include <iostream>
#include <vector>

bool isMatch(std::vector<char>& symbols) {
    Stack<char> stack;
    for (auto iter : symbols) {
        if (iter == '(')
            stack.push(iter);
        else if(iter == ')')
            stack.pop();
    }
    return stack.empty();
}

int main() {
    std::vector<char> symbols{'(', ')', '(', '(', '(', ')', ')', '(', ')', ')'};
    std::cout << std::boolalpha <<isMatch(symbols) << std::endl;

    return 0;
}