// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/max-non-overlapping-bridges-official/ojquestion

// C++ implementation of building bridges
#include <bits/stdc++.h>

using namespace std;

// north-south coordinates
// of each City Pair
struct CityPairs
{
	int north, south;
};

// comparison function to sort
// the given set of CityPairs
bool compare(struct CityPairs a, struct CityPairs b)
{
	if (a.south == b.south)
		return a.north < b.north;
	return a.south < b.south;
}

// function to find the maximum number
// of bridges that can be built
int maxBridges(struct CityPairs values[], int n)
{
	int lis[n];
	for (int i=0; i<n; i++)
		lis[i] = 1;
		
	sort(values, values+n, compare);
	
	// logic of longest increasing subsequence
	// applied on the northern coordinates
	for (int i=1; i<n; i++)
		for (int j=0; j<i; j++)
			if (values[i].north >= values[j].north
				&& lis[i] < 1 + lis[j])
				lis[i] = 1 + lis[j];
		
		
	int max = lis[0];
	for (int i=1; i<n; i++)
		if (max < lis[i])
			max = lis[i];
	
	// required number of bridges
	// that can be built	
	return max;	
}

// Driver program to test above
int main()
{
	struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
	int n = 4;
	cout << "Maximum number of bridges = "
			<< maxBridges(values, n);
	return 0;
}
