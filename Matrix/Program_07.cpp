//Using a 2D matrix input, check if the matrix is triadiagonal (only main diagonal)
#include <iostream>
using namespace std;
template<class T>
class MATRIX{
  private:
    int row;
    int col;
    int matrixSize;
    T* matrix = nullptr;
  public:
    //constructor for object initialization
    MATRIX(int R, int C){
      this->row = R;
      this->col = C;
      matrixSize = row * col;
      matrix = new T[matrixSize];
    }

    //destructor for deallocating memory automatically at after the object destroyed
    ~MATRIX(){
      delete[]matrix;
      matrix = nullptr;
    }

    //for user input into matrix
    void getElement(){
      int j = 1;
      int k = 1;

      for(int i = 0; i < matrixSize; i++){
        cout << "Enter at " << j << " " << k << ": ";
        cin >> matrix[i];
        if(cin.fail()){
          cout << "Invalid Argument | Run Program Again\n";
          exit(1);
        }
        if(k == col){
          j += 1;
          k = 0;
        }
        k++;
      }
    }
    
    //for displaying matrix elements
    void display(){
      for(int i = 0; i < matrixSize; i++){
        if(i != 0 && i % col == 0){
          cout << endl;
        }
        cout << matrix[i] << " ";
      }
      cout << endl;
    }

    //check is square or not
    bool isSquare(){
      return (row == col);
    }

    //is triadiagonal
    bool isTridiagonal(){
      cout << "Order: " << row << "x" << col << endl;
      if(!isSquare()){
        cout << "Not Square | Not Tridiagonal\n";
        return false;
      }
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(i <= 1 && j > i+1 && matrix[(i*col)+j] != 0){
            cout << "Is Not Triadiagonal\n";
            return false;
          }else if(i > 1 && j < i -1 && matrix[(i*col)+j] != 0){
            cout << "Is Not Triadiagonal\n";
            return false;
          }
        }
      }
      cout << "Is Triadiagonal\n";
      return true;
    }

};

int main(){
  MATRIX<int> M(4,4); //object initialization with row and col sizes of a matrix
  M.getElement(); //get elements in matrix 4 x 4
  M.display(); //for displaying matrix
  M.isTridiagonal();
  return 0;
}