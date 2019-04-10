/******************************************************************************
 * Created by Joshua Jones on 4/9/2019.
 * Copyright (c) 2019 
 * All rights reserved.
 ******************************************************************************/
#include <iostream>

using namespace std;

float performBlackMagic(float x);

double performBlackMagic(double x);

int main(){
    double num;
    float numTwo;
    cout << "Input a number: ";
    cin >> num;
    cout << "The square root of that number is: " << performBlackMagic(num) << endl;
    
    cout << "Input a number: ";
    cin >> numTwo;
    cout << "The square root of that number is: " << performBlackMagic(numTwo) << endl;

    return 0;
}

float performBlackMagic(float x){
    float b = x;
    int a = *(int*)&x;
    a = 0x1fc00000 + (a>>1);
    x = *(float*)&a;
    x = .5f*(x+(b/x));
    return x;
}

double performBlackMagic(double x){
    double b = x;
    long long a = *(long long*)&x;
    a = 0x1FF8000000000000 + (a>>1);
    x = *(double*)&a;
    x = .5*(x+(b/x));
    return x;
}