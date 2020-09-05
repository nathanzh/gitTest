/*
 * MyMathFunction.cpp
 *
 *  Created on: Jul 18, 2019
 *      Author: cd1021051
 */

#include <iostream>
#include <string>
#include <cmath>
#include "MyMathFunction.h"
using namespace std;



double areaOfCircle(int r)
{
	return PI * pow(r,2);
}
double volOfSphere(int r)
{
	return 4/3.0*PI*pow(r,3);
}
