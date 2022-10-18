//
//  main.cpp
//  HW2 PIC10C
//
//  Created by Aral Muftuoglu
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "Heap.h"

using namespace std;

int main() {
    
    // Case 1: empty heap
    std::cout<< "**************** Case 1: test an empty heap **********" << std::endl;
    
    Heap<int> eh;
    eh.pop();
    print(eh);

    // Case2: test constructor
    std::cout<< "**************** Case 2: constructor **********" << std::endl;
    Heap<string> sh; // empty min-heap of strings
    std::vector<int> v={3,2,1,4,7,6,5};
    Heap<int, std::greater<int> > ih(v); // max-heap of integers
    Heap<Employee, CompareBySalary> ITgroup;
    print(sh,ih,ITgroup);
    
    // Case3: push
    std::cout<< "**************** Case 3: push function **********" << std::endl;
    sh.push("B","A", "C");
    sh.push("D");
    Employee tom("Tom", 100);
    Employee jim("Jim", 200);
    Employee jerry("Jerry", 101);
    ITgroup.push(tom);
    ITgroup.push(jerry);
    ITgroup.push(jim);
    ih.push(10);
    ih.push(10,20);
    print(sh, ih, ITgroup);
    
    
    // Case4: top and pop
    std::cout<< "**************** Case 4: top and pop  ****" << std::endl;
    std::cout << sh.top() << std::endl;
    sh.pop();
    print(sh);
    std::cout << sh.top() << std::endl;
    sh.pop();
    sh.pop();
    print(sh);
    print(sh);
    
    // case 5: display function. Your elements can appear in a different order, but it should display a valid heap structure.
    std::cout<< "**************** Case 5: display. Your elements may appear in a different order.  ****" << std::endl;
    ih.display();
    
    return 0;
}
