#include <iostream>
using namespace std;

template<class T1>
void insert_sort(T1 *arr,int N)
{
        for (int i = 1; i < N; i++)
        {
            T1 now = arr[i];
            int j ;
            for (j=i;j > 0 && arr[j-1] > now;  j--)
            {
                arr[j ] = arr[j-1];
              
            }
            arr[j] = now;
        }
    
}

template<class T3>
void select_sort(T3* arr, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[i])
            {
                T3 temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

template<class T4>
void bubble_sort(T4* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T4 temp = arr[j ];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<class T>
void quick_sort(T* arr, int left, int right)
{
    int tempLeft = left;
    int tempRight = right;
    T flag = arr[(tempLeft + tempRight) / 2];
    do
    {
        while (arr[tempLeft] < flag)tempLeft++;
        while (arr[tempRight] > flag)tempRight--;
        if (tempLeft <= tempRight)
        {
            T temp = arr[tempLeft];
            arr[tempLeft] = arr[tempRight];
            arr[tempRight] = temp;
            tempLeft++;
            tempRight--;
        }
    } while (tempLeft <= tempRight);
    if (left < tempRight)quick_sort(arr, left, tempRight);
    if (tempLeft <right)quick_sort(arr, tempLeft, right);
}
template<class T2>
void showArr(T2 *arr,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[12] = { 8,2,9,7,10,5,3,11,19,17,14,15 };
    double arr1[12] = { 8.12,2.25,9.78,9.87,10.25,10.77,8.24,11.97,11.65,17.22,17.88,15.56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int left = 0;
    int right = n1 - 1;
  // insert_sort(arr, n);
    select_sort(arr, n);
    bubble_sort(arr1, n1);
   // quick_sort(arr1, left,right);
    showArr(arr, n);
    showArr(arr1,n1);
    return 0;
}
