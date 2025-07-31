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

---

### Examples

1. **[Car example](App/Src/car.cpp)**