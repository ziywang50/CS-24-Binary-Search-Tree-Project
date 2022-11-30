//cards.cpp
//Authors: Ziyue Wang
//Implementation of the classes defined in cards.h
#include "cards.h"
using namespace std;
Card::Card()
{
    this->suit = ' ';
    this->value = 0;
}

Card::Card(char suit, int value)
{
    this -> suit = suit;
    this -> value = value;
}

//ask about this function
//operator functions must named in this way?
bool Card::operator> (Card const& c1)
{
    int c1value = 0;
    int c2value = 0;
    if (c1.suit == 'h')
    {
        c1value = c1value + 10000;
    }
    else
    {
        int diff = c1.suit - '0';
        c1value = c1value + 30*(diff);
    }
    if (this -> suit == 'h')
    {
        c2value = c2value + 10000;
    }
    else
    {
        //define a separate int here or not?
        int diff = this->suit - '0';
        c2value = c2value + 30*(diff);
    }
    c1value = c1value + c1.value;
    c2value = c2value + this -> value;
    return (c1value < c2value);
}

bool Card::operator== (Card const& c1)
{
    int c1value = 0;
    int c2value = 0;
    if (c1.suit == 'h')
    {
        c1value = c1value + 10000;
    }
    else
    {
        int diff = c1.suit - '0';
        //cout<<"diff1="<<diff<<endl;
        c1value = c1value + 30*(diff);
    }
    if (this -> suit == 'h')
    {
        c2value = c2value + 10000;
    }
    else
    {
        //define a separate int here or not?
        int diff = this->getsuit() - '0';
        //cout<<"diff2="<<diff<<endl;
        c2value = c2value + 30*(diff);
    }
    c1value = c1value + c1.value;
    c2value = c2value + (this -> value);
    return (c1value == c2value);
}

bool Card::operator< (Card const& c1)
{
    //I made a switch of c1value and v2value but switched the sign at the end
    int c1value = 0;
    int c2value = 0;
    if (c1.suit == 'h')
    {
        c1value = c1value + 10000;
    }
    else
    {
        int diff = c1.suit - '0';
        c1value = c1value + 30*(diff);
    }
    if (this -> suit == 'h')
    {
        c2value = c2value + 10000;
    }
    else
    {
        //define a separate int here or not?
        int diff = this->suit - '0';
        c2value = c2value + 30*(diff);
    }
    c1value = c1value + c1.value;
    c2value = c2value + this -> value;
    return (c1value > c2value);
}
Card& Card::operator= (Card const& c1)
{
    if (&c1 == this)
        return *this;
    this -> suit = c1.suit;
    this -> value = c1.value;
    return *this;
}

char Card::getsuit()
{
    return suit;
}

void Card::setsuit(char c)
{
    this -> suit = c;
}

int Card::getvalue()
{
    return value;
}

void Card::setvalue(int i)
{
    this -> value = i;
}

void Card::printCard()
{
    cout << (this -> suit) << " ";
    if (this -> value == 1)
    {
        cout << "a" << " ";
    }
    else if (this -> value == 11)
    {
        cout << "j" << " ";
    }
    else if (this -> value == 12)
    {
        cout << "q" << " ";
    }
    else if (this -> value == 13)
    {
        cout << "k" << " ";
    }
    else
    {
        cout << (this -> value) << " ";
    }
}

//need a constructor to intialize root to nullptr
BST::BST()
{
    root = nullptr;
}

bool BST::insert(Card& cardinsert) {
    // handle special case of empty tree first
    if (!root) {
    //not sure if that causes error.
	root = new Node(cardinsert);
	return true;
    }
    // otherwise use recursive helper
    return insert(cardinsert, root);
}

//are pbject always passed as const reference?
bool BST::insert(Card& cardinsert, Node* r)
{
    if (cardinsert == r->card)
	    return false;
    if (cardinsert < r->card) 
    {
	    if (r->left)
	        return insert(cardinsert, r->left);
	    else {
            //ask this syntax
	        r->left = new Node(cardinsert);
	        r->left->parent = r;
	        return true;
	    }
    }
    else 
    {
	    if (r->right)
	        return insert(cardinsert, r->right);
	    else 
        {
	        r->right = new Node(cardinsert);
	        r->right->parent = r;
	        return true;
	    }
    }
}

BST::Node* BST::findmax(Node* r)
{
    BST::Node* current = r;
    while (current -> right)
    {
        current = current -> right;
    }
    return current;
}

BST::Node* BST::findmin(Node* r)
{
    BST::Node* current = r;
    while (current -> left)
    {
        current = current -> left;
    }
    return current;
}

BST::Node* BST::getNodeFor(Node* r, Card& cardc)
{
    BST::Node* current = r;
    //will there be a problem of doing this?
    if (cardc < current -> card)
    {
        //check if current -> left is null
        if (current -> left)
        {
            current = current -> left;
            return getNodeFor(current, cardc);
        }
        else
        {
            return nullptr;
        }
    }
    else if (cardc == current -> card)
    {
        return current;
    }
    else
    {
        if (current -> right)
        {
            current = current -> right;
            return getNodeFor(current, cardc);
        }
        else
        {
            return nullptr;
        }
    }
}

BST::Node* BST::getSuccessorNode(Card& c1){
    BST::Node* n = getNodeFor(root, c1);
    //cout << "j";
    if (!n)
    {
        return nullptr;
    }
    else if (n && n -> right == nullptr)
    {
        while(n -> parent)
        {
            if (n -> parent -> card > n -> card)
            {
                n = n -> parent;
                return n;
            }
            n = n -> parent;
        }
        return nullptr;
    }
    else
    {
        n = n->right;
        while (n && n -> left)
        {
            n = n -> left;
        }
        return n;
    } // REPLACE THIS NON-SOLUTION
}

//ask this const
Card BST::getSuccessor(Card& c1){
    BST::Node* n = getSuccessorNode(c1);
    //(n->card).printCard();
    if (!n)
    {
        Card c;
        return c;
    }
    return n->card;
}

BST::Node* BST::getPredecessorNode(Card& c1) {
    //find root first, how can I write this？
    Node* n = getNodeFor(root, c1);
    if (!n)
    {
        return nullptr;
    }
    //if n is a leaf node
    else if (n && n -> left == nullptr)
    {
        while(n -> parent)
        {
            if (n -> parent -> card < n -> card)
            {
                return n -> parent;
            }
            n = n -> parent;
        }
        return nullptr;         
    }
    else
    {
        n = n -> left;
        while (n && n -> right)
        {
            n = n -> right;
        }
        return n;
    } // REPLACE THIS NON-SOLUTION
}

bool BST::remove(Card& c1)
{
    Card suc;
    //no delete of cur needed?
    BST::Node* cur = this -> root;
    while (cur)
    {
        if (c1 == cur -> card)
        {
            //case 1: remove the leaf node
            if (cur -> left == nullptr && cur -> right == nullptr)
            {
                if (cur -> parent == nullptr)
                {
                    //but then have you removed the node?
                    root = nullptr;
                }
                else if (cur -> parent -> left == cur)
                {
                    //delete?
                    cur -> parent -> left = nullptr;
                    delete cur;
                }
                else
                {
                    //cout << "j";
                    cur -> parent -> right = nullptr;
                    delete cur;
                }
                return true;
            }
            //case 2: remove node with one child
            else if (cur -> left && !(cur -> right))
            {
                if (cur -> parent == nullptr)
                {
                    root = cur -> left;
                }
                //I need to delete?
                else if (cur -> parent -> left == cur)
                {
                    cur -> parent -> left = cur -> left;
                    cur -> left -> parent = cur -> parent;
                    delete cur;
                }
                else
                {
                    cur -> parent -> right = cur -> left;
                    cur -> left -> parent = cur -> parent;
                    delete cur;
                }
                return true;
            }
            else if (cur -> right && !(cur -> left))
            {
                if (cur -> parent == nullptr)
                {
                    root = cur -> left;
                }
                else if (cur -> parent -> left == cur)
                {
                    cur -> parent ->left = cur -> right;
                    cur -> right -> parent = cur -> parent;
                    delete cur;
                }
                else
                {
                    cur -> parent -> right = cur -> right;
                    cur -> right -> parent = cur -> parent;
                    delete cur;
                }
                return true;
            }
            //case3: remove node with two children.
            else
            {
                suc = getSuccessor(c1);
                remove(suc);
                cur -> card = suc;
            }
        }
        else if (c1 > cur -> card)
        {
            if (cur -> right)
            {
                cur = cur -> right;
                //cout << "j";
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (cur -> left)
            {
                cur = cur -> left;
            }
            else
            {
                return false;
            }
        }
    }
}

void BST::printInOrder() const {
    printInOrder(root);
}

void BST::printInOrder(Node *n) const {
    // IMPLEMENT HERE
    if (n)
    {
    printInOrder(n -> left);
    //getters and setters are needed to print private variables??
    cout<< (n -> card).getsuit() << " ";
    if ((n->card).getvalue() == 1)
    {
        cout << "a" << " " << endl;
    }
    else if ((n->card).getvalue() == 11)
    {
        cout << "j" << " " << endl;
    }
    else if ((n->card).getvalue() == 12)
    {
        cout << "q" << " " << endl;
    }
    else if ((n->card).getvalue() == 13)
    {
        cout << "k" << " " << endl;
    }
    else
    {
        cout<< (n -> card).getvalue() << " " << endl;
    }
    printInOrder(n -> right);
    }    
}
