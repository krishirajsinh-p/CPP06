/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:10:19 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/29 00:37:54 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Usage: ./convert <literal>" << endl;
		return EXIT_FAILURE;
	}

	ScalarConverter::convert(argv[1]);

	return EXIT_SUCCESS;
}
