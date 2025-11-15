//Given a matrix, determine if it is symmetric using only half of the matrix (do not compare all elements).
#include <iostream>
using namespace std;

class IS_SYMMETRIC{
  private:
    string isSym = "Is Symmetric";
    string isNotSym = "Is Not Symmetric";
  public:
    bool isSquare(int row, int col){
      return (row == col);
    }

    template<size_t R, size_t C>
    bool isSymmetric(int (&matrix)[R][C]){
      cout << "Order: " << R << " x " << C << endl;
      if(!isSquare(R, C)){
        cout << isNotSym << endl;
        return false;
      }
      for(int i = 0; i < R - 1; i++){
        for(int j = 0; j < C; j++){
          if(j > i && matrix[i][j] != matrix[j][i]){
            cout << isNotSym << endl;
            return false;
          }
        }
      }
      cout << isSym << endl;
      return true;
    }
};

int main(){
  int A[4][4] = { //square matrix A
    {1,2,3,4},
    {2,5,6,7},
    {3,6,9,8},
    {4,7,8,0}
  };
  int B[3][3] = { //square matrix B
    {1,2,3},
    {2,5,6},
    {3,0,9}
  };

  IS_SYMMETRIC S;
  S.isSymmetric(A);
  S.isSymmetric(B);
  return 0;
}