//Without using any built-in function, Write a program to compute the transpose of a matrix and check if it is symmetric.

#include <iostream>
using namespace std;

class TRANSPOSE{
  public:
    bool isSquare(int row, int col){
      return (row == col);
    }

    template<size_t R, size_t C>
    bool isTranspose(int (&Matrix)[R][C]){
      cout << "Order: " << R << " x " << C << endl;
      if(!isSquare(R, C)){
        cout << "Is Not Transpose | Not Symmetric\n";
        return false;
      }

      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(Matrix[i][j] != Matrix[j][i]){
            cout << "Is Not Transpose | Not Symmetric\n";
            return false;
          }
        }
      }
      cout << "Is Transpose | Symmetric\n";
      return true;
    }
};
int main(){
  int A[][1] = {
    {1}
  };
  TRANSPOSE T;
  T.isTranspose(A);
  return 0;
}