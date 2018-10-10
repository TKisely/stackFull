#include <iostream>
#include "Stack.h"

using namespace std;


int main() {
    Stack s1;
    s1.push(3);
    s1.push(4);

    // Másolókonstruktor tesztje
    Stack s2(s1);


    try
    {
        while(!s2.isEmpty())
        {
            int element;
            s2.pop(element);
            cout << element << endl;
        }

        int element;
        s1.pop(element);
        cout << "pop: " << element << endl;
        s1.pop(element);
        cout << "pop: " << element << endl;

        /*
        // Ez a rész kivételt dob...
        s1.pop(element);
        cout << "pop: " << element << endl;
        */

        s1.push(42);
        Stack *pS3=new Stack(s1); // Másolókonstruktor
        pS3->pop(element);
        cout << "pop: " << element << endl;
        delete pS3;
    }
    catch(const stack_exception& e) // Elkapjuk a Stack kivételeit
    {
        cout << e.what() << endl;
    }
    std::cout << "Lefutottam" << std::endl;
    return 0;
}