/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Brooks McKinley
 */

#include "std_lib_facilities.h"

int fib(const int num);
void modifyValue(int num);

int main(void) {
    for (int i = 0; i < 25; i++) {
        cout << fib(i) << endl;
    }
    int num = 4;
    cout << "The value of num is " << num << endl;
    modifyValue(num);
    cout << "The vlaue of num is still " << num << endl;

    return 0;
}

// inefficient but elegant, my favorite function :)
// The function takes a const int, proving it indeed does work.
int fib(const int num) {
    // The following line fails to compile, so marking the argument as a const int works properly
    // num = 3;
    if (num == 0 || num == 1) return num;
    return fib(num - 1) + fib(num - 2);
}

// This function does nothing, since it's pass by value instead of pass by reference.
void modifyValue(int num) {
    num = 3;
}

// Written response:
// Creating a function that takes a non-reference const as an argument definitely works. It's just not very useful.
// Const is more useful for references since you can be sure in the function signature that the variable you passed in
// won't be modified as a side effect, but if you're passing by value the variable you passed in won't be modified no
// matter what happens in the function. 
//
// It still might be useful though, from the perspective of the implementor of the called function. Marking a variable
// as const means that a programmer can be 100% sure at a glance that the value of that variable is never modified,
// which decreases the amount of moving parts in a function and makes it easier to debug, if not prevents some bugs
// from happening in the first place.
