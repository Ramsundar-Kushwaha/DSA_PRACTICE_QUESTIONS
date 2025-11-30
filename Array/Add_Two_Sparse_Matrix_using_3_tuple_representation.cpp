//write a program to add two sparse matrices using 3-tuple representation without converting them into full matrices.
#include <iostream>
using namespace std;

class Add_SPARSE{
  private:
    int Size1 = 0;
    int Size2 = 0;
    int (*sparse1)[3];
    int (*sparse2)[3];
  public:
    Add_SPARSE():sparse1(nullptr), sparse2(nullptr){}
    ~Add_SPARSE(){
      delete[]sparse1; //free memory
      delete[]sparse2; //free memory
      sparse1 = sparse2 = nullptr;
    }
    
    //for finding the size of non zero elements
    template<size_t R, size_t C, size_t R1, size_t C1>
    void findNonZeroSize(int (&matrix1)[R][C], int (&matrix2)[R1][C1]){
      Size1 = 0;
      Size2 = 0;
      
      static_assert(R == R1 && C == C1, "Dimensions of Matrix Is Not Equal\n"); // it will check for compile time error
      
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(matrix1[i][j] != 0){
            Size1++;
          }
          if(matrix2[i][j] != 0){
            Size2++;
          }
        }
      }
    }
    
    //sparse representation
    template<size_t row, size_t col, size_t  row2, size_t  col2>
    void SparseRepresentation(int (&m1)[row][col], int (&m2)[row2][col2]){
      findNonZeroSize(m1, m2); //function calling
      int srow1 = 0;
      int srow2 = 0;

      sparse1 = new int[Size1][3]; //memory allocation
      sparse2 = new int[Size2][3]; //memory allocation

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(m1[i][j] != 0){
            sparse1[srow1][0] = i;
            sparse1[srow1][1] = j;
            sparse1[srow1++][2] = m1[i][j];
          }
          if(m2[i][j] != 0){
            sparse2[srow2][0] = i;
            sparse2[srow2][1] = j;
            sparse2[srow2++][2] = m2[i][j];
          }
        }
      }
    }
    

    //for displaying elements
    void display(){
      for(int i = 0; i < Size1; i++){
        for(int j = 0; j < 3; j++){
          cout << sparse1[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      for(int i = 0; i < Size2; i++){
        for(int j = 0; j < 3; j++){
          cout << sparse2[i][j] << " ";
        }
        cout << endl;
      }
    }

};

int main(){
  int A[3][3] = {
    {1,3,0},
    {0,2,0},
    {0,0,0}
  };

  int B[3][3] = {
    {0,0,0},
    {0,2,1},
    {9,0,0}
  };
  
  Add_SPARSE S;
  S.SparseRepresentation(A, B);
  S.display();
  return 0;
}