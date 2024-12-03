#include <iostream>
using std::cout;

class K {
  int data_private;

protected:
  int data_protected;

public:
  int data_public;
  K() : data_private(1), data_protected(2), data_public(3) {}
  int get_private() const { return data_private; }
  void set_private(int v) { data_private = v; }
};

class Ksub : public K { // 1. use public inheritance
                        // 2. Override the base class' member
                        // Base's member can be accessed by K::data_public
  int data_public;

public:
  // 3. Delegate to base class' ctor (preferred)
  // There are no access to data_private anyway.
  Ksub() : K(), data_public(4) {}
  void print() {
    // 4. Access private member in base class via member function
    set_private(5);
    cout << get_private() << "," << data_protected
         << ","
         // Access base class' member with the same name
         << K::data_public << "," << data_public << "\n";
  }
};

void test_delegation() {
  cout << "Test Ksub:\n";
  Ksub kk;
  kk.print();
  cout << "\n";
}

int main()
{
    test_delegation();
    return 0;
}