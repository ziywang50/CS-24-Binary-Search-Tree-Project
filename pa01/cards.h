//cards.h
//Authors: Your name and your partner's name
//All class declarations go here
#include <iostream>
#include <fstream>
#include <string>
#ifndef CARDS_H
#define CARDS_H

class Card
{
private:
    char suit;
    int value;
public:
    Card();
    Card(char suit, int value);
    //as a member operator must take exactly one argument.
    bool operator> (Card const& c1);
    bool operator== (Card const& c1);
    bool operator< (Card const& c1);
    Card& operator= (Card const& c1);
    char getsuit();
    void setsuit(char c);
    int getvalue();
    void setvalue(int i);
    void printCard();
};

class BST
{
public:
    struct Node{
        Card card;
        Node *left, *right, *parent;
        //how to give a default value of a card?
        Node(Card cardone) : card(cardone), left(0), right(0), parent(0) { }
    };
    Node* root;
    BST();
    bool insert(Card& cardinsert);
    bool insert(Card& cardinsert, Node* r);
    BST::Node* findmax(Node* r);
    BST::Node* findmin(Node* r);
    BST::Node* getNodeFor(Node* r, Card& cardc);
    BST::Node* getSuccessorNode(Card& c1);
    BST::Node* getPredecessorNode(Card& c1);
    Card getSuccessor(Card& c1);
    bool remove(Card& c1);
    void printInOrder() const;
    void printInOrder(Node *n) const;
};

#endif