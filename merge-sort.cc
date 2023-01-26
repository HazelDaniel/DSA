#include <iostream>
#include <math.h>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::floor;


int* merge_sort(int* list, size_t s_index, size_t l_index);
void merge(int* list, size_t s_index, size_t middle, size_t l_index);

int main (){
    cout << boolalpha;

    int arr_list [6] {7,1,3,0,9,2};
    cout << "list before sorting : ";
    
    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    
    int* sorted_arr {merge_sort(arr_list,0,5)};
    for(size_t i{0}; i < 6; i++){
        cout << *(sorted_arr + i) << " ";
    }

    return 0;

}

void merge(int* list, size_t s_index, size_t middle, size_t l_index){

    size_t n1{middle - s_index + 1};
    size_t n2{l_index - middle};

    int L [n1+1];
    int R [n2+1];


    for(size_t i {0}; i < n1; i ++){
        L[i] = list[s_index + i];
    }

    for(size_t j {0}; j < n2; j ++){
        R[j] = list[middle + j];
    }

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    size_t i {0};
    size_t j {0};

    for(size_t k {s_index}; k <= l_index; k++){
        if(L[i] <= R[j]){
            list[k] = L[i];
            i++;
        }else{
            list[k] = R[j];
            j++;
        }
    }

}

int* merge_sort(int* list, size_t s_index, size_t l_index){
    
   if(s_index < l_index){

        size_t middle {static_cast<size_t>(floor((s_index + l_index)/2))};

        merge_sort(list, s_index, middle);
        merge_sort(list, middle + 1, l_index);
        merge(list,s_index,middle,l_index);
   }

    return list;
}