# Orthodox Canonical Form

Orthodox Canonical Form (OCF) is a classic C++ rule that says every class should define exactly these **four special members**:

---

### 1. Default constructor
```cpp
MyClass();
```
Creates an object with no arguments. Required because without it, you can't make arrays of your class or declare variables without initializing them.

---

### 2. Copy constructor
```cpp
MyClass(const MyClass &other);
```
Creates a **new object** as a copy of an existing one. Called when you do:
```cpp
MyClass b = a;       // copy construction
MyClass b(a);        // same thing
void foo(MyClass x); // passing by value
```
If you don't define it, C++ generates a shallow copy — dangerous if your class owns heap memory.

---

### 3. Copy assignment operator
```cpp
MyClass &operator=(const MyClass &other);
```
Copies into an **already existing** object. Called when you do:
```cpp
MyClass b;
b = a;  // b already exists — this is assignment, not construction
```
Key difference from copy constructor: the object already exists, so you may need to **free existing resources** before copying. Always return `*this`.

---

### 4. Destructor
```cpp
~MyClass();
```
Cleans up when the object dies. If you allocated memory with `new`, this is where you `delete` it.

---

### The Rule of Three

OCF is essentially the same as the **Rule of Three**: if you need any one of destructor / copy constructor / copy assignment, you almost certainly need all three. The reason is that you usually only need them when your class manages a resource (heap memory, file handle, etc.) — and all three touch that resource.

---

### Minimal OCF example

```cpp
// MyClass.hpp
class MyClass {
public:
    MyClass();                                // default constructor
    MyClass(const MyClass &other);            // copy constructor
    MyClass &operator=(const MyClass &other); // copy assignment
    ~MyClass();                               // destructor
private:
    int *_data;
};
```

```cpp
// MyClass.cpp
MyClass::MyClass() : _data(new int(0)) {}

MyClass::MyClass(const MyClass &other) : _data(new int(*other._data)) {}

MyClass &MyClass::operator=(const MyClass &other) {
    if (this != &other) {       // self-assignment guard
        delete _data;           // free existing resource
        _data = new int(*other._data);
    }
    return *this;
}

MyClass::~MyClass() {
    delete _data;
}
```
