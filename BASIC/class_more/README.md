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

### Access Specifiers

Are keywords that define the accessibility or visibility level of class members
(data members and member functions). They are fundamental to encapsulation, a
core principle of Object-Oriented Programming (OOP), as they control which parts
of a program can access the internal workings of a class.


There are three primary access specifiers in C++:

**public:**

- Members declared as public are accessible from anywhere in the program, both
inside and outside the class. 
- They define the public interface of the class, allowing other parts of the
program to interact with the class's functionality.
- Example: Member functions that provide services or retrieve data from the
class are often declared public

**private:** 

- Members declared as private are only accessible within the same class. 
- They cannot be accessed directly from outside the class, including by derived
classes or external functions
- private members are used to encapsulate the internal state and implementation
details of a class, hiding them from external access and preventing unauthorized
modification. 
- By convention, data members are typically declared private to ensure data
integrity and enforce controlled access through public member functions (e.g.,
getter and setter methods).

**protected:**

- Members declared as protected are accessible within the same class and by its
derived classes. 
- They are not directly accessible from outside the class by non-derived classes
or external functions.
- protected members facilitate inheritance, allowing derived classes to access
and potentially modify base class members while maintaining a level of
encapsulation from external code.

**[Access Specifiers - Example](App/Src/acessSpecifiers.cpp)**



