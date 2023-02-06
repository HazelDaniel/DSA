#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::floor;
using std::vector;

size_t merge_sort(vector<int> &list, size_t s_index, size_t l_index);
size_t merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index);


int main (){
    cout << boolalpha;

    vector<int> arr_list {1,4,0,6,2,8};


    cout << "list before sorting : ";

    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << endl;

    cout << merge_sort(arr_list,0,arr_list.size() - 1) << " inversions found in the array" << endl;
    cout << "list after sorting : ";

    for(auto const &item: arr_list){
        cout << item << " ";
    }
    
    cout << "" << endl;

    return 0;

}

size_t merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index){

    size_t inv{0};
    size_t n1 {middle - s_index + 1};
    size_t n2 {l_index - middle};

    vector<int> L (n1+1);
    vector<int> R (n2+1);

    for(size_t i {0}; i < n1; i++){
        L.at(i) = list.at(s_index + i);
    };
    for(size_t j {0}; j < n2; j++){
        R.at(j) = list.at(middle+j);
    }

    size_t i {0};
    size_t j {0};
    size_t k {s_index};

    while(i != n1 && j != n2){
        if(L.at(i) <= R.at(j)){
            list.at(k) = L.at(i);
            i++;
        }else{
            list.at(k) = R.at(j);
            inv+=j;
            j++;
        }
    }
    if(i == n1){
        for(size_t m {j}; m < n2; m++){
            list.at(k) = R.at(m);
            k++;
        }
    }
    if(j == n2){
        for(size_t m {i}; m < n1; m++){
            list.at(k) = L.at(m);
            inv+=n2;
            k++;
        }
    }
    return inv;


}

size_t merge_sort(vector<int> &list, size_t s_index, size_t l_index){
    
    size_t inv {0};

    if(s_index < l_index){

        size_t middle {static_cast<size_t>(floor((s_index + l_index)/2))};
        size_t left {0};
        size_t right {0};


        left = merge_sort(list, s_index, middle);
        right = merge_sort(list, middle + 1, l_index);
        inv = merge(list,s_index,middle,l_index) + left + right;
    }
    return inv;

}