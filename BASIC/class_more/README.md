# More about Class

### Class Inheritance

Is a fundamental concept of Object-Oriented Programming (OOP) that allows a new
class (the derived class or child class) to inherit properties and behaviors
(data members and member functions) from an existing class (the base class or
parent class). This mechanism promotes code reusability and establishes an
"is-a" relationship between classes. 

The general syntax for declaring a derived class is:

```cpp
class DerivedClass : access_specifier BaseClass
{
    // Members of DerivedClass
};
```

(access_specifier can be `public`, `protected`, or `private`, controlling the
visibility of inherited members in the derived class.)

[Inheritance Example](App/Src/inheritance.cpp)