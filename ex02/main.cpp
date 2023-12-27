/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:52:16 by kpuwar            #+#    #+#             */
/*   Updated: 2023/12/27 17:11:02 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

Base* generate(void) {
	Base* ptr[] = {
		new A(),
		new B(),
		new C()
	};
	return ptr[rand() % 3];
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
	else
		cout << "unknown" << endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		cout << "A" << endl;
		(void)a;
	} catch (const exception& e) {
	}

	try {
		B& b = dynamic_cast<B&>(p);
		cout << "B" << endl;
		(void)b;
	} catch (const exception& e) {
	}

	try {
		C& c = dynamic_cast<C&>(p);
		cout << "C" << endl;
		(void)c;
	} catch (const exception& e) {
	}
}

int main(void) {
	Base* a = generate();
	Base* b = generate();
	Base* c = generate();

	cout << "=======" << endl;
	cout << "a* = "; identify( a );
	cout << "a& = "; identify( *a );
	cout << "=======" << endl;
	cout << "b* = "; identify( b );
	cout << "b& = "; identify( *b );
	cout << "=======" << endl;
	cout << "c* = "; identify( c );
	cout << "c& = "; identify( *c );
	cout << "=======" << endl;

	delete a;
	delete b;
	delete c;

	return 0;
}
