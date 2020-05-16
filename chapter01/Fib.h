//
// Created by wangheng on 2020/5/16.
//

#ifndef DATA_STRUCTURE_FIB_H
#define DATA_STRUCTURE_FIB_H

class Fib {
private:
    int f, g;
public:
    Fib(int n)  // 初始化为不小于n的最小Fibonacci项
    {
        f = 1, g = 0;
        while (g < n)
            next();
    }
    int get() { return g; }
    int next() {    // 转至下一Fibonacci项
        g += f;
        f = g - f;
        return g;
    }
    int prev() {    // 转至上一Fibonacci项
        f = g - f;
        g -= f;
        return g;
    }
};

#endif //DATA_STRUCTURE_FIB_H
