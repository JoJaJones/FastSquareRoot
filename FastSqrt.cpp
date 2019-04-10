/******************************************************************************
 * Created by Joshua Jones on 4/9/2019.
 * Copyright (c) 2019 
 * All rights reserved.
 ******************************************************************************/
#include <iostream>

using namespace std;

//float performBlackMagic(float x);

double performBlackMagic(double x);

int main(){
    double num;
    do {
        cout << "Input a number: ";
        cin >> num;

        cout << "The square root of that number is: " << performBlackMagic(num) << endl;
    }while(num!=0);
    return 0;
}

//float performBlackMagic(float x){
//    float b = x;
//    int a = *(int*)&x;
//    a = 0x1fc00000 + (a>>1);
//    x = *(float*)&a;
//    x = .5f*(x+(b/x));
//    return x;
//}

double performBlackMagic(double x){//significantly faster first 500k whole numbers or so then drops off
    double b = x;
    long long a = *(long long*)&x;
    a = 0x1FF8000000000000 + (a>>1);
    x = *(double*)&a;
    x = .5*(x+(b/x));
    //x = .5*(x+(b/x));
    //x = .5*(x+(b/x));
    return x;
}

//fast sqrt float 0x1fc00000 + x>>1
//fast sqrt double 0x1FF8000000000000 + x>>1