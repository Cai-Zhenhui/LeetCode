#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1114. 按序打印
https://leetcode.cn/problems/print-in-order/
*/

//方法一 互斥量(好像没有啥用)+标志
class Foo {
public:
    mutex m;
    int nextIndex = 1;

    Foo() {

    }

    void first(function<void()> printFirst) {
        m.lock();
        nextIndex = 2;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m.unlock();
    }

    void second(function<void()> printSecond) {
        m.lock();
        while (nextIndex != 2) {
            m.unlock();
            //this_thread::sleep_for(chrono::milliseconds(2));
            m.lock();
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        nextIndex = 3;
        m.unlock();
    }

    void third(function<void()> printThird) {
        m.lock();
        while (nextIndex != 3) {
            m.unlock();
            //this_thread::sleep_for(chrono::milliseconds(2));
            m.lock();
        }
        // printThird() outputs "second". Do not change or remove this line.
        printThird();
        //nextIndex = 3;
        m.unlock();
    }
};

////方法二 仅win平台
//class Foo {
//public:
//    binary_semaphore firstDone{ 0 };
//    binary_semaphore secondDone{ 0 };
//
//    Foo() {
//
//    }
//
//    void first(function<void()> printFirst) {
//
//        // printFirst() outputs "first". Do not change or remove this line.
//        printFirst();
//        firstDone.release();
//    }
//
//    void second(function<void()> printSecond) {
//        firstDone.acquire();
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        secondDone.release();
//    }
//
//    void third(function<void()> printThird) {
//        secondDone.acquire();
//        // printThird() outputs "third". Do not change or remove this line.
//        printThird();
//    }
//};

