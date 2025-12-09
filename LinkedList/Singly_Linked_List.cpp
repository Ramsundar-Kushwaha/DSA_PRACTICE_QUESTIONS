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
  //destructor for freeing memory
  ~SINGLY_LINKED_LIST(){
    Node* ptr = head;
    while(head != NULL){
      ptr = head->next;
      delete head;
      head = ptr;
    }
  }

  //is empty linked list
  bool isEmpty(){
    return (head == NULL);
  }
  //count node
  int nodeCount(){
    int count = 0;
    if(isEmpty()){
      return 0;
    }
    Node* ptr = head;
    while(ptr != NULL){
      ptr = ptr->next;
      count++;
    }
    return count;
  }

  //insertion at beginning
  void insertAtBeginning(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(int);
  void insertAt(int, int);
  void reverseDisplay(Node*);
  void reverseOriginal();
  void display(bool reverse = false);
};

//display Linded List
void SINGLY_LINKED_LIST::display(bool reverse){
   Node* ptr = head;
   if(reverse){
    reverseDisplay(ptr);
  }else{
    while(ptr != NULL){
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }
  cout << endl;
}

//reverse display
void SINGLY_LINKED_LIST::reverseDisplay(Node* ptr){
  if(ptr == NULL){return;}
  reverseDisplay(ptr->next);
  cout << ptr->data << " ";
}

//itrative reverse display
void SINGLY_LINKED_LIST::reverseOriginal(){
  if(this->isEmpty()){cout << "Empty Linked List\n"; return;} // if linked list is empty
  if(head->next == NULL){cout << "Only One Node\n"; return;} //if there is only one node

  Node* prev = head;
  Node* curr = head->next;
  head->next = NULL;

  while(curr != NULL){
    Node* nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  head = prev;
}

//insertion at end
void SINGLY_LINKED_LIST::insertAtEnd(int value){
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;

  //if list is empty
  if(isEmpty()){
    head = newNode;
    return;
  }

  Node* ptr = head;
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  ptr->next = newNode;
}

//insertion at middle at given position
void SINGLY_LINKED_LIST::insertAt(int position, int value){
  Node* ptr = head;
  if(position <= 0){
    cout << "0th and Negative Index Not Allowed\n";
    return;
  }
  else if(position == 1){
    insertAtBeginning(value);
    return;
  }

  int i = 1;
  while(ptr != NULL && i < position-1){
    ptr = ptr->next;
    i++;
  }

  if(ptr == NULL){
    cout << "Position Out Of Index\n";
    return;
  }

  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = ptr->next;
  ptr->next = newNode;
}

int main(){
  SINGLY_LINKED_LIST S;
  S.insertAtEnd(2);
  S.insertAtEnd(3);
  S.insertAtEnd(4);
  S.insertAtEnd(5);
  S.insertAtEnd(6);
  S.display();

  S.insertAtBeginning(1);
  S.display();

  S.insertAt(3, 7);
  S.display();

  S.insertAt(8, 8);
  S.display();
  
  S.insertAt(10, 10);
  S.display();

  S.insertAt(0,100);
  S.display();

  cout << "size of node " << S.nodeCount() << endl;
  S.display(true);
  S.display();
  S.reverseOriginal();
  S.display();
  S.display();
  S.reverseOriginal();
  S.display();
  return 0;
}