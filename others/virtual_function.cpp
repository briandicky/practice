#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Foo1 {
    public:
        virtual void show() {
            cout << "Foo1's show" << endl;
        }
};

class Foo2 : public Foo1 {
    public:
        virtual void show() {
            cout << "Foo2's show" << endl;
        }
};

void showFooByPtr(Foo1 *foo) {
    foo->show();
}

void showFooByRef(Foo1 &foo) {
    foo.show();
}


int main(void) {
    Foo1 f1;
    Foo2 f2;
    Foo1 *f1Ptr = &f2;

    // Dynamically binding
    cout << "[Info] Show Foo By Ptr:" << endl;
    showFooByPtr(&f1);
    showFooByPtr(&f2);
    showFooByPtr(f1Ptr);
    cout << endl;

    // Dynamically binding
    cout << "[Info] Show Foo By Ref:" << endl;
    showFooByRef(f1);
    showFooByRef(f2);
    cout << endl;

    // Statically binding
    cout << "[Info] Show Foo By Object:" << endl;
    f1.show();
    f2.show();
    cout << endl;

    return 0;
}
