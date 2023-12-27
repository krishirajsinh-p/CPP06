/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:49:14 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/27 17:04:20 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::rand;
using std::exception;

class Base {
	public:
		virtual ~Base() {
		}
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

#endif
