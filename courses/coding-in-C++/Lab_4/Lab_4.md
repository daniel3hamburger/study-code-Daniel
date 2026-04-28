# Lab 4: Polymorphie in C++

This lab focuses on understanding **polymorphism** in C++.

All the following sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟡 Section I: Static Polymorphism - Function and Operator Overloading

In this section you will implement a mathematical **2D vector class** and practice different types of **overloading techniques** which represent a static form of polymorphism.

You will practice the following concepts:

- function overloading  
- operator overloading (member vs free functions)   

---

### 🧩 Task Description

You are asked to implement a class `Vector2D` representing a 2D vector.

The class should support common mathematical operations such as vector addition, subtraction, scaling, and comparison. The goal is to design the class interface yourself and apply overloading where appropriate.

---

### Part 1 – Basic Class

Create a class called Vector2D which contains:
1. **x** and **y** coordinates (type: double)
2. a default constructor
3. a parameterized constructor to set the coordinates
3. two getter methods for the coordinates

---

#### Part 2 – Function Overloading

Implement a function that computes the length (magnitude) of the vector.

- Provide one version that returns the exact length
- Provide a second overloaded version that returns the length rounded to a specified number of decimal places
- Test both versions of the function in the main function

Explicitly use function overloading

---

#### Part 3 – Operator Overloading (Member Functions)

Implement operator overloading for basic vector operations.

Your class should support:

- adding two vectors
- subtracting two vectors
- adding another vector to the current object (+=)
- Test all operators in `main`

Decide:

- which operators should return new objects
- which operators should modify the existing object

---

#### Part 4 – Operator Overloading (Free Functions)

Implement functionality to:

- multiply a vector with a scalar
- allow multiplication in both orders (vector * scalar and scalar * vector)
- print a vector using standard output streams
- Test all operators in `main`

Think carefully about:

- why these operators should not necessarily be member functions
- how to pass parameters efficiently

---

#### 🔹 Part 5 – Comparison Operators

Enable comparison between two vectors.

- Implement equality and inequality checks
- Consider the challenges of comparing floating-point values
- Test the comparison operators in the main function

---

## 🟢 Section II: Introduction to dynamic Polymorphism

In this section you will learn the basics of **runtime polymorphism** using **virtual functions** and **abstract classes**.

You will practice the following concepts:

- virtual functions  
- overriding functions  
- abstract classes  
- pure virtual functions  

---

### 🧩 Task Description

You will implement a simple class hierarchy for geometric shapes.

---

### 📘 Requirements

#### 🔹 Part 1 – Base Class

Create a base class that represents a general geometric shape.

- The class should define a method that computes the area
- This method should just return a default value (0.0)
- Think about whether this function should be declared as virtual and why

---

#### 🔹 Part 2 – Derived Classes

Create two derived classes:

```cpp
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    double area() const override;
};
```

```cpp
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h);
    double area() const override;
};
```

⚠️ Test both classes in `main`.

---

#### 🔹 Part 3 – Polymorphism

- Create a pointer of type `Shape*`
- Assign it objects of `Circle` and `Rectangle`
- Call `area()` via the pointer

⚠️ Test this behavior in `main`.

---

#### 🔹 Part 4 – Abstract Class

Modify `Shape`:

```cpp
class Shape {
public:
    virtual double area() const = 0;
};
```

- Explain what changes
- Why can `Shape` no longer be instantiated?

⚠️ Test usage in `main`.

---

### 🧠 Reflection Questions

1. What is the purpose of the `virtual` keyword?  
2. What is the difference between overriding and overloading?  
3. What is a pure virtual function?  
4. Why are abstract classes useful?  
