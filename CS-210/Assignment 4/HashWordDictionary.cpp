#include "HashWordDictionary.h"
#include "DuplicateKeyException.h"
#include <string>
#include <cmath>

/*

    COMPLETED
    NAME: Maksim Sharoika
    SID: 200446763

*/

/* Implementing Private Methods */
// A polynomial hash code function using Horner's Method 
int HashWordDictionary::hashFunction(std::string input)
{
  // our function presumes it is not empty so we check before hashing
  if (input.empty())
  {
    // if it is empty we return 0
    return 0; 
  }
  // we use an int seed value of 33 creates very large numbers
  int result = 0; 
  // we loop through the string and perform the hash calculation
  for (int i = 0; i < input.length(); i++)
    {
      // we keep adding to the result and multiplying for 33
      result = ((result*33) + (input[i])) % M();
    }
  // we use a remainder function (for doubles) to get the remainder
  result = result % M();
  // then the result is returned between 0 and size of table
  return result;
}


/* Implementing Public Methods */
// default constructor 
HashWordDictionary::HashWordDictionary()
{
  // creates an array of WordNode pointers (our table)
  table = new WordNode*[tableSize];
  for (int i = 0; i < tableSize; i++)
    {
      // for all positions in the table set it to a nullptr
      table[i] = nullptr; 
    }
  // set the number of elements to 0
  numElem = 0;
}


// constructor with input for the table size
HashWordDictionary::HashWordDictionary(int M)
{
  // sets the objects tableSize to the provided one
  tableSize = M; 
  // creates an array of WordNode pointers (our table)
  table = new WordNode*[tableSize];
  for (int i = 0; i < tableSize; i++)
    {
      // for all positions in the table set it to a nullptr
      table[i] = nullptr; 
    }
  numElem = 0;
  // set the number of elements to 0
}


// deconstructor for the class
HashWordDictionary::~HashWordDictionary()
{
  for (int i = 0; i < M(); i++)
    {
      // set the current node to the head of the linked list
      WordNode* current = table[i];
      // create a next pointer of WordNode
      WordNode* next = nullptr;
      // while we are not at the end of the linked list
      while (current != nullptr)
      {
        // go to the next node in the linked list
        next = current->getNext();
        // delete the current node
        delete current;
        // set the current node to the next one
        current = next;
      }
      // set the head of the linked list to a null pointer
      table[i] = nullptr; 
    }
}


// put operation with seperate chaining inserts records into our dictionary
void HashWordDictionary::put(WordData* word)
{
  // use the hash function to compute position into the table, 
  // and set that poisition to pointer p
  WordNode* p = table[hashFunction(word->keyString())];
  if (p == nullptr)
  {
    // if the pointer is null we can create a new node at the head of the linked list
    table[hashFunction(word->keyString())] = new WordNode(word);
    numElem++;
  }
  else
  {
    // scan through the linked list untill we find the same word 
    // or we get to the end of the list
    while (p->getNext() != nullptr && p->getData()->getKey() != word->getKey())
      {
        // each time we want to go to the next node in the linked list
        p = p->getNext();
      }
    // if once we get out of the loop the word we have and the node we found have the same key
    if (p->getData()->getKey() == word->getKey())
    {
      // then we want to increment the frequency of that word
      p->getData()->setValue(p->getData()->getValue()+1);
      // and we throw the Diplicate Key Exception
      throw DuplicateKeyException(); 
    }
    else
    {
      // otherwise we are at the end of the linked list and make a new record
      p->setNext(new WordNode(word));
      // then we increment the number of extra elements
      numElem++;
    }
  }
}


// return the WordData object that has the same key as the parameter if none, return nullptr
WordData* HashWordDictionary::get(std::string key)
{
  // create a pointer at the hashed location in the table
  WordNode* p = table[hashFunction(key)];
  if (p == nullptr)
  {
    // if it is a nullptr there is nothing there therefore return nullptr
    return nullptr; 
  }
  else if (p->getData()->keyString() == key)
  {
    // otherwise search the data of that pointer to see if it is the key
    return p->getData();
    // if it is the key we want to return that WordData object 
  }
  else
  {
    // if niether we want to go through the linked list and search for the same key
    while (p->getNext() != nullptr &&
      p->getData()->keyString() != key)
      {
        // we search until the end of the linked list or until we find the key
        p = p->getNext(); 
        // each time go to the next node
      }
    if (p->getData()->keyString() == key)
      // we if the loop ended we check for the keys if they are the same 
      // we want to return the WordData item we found
      return p->getData(); 
  }
  // otherwise we did not find the WordData item with the same ket and return nullptr
  return nullptr; 
}


// creates a vector that has all the records in the dictionary in it
std::vector<WordData*> HashWordDictionary::listRecords()
{ 
  std::vector<WordData*> recordList; 
  // we create a vector with WordData and the name of recordlist 
  for (int i = 0; i < M(); i++)
  {
    // from the begining of the table to the end
    WordNode* p = table[i];
    // set a pointer to the "head" of a linked list (if it exists)
    if (table[i] == nullptr)
      // if the "head" is a nullptr there is no list we move on to next iteration
      continue;
    // otherwise there is a WordData item so we add it to the vector
    recordList.push_back(table[i]->getData());
    // while we are not at the end of the linked list
    while (p->getNext() != nullptr)
      {
        // keep going to the next item
        p = p->getNext();
        // and keep adding it to the vector
        recordList.push_back(p->getData());
      }
    }
  // once we have gone through the entire table we return the vector 
  return recordList; 
}


// return the number of records in the dictionary 
int HashWordDictionary::size()
{ 
  // return the number of records created in the dictionary
  return numElem; 
}


// return the table size (it is set and adjusted by a constructor earlier)
int HashWordDictionary::M()
{
  // return the table size to the calling function
  return tableSize;
}


// method to check if our table is empty (dictionary is empty)
bool HashWordDictionary::isEmpty()
{
  // if there are no elements it is empty
  if (numElem == 0)
    return true;
  else 
    // if there us more than 0, x >= 1 elements it is not empty
    return false;
}
