#include <iostream>
#include <fstream>
using namespace std;

template <class type> void input(type arr[], int n) {
   ifstream input;
   input.open("input.txt", ios::in);
   for(int i=0; i<n; i++) {
    cin>>arr[i];
   }
   input.close();
}

template <class type> int part(type arr[], int l, int r) {
   int i = l-1;
   for(int j=l; j<r; j++) {
    if(arr[j]<arr[r]) {
        i++;
        swap(arr[i], arr[j]);
    }
   }
   swap(arr[i+1], arr[r]);
   return i+1;
}

template <class type> void quicksort(type arr[], int l, int r) {
   if(l<r) {
    int m = part(arr, l, r);
    quicksort(arr, l, m-1);
    quicksort(arr, m+1, r);
   }
}
int main() {
    int arr[4] = {3,1,4,5};
    quicksort(arr,0,3);
    for(int i=0; i<4; i++) {
        cout<<arr[i]<<" ";
    }
   return 0;
}
