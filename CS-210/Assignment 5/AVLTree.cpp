#include "AVLTree.h"
#include "BSTNode.h"
#include "Product.h"
#include "DuplicateKeyException.h"
#include "NoKeyException.h"
#include <iostream>

//////////////////////////////////////////////////////
/* INFORMATION */
// NAME: MAKSIM SHAROIKA
// SID: 200446763
// FILENAME: AVLTree.cpp
// PURPOSE: Implementation of BST and AVLTree functions from header

//////////////////////////////////////////////////////
/* PRIVATE METHODS */

// Function: A1
// Funtion: get(BSTNode* r, int key)
// Input: the root of the subtree, and the key are looking for. 
// Output: the node of a leaf node if not found, or node of key if found.
BSTNode* AVLTree::get(BSTNode* r, int key)
{
  // if subtree is a leaf then we return the subtree root
  if (r->isLeaf())
  {
    return r;
  }
  // otherwise if the key is the one we looking for we return the subtree root
  else if (r->getData()->getKey() == key)
  {
    return r; 
  }
  else
  {
    // if the current node's key is smaller we move to the right
    if (r->getData()->getKey() < key)
    {
      return get(r->getRight(), key);
    }
    // if the current node's key is bigger we move to the left
    else
    {
      return get(r->getLeft(), key);
    }
  }
}

// Function: A2
// Funtion: put(BSTNode* r, Product* prod)
// Input: the root of the subtree, r, and the product onject we are inputting 
// Output: true if put in and sorted, false if failed
bool AVLTree::put(BSTNode* r, Product* prod)
{
  // create a temporary object of location where the corrosponding key would be
  BSTNode* tmp = get(r, prod->getKey());
  // if it exists we return false, it is an existant internal node
  if (tmp->isInternal())
  {
    return false; 
  }
  // otherwise we want to input the data
  else
  {
    // sest the data of temp node to the product
    tmp->setData(prod); 
    // create new nodes to the right and to the left
    tmp->setRight(new BSTNode(tmp));
    tmp->setLeft(new BSTNode(tmp));
    // increment number of of records in the tree
    numRecords++;
    return true; 
  }
}

// Function: A3 
// Funtion: remove(BSTNode* r, int key)
// Input: r the root of the subtree we are removing from, key the key of the object removed
// Output: the location of the node that was deleted
BSTNode* AVLTree::remove(BSTNode* r, int key)
{
  // create a temporary object of location where the corrosponding key would be
  BSTNode* tmp = get(r, key);
  // if the object is a leaf node we didnt find it therefore throw
  if (tmp->isLeaf())
  {
    throw NoKeyException(); 
  }
  else
  {
    // if there is at least one leaf node of the found object
    if (tmp->getRight()->isLeaf() || tmp->getLeft()->isLeaf())
    {
      // create two prime objects one being the parent of the temp object
      BSTNode* p_prime = tmp->getParent();
      BSTNode* c_prime; 
      // if right is a leaf assign the left
      if (tmp->getRight()->isLeaf())
      {
        c_prime = tmp->getLeft();
      }
      else
      // if left is a leaf assign the right
      {
        c_prime = tmp->getRight(); 
      }
      // if the temp onbect is the root we will just change the root to the one under
      if (tmp == root)
      {
        root = c_prime; 
        // set the new roots parent to a nullptr
        c_prime->setParent(nullptr);
        // delete the old object (the one to be deleted)
        delete tmp->getData();
        delete tmp;
      }
      else
      {
        // if it is on the right side of its parent we want to set it to the right
        if (p_prime->getRight() == tmp)
        {
          p_prime->setRight(c_prime);
          c_prime->setParent(p_prime);
          // delete the old object (the one to be deleted)
          delete tmp->getData();
          delete tmp;
        }
        // otherwise it must be on the left side of the parent we want to set it to the left
        else
        {
          p_prime->setLeft(c_prime);
          c_prime->setParent(p_prime);
          // delete the old object (the one to be deleted)
          delete tmp->getData();
          delete tmp;
        }
      }
      // we want to decrement the number of record because we deleted some
      numRecords--;
      // return the location of c_prime
      return c_prime; 
    }
    else
    {
      // otherwise there may be no leafs therefore we pick the smallest of the right
      BSTNode* s = smallest(tmp->getRight()); 
      // we make a temporary object with all the attributes of the smallest one
      Product* tmp_product;
      // we then create a product pointer with the correct attributes 
      tmp_product = new Product; 
      tmp_product->setKey((s->getData()->getKey()));
      tmp_product->setName((s->getData()->getName()));
      tmp_product->setQuantity((s->getData()->getQuantity()));
      // we put the temporary object at the temporary node we found earlier (where key is)
      tmp->setData(tmp_product);
      // we would recursibly call remove at the node we just copied over so no duplicates arise
      return remove(s, s->getData()->getKey());
    }
  }
}

// Function: A4 
// Funtion: smallest(BSTNode* r)
// Input: r the root of the subtree we are requesting small of
// Output: position of the smallest key value in the subtree, nullptr is doesnt exist
BSTNode* AVLTree::smallest(BSTNode* r)
{
  // if r is a leafnode
	if (r->isLeaf())
  {
    // there is no data therefore return nullptr
    return nullptr;
  }
	else
	{
    // otherwise make a temp object equal to r
		BSTNode* tmp;
    tmp = r;
    // keep going to the left of the temp object until we hit a leaf
		while (tmp->isInternal())
		{
			tmp = tmp->getLeft();
		}
    // go up 1 parent and we have the smallest object in the subtree
		return tmp->getParent();
	}
}

// Funtion: A5
// Funtion: sortRec(BSTNode* r, std::vector<Product*>& sortedList)
// Input: the root of the subtree we are trying to sort r, and a vector of the product objects
// Output: a softed vector (in order) of the objects in the tree
void AVLTree::sortRec(BSTNode* r, std::vector<Product*>& sortedList)
{
  // if r is internal its safe to sort it
  if (r->isInternal())
  {
    // we will use a inorder recursive call
    sortRec(r->getLeft(), sortedList);
    // push back the farthest left and work my way to the right
    sortedList.push_back(r->getData());
    // pushed call right
    sortRec(r->getRight(), sortedList);
  }
}

// Funtion: A6
// Funtion: highestQuantityRec(BSTNode* r)
// Input: the root of the subtree r, we are trying to find the item with the highest quantity
// Output: 
Product* AVLTree::highestQuantityRec(BSTNode* r)
{
  // if r is a leaf, we want to call a nnullptr
  if (r->isLeaf())
  {
    return nullptr; 
  }
  // make two temporary products A and B of the left and right of the node
  // then call the highest quantity on them and itll return with the highest of each node
  Product* A = highestQuantityRec(r->getLeft());
  Product* B = highestQuantityRec(r->getRight());
  // if A is a nullptr but B is not a nullptr
  if (A == nullptr && B!=nullptr)
  {
    // the quantity at B is larger then the quantity are R then return B
    if (B->getQuantity() > r->getData()->getQuantity())
      return B;
    else
      // otherwise we want to return r
      return r->getData();
  }
  // if B is a nullptr but A is not a nullptr
  else if (A!=nullptr && B==nullptr)
  {
    // the quantity at A is larger then the quantity are R then return B
    if (A->getQuantity() > r->getData()->getQuantity())
      return A;
    else
      // otherwise we want to return r
      return r->getData();
  }
    // if both pointers are not null pointers
  else if (A!=nullptr && B!=nullptr)
  {
    Product* tmp;
    // we want to find out is B or A quantity is bigger and then set tmp pointer to the bigger
    if (A->getQuantity() > B->getQuantity())
    {
      tmp = A; 
    }
    else
    {
      tmp = B; 
    }
    // then the temp object is compared against the root of the calling objects size
    if (tmp->getQuantity() > r->getData()->getQuantity())
      // return tmp if its bigger
      return tmp; 
    else
      // return the root data object if it is bigger
      return r->getData(); 
  }
  else
  {
    // if we both of the children are leafs then we just return the quantity of the parent
    return r->getData(); 
  }
}

// Funtion: A7
// Funtion: deleteTree(BSTNode* r)
// Input: the root of the subtree r, that we are trying to delete the nodes of 
// Output: the memory should be cleared and the tree should be delete
void AVLTree::deleteTree(BSTNode* r)
{
  // if r is a leaf node
  if (r->isLeaf())
  {
    // delete r and set the pointer to a nullptr
    delete r; 
    r = nullptr; 
  }
  // otherwise it must be an internal node
  else
  {
    // call delete on both side of the internal node to continue deletion
    deleteTree(r->getLeft());
    deleteTree(r->getRight());
    // delete r, its data and set the pointer to a nullptr
    delete r->getData(); 
    delete r; 
    r = nullptr;
  }
}

//////////////////////////////////////////////////////
/* PUBLIC METHODS */

// Funtion: B1
// Funtion: AVLTree()
// Input: constructor for a tree
// Output: a tree object with a empty Product root and a number of records of -
AVLTree::AVLTree()
{
  // set the root to a new node and the numrecord to 0
	root = new BSTNode();
	numRecords = 0;
}

// Funtion: B2
// Funtion: ~AVLTree()
// Input: a destructor for a tree
// Output: will call the delete tree function with the root of the tree and clear memory 
AVLTree::~AVLTree()
{
  // delete the AVL tree starting at the main root
	deleteTree(root);
}

// Funtion: B3
// Funtion: get(int key)
// Input: the key of the product you are looking for 
// Output: fill output the product pointer with that key
Product* AVLTree::get(int key)
{
  // create a temp object and run the get function on it
  BSTNode* tmp; 
  tmp = get(root, key);
  // if its a leaf we did not find it and therefore return a nullptr
  if (tmp->isLeaf())
  {
    return nullptr;
  }
  // otherwise we did find it and therefore would return the data of the node with key  
  else
  {
    return tmp->getData(); 
  }
}

// Funtion: B4
// Funtion: put(Product* prod)
// Input: the product we are inputing into our tree
// Output: no output, but the product is added to our tree if it is not a duplicate
void AVLTree::put(Product* prod)
{
  // if the put command does not return true then we would throw a no key exception
	if (!(put(root, prod) == true))
  {
		throw DuplicateKeyException();
  }
}

// Funtion: B5
// Funtion: remove(int key)
// Input: the key we of the product we are trying to remove from the tree
// Output: no output, but the product object would be removed from a node in tree, if found
void AVLTree::remove(int key)
{
  // call the remove fuction with the root of the tree and the key 
	remove(root, key);
}

// Funtion: B6
// Funtion: smallest()
// Input: nothing we are looking for smallest in the whole tree not subtree
// Output: we would find and return the product with the smallest key
Product* AVLTree::smallest()
{
  // make a tmp node and request the smallest from the root
	BSTNode* tmp = smallest(root);
  // if it return nullptr we didnt find it therefore we want to return a nullptr
  if (tmp == nullptr)
  {
    return nullptr;
  }
  // otherwise we did find it and want to return the data object of that node
  else
  {
    return tmp ->getData();
  }
}

// Funtion: B7
// Funtion: size()
// Input: nothing, it has the tree object
// Output: the number of records present in the tree
int AVLTree::size()
{
  // return the integer numberofrecords
  return numRecords; 
}

// Funtion: B8
// Funtion: isEmpty()
// Input: true if the tree is empty, false if the tree is not empty
// Output:
bool AVLTree::isEmpty()
{
  // if the tree had exactly 0 records it must be empty, return tree
  if (numRecords == 0)
  {
    return true;
  }
  // otherwise the tree has to have records in it
  else
  {
    return false; 
  }
}

// Funtion: B9
// Funtion: AVLTree::treeSort()
// Input: the public function for the sort already had the root of the tree
// Output: a sorted vector from the smallest key value to the largest
std::vector<Product*> AVLTree::treeSort()
{
  // create a temp vector called List
  std::vector<Product*> List;
  // call the sort function from the root into List
  sortRec(root, List);
  // return the vector of List
  return List;
}

// Funtion: B10
// Funtion: highestQuantity()
// Input: the root is alread avialable to this function, no input
// Output: the product pointer with the highest quantity assigned to it
Product* AVLTree::highestQuantity()
{
  // call the highest quantity function and return the largest quantity in the tree
  return highestQuantityRec(root);
}

// Funtion: B11
// Funtion: updateProductName(int key, std::string newName)
// Input: the key of the product and the new name of it
// Output: the product will have its old name removed, and a new one placed
void AVLTree::updateProductName(int key, std::string newName)
{
  // make a temp object and run a get command to try and find the correct product pointer
  BSTNode* tmp;
  tmp = get(root, key);
  // if we are an internal node then we found it
  if (tmp->isInternal())
  {
    // we want to set the nodes product name to the new name given
    tmp->getData()->setName(newName);
  }
}

//////////////////////////////////////////////////////
/* GIVEN METHODS */

// Funtion: C1
// Funtion:
// Input:
// Output:
void AVLTree::printLevelOrderKeys()
{
	std::queue<BSTNode*> treeQueue;
	treeQueue.push(root);
	std::cout << "[";
	while (!treeQueue.empty()) {
		BSTNode* node = treeQueue.front();//get the element at the front of queue
		if (node->getData() == nullptr) {
			std::cout << "[null]";
		}
		else {
			std::cout << "[" << std::to_string(node->getData()->getKey()) << "]";
		}
		treeQueue.pop();//removes first element (in a queue)
		if (node->getLeft() != nullptr) {
			treeQueue.push(node->getLeft());//enqueue left
		}
		if (node->getRight() != nullptr) {
			treeQueue.push(node->getRight());//enqueue right
		}
	}//while there is still a node
	std::cout << "]" << std::endl;
}

//////////////////////////////////////////////////////
/* AVL PRIVATE METHODS */

// Funtion: D1
// Funtion: taller(BSTNode* x, bool onLeft)
// Input: the child we are comparing and if it is on the left of the parent
// Output: the node pointer of the taller (bigger height) node
BSTNode* AVLTree::taller(BSTNode* x, bool onLeft)
{
  // if the height of the right node is larger then the left node
  if (x->getRight()->getHeight() > x->getLeft()->getHeight())
  {
    // return the node to the right
    return x->getRight();
  }
  // if the height of the left node is larger then the right node
  else if (x->getRight()->getHeight() < x->getLeft()->getHeight())
  {
    // return the node to the left
    return x->getLeft();
  }
  // otherwise they are equal to we choose to the left
  else
  {
    // if it is on the left then we get the child left of x
    if (onLeft == true)
    {
      return x->getLeft();
    }
    // if it is not the left then we get the child right of x
    else
    {
      return x->getRight();
    }
  }
}

// Funtion: D2
// Funtion: rotate(BSTNode* x)
// Input: the node x which we are trying to perform the rotation at
// Output: a rotated tree at the correct location
BSTNode* AVLTree::rotate(BSTNode* x)
{
  // if x is on the left side of the parent
  if (x->getParent()->getLeft() == x)
  {
    // get the grandparent of x
    BSTNode* p = x->getParent()->getParent();
    // x is not on the left as a base
    bool onLeft = false;
    // make sure the parent is not null
    if (p != nullptr)
    {
      // then check if x is on the left of the parent if so set the left bool to true
      if (p->getLeft() == x->getParent())
      {
        onLeft = true;
      }
    }
    // get the parent of x then set its left to the x's right
    x->getParent()->setLeft(x->getRight());
    // set the x's right to the parent of x
    x->setRight(x->getParent()); 
    // then we set the parents parent to x
    x->getParent()->setParent(x);
    // then we set x's parent to the grandparent from the p object
    x->setParent(p);
    // of p is not a bull ptr
    if (p != nullptr)
    {
      // if it is on the left
      if (onLeft)
      {
        // we set x to the left of the grandparent
        p->setLeft(x);
      }
      else
      {
        // otherwise we would set x to the right of the grandparent
        p->setRight(x);
      }
    }
    // then we want to cleanup the parent of the original child of x to the right parent
    x->getRight()->getLeft()->setParent(x->getRight());
    // recompute the height of the two nodes that were rotated
    recomputeHeight(x->getRight());
    recomputeHeight(x);
    // return the moved node which is x
    return x;
  }
  // otherwise it must be on the right side of the parent
  else
  {
    // get the grandparent of x and hold it in a temp pointer of p
    BSTNode* p = x->getParent()->getParent();
    // set the on the right to false to begin with
    bool onRight = false;
    // if the grandparent pointer is not null
    if (p != nullptr)
    {
      // if x is on the right of it parent 
      if (p->getRight() == x->getParent())
      {
        // set the bool on right to true
        onRight = true;
      }
    }
    // get the parent of x then set its right to the x's right
    x->getParent()->setRight(x->getLeft());
    // set the x's left to the parent of x
    x->setLeft(x->getParent()); 
    // then we set the parents parent to x
    x->getParent()->setParent(x);
    // set the parent of x to the grandfather from before
    x->setParent(p);
    // if the grandfather is not a nullptr
    if (p != nullptr)
    {
      if (onRight)
      {
        // we want to set x to the right of the grandfather is on right
        p->setRight(x);
      }
      else
      {
        // otherwise x is on the left therefore we set it accordigly
        p->setLeft(x);
      }
    }
    // then we cleanup the parent of the original node of x
    x->getLeft()->getRight()->setParent(x->getLeft());
    // recompute the height of the two nodes that were rotated
    recomputeHeight(x->getLeft());
    recomputeHeight(x);
    // then we want to return the position of the moved node (i.e x)
    return x; 
  }
}

// Funtion: D3
// Funtion: rotation(BSTNode* z, BSTNode* y, BSTNode* x)
// Input: the location of 3 subsequent nodes with an inbalance occuring with them z > y > x
// Output: the sorted tree using an RL or LR or LL or RR rotation
BSTNode* AVLTree::rotation(BSTNode* z, BSTNode* y, BSTNode* x)
{
  // if z and x are requiring an RR or LL rotation then this is true
  if (z->getRight()->getRight() == x || z->getLeft()->getLeft() == x)
  {
    // call the rotate function at y that will fix the inblanace
    rotate(y);
    // then we want to recompute the heights of z, x, and y in that exact order
    recomputeHeight(z);
    recomputeHeight(x);
    recomputeHeight(y);
    // we return y due to it being the root of the current subtree
    return y; 
  }
  // if z and x are requiring an RL or LR rotation then this is true
  else
  {
    // call the rotate function at x twice to get it in the position of the root of subtree
    rotate(x);
    rotate(x);
    // then we want to recompute the heights of z, x, and y in that exact order
    recomputeHeight(z);
    recomputeHeight(y);
    recomputeHeight(x);
    // we return x due to it being the root of the current subtree
    return x; 
  }
}

// Funtion: D4
// Funtion: recomputeHeight(BSTNode* p) 
// Input: we want to input p the pointer at which we want to recompute the height
// Output: the height of that node will be updated correctly
void AVLTree::recomputeHeight(BSTNode* p) //update the height of node p.
{
  // if p is an internal node (not a leaf node)
	if (p->isInternal())
  {
    // we find hegihts of children then add one
    p->setHeight(1+std::max(p->getLeft()->getHeight(), p->getRight()->getHeight()));
  }
    // otherwise it is a leafnode
  else
  {
    // we want all leaf nodes to always have a height of 0 
    p->setHeight(0);
  }
}

// Funtion: D5
// Funtion: rebalanceAVL(BSTNode* v)
// Input: this would have a node v the root of the subtree we are rebalancing
// Output: the subtree would be rebalanced and sorted correctly 
void AVLTree::rebalanceAVL(BSTNode* v)
{
  // if the subtree root is an internal node
  if (v->isInternal())
  {
    // rewant to recompute its height
    recomputeHeight(v);
  }
  // then while the subtree node is not the root (move upwards)
  while (v != root)
  {
    // get the parent of v and assign it to ve
    v = v->getParent(); 
    // if the difference of both childrens heights is more than 1 (absolute value)
    if (abs(v->getLeft()->getHeight() - v->getRight()->getHeight()) > 1)
    {
      // we create two temporary pointers to help with calls
      BSTNode* x;
      BSTNode* y; 
      // if the one on the left was great then the one on the right
      if (v->getLeft()->getHeight() > v->getRight()->getHeight())
      {
        // then we want to set y to the one of the left
        y = v->getLeft();
      }
      else
      {
        // otherwise we want to set y to the one on the right
        y = v->getRight();
      }
      // if x is to the left of y 
      if (y->getParent()->getLeft() == y)
      {
        // we want to set x to the taller child with on the left bool being true
        x = taller(y, true);
      }
      else
      {
        // otheerwise we want to set k to the taller child with on the left bool being false
        x = taller(y, false);
      }
      // then we would perform a rotation with v = z and the other two parameters having same name
      v = rotation(v, y, x);
      // if the root was modified we want to set the new root to returned v
      if (root->getParent() != nullptr)
      {
        // set the root
        root = v;
      }
    }
    // recompute height of the new v is it is adjusted
    recomputeHeight(v);
  }
}


//////////////////////////////////////////////////////
/* AVL PUBLIC METHODS */

// Funtion: E1
// Funtion: putAVL(Product* prod) 
// Input: the product we are inputting into the avl tree
// Output: a sorted AVLTree with the new product
void AVLTree::putAVL(Product* prod)
{
  // if the put is not true
	if (!(put(root, prod) == true))
  {
    // we want to throw the duplicate key exception, it failed to put
    throw DuplicateKeyException();
  }
  // set a temp object and find the location of the inputted product
	BSTNode* tmp;
  tmp = get(root, prod->getKey());
  // then run rebalance on that location to make sure the AVL properties are kept
	rebalanceAVL(tmp);
}

// Funtion: E2
// Funtion: removeAVL(int key) 
// Input: the key of that we want to remove from the AVL tree
// Output: a sorted AVLTree with the product with that key removed
void AVLTree::removeAVL(int key)
{
  // make a temp object and set it to the position of the removed key
  BSTNode* tmp;
  tmp = remove(root, key);
  // reblaance at that position to make sure AVLTree holds onto its properties
  rebalanceAVL(tmp); 
}