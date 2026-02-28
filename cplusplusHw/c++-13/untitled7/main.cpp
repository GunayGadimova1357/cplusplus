#include <iostream>

template <typename T>
void fill_arr(T* arr, unsigned short size);

template <typename T>
void display_arr(T* arr, unsigned short size);

template <typename T>
void append_el(T* &arr, unsigned short &size, T element );

template <typename T>
void pop_el(T* &arr, unsigned short &size);

template <typename T>
void insert_el(T* &arr, unsigned short &size, int index,  T element_to_insert);

template <typename T>
void clear(T* &arr, unsigned short &size);

int main(){
    unsigned short size;
    std::cout<<"enter size: ";
    std::cin>>size;
    int* arr{new int[size]};
    fill_arr(arr, size);
    std::cout<<"your array: ";
    display_arr(arr, size);

    while(true) {
        std::cout<<"your new array: ";
        display_arr(arr, size);
        int choice;
        std::cout<<"1. pop element\n"
                   "2. insert element\n"
                   "3. append element\n"
                   "4. clear\n"
                   "5. exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>choice;

        int index;
        int element_to_insert;
        int element_to_append;
        if(choice == 1) {
            pop_el(arr, size);
        }
        else if(choice == 2) {
            std::cout<<"index(1-)?"<<std::endl;
            std::cin>>index;
            std::cout<<"your element to insert: "<<std::endl;
            std::cin>>element_to_insert;
            insert_el(arr, size, index, element_to_insert);
        }
        else if(choice == 3) {
            std::cout<<"your element to append: "<<std::endl;
            std::cin>>element_to_append;
            append_el(arr, size, element_to_append);
        }
        else if(choice == 4) {
            clear(arr, size);
        }
        else if(choice == 5) {
            break;
        }
        else {
            std::cout<<"wrong choice"<<std::endl;
        }
    }

    delete[] arr;

    return 0;
}
template <typename T>
void fill_arr(T* arr, unsigned short size){
    srand(time(NULL));

    for(unsigned short  i=0; i<size; i++){
        arr[i]=rand()%100;
    }
}
template <typename T>
void display_arr(T* arr, unsigned short size){
    for (int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }std::cout<<std::endl;
}
template <typename T>
void append_el(T* &arr, unsigned short &size, T element){
    T* temp_arr= new T[size+1];
    for (int i=0; i<size; i++){
        temp_arr[i]=arr[i];
    }
    temp_arr[size]=element;
    delete[] arr;

    arr= temp_arr;
    size++;
}
template <typename T>
void pop_el(T *&arr, unsigned short &size){
    T* temp_arr= new T[size-1];
    for (int i=0; i<size; i++){
        temp_arr[i]=arr[i];
    }

    delete[] arr;

    arr= temp_arr;
    size--;
}
template <typename T>
void insert_el(T* &arr, unsigned short &size, int index, T element_to_insert){
if(index<=size){
    T* temp_arr= new T[size+1];
    for (int i=0; i<size; i++){
        temp_arr[i]=arr[i];
    }
    temp_arr[index-1]=element_to_insert;

    for (int i=index-1; i<size; i++){
        temp_arr[i+1]=arr[i];
    }
    delete[] arr;

    arr= temp_arr;
    size++;
}
else{
    T* temp_arr= new T[size+1];
    for (int i=0; i<size; i++){
        temp_arr[i]=arr[i];
    }
    temp_arr[size]=element_to_insert;
    delete[] arr;

    arr= temp_arr;
    size++;

}

}

template <typename T>
void clear(T* &arr, unsigned short &size) {
    delete[] arr;
    arr = nullptr;
    size = 0;
}
