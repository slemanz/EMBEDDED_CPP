# Essential

a class is a user-defined data type that serves as a blueprint for creating
objects. It encapsulates data (member variables) and functions (member
functions) that operate on that data into a single unit.

### Class Property Functions 

Refers to member functions that provide controlled access to the private data
members (attributes) of a class. These are commonly known as getter and setter
methods, or more broadly, accessor and mutator methods.

- Getters (Accessor Methods)

```Cpp
class MyClass
{
    private:
        int myValue;

    public:
        int getMyValue() const
        { 
            return myValue;
        }
};
```

- Setters (Mutator Methods)

```cpp
class MyClass
{
    private:
        int myValue;

    public:
        void setMyValue(int value)
        { 
            if (value >= 0)
            {
                myValue = value;
            }
        }
};
```

[Led example](App/Src/property_fn.cpp)