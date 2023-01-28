#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int* selection_sort(int* list, size_t size);

int main (){
    cout << boolalpha;

    int arr_list [10] {7,1,3,0,9,8,2,1,4,2};

    cout << "list before sorting : ";
    
    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    
    int* sorted_arr = selection_sort(arr_list,10);

    for(size_t i{0}; i < 10; i++){
        cout << sorted_arr[i] << " ";
    }

    return 0;

}

int* selection_sort(int* list, size_t size){

    for(size_t i {0}; i < size - 1; i++){

        for(size_t j {i + 1}; j < size; j++){

            int key {list[i]};

            if(list[j] < key){
                list[i] = list[j];
                list[j] = key;
            }
        }


    }

    return list;
}