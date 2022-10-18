/*
    PIC 10C Homework 2, Heap.h
    Purpose: Implement a template heap class
    Author: Aral Muftuoglu
    Date: 10/18/2022
*/


#ifndef Heap_hpp
#define Heap_hpp

#include <vector>


template<typename T, typename CMP = std::less<T>>

class Heap {
    
    public:
        Heap();
        Heap(std::vector <T> input);
        void display();
        void push();
        template<typename... Ts>
        void push(T param1, Ts... params);
        T top();
        void pop();
        bool isEmpty();
        std::vector<T> getData();
        CMP getComparator();
        
    
    private:
        std::vector<T> data;
        CMP comparator;
       
    
};


//If an element is stored in i-th position, then its
//Left child is stored at index 2i+1
//Right child is stored at index 2i+2
//Parent is stored at [(i-1)/2]

template<typename T, typename CMP>
Heap<T,CMP>::Heap() {
    // do nothing
}

template<typename T, typename CMP>
Heap<T,CMP>::Heap(std::vector<T> input) {
    
    for (int i = 0; i < input.size(); i++)
    {
        data.push_back(input[i]);
        int currentIndex = i;
        
        while (comparator(data[currentIndex], data[(currentIndex-1)/2]))
        {
            T temp = data[(currentIndex-1)/2];
            data[(currentIndex-1)/2] = data[currentIndex];
            data[currentIndex] = temp;
            
            currentIndex = (i-1)/2;
        }
    }
}

template<typename T, typename CMP>
void Heap<T,CMP>::display() {
    
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << '\t';
    }
}

template<typename T, typename CMP>
void Heap<T,CMP>::push() {
    // do nothing
}

template<typename T, typename CMP>
template<typename... Ts>
void Heap<T,CMP>::push(T param1, Ts... params) {
    
    data.push_back(param1);
    
    int currentIndex = data.size()-1;
    
    while (comparator(data[currentIndex], data[(currentIndex-1)/2]))
    {
        T temp = data[(currentIndex-1)/2];
        data[(currentIndex-1)/2] = data[currentIndex];
        data[currentIndex] = temp;
        
        currentIndex = (currentIndex-1)/2;
    }
    push(params...);
}


template<typename T, typename CMP>
T Heap<T,CMP>::top() {
    
    return data[0];
}


template<typename T, typename CMP>
void Heap<T,CMP>::pop() {
    
    if (data.size() == 0)
    {
        return;
    }
    
    data.erase(data.begin());
    
}

template<typename T, typename CMP>
std::vector<T> Heap<T,CMP>::getData() {
    
    return data;
}

template<typename T, typename CMP>
CMP Heap<T,CMP>::getComparator() {
    
    return comparator;
}

void print() {
    // do nothing
}


template<typename T, typename CMP, typename... Rest>

void print(Heap<T,CMP> param1, Rest... params)
{
    
    std::vector<T> printOrder = param1.getData();
    CMP copyComparator = param1.getComparator();
    
    std::sort(printOrder.begin(), printOrder.end(), copyComparator);
    
    for (int i = 0; i < printOrder.size(); i++)
    {
        std::cout << printOrder[i] << '\t';
    }
    
    std::cout << std::endl;
    print(params...);
    
}



#endif /* Heap_hpp */
