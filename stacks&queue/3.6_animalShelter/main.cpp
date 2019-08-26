/*
    An animal shelter operates on a stricly fifo basis. People must adopt either the oldest of all animals
    or they can select whether they would prefer a dog or a cat (always the oldest). Create the data structure
    to maintain this system and implement operations such as enqueue, dequeue, dequeueDog, dequeueCat.
*/

#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
class Animal{
    private: int order;
    private: string type;
    public: Animal(){};
    public: Animal(string type, int order){
        this->type = type;
        this->order = order;
    }

    public: bool isOlder(Animal a){
        return this->order < a.order;
    }

    public: string getType(){
        return this->type;
    }
};

class AnimalQueue{
    private: queue<Animal> d;
    private: queue<Animal> c;

    public: void enqueue(Animal a){
        if(a.getType() == "dog") this->enqueueDog(a);
        else if(a.getType() == "cat") this->enqueueCat(a);
        else throw new exception();
    }
    
    public: void enqueueDog(Animal a){
        d.push(a);
    }

    public: void enqueueCat(Animal a){
        c.push(a);
    }

    public: Animal dequeue(){
        Animal a = Animal();
        if(d.front().isOlder(c.front())){
            return this->dequeueDog();
        } 
        return this->dequeueCat();
    }

    public: Animal dequeueDog(){
        Animal a = d.front();
        d.pop();
        return a;
    }

    public: Animal dequeueCat(){
        Animal a = c.front();
        c.pop();
        return a;
    }

};

int main(){
    
}