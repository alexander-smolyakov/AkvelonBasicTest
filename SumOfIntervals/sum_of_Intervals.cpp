// Link on task -> https://www.codewars.com/kata/52b7ed099cdc285c300001cd
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> mergeIntervals(pair<int, int> first, pair<int, int> second)
{
	pair<int, int> mergedInterval = { 0, 0 };

	mergedInterval.first = min(first.first, second.first);
	mergedInterval.second = max(first.second, second.second);

	return mergedInterval;
}

void display(pair<int, int> A)
{
	cout << A.first << " " << A.second << endl;
}

bool canIntervalsBeMerged(pair<int, int> A, pair<int, int> B)
{
	bool canBeMerged = false;

	canBeMerged = (A.first < B.first && B.second < A.second) ||
		(B.first < A.first && A.second < B.second);

	if (!canBeMerged)
	{
		canBeMerged = ((A.first >= B.first && A.first <= B.second) ||
			(B.first >= A.first && B.first <= A.second));
	}

	return canBeMerged;
}

int calcSingleIntervalLength(pair<int, int> interval)
{
	if (interval.first < 0 && interval.second < 0)
		return abs(interval.first) - abs(interval.second);

	if (interval.first > 0 && interval.second > 0)
		return abs(interval.second) - abs(interval.first);

	if (interval.first < 0)
		return abs(interval.first) + interval.second;

	return interval.second - interval.first;
}

int sum_intervals(vector<pair<int, int>> intervals)
{
	sort(intervals.begin(), intervals.end());

	if (intervals.empty()) return 0;
	vector <pair<int, int>> mergedIntervals;
	mergedIntervals.emplace_back(intervals.front());

	for (int i = 1; i < intervals.size(); i++)
	{
		int j = 0;
		bool wasMerged = false;
		while (j < mergedIntervals.size())
		{
			if (canIntervalsBeMerged(mergedIntervals[j], intervals[i]))
			{
				mergedIntervals[j] = mergeIntervals(mergedIntervals[j], intervals[i]);
				wasMerged = true;
				break;
			}
			j++;
		}

		if (!wasMerged) mergedIntervals.emplace_back(intervals[i]);
	}

	int sumOfIntervals = 0;

	for_each(mergedIntervals.rbegin(), mergedIntervals.rend(), [&](pair<int, int> mergedInterval) { sumOfIntervals += calcSingleIntervalLength(mergedInterval); });

	return sumOfIntervals;
}

int main()
{
	// Test cases from Codewars
	vector<pair<int, int>> intervals; 
	intervals = { {1,2}, {6, 10}, {11, 15} };
	cout << "First test - > " << ((sum_intervals(intervals) == 9) ? "passed" : "error") << endl;

	intervals = { {1,4}, {7, 10}, {3, 5} };
	cout << "Second test - > " << ((sum_intervals(intervals) == 7) ? "passed" : "error") << endl;

	intervals = { {1,5}, {10, 20}, {1, 6}, {16, 19}, {5, 11} };
	cout << "Third test - > " << ((sum_intervals(intervals) == 19) ? "passed" : "error") << endl;

	return 0;
}