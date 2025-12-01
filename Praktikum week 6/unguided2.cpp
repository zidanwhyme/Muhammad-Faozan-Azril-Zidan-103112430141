#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S, 4);
    pushAscending(S, 5);
    pushAscending(S, 9);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 10);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
