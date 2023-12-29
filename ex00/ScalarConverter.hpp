/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:11:33 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 01:15:53 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

using std::string;
using std::cout;
using std::endl;
using std::isdigit;

enum varTypes {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE
};

struct vars {
	enum varTypes type;
	bool isLiteral;
	char c;
	int n;
	float f;
	double d;
};

class ScalarConverter
{
	public:
		static vars* data;

		static void convert(const string& literal);
};

#endif
