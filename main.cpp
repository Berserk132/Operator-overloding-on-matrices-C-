// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0


//Abdulrahman mohamed hassan
//20170150
//G1
#include <bits/stdc++.h>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;

  void operator=  (matrix& mat2){
    this->col=mat2.col;
    this->row=mat2.row;
    this->data.resize(mat2.data.size());
    this->data=mat2.data;
}
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}

//add every element of the first matrix to the other one in the second matrix
matrix operator+  (matrix mat1, matrix mat2){
        matrix tmp;
    if (mat1.row==mat2.row && mat1.col==mat2.col){
        tmp.col=mat1.col;
        tmp.row=mat1.row;
        tmp.data.resize(mat1.data.size());
        for(int i=0;i< mat1.row * mat1.col ;++i){
            tmp.data[i]=mat1.data[i]+mat2.data[i]; // put the addition in the tmp matrix
        }
    }
    else{
        cout<<"the dimensions of tow matrices are not equal\n";     // if the tow dimensions not equal return matrix with
        tmp.col=1,tmp.row=1;                                        // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//subtract every element of the first matrix from the other one in the second matrix

matrix operator-  (matrix mat1, matrix mat2){
        matrix tmp;
    if (mat1.row==mat2.row && mat1.col==mat2.col){
        tmp.col=mat1.col;
        tmp.row=mat1.row;
        tmp.data.resize(mat1.data.size());
        for(int i=0;i< mat1.row * mat1.col ;++i){
            tmp.data[i]=mat1.data[i]-mat2.data[i];  //put the subtract in the tmp matrix
        }
    }
    else{
        cout<<"the dimensions of tow matrices are not equal\n";     // if the tow dimensions not equal return matrix with
        tmp.col=1,tmp.row=1;                                        // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//multiple tow matrices if the 1st column = the second row
matrix operator*  (matrix mat1, matrix mat2){
        matrix tmp;
    if(mat1.col==mat2.row){
        tmp.col=mat2.col,tmp.row=mat1.row;
        tmp.data.resize(mat1.row*mat2.col);
        for(int i=0;i<tmp.data.size();++i){
            int tmp2=0;
                for(int k=(i/tmp.col)*mat1.col;k<(i/tmp.col)*mat1.col+mat1.col;++k){
                    tmp2+=mat1.data[k]*mat2.data[i%tmp.col+(k%mat2.row)*mat2.col];  //equation to multiple matrices
                }                                                                  //i%col to determine the column
            tmp.data[i]=tmp2;                                                      //(k%row)*col to determine the row
        }
    return tmp;
    }
   else{
        cout<<"can't multiple matrices\n";                  // if the tow dimensions not equal return matrix with
        tmp.col=1,tmp.row=1;                                // 1 element equal to 0
        tmp.data.resize(1);
        tmp.data[0]=0;
    }
    return tmp;
}

//add number to every element of the matrix
matrix operator+  (matrix mat1, int scalar){
    matrix tmp;
    tmp.col=mat1.col;
    tmp.row=mat1.row;
    tmp.data.resize(mat1.data.size());
    for(int i=0;i<mat1.row * mat1.col;++i){
        tmp.data [i]+=scalar;           // add each element to the scalar
    }
    return tmp;
}

//subtract number from all the matrix elements
matrix operator-  (matrix mat1, int scalar){
    matrix tmp;
    tmp.col=mat1.col;
    tmp.row=mat1.row;
    tmp.data.resize(mat1.data.size());
    for(int i=0;i<mat1.row * mat1.col;++i){
        tmp.data [i]-=scalar;       //subtract each element from the scalar
    }
    return tmp;
}

//multiple number with each number of the matrix
matrix operator*  (matrix mat1, int scalar){
    matrix tmp;
    tmp.col=mat1.col;
    tmp.row=mat1.row;
    tmp.data.resize(mat1.data.size());
    for(int i=0;i<mat1.row * mat1.col;++i){
        tmp.data [i]*=scalar;           // multiple each element in the scalar
    }
    return tmp;
}

//____________________________________

istream& operator>> (istream& in, matrix& mat)
{
    int counter = 0;
    for (int i=0;i<mat.data.size();i++)
    {
        in >> mat.data[i];
    }
    return in;
}
// Printing out an array of data


// Taking 2 matrix and adding the second one to the first keeping in mind
// that the change would be in the first matrix

matrix operator+= (matrix& mat1, matrix mat2)
{
    if (mat1.row==mat2.row && mat1.col ==mat2.col ){
        for (int i=0;i<mat2.row*mat2.col;i++)
        {
            mat1.data[i] += mat2.data[i];
        }
        return mat1;
    }
    else {
        cout << "Can't be added Because the size of two array isn't equal each others." << endl;

    }

}

// Taking 2 matrix and subtract the first one to the second keeping in mind
// that the change would be in the first matrix
matrix operator-= (matrix& mat1, matrix mat2)
{
    if (mat1.row*mat1.col == mat2.row*mat2.col ){
        for (int i=0;i<mat2.row*mat2.col;i++)
        {
            mat1.data[i] -= mat2.data[i];
        }
        return mat1;
    }
    else {
        cout << "Can't be added Because the size of two array isn't equal each others." << endl;

    }
}

// Taking 1 matrix and adding a number to it
matrix operator+= (matrix& mat, int scalar)
{
    for (int i=0;i<mat.row*mat.col;i++)
    {
        mat.data[i] += scalar;
    }
    return mat;
}

// Taking 1 matrix and subtract a number from it
matrix operator-= (matrix& mat, int scalar)
{
    for (int i=0;i<mat.row*mat.col;i++)
    {
        mat.data[i] -= scalar;
    }
    return mat;
}


// Add one to the elements of the matrix
void   operator++ (matrix& mat)
{
    for (int i=0;i<mat.row*mat.col;i++)
    {
        ++mat.data[i];
    }
}

// Subtract one from the elements of the matrix
void   operator-- (matrix& mat)
{
    for (int i=0;i<mat.row*mat.col;i++)
    {
        --mat.data[i];
    }
}

//______________________________________________

bool   operator== (matrix mat1, matrix mat2){
    if((mat1.row==mat2.row) && (mat1.col==mat2.col)){
          for (int i = 0; i < mat1.data.size(); i++)
                if(mat1.data[i]!=mat2.data[i]) return 0; //compare between every element of the 2 matrices return 0 if not equal
    }
    else return 0;
    return 1;
}

bool   operator!= (matrix mat1, matrix mat2){
    if((mat1.row==mat2.row) && (mat1.col==mat2.col)){
          for (int i = 0; i < mat1.row * mat1.col; i++)
                if(mat1.data[i]==mat2.data[i]) return 0;//compare between every element of the 2 matrices return 0 if equal
    }
    return 1;
}

bool   isSquare   (matrix mat){
    if(mat.row==mat.col) return 1;  // check if column = row or not
    else return 0;
}

bool   isSymetric (matrix mat){
    if(mat.row==mat.col){
        int counter = 0;
        for (int i =0; i<mat.row; i++)
        {
            for (int j=0; j<mat.col; j++)
            {
                if(j <= i){             //skip the visited element
                    counter++;
                    continue;
                }
                if(mat.data[counter]!=mat.data[mat.row*j+i]) return 0;  //compare between element and its symmetric
                counter++;                                              // if not equal return 0
            }
        }
    }
    else return 0;
    return 1;
}
bool   isIdentity (matrix mat){
    int counter=0;
    if(isSquare(mat)){
        if(mat.data[0]!=1) return 0;
        for(int i=0;i<mat.data.size();++i){
            if(i==mat.col+1+counter){           //check if the main diameter equal to 1 or no
                if(mat.data[i]!=1)
                    return 0;
                counter+=mat.col+1;
            }
            else if(mat.data[i]!=0) return 0;   // check the other elements if equal to 0 or no

        }
    }
    return 1;
}
matrix transpose(matrix mat)
{
    matrix tmp;
    tmp.col=mat.row;
    tmp.row=mat.col;
    tmp.data.resize(mat.data.size());
    int counter = 0;

    for (int i =0; i<mat.col; i++)
    {
        for (int j=0; j<mat.row; j++)
        {
            tmp.data[counter]=mat.data[mat.col*j+i];    //transpose the matrix counter is the element in the transposed matrix
            counter++;
        }
    }
    return tmp;
}
ostream &operator<< (ostream &out , matrix mat){
    for(int i=0;i<mat.data.size();++i){
        if (i%mat.col==0) out<<endl;    //endl if its the last element in the row
        out<<mat.data[i]<<" ";
    }
    return out;
}


int main()
{
  int data1 [] = {1,2,3,4,5,6,7,18};
  int data2 [] = {13,233,3,4,5,6,7,8};
  int data3 [] = {1,2,3,4,5,6,7,8};
  int data4 [] = {1,5,7,2};
  matrix mat1, mat2, mat3,mat5;
  createMatrix(2,2,data4,mat5);
  cout<<transpose(mat5)<<endl;
  cout<<isSymetric(mat5);

  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 4, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  matrix mat4= (mat1*mat2);
  cout << "mat 2 "<<mat1 +mat1-mat3<<endl;
  cout << "mat 3 "<<mat4 << endl;
    mat1+= mat3+=mat3;
  cout << "mat 1 "<<mat1 << endl;
  return 0;
}
