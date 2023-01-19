// FILE FOR EDITING

#include "LinkedStack.h"

// class implementations for the linkedstack ADT 
// by: MAKSIM SHAROIKA

//Constructor (sets top to nullptr and count=0)
LinkedStack::LinkedStack()
{
  // setting the top pointer to null since no elements exist in the list yet
  top = nullptr; 
  // setting the count to 0 since no elements exist in the list yet
  count = 0; 
}

//Deconstructor (deletes each node in the linked list)
LinkedStack::~LinkedStack()
{
  // creating a temporary pointer node to work with
  TileNode* temp;
  // while top is not a null pointer, and we are not on the last node
  while (top != nullptr && top->getNext() != nullptr)
  {
    // set temp to the top pointer node
    temp = top; 
    // move top to the next node
    top = top->getNext();
    // delete the temp node
    delete temp; 
    // decrement the count by one because we just deleted a tile node
    count--; 
  }
  // delete the last top node if there is one left if there isnt
  // left this just clears anything if there is anything there for good measure 
  delete top;
  // set the top pointer to null so it is not pointing to anything random
  top = nullptr; 
  // set the count pointer to 0 because the stack is deleted 
  count = 0;
}

//push make a new node, insert at the head of the linked list with elem in it (top of the stack).
void LinkedStack::push(Tile* elem)
{
  // creating a temporary pointer node to work with
  TileNode* temp;
  // allocating dynamic memory and settingp oint to that location 
  temp = new TileNode(elem);  
  // if there no notes the new node bcomes the top of the stack
  if (count == 0)
  {
    // set the top pointer to the current new "temp" pointer 
    top = temp; 
  }
  // if there are already elements in the stack
  else
  {
    // set the temp elements next attribute to the current top pointer location
    temp->setNext(top);
    // set the top location to our new pointers location
    top = temp;
    // this effectivly pushes the the dyanmically allocated node 
    // at temp to the top of the stack 
  }
  // regardless a new node has been created therefore increment count
  count++; 
}

//pop the stack: remove the first node in the linked list, return its data.  If the stack is empty, return nullptr.
Tile* LinkedStack::pop()
{
  // if there are no nodes we cannot pop
  if (count == 0)
  { 
    // we return a null pointer because it does not exist 
    return nullptr; 
  }
  else
  {
    // create a temporary node pointer 
    TileNode* temp; 
    // create a temporary data tile pointer and save the current tops data in it
    Tile* data = (top->getData()); 
    // if there is only one node in the stack
    if (count == 1)
    {
      // delete the contents of the top nodes, it was saved beforehand
      delete top; 
      // set the top node to a nullptr
      top = nullptr; 
    }
    // otherwise
    else
    {
      // set the temp pointer to the send element in the stack
      temp = (top->getNext());
      // delete the current content of top (the node we are popping)
      delete top; 
      // set the top to the temp which was the second node in the stack
      top = temp; 
      // this effectivly pops the top elements of the stack and saves its data 
    }
    // regardless a node has been deleted therefore decrement count
    count--;
    // return the data that was saved from the delete node
    return data;
  }
}

//return the top element of the stack, do not remove the node that has the top element.
Tile* LinkedStack::peek()
{
  // if there are no elements in the stacj
  if (count == 0)
  {
    // return a null pointer
    return nullptr;
  }
  // if there are elements in the stack
  else
  {
    // returns the top pointer's data
    return top->getData();    
  }
}

//return the number of elements in the stack
int LinkedStack::size()
{
  // returns the current count / number of elements of the stack
  return count;
}

//is the stack empty?
bool LinkedStack::isEmpty()
{
  if (count == 0)
  {
    // if there are no elements in the stack i.e 0 it is true
    return true;
  }
  else 
  {
    // if there are elements in the stack (not 0) then return false
    return false;
  }
}
