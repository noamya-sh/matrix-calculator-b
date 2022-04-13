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
TEST_CASE("one"){
    Matrix m1 = Matrix({1,2,1,2},2,2);
    Matrix m2 = Matrix({2,1,2,1},2,2);
    Matrix m3 = Matrix({3,3,3,3},2,2);
    CHECK_EQ((m1+m2) == m3, true);
    m3--;
    m3--;
    CHECK_EQ((m1+m2) == m3*3, true);
}
TEST_CASE("two"){
    vector<double> vec = {5, 9, 0, 5, 1, 2, -1, 0, 1};
    vector<double> vec2 = {5, 9, 0, 5, 1, 2, -1, 0,10, 1};
    vector<double> vec3 = {1, 2, 1, 1, 1, 4, 21, 0,11, 4};
    vector<double> vec4 = {5};
    vector<double> vec5 = {1,2,3};
    Matrix m1 = Matrix(vec,3,3);
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
    Matrix m5 = Matrix(vec5,1,3);
    Matrix m6 = Matrix({3,4,5},1,3);
    m6--;
    --m6;
    CHECK_EQ(m6 == m5, true);
    CHECK_NOTHROW(m4*m5);
    CHECK_THROWS(m5*m4);
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
    Matrix mat1{{1,2,3,3,2,1,1,2,3},3,3};
    Matrix mat2{{1,0,0,0,1,0,0,0,1},3,3};
    ostringstream os1;
    os1 << mat1;
    CHECK(os1.str() == "[1 2 3]\n[3 2 1]\n[1 2 3]");
    ostringstream os2;
    os2 << mat2;
    CHECK(os2.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]");
    CHECK_EQ(mat1*mat2 == mat1, true);
    CHECK_EQ(mat1*-1 == mat1*(-mat2), true);
    CHECK_EQ(mat1*2.5 == mat1*(mat2*2.5), true);
}