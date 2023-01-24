#include <stdbool.h>

struct Location {
	bool hit; 
	int c;
	int r;
};

struct Vessel {
	char name[20];
	bool sunk;
	unsigned int length;
	struct Location vesselLocations[5];
};
