// FILE FOR EDITING

// inluding the header files related to these implementations
#include "Tile.h"
#include "TileNode.h"

// class implementations for the tile node header file
// by: MAKSIM SHAROIKA

//constructor
TileNode::TileNode(Tile* d)
{
  // takes the provided tile node d and sets it to the classes data attribute
  data = d; 
  // sets the data attribute to nullptr so it does not point to a random piece of memory
  next = nullptr; 
}

//get the data of the node.
Tile* TileNode::getData()
{
  // return the data attribute 
  return data; 
}

//get the next node in the linked list
TileNode* TileNode::getNext()
{
  // return the next attribute of the code
  return next; 
}

//set the data for the node
void TileNode::setData(Tile* newData)
{
  // updating the data attribute of the nose to provided newData
  data = newData; 
}

//set the next node
void TileNode::setNext(TileNode* newNext)
{
  // updating the next attribute of the nose to provided newData
  next = newNext; 
}