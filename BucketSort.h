#pragma once
#ifndef BUCKETSORT_H
#define BUCKETSORT_H


class BucketSort
{
public:
	//Default Constructor
	BucketSort();

	//Overload Constructor
	BucketSort(int[], int);

	//Destructor
	~BucketSort();

	void sortIt();

private:
	int _size;
	int wArray[10];
	void printIt();
};

#endif