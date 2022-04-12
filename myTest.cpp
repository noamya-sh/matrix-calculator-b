//
// Created by נעמיה on 03/04/2022.
//
#include "Matrix.hpp"
//#include "Matrix.cpp"
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace zich;
TEST_CASE("temp"){
    vector<double> vec = {5, 9, 0, 5, 1, 2, -1, 0, 1};
    vector<double> vec2 = {5, 9, 0, 5, 1, 2, -1, 0,10, 1};
    vector<double> vec3 = {1, 2, 1, 1, 1, 4, 21, 0,11, 4};
    vector<double> vec4 = {5};
    Matrix m1 = Matrix(vec,3,3);
//    Matrix m2 = Matrix(vec2,3,3);
    CHECK_NOTHROW(Matrix(vec2,5,2));
    CHECK_THROWS(Matrix(vec2,3,3));
    CHECK_THROWS(Matrix(vec4,3,3));
    CHECK_THROWS(Matrix(vec4,1,3));
    Matrix m2 = Matrix(vec2,5,2);
    Matrix m3 = Matrix(vec3,5,2);
    Matrix m4 = Matrix(vec4,1,1);
    CHECK_THROWS(m1+m2);
    CHECK_THROWS(m1-m2);
    CHECK_THROWS(m1+=m2);
    CHECK_THROWS(m1-=m2);
//    CHECK_THROWS(m1==m2);
//    CHECK_THROWS(m1>=m2);
    CHECK_THROWS(m1*m2);
    CHECK_THROWS(m3*m2);
    CHECK_NOTHROW(m1*0.5);
    CHECK_NOTHROW(4.1*m1);
    CHECK_NOTHROW(-m1);
    CHECK_NOTHROW(m3+m2);
    CHECK_NOTHROW(m3-m2);
    CHECK_NOTHROW(m3+=m2);
    CHECK_NOTHROW(m3-=m2);
    CHECK_NOTHROW(m3*2);
    CHECK_NOTHROW(1.6*m3);
    CHECK_NOTHROW(-m3);
    CHECK_NOTHROW(-m4);
    CHECK_NOTHROW(m4*5);
    CHECK_NOTHROW(m4+=m4);
//    CHECK_NOTHROW(+m1);

}