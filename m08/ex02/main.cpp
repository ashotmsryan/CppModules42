#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> a(mstack);
		MutantStack<int> s(mstack);
		MutantStack<int>::iterator i = s.begin();
		MutantStack<int>::iterator ie = s.end();
		while (i != ie)
		{
			std::cout << *i << std::endl;
			++i;
		}
	}
		std::cout << "--------------------------------" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> a(mstack);
		std::list<int> s(mstack);
		std::list<int>::iterator i = s.begin();
		std::list<int>::iterator ie = s.end();
		while (i != ie)
		{
			std::cout << *i << std::endl;
			++i;
		}

	}
	std::cout << "--------------------------------" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		MutantStack<int> a(mstack);
		std::cout << a.top() << " " << *a.begin() << std::endl;
	}
	return 0;
}