#include <iostream>
#include <fstream>
#include <string>
//include .h file in every file
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  BST b1, b1copy;
  BST b2, b2copy;
  while (getline (cardFile1, line) && (line.length() > 0))
  {
    string str = line;
    int pos = str.find(" ");
    char suit = str[pos-1];
    string value = str.substr(pos+1);
    int valueofcard = 0;
    if (value == "a")
    {
      valueofcard = 1;
    }
    else if (value == "j")
    {
      valueofcard = 11;
    }
    else if (value == "q")
    {
      valueofcard = 12;
    }
    else if (value == "k")
    {
      valueofcard = 13;
    }
    else
    {
      valueofcard = stoi(value);
    }
    //cout << "j";
    Card c1 = Card(suit, valueofcard);
    if (!b1.root)
    {
      b1.insert(c1);
      b1copy.insert(c1);
    }
    else
    {
      b1.insert(c1, b1.root);
      b1copy.insert(c1, b1copy.root);
    }
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    string str = line;
    int pos = str.find(" ");
    char suit = str[pos-1];
    string value = str.substr(pos+1);
    int valueofcard = 0;
    if (value == "a")
    {
      valueofcard = 1;
    }
    else if (value == "j")
    {
      valueofcard = 11;
    }
    else if (value == "q")
    {
      valueofcard = 12;
    }
    else if (value == "k")
    {
      valueofcard = 13;
    }
    else
    {
      valueofcard = stoi(value);
    }
    Card c2 = Card(suit, valueofcard);
    if (!b2.root)
    {
      b2.insert(c2);
      b2copy.insert(c2);
    }
    else
    {
      b2.insert(c2, b2.root);
      b2copy.insert(c2, b2copy.root);
    }
  }

int count = 1;
while(count != 0)
{
  //Alice turn
  if ((count % 2) == 1)
  {
    //if b1 and b2 are not empty.
    if (b1.root != nullptr && b2.root != nullptr)
    {
      BST::Node* min = b1.findmin(b1.root);
      BST::Node* j1 = b1.getNodeFor(b1.root, min -> card);
      BST::Node* j2 = b2.getNodeFor(b2.root, min -> card);
      while (!(j1 && j2) && (b1copy.root != nullptr))
      {
        //b1copy.remove(min -> card);
        //min = b1copy.findmin(b1copy.root);
        min = b1.getSuccessorNode(min->card);
        j1 = b1.getNodeFor(b1.root, min -> card);
        j2 = b2.getNodeFor(b2.root, min -> card);
      }
      if (j1 && j2)
      {
        cout << "Alice picked matching card ";
        (min -> card).printCard();
        cout << endl;
        b1.remove(j1 -> card);
        b2.remove(j2 -> card);
        //cout << "removed";
      }
      else
      {
        cout << "Alice's cards: " << endl;
        b1.printInOrder();
        cout << endl;
        cout << "Bob's cards: " << endl; 
        b2.printInOrder();
        break;
      }
      count = count + 1;
    }
    else
    {
      cout << "Alice's cards: ";
      cout << "Bob's cards: ";
      break;
    }
  }
//Bob turn
//declare a variable inside a block then I cannot use it outside the block
  else
  {
    if (b1.root != nullptr && b2.root != nullptr)
    {
      BST::Node* max = b2.findmax(b2.root);
      BST::Node* w2 = b2.getNodeFor(b2.root, max -> card);
      BST::Node* w1 = b1.getNodeFor(b1.root, max -> card);
      while (!(w1 && w2) && b2copy.root != nullptr)
      {
        //(max->card).printCard();
        //b2copy.remove(max -> card);
        //max = b2copy.findmax(b2copy.root);
        max = b2.getPredecessorNode(max->card);
        w2 = b2.getNodeFor(b2.root, max -> card);
        w1 = b1.getNodeFor(b1.root, max -> card);
      }
      if (w1 && w2)
      {
        cout << "Bob picked matching card ";
        (max -> card).printCard();
        cout << endl;
        b1.remove(w1 -> card);
        b2.remove(w2 -> card);
      }
      else
      {
        cout << "Alice's cards: ";
        b1.printInOrder();
        cout << "Bob's cards: ";
        b2.printInOrder();
        break;
      }
      count = count + 1;
    }
    else
    {
      cout << "Alice's cards: ";
      cout << "Bob's cards: ";
      break;
    }
  }
}
  return 0;
}
