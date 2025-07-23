/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:20:57 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 12:29:37 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        //copy constructor
        Array(const Array &other);
        //destructor
        ~Array(void);
        //copy assignment operator
        Array &operator=(const Array &other);
        //subscript operator
        T &operator[](unsigned int index);
        //size getter
        unsigned int size(void) const;

        class OutOfBoundsException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
};

#include "Array.tpp"

#endif