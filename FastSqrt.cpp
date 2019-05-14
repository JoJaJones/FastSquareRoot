/******************************************************************************
 * Created by Joshua Jones on 4/9/2019.
 * Copyright (c) 2019 
 * All rights reserved.
 *
 *      Uses bit manipulation and "magic" number to get an approximation of
 *      the square root of the entered numbers. Performs more quickly than
 *      built in square root function for numbers closer to 0 (was ahead
 *      in first 500k whole numbers in initial test)
 ******************************************************************************/
#include <iostream>

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