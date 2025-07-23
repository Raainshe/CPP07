/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:21:09 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 12:29:59 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
    std::cout << "=== Testing Array Template Class ===" << std::endl;
    
    try {
        // Test 1: Default constructor
        std::cout << "\n1. Testing default constructor:" << std::endl;
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
        
        // Test 2: Parameterized constructor
        std::cout << "\n2. Testing parameterized constructor:" << std::endl;
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;
        
        // Test 3: Fill and access elements
        std::cout << "\n3. Testing element access and assignment:" << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
        }
        
        std::cout << "Array contents: ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 4: Copy constructor
        std::cout << "\n4. Testing copy constructor:" << std::endl;
        Array<int> copy(arr);
        std::cout << "Copy size: " << copy.size() << std::endl;
        std::cout << "Copy contents: ";
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 5: Assignment operator
        std::cout << "\n5. Testing assignment operator:" << std::endl;
        Array<int> assigned;
        assigned = arr;
        std::cout << "Assigned size: " << assigned.size() << std::endl;
        
        // Test 6: Modify copy to verify deep copy
        std::cout << "\n6. Testing deep copy (modifying copy):" << std::endl;
        copy[0] = 999;
        std::cout << "Original arr[0]: " << arr[0] << std::endl;
        std::cout << "Modified copy[0]: " << copy[0] << std::endl;
        
        // Test 7: Out of bounds exception
        std::cout << "\n7. Testing out of bounds exception:" << std::endl;
        std::cout << "Trying to access arr[10]..." << std::endl;
        std::cout << arr[10] << std::endl;  // This should throw
        
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test completed ===" << std::endl;
    return 0;
}

