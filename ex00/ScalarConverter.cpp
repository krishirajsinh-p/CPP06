/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:11:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 01:38:51 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

vars* ScalarConverter::data = 0;

static bool isInt(const string &literal)
{
	char c = literal.at(0);
	if (!(c == '-' || c == '+' || isdigit(c)))
		return false;

	for (size_t i = 1; i < literal.size(); i++)
		if (isdigit(literal.at(i)) == false)
			return false;

	return true;
}

static bool isDecibleNum(const string &literal, short length)
{
	char c = literal.at(0);
	if (!(c == '-' || c == '+' || isdigit(c)))
		return false;

	short dotPos = literal.find('.');
	if (dotPos == (short)string::npos || dotPos == 0 || dotPos == length - 1)
		return false;

	for (short i = 1; i < length; i++)
		if (isdigit(literal.at(i)) == false && i != dotPos)
			return false;

	return true;
}

static bool isDecibleLiteral(const string &literal)
{
	char c = literal.at(0);
	if ((c == '-' || c == '+') && literal.find("inf") == 1)
	{
		if (literal.size() == 4)
		{
			ScalarConverter::data->type = DOUBLE;
			return true;
		}
		else if (literal.size() == 5 && literal.at(4) == 'f')
		{
			ScalarConverter::data->type = FLOAT;
			return true;
		}
	}
	else if (literal == "nan")
	{
		ScalarConverter::data->type = DOUBLE;
		return true;
	}
	return false;
}

static void getType(const string &literal)
{
	if (literal.size() == 1)
		ScalarConverter::data->type = CHAR;
	else if (isInt(literal))
		ScalarConverter::data->type = INT;
	else if (isDecibleLiteral(literal))
		ScalarConverter::data->isLiteral = true;
	else if (literal.find('f') == literal.size() - 1 && isDecibleNum(literal, literal.size() - 1))
		ScalarConverter::data->type = FLOAT;
	else if (isDecibleNum(literal, literal.size()))
		ScalarConverter::data->type = DOUBLE;
	else
	{
		std::cerr << "Enter valid literal." << endl;
		exit(EXIT_FAILURE);
	}
}

static void printChar() {
	char c = ScalarConverter::data->c;

	if (ScalarConverter::data->isLiteral)
		cout << "Impossible" << endl;
	else if (c >= 127 || !isprint(c))
		cout << "Non displayable" << endl;
	else
		cout << c << endl;
}

static void printInt() {
	if (ScalarConverter::data->isLiteral)
		cout << "Impossible" << endl;
	else if (ScalarConverter::data->type == FLOAT || ScalarConverter::data->type == DOUBLE) {
		long l = static_cast<long>(ScalarConverter::data->d);
		if (l > INT_MAX || l < INT_MIN)
			cout << "Impossible" << endl;
		else
			cout << ScalarConverter::data->n << endl;
	} else {
		cout << ScalarConverter::data->n << endl;
	}
}

static void print(const string &literal)
{
	cout << "char: "; printChar();
	cout << "int: "; printInt();
	if (ScalarConverter::data->type == FLOAT) {
		cout << "float: " << literal << endl;
		string str = literal;
		str[str.size() - 1] = '\0';
		cout << "double: " << str << endl;
	} else if (ScalarConverter::data->type == DOUBLE) {
		cout << "float: " << ScalarConverter::data->f << 'f' << endl;
		cout << "double: " << literal << endl;
	} else {
		cout << "float: " << ScalarConverter::data->f << ".0f" << endl;
		cout << "double: " << ScalarConverter::data->d << ".0" << endl;
	}
}

void ScalarConverter::convert(const string &literal)
{
	vars Data;
	ScalarConverter::data = &Data;

	ScalarConverter::data->isLiteral = false;
	getType(literal);

	try
	{
		switch (ScalarConverter::data->type)
		{
			case CHAR:
				ScalarConverter::data->c = literal.at(0);
				ScalarConverter::data->n = static_cast<int>(ScalarConverter::data->c);
				ScalarConverter::data->f = static_cast<float>(ScalarConverter::data->c);
				ScalarConverter::data->d = static_cast<double>(ScalarConverter::data->c);
				break;
			case INT:
				ScalarConverter::data->n = std::stoi(literal);
				ScalarConverter::data->f = static_cast<float>(ScalarConverter::data->n);
				ScalarConverter::data->d = static_cast<double>(ScalarConverter::data->n);
				ScalarConverter::data->c = static_cast<char>(ScalarConverter::data->n);
				break;
			case FLOAT:
				ScalarConverter::data->f = std::stof(literal);
				ScalarConverter::data->n = static_cast<int>(ScalarConverter::data->f);
				ScalarConverter::data->d = static_cast<double>(ScalarConverter::data->f);
				ScalarConverter::data->c = static_cast<char>(ScalarConverter::data->f);
				break;
			case DOUBLE:
				ScalarConverter::data->d = std::stod(literal);
				ScalarConverter::data->n = static_cast<int>(ScalarConverter::data->d);
				ScalarConverter::data->f = static_cast<float>(ScalarConverter::data->d);
				ScalarConverter::data->c = static_cast<char>(ScalarConverter::data->d);
				break;
			default:
				break;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	print(literal);
}
