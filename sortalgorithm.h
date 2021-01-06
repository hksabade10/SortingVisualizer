#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H


#include "arrayelement.h"

class SortAlgorithm
{
public:
    SortAlgorithm();

    void selectionSort(QVector<ArrayElement*>& arr, int& speed);

    void insertionSort(QVector<ArrayElement*>& arr, int& speed);

    void bubbleSort(QVector<ArrayElement*>& arr, int& speed);

    void mergeSort(QVector<ArrayElement*>& arr, int& speed, int l, int h);

    void quickSort(QVector<ArrayElement*>& arr, int& speed, int l, int h);

    void shellSort(QVector<ArrayElement*>& arr, int& speed);

    int getCount();

private:

    void merge(QVector<ArrayElement*>& arr, int& speed, int l, int mid, int h);

    int partition(QVector<ArrayElement*>& arr, int& speed, int l, int h);

    void update(int& speed);

    struct Node{
        int data;
        Node* next;
    };

    int count = 0;

};

#endif // SORTALGORITHM_H
