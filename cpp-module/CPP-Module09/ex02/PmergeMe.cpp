#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int argc, char *data[]) {
	merge(argc, data, this->_lstOG, this->_listSorted, this->_timerList);
	merge(argc, data, this->_vecOG, this->_vecSorted, this->_timerVector);
}

PmergeMe::PmergeMe(PmergeMe& input) {
    *this = input;
}

PmergeMe& PmergeMe::operator=(PmergeMe& input){
    this->~PmergeMe();
    new PmergeMe(input);
    return(*this);
}

PmergeMe::~PmergeMe(void) {}

template <typename T, typename K, typename S>
void PmergeMe::merge(int argc, char *sequence[], T& t, K& k, S& time) {
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(sequence[i]);
        t.push_back(value);
    }
	struct timeval start, end;
	double elapsed;

    k = t;
	gettimeofday(&start, NULL);
    mergeSort(k);
	gettimeofday(&end, NULL);
	elapsed = end.tv_usec - start.tv_usec;
	printf("%lf %lf\n", elapsed, elapsed / CLOCKS_PER_SEC);
    time = elapsed / CLOCKS_PER_SEC;
}

void PmergeMe::mergeSort(std::list<int> &lst) {
    if (lst.size() <= 1)
		return;

    std::list<int> left;
    std::list<int> right;

    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);

    left.splice(left.begin(), lst, lst.begin(), mid);
    right.splice(right.begin(), lst, mid, lst.end());

    mergeSort(left);
    mergeSort(right);

    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            lst.push_back(*it_left++);
        } else {
            lst.push_back(*it_right++);
        }
    }

    lst.splice(lst.end(), left, it_left, left.end());
    lst.splice(lst.end(), right, it_right, right.end());
}

void PmergeMe::Merge3(std::vector<int>& v,int start,int mid,int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if (this->_vecOG[i] <= this->_vecOG[j]) {
			v[k] = this->_vecOG[i];
			i++;
		}
		else {
			v[k] = this->_vecOG[j];
			j++;
		}
		k++;
	}

	int entry = (i > mid) ? j:i;
	int target= (i > mid) ? end : mid;
	//남아 있는 값들 복사 
	for (int t = entry; t <= target; ++t)
	{
		v[k] = this->_vecOG[t];
		k++;
	}
	//정렬된 임시 리스트를  원래 리스트에 복사 
	for (int t = start; t <= end; ++t) {
		this->_vecOG[t] = v[t];
	}

}

void PmergeMe::mergeSort2(std::vector<int>& v, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort2(v, start, mid);
		mergeSort2(v, mid + 1, end);
		Merge3(v,start, mid,end);
	}
}

void PmergeMe::mergeSort(std::vector<int> &v) {
    mergeSort2(v, 0, v.size() );
}

void PmergeMe::show(void) {

    std::cout << "Before: ";
    int counter = 0;
    std::list<int>::iterator it = _lstOG.begin();
    while (counter != 5 && it != _lstOG.end()) {
        std::cout << *it << " ";
        ++it; 
        ++counter;
    }
    if (it != _lstOG.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;

    std::cout << "After: ";
    int scounter = 0;
    std::list<int>::iterator sit = _listSorted.begin();
    while (scounter != 5 && sit != _listSorted.end()) {
        std::cout << *sit << " ";
        ++sit; 
        ++scounter;
    }
    if (sit != _listSorted.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;

    std::cout << "Time to process a range of " << _listSorted.size() << " elements with std::list<>: ";
    std::cout << std::fixed << std::setprecision(5) << _timerList * 1000000 << " us" << std::endl;

    std::cout << "Time to process a range of " << _vecOG.size() << " elements with std::vector<>: ";
    std::cout << std::fixed << std::setprecision(5) << _timerVector* 1000000 << " us" << std::endl;
}