#include "tree.hpp"
#include <iostream>

using namespace std;

int main(){
    Tree avl;

    cout << "TEST: INSERT 1" << endl;
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10); // LL
    avl.insert(25); // LR
    avl.insert(35); // Balanced
    avl.insert(50); // RR
    avl.insert(5);  // Balancing

    cout << "In-order traversal (should be sorted):";
    avl.printInOrder(avl.getRoot());
    cout << endl;

    cout << "Verify with balance factors:";
    avl.printBalance(avl.getRoot());
    cout << endl;
    
    cout << "TEST: FIND 1" << endl;
    cout << "Testing with 25 and 99" << endl;
    cout << "Expected output: 25 ??" << endl;
    if(avl.find(25)){
        cout << "25" << endl;
    }else{
        cout << "??" << endl;
    }
    if(avl.find(99)){
        cout << "99" << endl;
    }else{
        cout << "??" << endl;
    }

    return 0;
}
