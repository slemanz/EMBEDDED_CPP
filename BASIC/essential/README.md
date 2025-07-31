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

### Variable Reference

In programming, "aliasing" primarily refers to a situation where the same memory
location or data object can be accessed or referenced using different names or
expressions. This means that changes made through one name will be visible when
accessing the data through another name, as both names ultimately refer to the
same underlying entity.

A reference variable serves as an alias or an alternative name for an existing
variable. It provides a way to refer to the same memory location as another
variable, allowing modifications through either

References are declared using the ampersand (&) symbol during initialization. For example:

```cpp
    int originalVar = 10;
    int& referenceVar = originalVar; // referenceVar is now an alias for originalVar
```

Other example:

```cpp
    int num = 234;
    int &ref_alias = num;
    int norm_alias = num;

	printf("num is %d \n", num);                // 234
	printf("ref_alias is %d \n", ref_alias);    // 234
	printf("norm_alias is %d \n", norm_alias);  // 234
        
    ref_alias++;

	printf("num is %d \n", num);                // 235
	printf("ref_alias is %d \n", ref_alias);    // 235
	printf("norm_alias is %d \n", norm_alias);  // 234
```


---

### Examples

1. **[Car example](App/Src/car.cpp)**
2. **[Dynamic example](App/Src/dynamic.cpp)**