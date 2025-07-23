/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:28:00 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 12:32:39 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>

// Default constructor
template <typename T>
Array<T>::Array() : array(NULL), _size(0) {
    std::cout << "Array default constructor called" << std::endl;
}

// Parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), _size(n) {
    std::cout << "Array parameterized constructor called with size " << n << std::endl;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other) : array(NULL), _size(0) {
    std::cout << "Array copy constructor called" << std::endl;
    *this = other;
}

// Destructor
template <typename T>
Array<T>::~Array(void) {
    std::cout << "Array destructor called" << std::endl;
    delete[] array;
}

// Copy assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &other) {
        delete[] array;
        _size = other._size;
        if (_size > 0) {
            array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                array[i] = other.array[i];
            }
        } else {
            array = NULL;
        }
    }
    return *this;
}

// Subscript operator
template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return array[index];
}

// Size getter
template <typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}

// Exception what() method
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}

#endif
