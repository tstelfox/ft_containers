/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 17:04:58 by tmullan       #+#    #+#                 */
/*   Updated: 2022/02/13 20:24:07 by tmullan       ########   odam.nl         */
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
	#include <vector>
	#include <time.h>
	#include <iomanip>
#endif

// template < class T>
// void	small_map(T &small) {
// 	small.insert(ft::pair<int, std::string>(1, "Root"));
// 	typename T::const_iterator it = small.begin();
	
// 	std::cout << it->first << " " << it->second << std::endl;
// }

// void	test_basic() {

// 	std::cout << std::boolalpha;

// 	ft::map<int, std::string> small;
// 	small_map(small);
// 	ft::map<int, std::string> test;

// 	test.insert(ft::pair<int, std::string>(10, "Fuoco"));
// 	test.insert(ft::pair<int, std::string>(12, "Kali"));
// 	test.insert(ft::pair<int, std::string>(17, "Uchis"));
// 	test.insert(ft::pair<int, std::string>(6, "Colombia"));
// 	test.insert(ft::pair<int, std::string>(15, "Gran Colombia"));
// 	test.insert(ft::pair<int, std::string>(4, "Shakira Shakira"));
// 	test.insert(ft::pair<int, std::string>(5, "Aiuto Shakira"));
// 	test.insert(ft::pair<int, std::string>(2, "Dio cane"));
// 	test.insert(ft::pair<int, std::string>(99, "dio bastardo"));
// 	test.insert(ft::pair<int, std::string>(47, "dio porco"));
// 	test.insert(ft::pair<int, std::string>(16, "dio stronzo"));


// 	std::cout << "\nSQUARE BRACKETS" << std::endl;
// 	// test.printBT();
// 	std::cout << "What is the value here with a non-used key? " << test[68] << std::endl;
// 	std::cout << "And another unused key " << test[999] << std::endl;
// 	std::cout << "And another unused key " << test[9399] << std::endl;
// 	// std::cout << "And another unused key " << test[232] << std::endl;
// 	std::cout << "What about with a used key? " << test[17] << std::endl;
// 	// test.printBT();
// 	std::cout << test.size() << std::endl;

// 	std::cout << "\nTESTIN ITERATORS" << std::endl;
// 	ft::map<int, std::string>::iterator it = test.begin();
// 	// std::cout << "Value at beginning: " << it->first << " " << it->second << std::endl;
// 	while (it != test.end()) {
// 		std::cout << "Value at next iteration: " << it->first << " " << it->second << std::endl;
// 		it++;
// 	}
// 	it--;
// 	std::cout << "This should be the last item: " << it->first << " " << it->second << std::endl;
// 	std::cout << "NOW BACKWARDS WITH REVERSE_ITERATOR" << std::endl;
// 	ft::map<int, std::string>::reverse_iterator rev_it = test.rbegin();
// 	while (rev_it != test.rend()) {
// 		std::cout << "Value at previous iteration: " << rev_it->first << " " << rev_it->second << std::endl;
// 		rev_it++;
// 	}
// 	test.insert(ft::pair<int, std::string>(4, "This shouldn't exist"));
// 	// test.printBT();


// 	ft::map<int, std::string>::iterator found = test.find(99);
// 	std::cout << "Found: " << found->second << std::endl;
// 	// ft::map<int, std::string>::iterator not_found = test.find(0);
// 	// std::cout << "Found: " << not_found->second << std::endl;

// 	std::cout << "Should be there " << test.count(99) << std::endl;
// 	std::cout << "Should not be there " << test.count(66) << std::endl;

// 	// std::cout << "\nSQUARE BRACKETSSS" << std::endl;

// 	std::cout << "\nLower_bound and sheet" << std::endl;

// 	std::cout << "Lower bound of 6: " << test.lower_bound(6)->first << std::endl;
// 	std::cout << "Upper bound of 6: " << test.upper_bound(6)->first << std::endl;

// 	std::cout << "Equal range with a match: " << test.equal_range(15).first->first << " " <<
// 		test.equal_range(15).second->first << std::endl;
// 	std::cout << "Equal range without a match: " << test.equal_range(87).first->first << " " <<
// 		test.equal_range(87).second->first << std::endl;


// 	std::cout << "\nRANGED INSERT LEZGO" << std::endl;
// 	// {
// 	ft::map<std::string, int>	range_rover;
// 	std::vector<ft::pair<std::string, int> > thething;
// 	thething.push_back(ft::make_pair("Carlo", 1));
// 	thething.push_back(ft::make_pair("Eugenio", 7));
// 	thething.push_back(ft::make_pair("Dé", 3));
// 	thething.push_back(ft::make_pair("Turlough", 99));
// 	thething.push_back(ft::make_pair("Cigio", 98));
// 	thething.push_back(ft::make_pair("Juanito", 69));
// 	thething.push_back(ft::make_pair("Pilerda", 66));
// 	thething.push_back(ft::make_pair("Lindsay", 700));
// 	thething.push_back(ft::make_pair("Perosh", 77));
// 	thething.push_back(ft::make_pair("DEfo", 88));

// 	range_rover.insert(thething.begin(), thething.end());

// 	std::cout << "\nERASING" << std::endl;

// 	std::cout << "Size before erasing two items: " << range_rover.size() << std::endl;

// 	range_rover.erase("DEfo");
// 	range_rover.erase("Dé");

// 	std::cout << "Size after erasing two items: " << range_rover.size() << std::endl;

// 	{	
// 		std::cout << "\nGonna clear the map, add a single element and erase it" << std::endl;
// 		range_rover.clear();
		
// 		std::cout << "Map is empty after clear()? " << range_rover.empty() << std::endl;
// 		range_rover.insert(thething.begin() + 2, thething.begin() + 3);
// 		std::cout << "Item inserted after clearing: " << range_rover.begin()->first << std::endl;
// 		range_rover.erase(range_rover.begin());
// 		std::cout << "Map is empty after erasing single item? " << range_rover.empty() << std::endl;
// 	}
// 	std::cout << "\nGonna be testin swap() now with test and another map" << std::endl;

// 	ft::map<int, std::string>	swappety;
// 	swappety.insert(ft::pair<int, std::string>(44, "M'importa"));
// 	swappety.insert(ft::pair<int, std::string>(22, "Una"));
// 	swappety.insert(ft::pair<int, std::string>(33, "Bella"));
// 	swappety.insert(ft::pair<int, std::string>(77, "Sega"));
// 	swappety.insert(ft::pair<int, std::string>(45, "A"));
// 	swappety.insert(ft::pair<int, std::string>(23, "Du mani"));

// 	swappety.swap(test);

// 	std::cout << "Contents of swappety:" << std::endl;
// 	for (ft::map<int, std::string>::iterator itery = swappety.begin(); itery != swappety.end(); itery++)
// 		std::cout << "item: " << itery->first << " containing: " << itery->second << std::endl;
	
// 	std::cout << "Contents of test:" << std::endl;
// 	for (ft::map<int, std::string>::iterator itest = test.begin(); itest != test.end(); itest++) {
// 		std::cout << "item: " << itest->first << " containing: " << itest->second << std::endl;
// 		// ft::map<int, std::string>::const_iterator& const_thing = reinterpret_cast<ft::map<int, std::string>::const_iterator&>(itest);
// 	}

// 	std::cout << "Erasing something not in swappety" << std::endl;
	
// 	swappety.erase(99);
	


// 	std::cout << "\nReverse_iterator with the iterator_traits." << std::endl;


// 	ft::map<int, std::string>::reverse_iterator	randello = swappety.rbegin();
// 	randello++;
// 	std::cout << randello->first << std::endl;

	
// }

// int		main() {
	
// 	test_basic();
// 	return 0;
// }


# if defined(unix) || defined(__unix__) || defined(__unix)
#  define LINUX 1
# else
#  define LINUX 0
# endif

size_t begintime;
size_t endtime;
struct timeval	tv;

template< typename K, typename V >
void	print_container_content(ft::map<K, V>& mappie, std::string name = "container") {
	std::cout << name << " contains:";
	// std::cout << "wtf 5real" << std::endl;
	for (typename ft::map<K, V>::const_iterator it = mappie.begin(); it != mappie.end(); it++)
		std::cout << ' ' << it->second;
	std::cout << " $" << std::endl;
}

template< typename K, typename V>
void	compare_keys(ft::map<K, V>& mappie, K compelem = K(), std::string name = "container") {
	typename ft::map<K, V>::key_compare kcomp = mappie.key_comp();
	(void)name;
	for (typename ft::map<K, V>::const_iterator it = mappie.begin(); it != mappie.end(); it++) {
		if (kcomp(it->first, compelem))
			std::cout << it->first << " is lower than " << compelem << std::endl;
		else if (kcomp(compelem, it->first))
			std::cout << it->first << " is higher than " << compelem << std::endl;
		else
			std::cout << it->first << " is equal to " << compelem << std::endl;
	}
}

template< typename K, typename V>
void	compare_values(ft::map<K, V>& mappie, ft::pair<K, V> compelem = ft::make_pair(K(), V()), std::string name = "container") {
	typename ft::map<K, V>::value_compare vcomp = mappie.value_comp();
	(void)name;
	for (typename ft::map<K, V>::const_iterator it = mappie.begin(); it != mappie.end(); it++) {
		if (vcomp(*it, compelem))
			std::cout << it->first << " is lower than " << compelem.first << std::endl;
		else if (vcomp(compelem, *it))
			std::cout << it->first << " is higher than " << compelem.first << std::endl;
		else
			std::cout << it->first << " is equal to " << compelem.first << std::endl;
	}
}

ft::map<int, std::string>	getstlmap() {
	ft::map<int, std::string> stl;
	stl[10] = "tien";
	stl[7] = "zeven";
	stl[6] = "zes";
	stl[13] = "dertien";
	stl[1] = "een";
	stl[4] = "vier";
	stl[3] = "drie";
	stl[8] = "acht";
	stl[14] = "veertien";
	return stl;
}	

void	ctors_dtor() {
	ft::map<int, std::string>	mappie;
	mappie.insert(ft::make_pair(0, "nul"));
	mappie.insert(ft::make_pair(1, "een"));
	mappie.insert(ft::make_pair(1, "een-1"));
	mappie.insert(ft::make_pair(1, "een-2"));
	mappie.insert(ft::make_pair(-1, "min een"));
	mappie.insert(ft::make_pair(5, "vijf"));

	print_container_content(mappie, "mappie");
	ft::map<int, std::string> wappie(mappie);
	wappie.insert(ft::make_pair(8, "acht"));
	wappie.insert(ft::make_pair(7, "zeven"));
	wappie.insert(ft::make_pair(7, "zeven-1"));
	print_container_content(wappie, "wappie");
	ft::map<int, std::string>::iterator it = wappie.begin();
	for (int i = 0; i < 4; i++)
		++it;
	ft::map<int, std::string>	range2(wappie.begin(), it);
	print_container_content(range2, "range2");
}

void	iterators() {
	ft::map<int, std::string>	stl = getstlmap();
	ft::map<int, std::string>	peer;

	// testing if the container is empty
	if (peer.begin() == peer.end())
		std::cout << "begin is the same as end" << std::endl;
	else std::cout << "begin is NOTTTT the same as end" << std::endl;
	peer.insert(stl.begin(), stl.end());

	ft::map<int, std::string>::iterator					it = peer.begin();
	ft::map<int, std::string>::reverse_iterator			rit = peer.rbegin();
	ft::map<int, std::string>::const_reverse_iterator	crit(rit);				// Just testing if you can convert a regular iterator to a const one
	ft::map<int, std::string>::const_iterator 			cit(it);				// Just testing if you can convert a regular iterator to a const one
	std::cout << "it gives: " << it->first << " ===> " << it->second << std::endl;
	std::cout << "cit gives: " << cit->first << " ===> " << cit->second << std::endl;
	std::cout << "rit gives: " << rit->first << " ===> " << rit->second << std::endl;
	std::cout << "crit gives: " << crit->first << " ===> " << crit->second << std::endl;

	// Testing if equal operators work
	if (it == cit)
		std::cout << "equal operator work on regular iterators " << it->first << " and " << cit->first << std::endl;
	if (rit == crit)
		std::cout << "equal operator work on reverse iterators " << rit->first << " and " << crit->first << std::endl;
	++it;
	it++;
	--it;
	it--;
	if (it != peer.end() && cit != peer.end())
		std::cout << "UNequal operator work on regular iterators " << (*it).first << " and " << (*cit).first << std::endl;
	if (rit != peer.rend() && crit != peer.rend())
		std::cout << "UNequal operator work on reverse iterators " << (*rit).first << " and " << (*crit).first << std::endl;
	it->second = "NIEUW";
//	it->first = 8;
	print_container_content(peer);
	ft::pair<int, std::string> ret = *it++;
	std::cout << "ret: " << ret.first << " => " << ret.second << std::endl;
	std::cout << " it: " << it->first << " => " << it->second << std::endl;
}

void 	capacity() {
	ft::map<int, std::string>	stl = getstlmap();
	ft::map<int, std::string>	mymap(stl.begin(), stl.end());
	std::cout << std::boolalpha << "mymap.empty() returns " << mymap.empty() << std::endl;
	std::cout << "mymap.size() returns " << mymap.size() << std::endl;
	// std::cout << "mymap.max_size() returns " << mymap.max_size() << std::endl;
}

void	element_access() {
	ft::map<int, std::string> in = getstlmap();
	print_container_content(in);
# if __cplusplus >= 201103L
	try {
		std::cout << "in.at(6) gives: " << in.at(6) << std::endl;
		std::cout << "in.at(5) gives: " << in.at(5) << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "exception thrown" << std::endl;
		// std::cerr << e.what() << std::endl;
	}
# endif
}

void	modifiers() {
	ft::map<int, std::string> mymap = getstlmap();
	mymap.insert(ft::make_pair(12, "twaalf"));
	mymap.insert(ft::make_pair(12, "twaalf"));
	mymap.insert(mymap.find(7), ft::make_pair(2, "negen"));
//	 mymap.printBT();

 	mymap.erase(1);
 	mymap.erase(13);
// //	 mymap.printBT();
 	mymap.erase(mymap.find(4));
 	mymap.erase(7);
	for (ft::map<int, std::string>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		std::cout << "it: " << it->first << " ==> " << it->second << std::endl;
	}
	ft::map<int, std::string> emptymap;
	std::cout << "wtf" << std::endl;
	// std::cout << "emptymap of course"
	emptymap.swap(mymap);
	std::cout << "wtf 4r" << std::endl;
	print_container_content(mymap);
	
	print_container_content(emptymap);
	std::cout << "wtf" << std::endl;
}

void	operations() {
	ft::map<int, std::string> mymap = getstlmap();
	print_container_content(mymap);
	ft::map<int, std::string>::iterator it = mymap.find(4);
	if (it == mymap.end())
		std::cout << "element not found!" << std::endl;
	else std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "i have " << mymap.count(1) << " elements with key = 1" << std::endl;
	std::cout << "i have " << mymap.count(2) << " elements with key = 2" << std::endl;
	std::cout << "i have " << mymap.count(3) << " elements with key = 3" << std::endl;

	it = mymap.lower_bound(6);
	std::cout << "lower bound of 6 returns: " << it->first << std::endl;
	it = mymap.upper_bound(6);
	std::cout << "upper bound of 6 returns: " << it->first << std::endl;
	it = mymap.upper_bound(14);
	if (it != mymap.end())
		std::cout << "upper bound of 14 returns: " << it->first << std::endl;
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> peer = mymap.equal_range(10);
	std::cout << "mymap.equal_range(10) gives a range from " << peer.first->first << " to " << peer.second->first << std::endl;
}

void	observers() {
	ft::map<int, int>	mymap;
	ft::map<int, int>	othermap;
	for (size_t i = 0; i < 20; i++) {
		mymap[i * 2] = i * 4;
		othermap[i * 3] = i * 6;
	}
	compare_keys(mymap, 18);
	compare_keys(othermap, 29);
	compare_values(mymap, ft::make_pair(18, 45));
	compare_values(othermap, ft::make_pair(29, 76));
}

void	tellyinspired() {
	ft::map<int, int>::iterator it;
	ft::map<int, int> mymap;
	mymap[18] = 87;
	mymap[30] = 67;
	mymap[22] = 6;
	mymap[17] = 238;
	mymap[15] = 8;
//	it = mymap.end();
//	it--;
//	mymap.printBT();
	std::cerr << std::endl;
//	std::cout << "it: " << it->first << " ==> " << it->second << std::endl;

	ft::map<int, int> stdmap;
	stdmap[14] = 14;
	stdmap[13] = 13;
	stdmap[10] = 10;
	stdmap[8] = 8;
	stdmap[3] = 3;
	stdmap[2] = 2;
	stdmap[6] = 6;
	stdmap[4] = 4;
	stdmap[7] = 7;
//	stdmap.printBT();
	for (size_t i = 0; i < 1000000; i++)
		stdmap[i] = i * i;

//	it = stdmap.find(13);
//	std::cout << "*it = " << it->first << " =>> " << it->second << std::endl;
//	it--;
//	std::cout << "*it-- = " << it->first << " =>> " << it->second << std::endl;
}

void	telly() {
	std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(10, 353));
	 	MyMap.insert(ft::make_pair(100, 4543));
	 	MyMap.insert(ft::make_pair(1000, 34534));
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> Range;
	 	Range.insert(ft::make_pair(10, 99));
	 	Range.insert(ft::make_pair(100, 999));
	 	Range.insert(ft::make_pair(1000, 9999));
	 	ft::map<int, int> MyMap(Range.begin(), Range.end());
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	std::cout << std::endl;
	{
		ft::map<int, int> Range;
		Range.insert(ft::make_pair(1, 80));
		Range.insert(ft::make_pair(-10, 57758));
		Range.insert(ft::make_pair(89, 34));
		std::cout << "distance: " << std::distance(Range.begin(), Range.end()) << std::endl;
		ft::map<int, int> MyMap(Range.begin(), Range.end());
		std::cout << "haha" << std::endl;
		ft::map<int, int>::iterator it = --MyMap.end();
		std::cout << "it: " << it->first << " => " << it->second << std::endl;
		ft::map<int, int>::iterator result = MyMap.insert(it, ft::make_pair(-666, 33333));
		std::cout << result->first << " => " << result->second << std::endl;
		for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << "for:\t" << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(-10, 57758));
	 	MyMap.insert(ft::make_pair(89, 34));
	 	ft::map<int, int>::iterator result = MyMap.find(89);
	 	std::cout << result->first << " => " << result->second << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(-10, 57758));
	 	MyMap.insert(ft::make_pair(89, 34));
	 	std::cout << (MyMap.lower_bound(2))->first << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(-10, 57758));
	 	MyMap.insert(ft::make_pair(89, 34));
	 	std::cout << (MyMap.lower_bound(88))->first << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(-10, 57758));
	 	MyMap.insert(ft::make_pair(89, 34));
	 	std::cout << (MyMap.equal_range(-5)).first->first << " --- " << (MyMap.equal_range(2)).second->first << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(100, 34));
	 	std::cout << MyMap[10] << std::endl;
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(100, 34));
	 	MyMap[10] = 99;
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(100, 34));
	 	MyMap[1000] = 99;
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }

	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.erase(MyMap.begin());
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(100, 34));
	 	MyMap.erase(MyMap.begin());
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	 std::cout << std::endl;
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(100, 34));
	 	MyMap.erase(10);
	 	for (ft::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
	 		std::cout << it->first << " => " << it->second << std::endl;
	 }
	 {
	 	ft::map<int, int> MyMap1;
	 	MyMap1.insert(ft::make_pair(10, 57758));
	 	MyMap1.insert(ft::make_pair(1, 80));
	 	MyMap1.insert(ft::make_pair(100, 34));


	 	ft::map<int, int> MyMap2;
	 	MyMap2.insert(ft::make_pair(10, 57758));
	 	MyMap2.insert(ft::make_pair(1, 80));
	 	MyMap2.insert(ft::make_pair(100, 34));

	 	if (MyMap1 == MyMap2)
	 		std::cout << "MyMap1 is equal to MyMap2" << std::endl;
	 	if (MyMap1 < MyMap2)
	 		std::cout << "MyMap1 is smaller than MyMap2" << std::endl;
	 	if (MyMap1 <= MyMap2)
	 		std::cout << "MyMap1 is smaller than or equal to MyMap2" << std::endl;
	 	if (MyMap1 > MyMap2)
	 		std::cout << "MyMap1 is larger than MyMap2" << std::endl;
	 	if (MyMap1 >= MyMap2)
	 		std::cout << "MyMap1 is larger than or equal to MyMap2" << std::endl;
	 	MyMap1.swap(MyMap2);
	 	if (MyMap1 < MyMap2)
	 		std::cout << "MyMap1 is smaller than MyMap2" << std::endl;
	 	if (MyMap1 <= MyMap2)
	 		std::cout << "MyMap1 is smaller than or equal to MyMap2" << std::endl;
	 	if (MyMap1 > MyMap2)
	 		std::cout << "MyMap1 is larger than MyMap2" << std::endl;
	 	if (MyMap1 >= MyMap2)
	 		std::cout << "MyMap1 is larger than or equal to MyMap2" << std::endl;
	 }
	 {
	 	ft::map<int, int> MyMap;
	 	MyMap.insert(ft::make_pair(10, 57758));
	 	MyMap.insert(ft::make_pair(1, 80));
	 	MyMap.insert(ft::make_pair(100, 34));

	 	for (ft::map<int, int>::reverse_iterator rit = MyMap.rbegin(); rit != MyMap.rend(); rit++)
	 		std::cout << rit->first << " => " << rit->second << std::endl;

	 	for (ft::map<int, int>::reverse_iterator rit = MyMap.rbegin(); rit != MyMap.rend(); ++rit)
	 		std::cout << rit->first << " => " << rit->second << std::endl;
	 }
}

void	bs() {
	ft::map<int, std::string> hats = getstlmap();
	ft::map<int, std::string>::iterator it = hats.begin();
	ft::map<int, std::string>::const_iterator cit = it;
	(void)cit;
}
int	main(int argc, char **argv) {
	// if (argc >= 2 && strcmp(argv[1], "time") == 0) {
	// 	gettimeofday(&tv, NULL);
	// 	begintime = tv.tv_usec;
	// }
	ctors_dtor();
	iterators();
	capacity();
	element_access();
	modifiers();
	observers();
	operations();
	tellyinspired();
	telly();
	bs();
	// if (argc >= 2 && strcmp(argv[1], "time") == 0) {
	// 	gettimeofday(&tv, NULL);
	// 	endtime = tv.tv_usec;
	// 	std::cerr << "Time elapsed in total! = " << endtime - begintime << " nanoseconds" << std::endl;
	// }
	if (argc == 3 && strcmp(argv[2], "leaks") == 0 && !LINUX) {
		int a = system("leaks containers.out | grep \"total leaked bytes\" >&2");
		(void)a;
	}
}