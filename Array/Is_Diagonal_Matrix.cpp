//Given a square matrix, write code to check if the matrix is a diagonal matrix without using nested if conditions
#include <iostream>
using namespace std;

class IS_DIAGONAL{
  private:
    int Row;
    int Col;
  public:
    template<size_t R, size_t C>
    bool IsSquare(int (&matrix)[R][C]){ //chec it is square or not
      this->Row = R;
      this->Col = C;
      return (R==C);
    }

    template<size_t R, size_t C>
    void check(int (&matrix)[R][C]){
      if(!IsSquare(matrix)){
        cout << "Order: " << Row << " x " << Col << endl;
        cout << "It is Not Diagonal Matrix\n";
        return;
      }
      cout << "Order: " << Row << " x " << Col << endl;
      for(int i = 0; i < R; i++){
        int status = 0;
        for(int j = 0; j < C; j++){
          if(i != j && matrix[i][j] != 0){
            cout << "Not Diagonal Matrix | Non Diagonal Element is Non Zero\n";
            return;
          }
        }
      }
      cout << "Is Diagonal Matrix\n";
    }
};

int main(){
  int arr[3][3] = {
    {0,0,0},
    {0,9,0},
    {0,1,0}
  };
  IS_DIAGONAL D;
  D.check(arr);
  return 0;
}