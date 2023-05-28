#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int argc, char *data[]) {
	merge(argc, data, this->_lstOG, this->_listSorted, this->_timerList);
	merge(argc, data, this->_vecOG, this->_vecSorted, this->_timerVector);
}

PmergeMe::PmergeMe(PmergeMe& input) {
    *this = input;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other){
    if (this != &other) {
        this->_lstOG = other._lstOG;
        this->_listSorted = other._listSorted;
        this->_vecOG = other._vecOG;
        this->_vecSorted = other._vecSorted;
        this->_vecTmp = other._vecTmp;
        this->_timerList = other._timerList;
        this->_timerVector = other._timerVector;
    }
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

    k = t;
	gettimeofday(&start, NULL);
    mergeSort(k);
	gettimeofday(&end, NULL);
	time = end.tv_usec - start.tv_usec;
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

	while (i <= mid && j <= end) {
		if (this->_vecTmp[i] <= this->_vecTmp[j]) {
			v[k] = this->_vecTmp[i];
			i++;
		}
		else {
			v[k] = this->_vecTmp[j];
			j++;
		}
		k++;
	}

	int entry = (i > mid) ? j:i;
	int target= (i > mid) ? end : mid;
	for (int t = entry; t <= target; ++t) {
		v[k] = this->_vecTmp[t];
		k++;
	}
	for (int t = start; t <= end; ++t) {
		this->_vecTmp[t] = v[t];
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
    this->_vecTmp = this->_vecOG;
    mergeSort2(v, 0, v.size()-1);
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



    std::cout << "Before: ";
    int counter2 = 0;
    std::vector<int>::iterator it2 = _vecOG.begin();
    while (counter2 != 5 && it2 != _vecOG.end()) {
        std::cout << *it2 << " ";
        ++it2; 
        ++counter2;
    }
    if (it2 != _vecOG.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;

    std::cout << "After: ";
    int scounter2 = 0;
    std::vector<int>::iterator sit2 = _vecSorted.begin();
    while (scounter2 != 5 && sit2 != _vecSorted.end()) {
        std::cout << *sit2 << " ";
        ++sit2; 
        ++scounter2;
    }
    if (sit2 != _vecSorted.end())
        std::cout << " [...]\n";
    else
        std::cout << std::endl;


    std::list<int>::iterator lit = this->_listSorted.begin();
    std::vector<int>::iterator vit = this->_vecSorted.begin();

    for (unsigned long i = 0 ; i < _listSorted.size() ; i++) {
        if (*lit != *vit) {
            throw std::runtime_error("not matched sorted list, vector");
        }
        lit++;
        vit++;
    }

    std::cout << "Time to process a range of " << _listSorted.size() << " elements with std::list<>: ";
    std::cout << std::fixed << std::setprecision(5) << _timerList << " us" << std::endl;

    std::cout << "Time to process a range of " << _vecOG.size() << " elements with std::vector<>: ";
    std::cout << std::fixed << std::setprecision(5) << _timerVector << " us" << std::endl;
}