#pragma once

#include <stdlib.h>	// for srand and rand
#include <cassert>	// for assert
#include <ctime>	   // for time used in seed

using namespace std;

class RandomNumberGenerator
{
	public:
		// constructors
		// RandomNumberGenerator();

		// accessors
        static int get_random_value(int);

	private:
		// supporting functions
        static void seed();
};