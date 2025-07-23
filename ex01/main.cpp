/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:59:07 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 12:04:36 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


// Test functions for non-const references
void printInt(int &n) {
    std::cout << n << " ";
}

void doubleInt(int &n) {
    n *= 2;
}

void printString(std::string &str) {
    std::cout << str << " ";
}

void uppercaseString(std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void printDouble(double &d) {
    std::cout << d << " ";
}

void addOne(double &d) {
    d += 1.0;
}

// Test functions for const references
void printConstInt(const int &n) {
    std::cout << n << " ";
}

void printConstString(const std::string &str) {
    std::cout << str << " ";
}

void printConstDouble(const double &d) {
    std::cout << d << " ";
}

int main(void)
{
    std::cout << "=== Testing iter template function ===" << std::endl;
    
    // Test 1: Non-const int array
    std::cout << "\n1. Testing with non-const int array:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    std::cout << "After doubling: ";
    iter(intArray, intSize, doubleInt);
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    // Test 2: Const int array
    std::cout << "\n2. Testing with const int array:" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const array: ";
    iter(constIntArray, constIntSize, printConstInt);
    std::cout << std::endl;
    
    // Test 3: Non-const string array
    std::cout << "\n3. Testing with non-const string array:" << std::endl;
    std::string stringArray[] = {"hello", "world", "template", "test"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    std::cout << "After uppercase: ";
    iter(stringArray, stringSize, uppercaseString);
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    // Test 4: Const string array
    std::cout << "\n4. Testing with const string array:" << std::endl;
    const std::string constStringArray[] = {"const", "string", "array", "test"};
    size_t constStringSize = sizeof(constStringArray) / sizeof(constStringArray[0]);
    
    std::cout << "Const strings: ";
    iter(constStringArray, constStringSize, printConstString);
    std::cout << std::endl;
    
    // Test 5: Non-const double array
    std::cout << "\n5. Testing with non-const double array:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Original doubles: ";
    iter(doubleArray, doubleSize, printDouble);
    std::cout << std::endl;
    
    std::cout << "After adding 1: ";
    iter(doubleArray, doubleSize, addOne);
    iter(doubleArray, doubleSize, printDouble);
    std::cout << std::endl;
    
    // Test 6: Const double array
    std::cout << "\n6. Testing with const double array:" << std::endl;
    const double constDoubleArray[] = {5.5, 6.6, 7.7, 8.8};
    size_t constDoubleSize = sizeof(constDoubleArray) / sizeof(constDoubleArray[0]);
    
    std::cout << "Const doubles: ";
    iter(constDoubleArray, constDoubleSize, printConstDouble);
    std::cout << std::endl;
    
    // Test 7: Empty array
    std::cout << "\n7. Testing with empty array:" << std::endl;
    int *emptyArray = NULL;
    std::cout << "Empty array test (should print nothing): ";
    iter(emptyArray, 0, printInt);
    std::cout << "Done" << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}