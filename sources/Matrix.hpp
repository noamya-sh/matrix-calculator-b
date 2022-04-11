
#include <iostream>
#include <vector>
using namespace std;
namespace zich {
    class Matrix {
    private:
        vector<double> mat;
        int height;
        int width;
    public:
        Matrix(vector<double> input, int height, int width);
        Matrix(const Matrix &matrix);
//        Matrix(const vector<vector<double>> mat, int height, int width);
        ~Matrix();
        int get_width() const{return width;}
        int get_height() const{return height;}
        friend Matrix operator*(Matrix &matrix, double scalar);
        friend Matrix operator*(double scalar,Matrix &matrix);
        Matrix operator*(const Matrix &matrix) const;
        Matrix &operator*=(const Matrix &matrix);
        Matrix &operator*=(double scalar);
        Matrix operator+(const Matrix &matrix) const;
        Matrix operator+();
        Matrix operator++(int);
        Matrix& operator++();
        Matrix &operator+=(const Matrix &matrix);
        Matrix operator-(const Matrix &matrix) const;
        Matrix operator-();
        Matrix &operator-=(const Matrix &matrix);
        Matrix operator--(int);
        Matrix& operator--();
        bool operator<(const Matrix &other) const;
        bool operator>(const Matrix &other) const;
        bool operator<=(const Matrix &other) const;
        bool operator>=(const Matrix &other) const;
        friend bool operator==(const Matrix &left,const Matrix &right);
//        bool operator==(const Matrix &other) const;
        bool operator!=(const Matrix &other) const;

// I/O functions:
        friend ostream &operator<<(ostream &output, const Matrix &matrix);

        friend istream &operator>>(istream &input, Matrix &matrix);
    };
}