//-------------
/*
From:
http://www.softwareandfinance.com/Visual_CPP/Merge_Sort_Iterative.html
*/

#include <iostream>
#include <queue>
#include <vector>

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

    for(int i = mlist.size() - 1; i >= 0; i--) {

        DoMerge(numbers, mlist[i].left, mlist[i].mid, mlist[i].right);

    }

}

void MergeSortHelper(int numbers[], int array_size)
{
    Merge_Sort_Iterative(numbers, 0, array_size - 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
    int arr[] = { 3, 8, 7, 5, 2, 1, 9, 6, 4 };

    int len = sizeof(arr) / sizeof(arr[0]);

    MergeSortHelper(arr, len);

    for(int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
 
     return 0;
}
//--------------
// This is the start of an iterative version of merge sort based on C code (below), but not yet begun.

// It merges pairs of two consecutive lists one after another.
// After scanning the whole array to do the above job,
// it goes to the next stage. Variable k controls the size
// of lists to be merged. k doubles each time the main loop
// is executed.
#include <stdio.h>
#include <math.h>
int i,n,t,k;
int a[100000],b[100000];
int merge(int l,int r,int u)
{ 
  int i,j,k;

  i = l;
  j = r; 
  k = l;

  while (i<r && j<u) { 

   if (a[i]<=a[j]) {

      b[k]=a[i]; i++;

   } else {

     b[k] = a[j];
     j++;
   }

    k++;
  }

  while (i<r) { 

    b[k]=a[i];
    i++;
    k++;
  }

  while (j < u) { 

    b[k]=a[j];
    j++;
    k++;
  }
  for (k=l; k<u; k++) { 
    a[k]=b[k]; 
  }
}
void sort()
{ 
  int k,u;
  k = 1;

  while (k<n) {

    i=1;

    while (i+k<=n) {

      u=i+k*2;

      if (u>n) 
         u=n+1;

      merge(i,i+k,u);

      i = i + k *2;
    }

    k = k * 2;
  }
}
main()
{
 printf("input size \n");

  scanf("%d",&n); 
/*  for (i=1;i<=n;i++) scanf("%d",&a[i]); */

  for (i=1;i<=n;i++) 
     a[i]=random()%1000;

  t=clock();

  sort();

  for (i=1;i<=10;i++) 
    printf("%d ",a[i]);

  printf("\n");

  printf("time= %d millisec\n",(clock()-t)/1000);
}
