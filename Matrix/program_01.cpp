//Write a program to check whether a given matrix is square. if not, display an error message.
#include <iostream>
using namespace std;

class Is_Squar{
  public:
    bool check(int m, int n){
      try{
        if(m == n){
          cout << "Is A Square Matrix";
          return true; 
        }else{
          throw 1;
        }
      }
      catch(int){
        cout << "Not A Square Matrix\n";
        return false;
      }
    }
};
int main(){
  int A[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  Is_Squar S;
  S.check(3, 3);

  return 0;
}