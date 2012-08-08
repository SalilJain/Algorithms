//
//  Heap.h
//  QuickSort
//
//  Created by Salil Jain on 8/6/12.
//  Copyright (c) 2012 SaachiTech. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <ostream>
template <class T>
class Heap {
private:
    int size;
    T* tree;
    void upHeap(int position);
    void downHeap(int position);
    void swap(int from, int to);
    int mary;
public:
    Heap(T* data,int _size,int _mary);
    Heap(int _mary);
    void addNode(T value,int * errorCode);
    T popNode(int * errorCode);
    
    template <class TT> friend std::ostream& operator<<(std::ostream &o, Heap<TT> heap);
    
};
template <class T> std::ostream& operator<<(std::ostream &out, Heap<T> heap)
{
    for(int i=0;i<heap.size;i++)
        out<<heap.tree[i]<<" ";
    out<<std::endl;
    return out;
}

template <class T> void Heap<T>::swap(int from, int to)
{
    T value=tree[from];
    tree[from]=tree[to];
    tree[to]=value;
}
template <class T> Heap<T>::Heap(int _mary)
{
    size=0;
    //TODO: Check _mary !=0 
    mary=_mary;
    tree=(T*)malloc(sizeof(T)*size);
}
template <class T> Heap<T>::Heap(T* data,int _size,int _mary)
{
    size=0;
    //TODO: Check _mary !=0 
    mary=_mary;
    tree=(T*)malloc(sizeof(T)*_size);
    //Create Heap from given data
    for(int i=0;i<_size;i++)
    {
        int errorCode;
        addNode(data[i],&errorCode);
    }
}
template <class T> void Heap<T>::upHeap(int position)
{
    if(position != 0)
    {
        //Find parent node
        int parent = ceil(position*1.0/mary)-1;
        if(parent >= 0)
        {
            //If parent is higher than child then child should go up
            if (tree[position] < tree[parent]) {
                swap(parent,position);
                //Now the child is swapped to parent so upHeap the parent if possible
                upHeap(parent);
            }
        }
    }
}
template <class T> void Heap<T>::downHeap(int position)
{
    if(position != size)
    {
        int childStart=mary*position+1;
        int childEnd=mary*(position+1);
        T value=tree[position];
        int swapPosition=-1;
        for(int child=childStart;child<=childEnd ;child++)
        {
            if(child < size)
            {
                if (value > tree[child]) {
                    value=tree[child];  
                    swapPosition=child;
                } 
            }
        }
        if(swapPosition != -1)
        {
            swap(swapPosition,position);
            downHeap(swapPosition);
        }
    }
}
template <class T> void Heap<T>::addNode(T value,int * errorCode)
{
    size++;
    tree=(T*)realloc(tree,sizeof(T)*size);
    *errorCode=0;
    if(tree == NULL)
    {
        *errorCode=1;
        //Memory exhausted
    }
    tree[size-1]=value;
    upHeap(size-1);
    
    
}
template <class T> T Heap<T>::popNode(int * errorCode)
{
    T value;
    *errorCode=0;
    if (size >= 1) {
        value=tree[0];
        size--;
        T lastLeafValue=tree[size];
        tree=(T*)realloc(tree,sizeof(T)*size);
        tree[0]=lastLeafValue;
        downHeap(0);
    }
    else
    {
        *errorCode=2;
    }
    return value;
}


