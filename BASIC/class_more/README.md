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

### Class Pointers

A class pointer is a pointer variable specifically designed to store the memory
address of an object (an instance) of a particular class. This allows for
indirect access and manipulation of the object's members (data members and
member functions).

A class pointer is declared similarly to other pointers, using the class name
followed by an asterisk (*). It is then initialized with the address of an
existing object using the address-of operator (&).

```cpp
int main() {
    MyClass obj;
    MyClass* ptr;
    ptr = &obj;
}
```

The new operator is used to dynamically allocate memory for objects of a class
on the heap.

To create an object of ClassName on the heap and get a pointer to it, use the
new operator followed by the class name and any constructor arguments.

```cpp
ClassName* pointerName = new ClassName(constructor_arguments);
```

To access members (data members or member functions) of the object pointed to by
a class pointer, use the arrow operator (->)

```cpp
pointerName->memberVariable;
pointerName->memberFunction();
```

Memory allocated with new must be explicitly deallocated using the delete
operator to prevent memory leaks. This calls the object's destructor before
releasing the memory.

```cpp
delete pointerName;
```

### Function Overriding

Is a core concept of object-oriented programming that allows a derived class to
provide its own specific implementation of a function that is already defined
in its base class. This mechanism is essential for achieving runtime
polymorphism. 


```cpp
// Base class
class Animal
{
    public:
        // Function to be overridden
        void speak()
        {
            printf("Animal makes a sound\n");
        }
};

// Derived class
class Dog : public Animal
{
    public:
        // Overriding the speak() function
        void speak()
        {
            printf("Dog barks: Woof!");
        }
};
```

### Virtual Function

Is a member function in a base class that is overridden in a
derived class. It allows runtime polymorphism, meaning the correct function is
called based on the actual object type, not the pointer/reference type.

When a base class pointer or reference points to an object of a derived class,
and a virtual function is called through that pointer or reference, C++
determines which version of the function (base class or derived class) to
execute at runtime based on the actual type of the object being pointed to. 


```cpp
// Base class
class Animal
{
    public:
        // Function to be overridden
        virtual void speak()
        {
            printf("Animal makes a sound\n");
        }
};

// Derived class
class Dog : public Animal
{
    public:
        // Overriding the speak() function
        void speak()
        {
            printf("Dog barks: Woof!");
        }
};
```
