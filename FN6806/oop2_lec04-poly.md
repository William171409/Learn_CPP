## Review for Inheritance

```cpp
class Base {
  public:
     int a;
  protected:
     int b;
  private:
     int c
  public or protected:
     setter or getter for c;  // direct access
     calculation() { return a + b + c; } // indirect access
  public:
    Base(): a(0), b(0), c(0) {}
    Base(int a, int b, int c): a(a), b(b), c(c) {}
    get_a();
    set_a();
    get_b();
    set_b();
};
```

```cpp
class Derived: public Base {
  /* Use inheritance to bring what's in Base to Derived.
     Avoid repeating the same code in Derived.

  public:
     int a;
  protected:
     int b;
  */
  c is in Derived but only accessible through base class's member functions directly or indirectly.

  public:
     Derived() = default; // same as below
     Derived(): Base() {} // same as above

     Derived(): Base(), b(-1) {} // OK
     Derived(): Base(), c(-1) {} // Error with c is a private of Base

     // Call the ctor of Base with a, b, c
     Derived(): Base(0, 0, 3) {}

     // Create a ctor exactly the same as Base but in Derived
     // Derived(int a, int b, int c): Base(a, b, c) {}
     // using Base::Base(int a, int b, int c); // Error
     using Base::Base; // bring all ctor of Base to Derived.
};
```

## If we don't want to use inheritance

We make Base a member and use its public members.

But inheritance brings "free lunch" - all the public and protected members of Base are available in Derived. Otherwise, we will need to repeat the code to make the class `Derived2` as similar as `Base`.

```cpp
class Derived2 {
   Base b;
   public:
     Derived(int a, int b, int c): b(a, b, c) {}

     calculation() {
        return b.calculate();
    }
    // if you need access to the protected member of Base.
    // or, you want to make derived as much similar of the Base,
    // use inheritance to bring what's in Base to the Derived.

    get_a() { return b.get_a(); }
    set_a() { return b.set_a(); }
    get_b() { return b.get_b(); }
    set_b() { return b.set_b(); }

};
```

## Inheritance Brings Fat Interface

It's easy to use inheritance to build up a rich set of functions as each inheritance brings new members, but it's difficult to maintain the complexity and slim down to the essential.

```cpp
df: pd.DataFrame = pd.read_csv()
df.insert
df.assign
df.sort
df.index
df.
```

## Maximize Code-Reuse

As the base class has the most of the implementation, adding a new derived class is easy.

```cpp
template <typename T1, typename T2>
class SquaredInterpolator : public Interpolator<T1, T2> {
public:
  using Interpolator<T1, T2>::Interpolator;

  T2 operator()(const T1 &date) const {
    return this->with_op(
        date, [](auto x) { return x * x; }, [](auto x) { return sqrt(x); });
  }
};
```

```cpp
template <typename T1, typename T2>
class ExpInterpolator : public Interpolator<T1, T2> {
public:
  using Interpolator<T1, T2>::Interpolator;

  T2 operator()(const T1 &date) const {
    return this->with_op(
        date, [](auto x) { return std::exp(x); }, [](auto x) { return std::log(x); });
  }
};
```

## class template inheritance

The derived class template need to specify all the type parameters that base class template needs

```cpp
template <typename T1, typename T2> class Interpolator { ... };

template <typename T1, typename T2, typename T3>
class LinearInterpolator : public Interpolator<T1, T2> { ... };

template <typename T1, typename T2>
class SquaredInterpolator : public Interpolator<T1, T2> { ... };
```

When we inherite from a specialized class, `LinearInterpolator` is no longer a class template.

```cpp
class LinearInterpolator : public Interpolator<double, double> { ... };
```

## TermStructure

Avoid repeating the same code in different classes.

```cpp
class YieldTermStructure {
public:
     LinearInterpolator interp;
     double calculate() { return … }
}

class VolatilityTermStructure {
     SquaredInterpolator interp;
     double calculate() { return … }
}

class DefaultTermStructure {
     ExpInterpolator interp;
     double calculate() { return … }
}
```

instead, we do the following:

```cpp
using YieldTermStructure = TermStructure<LinearInterpolator>
using VolatilityTermStructure = TermStructure<SquaredInterpolator>
using DefaultTermStructure = TermStructure<ExpInterpolator>

template <typename Interpolator>
class TermStructure {
   …
}
```

If we have a family of classes that are doing similar jobs with different method (you need to different implementation/definition) => use inheritance

If we have a family of classes that are doing same job with different method (can be just called by different class) => use template.

# poly

```cpp
class AbstractBase {
protected:
    vector<int> large_array;
public:
    virtual ~AbstractBase() = default;
    virtual void drive() = 0;
};

class DerivedFromAbstractBase: public AbstractBase {
public:
    ~DerivedFromAbstractBase() = default;
    virtual void drive() final {  cout << "here\n"; };
};

class DerivedFromAbstractBase2: public DerivedFromAbstractBase {
    // virtual void drive() override {  cout << "here2\n"; };
}
```

```cpp
{
   DerivedFromAbstractBase dfab; // dtor will be called in the order of ~DerivedFromAbstractBase then AbstractBase

   // camouflage/cover/cheat the compiler
   // In C++, when AbstractBase is not an abstract class, we can use the below code
   AbstractBase dfab = DerivedFromAbstractBase();
   // When AbstractBase is an abstract class, we can't use the above code.
   // We need to put the object in a smart pointer, then we can use the below code.
   // unique_ptr<AbstractBase> dfab = make_unique<DerivedFromAbstractBase>();

   dfab.drive();
   // The compiler thinks dfab is an object of AbstractBase, then it calls AbstractBase.drive().
   // but AbstractBase.drive() is virtual, so it gets re-directed to DerivedFromAbstractBase.drive();

} // when compiler wants to destructor dfab, it thinks it's object of AbstractBase.
  // Then it looks for dtor of AbstractBase, ~AbstractBase.
  // Since ~AbstractBase is a virtual, it is re-directed to the dtor of DerivedFromAbstractBase
  // then ~DerivedFromAbstractBase will be called first, followed by ~AbstractBase.
```

## `virtual` keyword

`virtual` keyword ensures that the function is re-directed to the correct function for both cases below.

```
// case 1: always can find the correct function to call
B b;
b.drive();
C c;
c.drive()

// case 2: only virtual functions will be called correctly.
unique_ptr<B> c = make_unique<C>();
c.drive();
```
