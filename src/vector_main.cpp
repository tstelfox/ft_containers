/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:44:37 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 17:52:40 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if STL
	#include <map>
	#include <iostream>
	#include <iomanip>
	#include <vector>
	#include <time.h>
	#define FT 0
	namespace ft = std;
#else
	#define FT 1
	#include "map.hpp"
	#include <time.h>
	#include <iomanip>
	#include "vector.hpp"
#endif

# if defined(unix) || defined(__unix__) || defined(__unix)
#  define LINUX 1
# else
#  define LINUX 0
# endif

size_t begintime;
size_t endtime;
struct timeval	tv;

template< typename T >
void	print_container_content(ft::vector<T> &vec, std::string name = "container") {
	std::cout << name << " contains:";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " $" << std::endl;
}

template< typename T >
void	reverse_print_container_content(ft::vector<T> &vec, const std::string& name = "container") {
	std::cout << name << " contains:";
	for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << ' ' << *it;
	std::cout << " $" << std::endl;
}

void	constructors_test() {
	int i = 8;
	ft::vector<int> def;
	print_container_content(def, "default constructor");
	ft::vector<int>	fill(i, 42);
	for (int i = 0; i < 8; i++)
		fill.push_back( i );
	print_container_content(fill, "fill constructor");
	ft::vector<int> range(fill.begin(), fill.end());
	print_container_content(range, "range constructor");
	ft::vector<int> copy(range);
	print_container_content(copy, "copy constructor");
	copy = def;
	print_container_content(copy, "assignation operator");
}

void	iterators_test() {
	ft::vector<int> hats;
	for (int i = 0; i < 72; i++)
		hats.push_back(i * 10);
	ft::vector<int>::iterator		it = hats.begin();
	ft::vector<int>::iterator		ite = hats.end();
		ite--;
	ft::vector<int>::iterator test = 5 + it;
	std::cout << "*test = " << *test << std::endl;
	std::cout << "*it = " << *it << ", *ite = " << *ite << std::endl;
	ft::vector<int>::const_iterator	cit = hats.begin();
	ft::vector<int>::const_iterator	cite = hats.end();
		cite--;
	std::cout << "sfhkdsfh" << std::endl;
	std::cout << "*cit = " << *cit << ", *cite = " << *cite << std::endl;
	ft::vector<int>::reverse_iterator		rit = hats.rbegin();
	ft::vector<int>::reverse_iterator		rite = hats.rend();
	(void)rite;
	ft::vector<int>::const_reverse_iterator	crit = hats.rbegin();
	ft::vector<int>::const_reverse_iterator	crite = hats.rend();
	std::cout << "regular iterators:" << std::endl;
	std::cout << "reg: operator==(): " << std::boolalpha << (it == cit) << ", " << (cit == it) << std::endl;
	std::cout << "reg: operator!=(): " << std::boolalpha << (it != cite) << ", " << (cite != it) << std::endl;
	std::cout << "reg: operator<(): " << std::boolalpha << (it < cite) << ", " << (cite < it) << std::endl;
	std::cout << "reg: operator<=(): " << std::boolalpha << (it <= cite) << ", " << (cite <= it) << std::endl;
	std::cout << "reg: operator>(): " << std::boolalpha << (it > cite) << ", " << (cite > it) << std::endl;
	std::cout << "reg: operator>=(): " << std::boolalpha << (it >= cite) << ", " << (cite >= it) << std::endl;
	ite = it;
	std::cout << "*it++ gives: " << *it++ << ", it now is " << *it << std::endl;
	std::cout << "*++it gives: " << *++it << ", it now is " << *it << std::endl;
	std::cout << "*rit++ gives: " << *rit++ << ", it now is " << *rit << std::endl;
	std::cout << "*++rit gives: " << *++rit << ", it now is " << *rit << std::endl;
	std::cout << "*it-- gives: " << *it-- << ", it now is " << *it << std::endl;
	std::cout << "*--it gives: " << *--it << ", it now is " << *it << std::endl;
	std::cout << "*rit-- gives: " << *rit-- << ", it now is " << *rit << std::endl;
	std::cout << "*--rit gives: " << *--rit << ", it now is " << *rit << std::endl;
	// *cit += 10;
	// *crit += 10;
	std::cout << "reverse iterators:" << std::endl;
	std::cout << "reverse: operator==(): " << std::boolalpha << (rit == crit) << ", " << (crit == rit) << std::endl;
	std::cout << "reverse: operator!=(): " << std::boolalpha << (rit != crite) << ", " << (crite != rit) << std::endl;
	std::cout << "reverse: operator<(): " << std::boolalpha << (rit < crite) << ", " << (crite < rit) << std::endl;
	std::cout << "reverse: operator<=(): " << std::boolalpha << (rit <= crite) << ", " << (crite <= rit) << std::endl;
	std::cout << "reverse: operator>(): " << std::boolalpha << (rit > crite) << ", " << (crite > rit) << std::endl;
	std::cout << "reverse: operator>=(): " << std::boolalpha << (rit >= crite) << ", " << (crite >= rit) << std::endl;
	std::cout << "dereference operator on iterators: " << it[2] << ", " << cit[3] << ", " << rit[4] << ", " << crit[5] << " WORK!" << std::endl;
}

void	capacity_test() {
	ft::vector<int>	papajohns;

	std::cout << "papajohns.empty(): " << std::boolalpha<< papajohns.empty() << std::endl;
	for (int i = 0; i < 10; ++i)
		papajohns.push_back(i);
	std::cout << "papajohns.size(): " << papajohns.size() << std::endl;
	std::cout << "papajohns.max_size(): " << papajohns.max_size() << std::endl;
	std::cout << "papajohns.capacacity(): " << papajohns.capacity() << std::endl;
	std::cout << "papajohns.empty(): " << std::boolalpha << papajohns.empty() << std::endl;

}

void	element_access_test() {
	ft::vector<int> kokkita;

	for (int i = 0; i < 10; ++i)
		kokkita.push_back(-3 * i);

	const ft::vector<int> constkita(kokkita);
	std::cout << "kokkita[3]: " << kokkita[3] << ", constkita[4]: " << constkita[4] << std::endl;
	try {
		std::cout << "the [] operator does not check if the input value is inbounds of the array" << std::endl;
		std::cout << "the function .at() does check and throws an exception if it is out of bounds, here I'll show you:" << std::endl;
		std::cout << "kokkita.at(13): " << kokkita.at(13) << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "See? it threw an exception" << std::endl;
		// I didnt print e.what(), because diff will see it as different (and wrong) sadface
	}
	std::cout << "kokkita.front() = " << kokkita.front() << ", constkita.front() = " << constkita.front() << std::endl;
	std::cout << "kokkita.back() = " << kokkita.back() << ", constkita.back() = " << constkita.back() << std::endl;
	// std::cout << "kokkita[" << 812039 << "]: " << kokkita[812039] << std::endl;
}

void	modifiers_test() {

	ft::vector<int>	tocopy;
	for (int i = 0; i < 14; ++i)
		tocopy.push_back(14 * i);
	ft::vector<int> wap;
	wap.assign(5, 69);
	print_container_content(wap, "after the first assign, wapwap");
	wap.assign(tocopy.begin(), tocopy.end());
	print_container_content(wap, "and after the second, wapwap");
	while (!(tocopy.empty()))
		tocopy.pop_back();
	print_container_content(wap, "wap");
	ft::vector<int>::iterator it = wap.begin() + 2;
	std::cout << "*it = " << *it << std::endl;
	wap.insert(it, 2, 800);
	it = wap.insert(wap.begin() + 1, 9999);
	std::cout << "returned iterator from insert gives " << *it << std::endl;
	tocopy.insert(tocopy.begin(), wap.begin(), wap.end() - 5);
	print_container_content(wap, "after insert, wap");
	
	it = tocopy.erase(tocopy.begin());
	std::cout << "erasing returns iterator to " << *it << std::endl;
	print_container_content(tocopy, "after insert and erasing, tocopy");
	it = tocopy.erase(tocopy.begin(), tocopy.begin() + 6);
	std::cout << "erasing returns iterator to " << *it << std::endl;
	
	print_container_content(tocopy, "after insert and erasing, tocopy");

}

void	relational_operators_test() {
	ft::vector<int>	a;
	ft::vector<int>	b;
	for (int i = 0; i < 8; i++) {
		a.push_back(i);
		b.push_back(i);
	}
	std::cout << "this one should return 1: " << (a == b) << ", and this one 0: " << (a != b) << std::endl;
	std::cout << (a < b) << (b < a) << (a <= b) << (b <= a) << std::endl;
	a.push_back(0);
	b.push_back(5);
	std::cout << "now vice versa, should return 0: " << (a == b) << ", and this one 1: " << (a != b) << std::endl;
	std::cout << (a < b) << (b < a) << (a <= b) << (b <= a) << std::endl;
}

void	stl_test() {
	// checking if I can also assign items from STL iterators
	ft::vector<int>		wap;
	std::vector<int>	stl;
	for (int i = 0; i < 12; i++)
		stl.push_back(i * 4);
	wap.assign(stl.begin(), stl.end());
	print_container_content(wap, "wap");
	reverse_print_container_content(wap, "wap");
}

void	sam() {
	ft::vector<int>	sam(8, 123);
	// int ret = sam.end() - sam.begin();
	int ret = sam.end() - sam.begin();
	std::cout << "ret = " << ret << std::endl;
	sam.resize(5);
	std::cout << "vector capacity: " << sam.capacity() << std::endl;
	std::cout << "vector size: " << sam.size() << std::endl;
	std::cout << "vector front: " << sam.front() << std::endl;
	std::cout << "vector back: " << sam.back() << std::endl;
	sam.resize(8, 100);
	std::cout << "vector capacity: " << sam.capacity() << std::endl;
	std::cout << "vector size: " << sam.size() << std::endl;
	std::cout << "vector front: " << sam.front() << std::endl;
	std::cout << "vector back: " << sam.back() << std::endl;
	sam.resize(12389);
	std::cout << "vector capacity: " << sam.capacity() << std::endl;
	std::cout << "vector size: " << sam.size() << std::endl;
	std::cout << "vector front: " << sam.front() << std::endl;
	std::cout << "vector back: " << sam.back() << std::endl;
}


int	main(int argc, char **argv) {
	// if (argc == 2 && strcmp(argv[1], "time") == 0) {
	// 	gettimeofday(&tv, NULL);
	// 	begintime = tv.tv_usec;
	// }
	 stl_test();
	 constructors_test();
	 iterators_test();
	 capacity_test();
	 element_access_test();
	 modifiers_test();
	 relational_operators_test();
	sam();
	// if (argc == 2 && strcmp(argv[1], "time") == 0) {
	// 	// gettimeofday(&tv, NULL);
	// 	endtime = tv.tv_usec;
	// 	std::cout << "Time elapsed in total! = " << endtime - begintime << " nanoseconds" << std::endl;
	// }
	if (argc == 3 && strcmp(argv[2], "leaks") == 0 && !LINUX) {
		int a = system("leaks containers.out | grep \"total leaked bytes\" >&2");
		(void)a;
	}
	return 0;
}

// class	tester {
	
// 		int			counts;
// 		float		angle;
// 		std::string	name;
// 	public:
// 		tester() : counts(1) , angle(0.78) , name("Fares") {}
// 		tester(int par, float para, std::string param) : counts(par) , angle(para) , name(param) {}
// 		tester(const tester &x) {
// 			*this = x;
// 		}
// 		tester&	operator= (const tester &x) {
// 			if (this != &x) {
// 				this->counts = x.getcounts();
// 				this->angle = x.getangle();
// 				this->name = x.getname();
// 			}
// 			return *this;
// 		}
// 		~tester() {}

// 		int getcounts() const {
// 			return (counts);
// 		}
// 		float getangle() const {
// 			return (angle);
// 		}
// 		std::string	getname() const {
// 			return(name);
// 		}
// };

// std::ostream& operator << (std::ostream &o, tester const &instance) {
// 	o << "Here are the contents: " << instance.getcounts() << " " << instance.getangle() << " " << instance.getname() << std::endl;
// 		return (o);
// }

// void	test_object() {
	
// 	std::cout << "<-------TESTING VECTOR WITH OBJECT------->" << std::endl;

// 	tester	testinstance;
// 	tester  *second = new tester(69, 3.14, "Montolivo");
// 	tester	*third = new tester(99, 49.473, "Simio");
// 	tester	*fourth = new tester(46, 6.66, "Magico Bilan");
// 	tester	*swapper = new tester(27, 9.47, "Forza Napoli");
// 	tester	*sixth = new tester(0, 1010, "Adriatico");
// 	ft::vector<tester>	attempt;
	
// 	attempt.push_back(testinstance);
// 	attempt.push_back(*second);
// 	attempt.push_back(*third);
// 	attempt.push_back(*fourth);

// 	std::cout << "** Iterator test **" << std::endl;

// 	ft::vector<tester>::iterator it_begin = attempt.begin();
// 	ft::vector<tester>::iterator it_end = attempt.end();
// 	std::cout << "Substracting the beginning from the end " << it_end - it_begin << std::endl;
// 	while (it_begin != it_end)
// 	{
// 		std::cout << *it_begin;
// 		it_begin++;
// 	}

// 	std::cout << "** Swap test **" << std::endl;

// 	ft::vector<tester> swapped;
// 	swapped.push_back(*swapper);

// 	swapped.swap(attempt);
// 	for (size_t i = 0; i < swapped.size(); i++)
// 		std::cout << "swapped item " << i << " " << swapped[i];
// 	std::cout << "Attempt has " << attempt[0];

// 	std::cout << "***** Assignation *****" << std::endl;
// 	ft::vector<tester>::iterator iter = swapped.begin();
// 	attempt.assign(iter, iter + 2);
// 	for (size_t i = 0; i < attempt.size(); i++)
// 		std::cout << "Attempt has been assigned the items from swapped: " << swapped[i];


// 	std::cout << "***** Insertion *****" << std::endl;
// 	iter += 2;
// 	swapped.insert(iter, *sixth);
// 	std::cout << "*Single*" << std::endl;
// 	for (size_t i = 0; i < swapped.size(); i++)
// 		std::cout << "Item no " << i << " of vector: " << swapped[i];
// 	// std::cout << "*Ranged*" << std::endl;
// 	// swapped.insert(iter, 5, swapper);
// 	for (size_t i = 0; i < swapped.size(); i++)
// 		std::cout << "Item no " << i << " of vector: " << swapped[i];
// 	std::cout << "*With Iterators*" << std::endl;
// 	for (size_t i = 0; i < attempt.size(); i++)
// 		std::cout << "Item no " << i << " of attempt vector BEFORE: " << attempt[i];
// 	ft::vector<tester>::iterator first = swapped.begin() + 1;
// 	ft::vector<tester>::iterator last = first + 4;
// 	attempt.insert(attempt.begin() + attempt.size(), first, last);
// 	for (size_t i = 0; i < attempt.size(); i++)
// 		std::cout << "Item no " << i << " of attempt vector AFTER: " << attempt[i];

// 	std::cout << "***** Erasing *****" << std::endl;
// 	std::cout << "*Single*" << std::endl;
// 	attempt.erase(attempt.begin() + 2);
// 	for (size_t i = 0; i < attempt.size(); i++)
// 		std::cout << "Item no " << i << " of attempt vector: " << attempt[i];
// 	std::cout << "*Ranged of first three elements*" << std::endl;
// 	attempt.erase(attempt.begin(), attempt.begin() + 3);
// 	for (size_t i = 0; i < attempt.size(); i++)
// 		std::cout << "Item no " << i << " of attempt vector: " << attempt[i];

// 	std::cout << "<--------TESTING WITH STRINGS---------->" << std::endl;

// 	ft::vector<std::string>	string_vec;
// 	ft::vector<std::string> other_vec;
// 	string_vec.push_back("Mother");
// 	string_vec.push_back("Fucking");
// 	string_vec.push_back("Hijueputa");
// 	string_vec.push_back("Porqué");
// 	string_vec.push_back("Has venido");
// 	string_vec.push_back("Al party con los hermanos?");

// 	other_vec.push_back("darkaufhayyyybung is kind of annoying");
// 	other_vec.push_back("Whiney, I'd say");

// 	for (ft::vector<std::string>::reverse_iterator rev_it = string_vec.rbegin(); rev_it != string_vec.rend(); rev_it++)
// 		std::cout << "In reverse order: " << *rev_it << std::endl;
// 	for (ft::vector<std::string>::iterator it = string_vec.begin(); it != string_vec.end(); it++)
// 		std::cout << "Elements of string_vec: " << *it << std::endl;
// 	string_vec[4] = "la cagaste";
// 	ft::vector<std::string>::iterator it = string_vec.begin();
// 	it += 4;
// 	std::cout << "After overwriting it, at begin() + 4 we find: " << *it << std::endl;
// 	*it++;
// 	std::cout << "Quick test of *it++: " << *it << std::endl;

// 	std::cout << "Size is " << string_vec.size() << std::endl;
// 	string_vec.resize(3);
// 	std::cout << "After resizing to 3 at the end of string_vec we find: " << string_vec.back() << std::endl;

// 	std::cout << "****Relational Operators****" << std::endl;
// 	if (string_vec < other_vec)
// 		std::cout << "string_vec is smaller" << std::endl;
// 	else if (other_vec < string_vec)
// 		std::cout << "other_vec is smaller" << std::endl;
	
// 	std::cout << "*Ranged*" << std::endl;
// 	string_vec.insert(string_vec.begin() + 3, 5, "NO ME IMPOLTA");

// 	for (it = string_vec.begin(); it != string_vec.end(); it++)
// 		std::cout << "Vector after ranged insert: " << *it << std::endl;
	
// 	std::cout << "Clearing both of them" << std::endl;
// 	other_vec.clear();
// 	string_vec.clear();
// 	if (string_vec == other_vec)
// 		std::cout << "Now they're equal" << std::endl;

// }

// void	test_int() {

// 	ft::vector<int>	fuck;
// 	int		numset[5] = {69, 99, 7, 111, 47};
	
// 	for (int i = 0; i < 5; i++)
// 		fuck.push_back(numset[i]);

// 	std::cout << "** Swap test **" << std::endl;

// 	ft::vector<int> swapped;
// 	swapped.push_back(99999);

// 	ft::vector<int>::iterator	swapit = swapped.begin();
// 	std::cout << "iterator should point to 99999 before swap: " << *swapit << std::endl;
// 	swapped.swap(fuck);
// 	std::cout << "iterator should still point to 99999 after swap: " << *swapit << std::endl;

// 	for (size_t i = 0; i < swapped.size(); i++)
// 		std::cout << "Swapped item [" << i << "] " << swapped[i] << std::endl;
	
// 	for (size_t i = 0; i < fuck.size(); i++)
// 		std::cout << "Fuck item [" << i << "] " << fuck[i] << std::endl;
	
// 	std::cout << "****Relational Operators****" << std::endl;
// 	if (fuck < swapped)
// 		std::cout << "Fuck is smaller" << std::endl;
// 	else if (swapped < fuck)
// 		std::cout << "swapped is smaller" << std::endl;
	
// 	std::cout << "Clearing both of them" << std::endl;
// 	swapped.clear();
// 	fuck.clear();
// 	if (fuck == swapped)
// 		std::cout << "Now they're equal" << std::endl;
// }

// int		main(void) {

// 	test_object();
// 	test_int();

// 	return 0;

// }
