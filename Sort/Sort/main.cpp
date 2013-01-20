//
//  main.cpp
//  Sort
//
//  Created by Salil Jain on 8/7/12.
//  Copyright (c) 2012 SaachiTech. All rights reserved.
//

#include <iostream>
#include "Heap.cpp"
#include "MergeSort.cpp"
void testMergeSort();
void testHeap();

void testMergeSort()
{
    vector<double> data;
    data.push_back(1.6);
    data.push_back(1.4);
    data.push_back(2.6);
    data.push_back(4.4);
    data.push_back(0.6);
    data.push_back(-1.4);
    MergeSort<double> mergeSort(&data);
    mergeSort.sort();
    cout<<"Sorted data ";
    for(int i=0;i<data.size();i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void testHeap()
{
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
}
int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    testMergeSort();
    return 0;
}

