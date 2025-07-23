# CPP07 - C++ Templates

This project explores **C++ templates**, demonstrating function templates, template specialization, and template classes. It's part of the 42 School C++ curriculum, focusing on generic programming and type-safe template implementations.

## 📋 Project Overview

**CPP07** consists of three exercises that progressively introduce template concepts:

- **Exercise 00**: Basic function templates (`swap`, `min`, `max`)
- **Exercise 01**: Function templates with iterators (`iter`)  
- **Exercise 02**: Template classes with exception handling (`Array`)

## 🗂️ Project Structure

```
CPP07/
├── ex00/           # Function templates (swap, min, max)
│   ├── main.cpp
│   ├── whatever.hpp
│   └── Makefile
├── ex01/           # Function template with iteration (iter)
│   ├── main.cpp
│   ├── iter.hpp
│   └── Makefile
├── ex02/           # Template class (Array)
│   ├── main.cpp
│   ├── Array.hpp
│   ├── Array.tpp
│   └── Makefile
├── subject.pdf     # Project requirements
└── README.md
```

## 🚀 Compilation & Execution

### Prerequisites
- **Compiler**: `g++` or `clang++` with C++98 standard support
- **Make**: GNU Make

### Building All Exercises

Each exercise can be compiled independently:

```bash
# Exercise 00 - Function Templates
cd ex00
make
./whatever

# Exercise 01 - Iterator Template  
cd ex01
make
./iter

# Exercise 02 - Array Template Class
cd ex02
make  
./array
```

### Cleaning Build Files

```bash
# In any exercise directory
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Clean rebuild
```

## 📚 Exercise Details

### Exercise 00: Basic Function Templates (`whatever.hpp`)

**Objective**: Implement generic function templates for common operations.

**Functions Implemented**:
- `swap<T>(T &a, T &b)` - Swaps two values of any type
- `min<T>(T &a, T &b)` - Returns the smaller of two values  
- `max<T>(T &a, T &b)` - Returns the larger of two values

**Key Features**:
- ✅ Type-safe generic functions
- ✅ Works with any comparable type
- ✅ Compile-time type deduction

**Usage Example**:
```cpp
int a = 2, b = 3;
::swap(a, b);           // a = 3, b = 2
std::cout << ::min(a, b);  // Output: 2
std::cout << ::max(a, b);  // Output: 3
```

---

### Exercise 01: Iterator Template (`iter.hpp`)

**Objective**: Create a function template that applies a function to each element in an array.

**Function Signature**:
```cpp
template <typename T>
void iter(T *array, size_t length, void (*f)(T&));
```

**Key Features**:
- ✅ Works with any array type
- ✅ Comprehensive test suite with const/non-const scenarios
- ✅ Function pointer parameter for flexible operations
- ✅ Safe array iteration

**Test Coverage**:
- Non-const arrays with modifying functions
- Const arrays with read-only functions  
- Multiple data types (`int`, `double`, `std::string`)
- Edge cases (empty arrays)

**Usage Example**:
```cpp
int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, doubleInt);    // Doubles each element
iter(arr, 5, printInt);     // Prints each element
```

---

### Exercise 02: Array Template Class (`Array.hpp` + `Array.tpp`)

**Objective**: Implement a generic dynamic array class with proper memory management.

**Class Features**:
- ✅ **Template class** supporting any type
- ✅ **Dynamic memory management** (RAII)
- ✅ **Deep copy semantics** (copy constructor & assignment operator)
- ✅ **Bounds checking** with custom exceptions
- ✅ **Separate implementation** (`.tpp` file pattern)

**Public Interface**:
```cpp
template <typename T>
class Array {
public:
    Array();                           // Default constructor
    Array(unsigned int n);             // Size constructor  
    Array(const Array &other);         // Copy constructor
    ~Array();                          // Destructor
    Array &operator=(const Array &other); // Assignment operator
    T &operator[](unsigned int index);    // Subscript operator
    unsigned int size() const;            // Size getter
};
```

**Exception Handling**:
- Custom `OutOfBoundsException` for invalid array access
- Exception-safe memory operations

**Usage Example**:
```cpp
Array<int> arr(5);          // Create array of 5 integers
arr[0] = 42;                // Set values
Array<int> copy = arr;      // Deep copy
std::cout << arr.size();    // Output: 5
```

## 🔑 Key Concepts Demonstrated

### 1. **Function Templates**
- Generic programming with `template <typename T>`
- Type deduction and instantiation
- Template specialization

### 2. **Template Classes**  
- Class templates with type parameters
- Separate compilation with `.tpp` files
- Template member functions

### 3. **Memory Management**
- RAII (Resource Acquisition Is Initialization)
- Deep vs shallow copying
- Exception-safe resource handling

### 4. **Type Safety**
- Compile-time type checking
- Template constraints and requirements
- Const correctness

## 🧪 Testing

Each exercise includes comprehensive tests:

- **ex00**: Basic functionality tests for all template functions
- **ex01**: Extensive test suite covering const/non-const scenarios, multiple types, and edge cases  
- **ex02**: Full array operations testing including memory management, copying, and exception handling

### Running Tests

The provided `main.cpp` files contain built-in test suites:

```bash
cd ex01 && make && ./iter
# Output shows detailed test results for all scenarios

cd ex02 && make && ./array  
# Output demonstrates array operations and exception handling
```

## 🛠️ Technical Implementation Notes

### Template Compilation Pattern

- **Headers only** for function templates (`ex00`, `ex01`)
- **Header + .tpp** pattern for class templates (`ex02`)
- Prevents template linking issues while maintaining code organization

### Exception Safety

The Array class provides strong exception safety guarantees:
- No memory leaks on failed operations
- Consistent state maintenance
- Proper cleanup in destructors

### C++98 Compliance

All code adheres to C++98 standard:
- No C++11+ features used
- Compatible with older compilers
- Follows 42 School coding standards

## 📖 Learning Outcomes

After completing this project, you will understand:

- ✅ How to write generic, reusable code with templates
- ✅ Template instantiation and type deduction mechanisms  
- ✅ Proper memory management in template classes
- ✅ Exception handling in generic programming
- ✅ The difference between function and class templates
- ✅ Best practices for template organization and compilation

---

**Author**: rmakoni  
**School**: 42 Heilbronn  
**Project**: CPP Module 07 - Templates