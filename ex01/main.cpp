/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:35:00 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/27 16:00:08 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data data = {"some string"};
	cout << "data.data Before Serialization and Deserialization: " << data.data << endl;

	uintptr_t ptr = Serializer::serialize(&data);
	cout << "Serialized form of data: " << ptr << endl;

	data = *(Serializer::deserialize(ptr));
	cout << "data.data After Serialization and Deserialization: " << data.data << endl;

	return 0;
}
