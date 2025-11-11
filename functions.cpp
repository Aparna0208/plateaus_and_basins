
#include <iostream>
#include "functions.h"

// returns the boolean value true if and only if 1,000 <= a <= b < 1,000,000,000,000
bool is_valid_range(long long a, long long b) {
	// TODO(student): return true if and only if 1,000 <= a <= b < 1,000,000,000,000
	return (a>=1000&&a<=b&&b < 1000000000000LL);
}

// returns the 'p' if number is a plateau, 'b' if number is a basin, and 'n' if number is neither
char classify_geo_type(long long number) {
// TODO(student): Initialize local variables
int n=0;
int digits[18];
long long temp=number;
	while (temp > 0) {
    temp /= 10;
    n++;
}

temp = number;
for (int i = n - 1; i >= 0; i--) {
    digits[i] = temp % 10;
    temp /= 10;
}

	// TODO(student): Determine whether number is a plateau: this is the key loop
    bool inc = false, constant = false, dec = false;
    int i = 1;

    while (i < n && digits[i] > digits[i-1]) { 
		inc = true; i++; 
	}
    while (i < n && digits[i] == digits[i-1]) { 
		constant = true; i++; 
	}
    while (i < n && digits[i] < digits[i-1]) {
		 dec = true; i++; 
	}
    if (i == n && inc && constant && dec) {
        return 'p';
    }

    // TODO(student): Determine whether number is a basin
    inc = constant = dec = false;
    i = 1;

    while (i < n && digits[i] < digits[i-1]) { 
		dec = true; i++; 
	}
    while (i < n && digits[i] == digits[i-1]) {
		 constant = true; i++; 
	}
    while (i < n && digits[i] > digits[i-1]) { 
		inc = true; i++; 
	}

    if (i == n && dec && constant && inc) {
        return 'b';
    }
// TODO(student): return the appropriate char, p for plateau, b for basin, n for neither
    return 'n';
}

	
// returns how many numbers in the range [a, b] are plateaus and basins
plateaus_and_basins count_pb_numbers(long long a, long long b) {
	int number_of_plateaus = 0;
	int number_of_basins = 0;
	number_of_plateaus=0;

	// TODO(student): count plateaus and basins in the range [a,b]
	
	
	for (long long num=a; num<=b; num++){
		char type = classify_geo_type(num);
		if (type =='p'){
			number_of_plateaus++;
		}
		if (type=='b'){
			number_of_basins++;
		}
	}
	return {number_of_plateaus, number_of_basins};
}

