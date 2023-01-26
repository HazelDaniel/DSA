#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::floor;
using std::vector;

void merge_sort(vector<int> &list, size_t s_index, size_t l_index);
void merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index);


int main (){
    cout << boolalpha;

    vector<int> arr_list {7,1,3,0,9,2,4,5};

    cout << "list before sorting : ";
    
    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    merge_sort(arr_list,0,7);

    for(auto const &item: arr_list){
        cout << item << " ";
    }
    
    cout << "" << endl;

    return 0;

}

void merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index){

    size_t n1{middle - s_index + 1};
    size_t n2{l_index - middle};

    vector<int> L (n1+1);
    vector<int> R (n2+1);


    for(size_t i {0}; i < n1; i ++){
        L.at(i) = list.at(s_index + i);
    }

    for(size_t j {0}; j < n2; j ++){
        R.at(j) = list.at(middle + j + 1);
    }

    L.at(n1) = static_cast<int>(MAXFLOAT);
    R.at(n2) = static_cast<int>(MAXFLOAT);

    size_t i {0};
    size_t j {0};

    for(size_t k {s_index}; k <= l_index; k++){

        if(L.at(i) <= R.at(j)){
            list.at(k) = L.at(i);
            i++;
        }else{
            list.at(k) = R.at(j);
            j++;
        }

    }

}

void merge_sort(vector<int> &list, size_t s_index, size_t l_index){
    
   if(s_index < l_index){

        size_t middle {static_cast<size_t>(floor((s_index + l_index)/2))};

        merge_sort(list, s_index, middle);
        merge_sort(list, middle + 1, l_index);
        merge(list,s_index,middle,l_index);
   }

}