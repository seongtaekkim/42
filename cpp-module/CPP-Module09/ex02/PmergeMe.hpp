#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <iomanip>
#include <limits>
#include <sys/time.h>

class PmergeMe {

private:
	std::list<int>      _lstOG;
	std::list<int>      _listSorted;

	std::vector<int>    _vecOG;
	std::vector<int>    _vecSorted;

	double               _timerList;
	double               _timerVector;

public:
	PmergeMe(void);
	PmergeMe(int argc, char *data[]);
	PmergeMe(PmergeMe& input);
	PmergeMe& operator=(PmergeMe& input);
	~PmergeMe(void);

	void show(void);
	template <typename T, typename K, typename S>
	void merge(int argc, char *sequence[], T& t, K& k, S& time);
	void mergeSort(std::list<int>& lst);
	void mergeSort(std::vector<int>& vec);
	void mergeSort2(std::vector<int>& vec, int start, int end);
	void Merge3(std::vector<int>& v,int start,int mid,int end);
};

#endif