//Write a function to check whether a given square matrix is upper triangular. Optimize so that it stops checking early when a non-zero element is found below diagonal.
#include <iostream>
using namespace std;

class IS_UPPER{
  private:
    string upperTriangular = "Is Upper Triangular Matrix";
    string notUpperTriangular = "Is Not Upper Triangular Matrix";
  public:
    template<size_t R, size_t C>
    bool isSquare(int (&matrix)[R][C]){ //function to check matrix is square or not?
      return (R == C);
    }

    template<size_t R, size_t C>
    bool check(int (&matrix)[R][C]){ //checks is upper triangular or not?
      cout << "Order: " << R << " x " << C << endl;
      if(!isSquare(matrix)){
        cout << notUpperTriangular << endl;
        return false;
      }
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if (i > j && matrix[i][j] != 0){
            cout << notUpperTriangular << endl;
            return false;
          }
        }
      }
      cout << upperTriangular << endl;
      return true;
    }
};

//main function
int main(){
  int A[3][3] = {
    {0,2,3},
    {0,0,6},
    {0,0,0}
  };
  IS_UPPER U;
  U.check(A);
  return 0;
}