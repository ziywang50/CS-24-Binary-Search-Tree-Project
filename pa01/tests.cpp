#include <iostream>
#include "cards.h"
using namespace std;
int main()
{
    Card c1('h', 3);
    Card c2('h', 2);
    Card c3('s', 4);
    Card c4('s', 1);
    Card c5('s', 1);
    //cout << c1.getvalue() <<endl;
    //cout << c2.getvalue() <<endl;
    bool b = (c1 > c2);
    bool c = (c4 == c5);
    cout << "testing c4 == c5 " << c << endl;
    cout << "testing c1 > c2 " << b << endl;
    BST b1;
    BST b2;
    cout << "testing insert..." << endl;
    b1.insert(c1);
    b1.insert(c2, b1.root);
    b1.insert(c3, b1.root);
    b2.insert(c1);
    b2.insert(c2);
    b2.insert(c4);
    Card C = b1.getSuccessor(c1);
    cout << "getsuccessor" << C.getsuit() << C.getvalue() << endl;
    b1.printInOrder();
    b2.printInOrder();
    cout << "testing remove ..." << endl;
    b1.remove(c1);
    b1.remove(c3);
    b2.remove(c1);
    b1.printInOrder();
    b2.printInOrder();
    BST::Node* n1 = b1.findmax(b1.root);
    BST::Node* n2 = b1.findmin(b1.root);
    return 0;
}