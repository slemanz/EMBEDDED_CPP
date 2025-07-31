# Essential

In C++, classes and objects are fundamental concepts of Object-Oriented
Programming (OOP), enabling the creation of modular and reusable code.

### Class

A class serves as a blueprint or a template for creating objects. It defines the
structure and behavior that objects of that class will possess. 

```Cpp
class Car
{
    public: // Public members are accessible from outside the class
        std::string color;
        int speed;

        void accelerate(int amount)
        {
            speed += amount;
        }

        void displayInfo()
        {
            printf("Color: %s, Speed: %d km/h\n", color, speed);
        }
};
```

### Object

An object is an instance of a class. When a class is instantiated (an object is
created), memory is allocated for its data members, and it can then interact
with the member functions defined in its class.

- Each object has its own set of data members, distinct from other objects of the
same class.

```Cpp
int main() {
    Car myCar; // Creating an object named 'myCar' of the Car class

    // Accessing and modifying data members using the dot operator
    myCar.color = "Red";
    myCar.speed = 0;

    // Calling member functions
    myCar.accelerate(50);
    myCar.displayInfo(); 

    Car anotherCar; // Creating another object
    anotherCar.color = "Blue";
    anotherCar.speed = 20;
    anotherCar.displayInfo(); 

    while(1)
}
```

**[Car example](App/Src/car.cpp)**

### Dynamic Allocation

Dynamic memory allocation in C++ refers to the process of allocating memory
during the runtime of a program, rather than at compile time. This is in
contrast to static or stack-based memory allocation, where memory is reserved
when the program is compiled or when a function is called, respectively.

```Cpp
    int* p_int = new int; // Allocates memory for a single integer
    int* p_array = new int[10]; // Allocates memory for an array of 10 integers

    delete p_int; // Deallocates memory for a single integer
    delete[] p_array; // Deallocates memory for an array
```

**[Dynamic example](App/Src/dynamic.cpp)**


---

### Examples

1. **[Car example](App/Src/car.cpp)**
2. **[Dynamic example](App/Src/dynamic.cpp)**