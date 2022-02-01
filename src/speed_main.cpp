#include <iostream>
#include <string>
#include <deque>
#include <chrono>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>
// #define STL 1
#if STL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif


#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {

// 	time_t start, end;
  
//     /* You can call it like this : start = time(NULL);
//      in both the way start contain total time in seconds 
//      since the Epoch. */
//     time(&start);
  
//     // unsync the I/O of C and C++.
//    std::ios_base::sync_with_stdio(false);
  
  
//     // Recording end time.
   
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		// std::cout << idx << std::endl;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		// std::cout << map_int[access] << std::endl;
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	std::cout << TEST << std::endl;
// 	time(&end);
  
//     // Calculating total time taken by the program.
//     double time_taken = double(end - start);
//     std::cout << "Time taken by program is : " << std::fixed
//          << time_taken << std::setprecision(5);
//     std::cout << " sec " << std::endl;
// 	return (0);
// }


void	map_speed() {

	ft::map<int, int>	speedmap;

	for (int i = 0; i < COUNT; ++i)
	{
		speedmap.insert(ft::make_pair(rand(), rand()));
	}
	// speedmap.count(76);

	int sum = 0;
	// int i = 0;
	// for (ft::map<int, int>::iterator it = speedmap.begin(); it != speedmap.end(); it++)
	// {
	// 	if (i == 20)
	// 		break;
	// 	std::cout << it->second << std::endl;
	// 	i++;
	// }
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		// if (i == 0){
		// 	std::cout << "access is: " << access << std::endl;
		// 	std::cout << "Can I find anything there? " << speedmap.find(access)->second << std::endl;
		// 	std::cout << "Why such a high number here? " << speedmap[access] << std::endl;
		// 	std::cout << "before " << sum << std::endl;
		// 	std::cout << typeid(sum).name() << std::endl;
		// 	std::cout << typeid(speedmap[access]).name() << std::endl;
		// 	std::cout << "Why such a high number here? " << speedmap[access] << std::endl;
		// }
		sum += speedmap[access];
		// if (i == 0){
		// 	std::cout << "after " << sum << std::endl;
		// 	std::cout << typeid(sum).name() << std::endl;
		// 	std::cout << typeid(speedmap[access]).name() << std::endl;
		// 	std::cout << "And now it is? " << speedmap[access] << std::endl;
		// }
		// if (i == 0){
		// 	std::cout << typeid(sum).name() << std::endl;
		// 	std::cout << typeid(speedmap[access]).name() << std::endl;
		// }
		// std::cout << speedmap[access];
	}
	std::cout << "Eh oh eh oh " << sum << std::endl;
	{
		ft::map<int, int> copy = speedmap;
	}
}

int		main(int argc, char *argv[]) {


	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);
	// MAP
	time_t start, end;
  
    time(&start);
  
	std::ios_base::sync_with_stdio(false);

	map_speed();

	time(&end);
  
    double time_taken = double(end - start);
    std::cout << "Time taken by map is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;


	// VECTOR
    // time(&start);
  
    // // unsync the I/O of C and C++.
	// std::ios_base::sync_with_stdio(false);
	// vector_speed();
	// time(&end);
  
    // // Calculating total time taken by the program.
    // double time_taken = double(end - start);
    // std::cout << "Time taken by map is : " << std::fixed
    //      << time_taken << std::setprecision(5);
    // std::cout << " sec " << std::endl;



	// STACK
	// time(&start);
  
	// std::ios_base::sync_with_stdio(false);
	// stack_speed();
	// time(&end);
  
    // // Calculating total time taken by the program.
    // double time_taken = double(end - start);
    // std::cout << "Time taken by program is : " << std::fixed
    //      << time_taken << std::setprecision(5);
    // std::cout << " sec " << std::endl;
}
