#include <iostream>
using namespace std;

class SINGLY_LINKED_LIST{
  private:
    struct node{
      int data;
      struct node* next;
    };

    typedef struct node Node;
    Node* head = NULL;

  public:
    //insertion at beginning
    void insertAtBeginning(int value){
      Node* newNode = new Node;
      newNode->data = value;
      newNode->next = head;
      head = newNode;
    }

    //insertion at end
    void insertAtEnd(int value){
      Node* newNode = new Node;
      newNode->data = value;
      newNode->next = NULL;

      //if list is empty
      if(head == NULL){
        head = newNode;
        return;
      }

      Node* ptr = head;
      while(ptr->next != NULL){
        ptr = ptr->next;
      }
      ptr->next = newNode;
    }

    //display Linded List
    void display(){
      Node* ptr = head;
      while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
      }
      ptr = nullptr;
    }

    //destructor for freeing memory
    ~SINGLY_LINKED_LIST(){
      cout << "\nMemory Freed";
      Node* ptr = head;
      while(head != NULL){
        ptr = head->next;
        delete head;
        head = ptr;
      }
    }
};

int main(){
  SINGLY_LINKED_LIST S;
  S.insertAtEnd(2);
  S.insertAtEnd(3);
  S.insertAtEnd(4);
  S.insertAtEnd(5);
  S.insertAtEnd(6);
  S.insertAtBeginning(1);
  S.display();
  return 0;
}