#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//constant functions
const int MAX = 100;

class Matrix {
private:
int rows;
int cols;
int** ar;
public:
Matrix(int r, int c): rows(r), cols(c) {
  ar = new int*[rows];
    for (int i = 0; i < rows; i++) {
      ar[i] = new int[cols];
    }
  }
  ~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete [] ar[i];
      }
      delete [] ar;
  }
  void display() const;
  int get_rows();
  int get_cols();
  int value_at(int row, int col);
  void fill_matrix(ifstream& ifstr);
};

int Matrix::value_at(int row, int col) {
  return ar[row][col];
}
int Matrix::get_rows() {
  return this->rows;
}
int Matrix::get_cols() {
  return this->cols;
}

void fill_dataFile(string file_name) {
  srand(time(0));
  ofstream fout(file_name);
  if (!fout.is_open()) {
    cerr << "Could not open file." << endl;
    return;
  }
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      fout << rand() % 101 << " ";
    }
    fout << endl;
  }
}

void Matrix::fill_matrix(ifstream& ifstr) {
  int number;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ifstr >> number;
      this->ar[i][j] = number;
    }
  }
  ifstr.close();
}

void Matrix::display() const {
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      cout << " " <<  ar[i][j] << " ";
    }
    cout << endl;
  }
}
#endif
