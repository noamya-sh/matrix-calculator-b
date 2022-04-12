/*
 * @author Noamya Shani
 * */
#include <vector>
#include "Matrix.hpp"
namespace zich {
    void insert_row(vector<double> &vector, const string &row) {
        unsigned int i = 1;
        string element;
        while (i < row.size() - 1) {
            while (row.at(i) != ' ' && row.at(i) != ']') {
                element += row.at(i++);
            }
            i++;
            vector.push_back(stod(element));
            element = "";
        }
    }
    int get_width(const string &row) {
        int width = 1;
        for (unsigned int i = 1; i < row.size() - 1; ++i) {
            while (row.at(i) == ' ') {
                width++;
                i++;
            }
        }
        return width;
    }
    void check_syntax(const string &row) {
        if (row.at(0) != '[' || row.at(row.size() - 1) != ']') {
            throw invalid_argument("Wrong row!");
        }
    }
    void check_width(int width, const string &row) {
        if (width != get_width(row)) {
            throw std::invalid_argument("columns must be same the size!");
        }
    }
    vector<double> get_sums(vector<double> mat1,vector<double> mat2,int height, int width){
        double sum_mat1 = 0;
        double sum_mat2 = 0;
        for (unsigned int i = 0; i < mat1.size(); ++i) {
            sum_mat1 += mat1[i];
            sum_mat2 += mat2[i];
        }
        vector<double> vector;
        vector.push_back(sum_mat1);
        vector.push_back(sum_mat2);
        return vector;
    }
    Matrix::Matrix(const Matrix &matrix) {
        this->mat = matrix.mat; //deep copy
        this->height = matrix.height;
        this->width = matrix.width;
    }
    Matrix::Matrix(const vector<double> &input, int height, int width){
        if (input.size() != height*width){
            throw invalid_argument("NO same size!!");
        }
        if (width < 0 || height <0){
            throw invalid_argument("Height and width are positive!!");
        }
        this->height = height;
        this->width = width;
        this->mat = input;
    }
    Matrix::~Matrix() {}
    bool operator==(const Matrix &left,const Matrix &right){
        if (left.height != right.height || left.width !=  right.width){
            throw runtime_error("not same size");
        }
        for (unsigned int i = 0; i < left.mat.size(); ++i) {
            if (left.mat[i] != right.mat[i]){
                return false;
            }
        }
        return true;
    }
    bool Matrix::operator<=(const Matrix &other) const {
        if (other.height != height || other.width !=  width){
            throw runtime_error("not same size");
        }
        vector<double> sums = get_sums(this->mat,other.mat,height,width);
        return sums[0] <= sums[1];
    }
    bool Matrix::operator!=(const Matrix &other) const {
        if (other.height != height || other.width !=  width){
            throw runtime_error("not same size");
        }
        for (unsigned int i = 0; i < other.mat.size(); ++i) {
            if (other.mat[i] != this->mat[i]){
                return true;
            }
        }
        return false;
    }
    bool Matrix::operator>=(const Matrix &other) const {
        if (other.height != height || other.width !=  width){
            throw runtime_error("not same size");
        }
        vector<double> sums = get_sums(this->mat,other.mat,height,width);
        return sums[0] >= sums[1];
    }
    bool Matrix::operator>(const Matrix &other) const {
        if (other.height != height || other.width !=  width){
            throw runtime_error("not same size");
        }
        vector<double> sums = get_sums(this->mat,other.mat,height,width);
        return sums[0] > sums[1];
    }
    bool Matrix::operator<(const Matrix &other) const {
        if (other.height != height || other.width !=  width){
            throw runtime_error("not same size");
        }
        vector<double> sums = get_sums(this->mat,other.mat,height,width);
        return sums[0] < sums[1];
    }
    Matrix &Matrix::operator*=(double scalar) {
        for (unsigned int i = 0; i < this->mat.size(); ++i) {
            this->mat[i]*=scalar;
        }
        return *this;
    }
    Matrix &Matrix::operator-=(const Matrix &matrix){
        if (this->height != matrix.height || this->width != matrix.width){
            throw runtime_error("Matrices should be the same size.");
        }
        for (unsigned int i = 0; i < matrix.mat.size(); ++i) {
            this->mat[i] -= matrix.mat[i];
        }
        return *this;
    }
    Matrix &Matrix::operator+=(const Matrix &matrix){
        if (this->height != matrix.height || this->width != matrix.width){
            throw runtime_error("Matrices should be the same size.");
        }
        for (unsigned int i = 0; i < matrix.mat.size(); ++i) {
            this->mat[i] += matrix.mat[i];
        }
        return *this;
    }
    Matrix Matrix::operator-(const Matrix &matrix) const {
        Matrix ans = Matrix(this->mat,this->height,this->width);
        return ans -= matrix;
    }
    Matrix Matrix::operator-(){
        Matrix ans = Matrix(this->mat,this->height,this->width);
        return ans *= -1;
    }
    Matrix& Matrix::operator++(){
        for (unsigned int i = 0; i < this->mat.size() ; ++i) {
            ++this->mat[i];
        }
        return *this;
    }
    Matrix Matrix::operator++(int){
        Matrix temp(this->mat,this->height,this->width);
        for (unsigned int i = 0; i < this->mat.size() ; ++i) {
            this->mat[i]++;
        }
        return temp;
    }
    Matrix& Matrix::operator--(){
        for (unsigned int i = 0; i < this->mat.size() ; ++i) {
            --this->mat[i];
        }
        return *this;
    }
    Matrix Matrix::operator--(int){
        Matrix temp(this->mat,this->height,this->width);
        for (unsigned int i = 0; i < this->mat.size() ; ++i) {
            this->mat[i]--;
        }
        return temp;
    }
    Matrix Matrix::operator+(const Matrix &matrix) const {
        Matrix ans = Matrix(this->mat,this->height,this->width);
        return ans += matrix;
    }
    Matrix Matrix::operator+(){
        return Matrix(this->mat,this->height,this->width);
    }
    Matrix Matrix::operator*(const Matrix &matrix) const{
        if (this->width != matrix.get_height()){
            throw runtime_error("Matrices cannot be multiplied.");
        }
        Matrix ans = Matrix(this->mat,this->height,this->width);
        return ans *= matrix;
    }
    Matrix operator*(double scalar, Matrix &matrix) {
        vector<double> mat((unsigned int )matrix.height*(unsigned int )matrix.width, 0);
        for (unsigned int i = 0; i < matrix.mat.size(); ++i) {
            mat[i] = scalar*matrix.mat[i];
        }
        Matrix ans = Matrix(mat,matrix.height,matrix.width);
        return ans;
    }
    Matrix operator*(Matrix &matrix,double scalar) {
        return operator*(scalar, matrix);
    }
    Matrix &Matrix::operator*=(const Matrix &matrix) {
        if (this->width != matrix.height){
            throw runtime_error("Matrices cannot be multiplied.");
        }
        vector<double > temp((size_t)this->height*(size_t)matrix.width);
        unsigned int ind = 0;
        for (unsigned int i = 0; i < this->height; ++i) {
            for (unsigned int j = 0; j < matrix.width; ++j,ind++) {
                for(unsigned int k =0; k < this->width;k++) {
                    temp[ind] += this->mat[((unsigned int) this->width * i) + k] *
                                 matrix.mat[(k * (unsigned int) matrix.width) + j];
                }
            }
        }
        this->mat = temp;
        this->width = matrix.width;
        return *this;
    }
    ostream &operator<<(ostream &output, const Matrix &matrix) {
        unsigned int k =0;
        for(int i=0;i<matrix.height;i++){
            output<<"[";
            for(int j=0;j<matrix.width;j++){
                output<<matrix.mat[k++] + 0;
                if (j != matrix.width - 1){
                    output<<" ";
                }
            }
            output << "]";
            if (i != matrix.height - 1){
            output<< endl;
            }
        }
        return output;
    }
    istream &operator>>(istream &input, Matrix &matrix) {
        vector<double> vector;
        string in;
        getline(input, in);
        int width = 0;
        int height = 0;
        string end_line = ", ";
        size_t pos = 0;
        string row;
        bool only_one_row = false;
        if ((pos = in.find(end_line)) == string::npos) {
            only_one_row = true;
        }
        // reading the first row:
        row = in.substr(0, pos);
        in.erase(0, pos + end_line.length());
        check_syntax(row);
        width = get_width(row);
        insert_row(vector, row);

        while ((pos = in.find(end_line)) != string::npos) {
            row = in.substr(0, pos);
            in.erase(0, pos + end_line.length());
            check_syntax(row);
            check_width(width, row);
            insert_row(vector, row);
            height++;
        }

        if (!only_one_row) {
            check_syntax(in);
            check_width(width, in);
            insert_row(vector, in); // adding the last row
            height++;
        }
        matrix.mat = vector;
        matrix.height = height;
        matrix.width = width;
        return input;
    }
}
