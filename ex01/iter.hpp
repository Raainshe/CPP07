/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:59:04 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 12:01:16 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void iter(T *array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    };
}

#endif