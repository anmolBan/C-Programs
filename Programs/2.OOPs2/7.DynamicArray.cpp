#include<iostream>
using namespace std;

class DynamicArray{

    int index;
    int size;
    int * arr;

    public:
    // Constructor
    DynamicArray(int size){
        index = 0;
        this -> size = size;
        arr = new int[this -> size];
    }

    // Copy Constructor
    DynamicArray(DynamicArray const & d){
        arr = new int[d.size];
        for(int i = 0; i < d.index; i++){
            arr[i] = d.arr[i];
        }
        index = d.index;
        size = d.size;
    }

    private:
    void resize(){
        int * newArr = new int[size * 2];
        for(int i = 0; i < index; i++){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
        size *= 2;
    }

    public:
    void add(int element){
        if(index == size){
            resize();
        }
        arr[index] = element;
        index++;
    }

    void add(int index, int element){
        if(index < this -> index){
            arr[index] = element;
            return;
        }

        else if(index == this -> index){
            arr[index] = element;
            this -> index++;
            return;
        }
        return;
    }

    int get(int index) const{
        if(index < this -> index){
            return arr[index];
        }
        else{
            return -1;
        }
    }

    void print()const{
        for(int i = 0; i < index; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Over-loading the Copy Assignment Operator
    void operator=(DynamicArray const & d){
        int * temp = new int[d.size];
        for(int i = 0; i < d.index; i++){
            temp[i] = d.arr[i];
        }
        delete [] arr;
        arr = temp;
        index = d.index;
        size = d.size;
    }
};

int main(){

    DynamicArray d1(5);
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();

    DynamicArray d2(5);
    d2.add(100);
    d2.print();

    d2 = d1;
    d1.add(0, 500);
    d2.print();

    DynamicArray d3(d2);
    d3.print();

}