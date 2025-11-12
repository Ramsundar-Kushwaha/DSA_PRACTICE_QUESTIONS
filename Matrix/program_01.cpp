//Write a program to check whether a given matrix is square. if not, display an error message.
#include <iostream>
using namespace std;

class Is_Squar{
  public:
    template<size_t R, size_t C> //generic or c++ templates
    bool check(int(&matrix)[R][C]){
      cout << "Row: " << R << endl;
      cout << "Col: " << C << endl;
      if(R == C){
        cout << "Is Square Matrix\n";
        return true;
      }else{
        cout << "Is Not Square Matrix\n";
        return false;
      }
    }
};

int main(){
  Is_Squar s;
  int A[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  s.check(A);
  return 0;
}