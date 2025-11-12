// for a given diagonal matrix, verify if it is also an identity matrix.
#include <iostream>
using namespace std;

template<typename T>
class IS_IDENTITY{
  public:
    template<size_t R, size_t C>
    bool isSquare(T (&matrix)[R][C]){ //checks matrix is square or not?
      return (R==C);
    }

    template<size_t R, size_t C>
    bool isDiagonal(T (&matrix)[R][C]){ //checks matrix is diagonal or not?
      if(!isSquare(matrix)){
        return false;
      }
      for (int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(i != j && matrix[i][j] != 0){
            return false;
          }
        }
      }
      return true;
    }

    template<size_t R, size_t C>
    bool check(T (&matrix)[R][C]){ //checks matrix is identity or not?
      cout << "Order: " << R << "x" << C << endl;
      if(!isDiagonal(matrix)){
        cout << "Is Not Diagonal\n";
        return false;
      }
      for(int i = 0; i < R; i++){
        if(matrix[i][i] != 1){
          cout << "Is Not Identity Matrix\n";
          return false;
        }
      }
      cout << "Is Identity Matrix\n";
      return true;
    }
};
int main(){
  int arr[3][3] = {
    {1,0,0},
    {0,1,0},
    {0,0,1}
  };
  IS_IDENTITY<int> I;
  I.check(arr);
  return 0;
}