//
//  MergeSort.cpp
//  Sort
//
//  Created by Jain, Salil  on 1/20/13.
//
//
#include <iostream>
#include <vector>
using namespace std;
template <class T> class MergeSort {
public:
    MergeSort(vector<T>* _data);
    void sort();
    
private:
    void divideAndMerge(vector<T>* data);
    void merge(vector<T>* merged,vector<T>* left,vector<T>* right);
    vector<T>* data;
    void printVector(vector<T>* vec);
};

template <class T>   MergeSort<T>::MergeSort(vector<T>* _data)
{
    data = _data;
}
template <class T>  void MergeSort<T>::sort()
{
    divideAndMerge(data);
}
template <class T>  void MergeSort<T>::divideAndMerge(vector<T>* _data)
{
   unsigned long size=_data->size();
   if(size < 2)
   {
       return;
   }
    unsigned int middle=size/2;
    vector<T> left(middle,0),right(size-middle,0);
    
    for(unsigned int i=0;i<middle;i++)
    {
        left[i]=_data->at(i);
    }
    for(unsigned int i=middle;i<size;i++)
    {
        right[i-middle]=_data->at(i);
    }
    divideAndMerge(&left);
    divideAndMerge(&right);
    merge(_data,&left,&right);
    printVector(_data);
    return;
}
template <class T>  void MergeSort<T>::merge(vector<T>* merged,vector<T>* left,vector<T>* right)
{
    
    unsigned long mergedSize=merged->size();
    typename vector<T>::iterator leftIter=left->begin(),rightIter=right->begin(),mergedIter=merged->begin();
    for(unsigned long  i=0;i<mergedSize;i++)
    {
        if(*leftIter < *rightIter)
        {
            *mergedIter=*leftIter;
            leftIter++;
            mergedIter++;
            if(leftIter == left->end())
            {
                while(rightIter != right->end())
                {
                    *mergedIter=*rightIter;
                    mergedIter++;
                    rightIter++;
                }
                 
                break;
            }
        }
        else
        {
            *mergedIter=*rightIter;
            rightIter++;
            mergedIter++;
            if(rightIter == right->end())
            {
                while(leftIter != left->end())
                {
                    *mergedIter=*leftIter;
                    mergedIter++;
                    leftIter++;
                }
                
                break;
            }
            
        }
        
    }
    return;
}
template <class T>  void MergeSort<T>::printVector(vector<T>* vec)
{
    cout<<"Vector ";
    for(int i=0;i<vec->size();i++)
    {
        cout<<vec->at(i)<<" ";
    }
    cout<<endl;
}