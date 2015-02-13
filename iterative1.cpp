//-------------
/*
From:
http://www.softwareandfinance.com/Visual_CPP/Merge_Sort_Iterative.html
*/

#include <iostream>
#include <queue>
#include <vector>

// Usual merge/sort step
void DoMerge(int numbers[], int left, int mid, int right)
{
    int temp[25];

    auto left_end = (mid - 1);

    auto tmp_pos = left;

    auto num_elements = (right - left + 1);

    while ((left <= left_end) && (mid <= right)) {

        if (numbers[left] <= numbers[mid]) {

            temp[tmp_pos++] = numbers[left++];

        }  else {

            temp[tmp_pos++] = numbers[mid++];
        }
    }

    while (left <= left_end) {

        temp[tmp_pos++] = numbers[left++];
    }

    while (mid <= right)  {

        temp[tmp_pos++] = numbers[mid++];
    }

    for (auto i=0; i < num_elements; i++) {

        numbers[right--] = temp[right];
    }
}

struct MergePosInfo {

    int left;
    int mid;
    int right;
};

void Merge_Sort_Iterative(int numbers[], int left, int right)
{
    int mid;

    if (right <= left)
        return;

    std::vector<std::pair<int, int> > list;

    std::vector<MergePosInfo> mlist;

    list.push_back(std::pair<int, int>(left, right));

    MergePosInfo info;

    while(1) {

        if(list.size() == 0)

            break;

        left = list.back().first;

        right = list.back().second;

        list.pop_back();

        mid = (right + left) / 2;

        if(left < right) {

            info.left = left;

            info.right = right;

            info.mid = mid + 1;

            mlist.push_back(info);

            list.push_back(std::pair<int, int>(left, mid));

            list.push_back(std::pair<int, int>((mid+1), right));
        }
    }

    // Q: Why not simply use a stack and pop it at the end of the loop. 
    for(int i = mlist.size() - 1; i >= 0; i--) {

        DoMerge(numbers, mlist[i].left, mlist[i].mid, mlist[i].right);

    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    int arr[] = { 3, 8, 7, 5, 2, 1, 9, 6, 4 };

    int len = sizeof(arr) / sizeof(arr[0]);

    Merge_Sort_iterative(arr, 0, len - 1);

    for(int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
 
     return 0;
}
