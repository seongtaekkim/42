#include <iostream>
#include <vector>
using namespace std;

vector<int> sorted;
// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void Merge(vector<int>& v,int start,int mid,int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;
	//분할 정렬된 리스트 합병
	while (i <= mid && j <= end)
	{
		if (v[i] <= v[j])
		{
			sorted[k] = v[i];
			i++;
		}
		else
		{
			sorted[k] = v[j];
			j++;

		}
		k++;
	}

	int entry = (i > mid) ? j:i;
	int target= (i > mid) ? end : mid;
	//남아 있는 값들 복사 
	for (int t = entry; t <= target; ++t)
	{
		sorted[k] = v[t];
		k++;
	}
	//정렬된 임시 리스트를  원래 리스트에 복사 
	for (int t = start; t <= end; ++t)
	{
		v[t] = sorted[t];
	}



}

void MergeSort(vector<int>& v, int start, int end)
{
	if (sorted.size() == 0)
	{
		sorted= vector<int>(v.size());
	}
	if (start < end)
	{
		int mid = (start + end) / 2;  // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		MergeSort(v, start, mid);  // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		MergeSort(v, mid + 1, end); // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		Merge(v,start, mid,end); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)


	}
}
#include <sys/time.h>

int main()
{
	vector<int> v = { 5,4,3,2,1 };
		struct timeval start, end;
	double elapsed;

	gettimeofday(&start, NULL);
	MergeSort(v, 0, v.size() - 1);
		gettimeofday(&end, NULL);
	elapsed = end.tv_usec - start.tv_usec;
	printf("%lf\n", elapsed / CLOCKS_PER_SEC);
    double time = elapsed / CLOCKS_PER_SEC;
	for (auto& e : v)
	{
		cout << e;

	}


	return 0;
}