/*
    PIC 10C Homework 2, Heap.h
    Purpose: Implement a template heap class
    Author: Aral Muftuoglu
    Date: 10/18/2022
*/


#ifndef Heap_h
#define Heap_h

#include <iostream>
#include <iomanip>
#include <vector>

// any heap with this structure, Heap<T>, has a CMP type of std::less<T> by default
template<typename T, typename CMP = std::less<T>>


//If an element is stored in i-th position, then its
//Left child is stored at index 2i+1
//Right child is stored at index 2i+2
//Parent is stored at [(i-1)/2]


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
        std::vector<T> getData();
        CMP getComparator();
        
    
    private:
        std::vector<T> data;
        CMP comparator;
};


// need empty function for recursive call
template<typename T, typename CMP>
Heap<T,CMP>::Heap() {
    // do nothing
}

template<typename T, typename CMP>
Heap<T,CMP>::Heap(std::vector<T> input) {
    
    // put elements in vector into heap structure
    for (int i = 0; i < input.size(); i++)
    {
        data.push_back(input[i]);
        int currentIndex = i;
        
        // swapping child and parent "nodes"
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

// need empty function for recursive call
template<typename T, typename CMP>
void Heap<T,CMP>::push() {
    // do nothing
}

template<typename T, typename CMP>
template<typename... Ts>
// T and Ts are of same type because of recursive call
void Heap<T,CMP>::push(T param1, Ts... params) {
    
    data.push_back(param1);
    
    int currentIndex = data.size()-1;
    
    // any data that is being added needs to be put into the heap structure accordingly:
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

// need empty function for recursive call
void print() {
    // do nothing
}


template<typename T, typename CMP, typename... Rest>
// Heap<T,CMP> and Rest are of same type because of recursive call
void print(Heap<T,CMP> param1, Rest... params)
{
    std::vector<T> printOrder = param1.getData();

    CMP copyComparator = param1.getComparator();
    
    // swap data 
    for (int i = 0; i < printOrder.size(); i++)
    {
        int pos = i;
        
        for (int j = i + 1; j < printOrder.size(); j++)
        {
            if (copyComparator(printOrder[j],printOrder[i]))
            {
                std::swap(printOrder[j],printOrder[i]);
            }
        }
        
        T temp = printOrder[pos];
        printOrder[pos] = printOrder[i];
        printOrder[i] = temp;
        
    }
    
    for (int i = 0; i < printOrder.size(); i++)
    {
        std::cout << printOrder[i] << '\t';
    }
    
    std::cout << std::endl;
    print(params...);
    
}



#endif /* Heap_h */
