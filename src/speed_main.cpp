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


void	map_speed() {

	ft::map<int, int>	speedmap;

	for (int i = 0; i < COUNT; ++i)
	{
		speedmap.insert(ft::make_pair(rand(), rand()));
	}
	speedmap.count(76);

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += speedmap[access];
	}
	std::cout << "Constant here: " << sum << std::endl;
	{
		ft::map<int, int> copy = speedmap;
	}
}

void	vector_speed() {
	ft::vector<float>	speedvec;

	for (int i = 0; i < (INT_MAX / 10); i++) {
		speedvec.push_back((0.9 * rand()));
	}

	int sum = 0;
	for (int i = 0; i < 500; i++)
		sum += speedvec[i];
	std::cout << "Constant again: " << sum << std::endl;
	{
		ft::vector<float> copy = speedvec;
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
    time(&start);
  
    // unsync the I/O of C and C++.
	std::ios_base::sync_with_stdio(false);
	vector_speed();
	time(&end);
  
    // Calculating total time taken by the program.
    time_taken = double(end - start);
    std::cout << "Time taken by vector is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;



	// STACK shouldn't matter cause it just uses ft::vector anyway
	// time(&start);
  
	// std::ios_base::sync_with_stdio(false);
	// stack_speed();
	// time(&end);
  
    // // Calculating total time taken by the program.
    // double time_taken = double(end - start);
    // std::cout << "Time taken by stack is : " << std::fixed
    //      << time_taken << std::setprecision(5);
    // std::cout << " sec " << std::endl;
}
