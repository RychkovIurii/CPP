/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:45:53 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/07 14:43:40 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main( void )
{
	try {
		std::cout << "\n==== Test provided by the subject ====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "On the top of the stack: ";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "After pop, the size of the stack is: ";
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		std::cout << "Size of the stack after pushing more elements: ";
		std::cout << mstack.size() << std::endl;
		std::cout << "Iterating through the stack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		std::cout << "Test passed successfully!" << std::endl;

		std::cout << "\n==== Test with list ====" << std::endl;
		std::list<int> mstack_list;
		mstack_list.push_back(5);
		mstack_list.push_back(17);
		std::cout << "On the top of the list: ";
		std::cout << mstack_list.back() << std::endl;
		mstack_list.pop_back();
		std::cout << "After pop, the size of the list is: ";
		std::cout << mstack_list.size() << std::endl;
		mstack_list.push_back(3);
		mstack_list.push_back(5);
		mstack_list.push_back(737);
		//[...]
		mstack_list.push_back(0);
		std::cout << "Size of the list after pushing more elements: ";
		std::cout << mstack_list.size() << std::endl;
		std::cout << "Iterating through the list:" << std::endl;
		std::list<int>::iterator lit = mstack_list.begin();
		std::list<int>::iterator lite = mstack_list.end();
		++lit;
		--lit;
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
		std::list<int> s_list(mstack_list);
		std::cout << "Test with list passed successfully!" << std::endl;

		std::cout << "\n==== My tests with MutantStack ====" << std::endl;
		MutantStack<int> myStack;
		std::cout << "Size of my stack: " << myStack.size() << std::endl;
		myStack.push(1);
		myStack.push(2);
		myStack.push(3);
		myStack.push(4);
		myStack.push(5);
		std::cout << "We have pushed 5 elements into my stack." << std::endl;
		std::cout << "Size of my stack: " << myStack.size() << std::endl;
		std::cout << "Elements in my stack:" << std::endl;
		for (MutantStack<int>::iterator iter1 = myStack.begin(); iter1 != myStack.end(); ++iter1) {
			std::cout << *iter1 << " ";
		}
		std::cout << std::endl;
		myStack.pop();
		std::cout << "Size of my stack after pop: " << myStack.size() << std::endl;
		std::cout << "Elements in my stack after pop:" << std::endl;
		for (MutantStack<int>::iterator iter2 = myStack.begin(); iter2 != myStack.end(); ++iter2) {
			std::cout << *iter2 << " ";
		}
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
