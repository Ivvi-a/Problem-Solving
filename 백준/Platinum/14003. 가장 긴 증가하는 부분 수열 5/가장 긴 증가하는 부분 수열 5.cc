#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
int A[1000000], V[1000000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	vector<int> vec; 
	vec.push_back(A[0]);
    memset(V, -1, sizeof(V));
	V[0] = 0;
	for (int i = 1; i < N; ++i) {
		if (vec.back() < A[i])
		{
			vec.push_back(A[i]);
			V[i] = vec.size() - 1;
		}
		else
		{
			int start = 0; 
			int end = vec.size() - 1;
			int mid = end;

			while (start < end)
			{
				mid = (start + end) / 2; // (start = 0 + end = 3)  2 = 1 

				if (vec[mid] < A[i]) // ex) vec[] = 10,(*)15, 18, 25, 30 <--- push (20)
				{
					start = mid + 1;
				}
				else // ex) vec[] = 10, 15, 18,(*)25 30 <--- push (20)
				{
					end = mid;
				}

			}
            vec[end] = A[i];
			V[i] = end;
		}
	}
	//=======================================//
	vector<int> _result;
	int index = vec.size() - 1;

	for (int i = N; i >= 0; --i)
	{
		if (V[i] == index)
		{
			_result.push_back(A[i]);
			--index;
		}
	}
	//=======================================//
	cout << vec.size() << "\n";

	reverse(_result.begin(), _result.end());

	for (auto& res : _result)
	{
		cout << res << " ";
	}
	return 0;
}