#include <stdlib.h>
#include <iostream>
using namespace std;
/**
 * Simple implementation of ArrayList
 */
class Arraylist {
    private: int* array;
    private: int size;
    private: int dim;
    public: Arraylist() { 
        array = new int[1];
        size = 1;
        dim = 0;
    };
    /**
     * push an element into the arraylist
     */
    public: void push_back(int n){
        if(dim >= size){
            //cout << "in" << endl;
            int tmp[size];
            for(int i = 0; i < size; i++){
                tmp[i] = array[i];
                 //cout << tmp[i] << " ";
            }
            //cout << endl;
            size *= 2;
            array = new int[size];
            for(int i = 0; i < size/2; i++){
                array[i] = tmp[i];
                //cout << array[i] << " ";
            }
            //cout << endl;
        }
        array[dim] = n;
        dim++;
    }

    public: void print(){
        cout << "ArrayList: ";
        for(int i = 0; i < dim; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

int main(){
    Arraylist al = Arraylist();
    al.push_back(3);
    al.push_back(2);
    al.push_back(5);
    al.print();
}