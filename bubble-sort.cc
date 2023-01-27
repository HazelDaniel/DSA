#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int* bubble_sort(int* list, size_t size);

int main (){
    cout << boolalpha;

    int arr_list [10] {7,1,3,0,9,8,2,1,4,2};

    cout << "list before sorting : ";
    
    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    

    for(size_t i{0}; i < 10; i++){
        cout << bubble_sort(arr_list,10)[i] << " ";
    }

    return 0;

}

int* bubble_sort(int* list, size_t size){

    for(size_t j {0}; j < size - 1; j++){

        for(size_t i {size - 1}; i > 0; i--){

            int key {list[i]};

            if(list[i] < list[i - 1]){
                list[i] = list[i - 1];
                list[i - 1] = key;
            }
        }


    }

    return list;
}