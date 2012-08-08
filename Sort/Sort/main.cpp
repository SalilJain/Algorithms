//
//  main.cpp
//  Sort
//
//  Created by Salil Jain on 8/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Heap.cpp"
int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    int size=5;
    int errorCode=0;
    /*int * tree=(int*)malloc(sizeof(int)*size);
    tree[0]=1;
    tree[1]=4;
    tree[2]=2;
    tree[3]=3;
    tree[4]=5;
    Heap<int>  heap(tree,size,2);
    std::cout<<heap;
    
    for(int i=0;i<size;i++)
    {
        int value=heap.popNode(&errorCode);
        if(errorCode ==0)
            std::cout<<"Pop "<<value<<std::endl;
        else
            std::cout<<"Tree exhausted"<<std::endl;
        std::cout<<heap;
    }*/
    double * data=(double*)malloc(sizeof(double)*size);
    data[0]=1.6;
    data[1]=1.4;
    data[2]=2.4;
    data[3]=3.3;
    data[4]=1.5;
    Heap<double>  heapdbl(3);
    std::cout<<heapdbl;
    heapdbl.addNode(3.9, &errorCode);
    std::cout<<heapdbl;
    heapdbl.addNode(1.6, &errorCode);
    std::cout<<heapdbl;

    heapdbl.addNode(2.7, &errorCode);
    std::cout<<heapdbl;
    heapdbl.addNode(1.9, &errorCode);
    std::cout<<heapdbl;
    heapdbl.addNode(2.6, &errorCode);
    std::cout<<heapdbl;
    
    heapdbl.addNode(0.7, &errorCode);
    std::cout<<heapdbl;
    double value=heapdbl.popNode(&errorCode);
    while(errorCode==0)
    {
        
        if(errorCode ==0)
            std::cout<<"Pop "<<value<<std::endl;
        std::cout<<heapdbl;
        value=heapdbl.popNode(&errorCode);
        
    }
    return 0;
}
