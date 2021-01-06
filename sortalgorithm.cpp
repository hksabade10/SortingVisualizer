#include "sortalgorithm.h"

#include <QtCore>

SortAlgorithm::SortAlgorithm()
{
    count = 0;
}

void SortAlgorithm::selectionSort(QVector<ArrayElement *> &arr, int &speed)
{
    int N = arr.size();

    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(arr[i]->getHeight() > arr[j]->getHeight())
            {
                int temp = arr[i]->getHeight();
                arr[i]->setHeight(arr[j]->getHeight());
                arr[j]->setHeight(temp);

                count++;
                update(speed);
            }
        }
    }
}

void SortAlgorithm::insertionSort(QVector<ArrayElement *> &arr, int &speed)
{
    int N = arr.size();

    for(int i = 1; i < N; i++)
    {
        int j = i - 1;
        int x = arr[i]->getHeight();
        while(j >= 0 && arr[j]->getHeight() > x)
        {
            arr[j+1]->setHeight(arr[j]->getHeight());
            j--;

            count++;
            update(speed);
        }
        arr[j+1]->setHeight(x);
    }
}

void SortAlgorithm::bubbleSort(QVector<ArrayElement *> &arr, int &speed)
{
    int N = arr.size();

    for(int i = 0; i < N-1; i++)					// for each pass
    {
        bool flag = false;
        for(int j = 0; j < N-i-1; j++)              // for each comparison
        {
            if(arr[j]->getHeight() > arr[j+1]->getHeight())
            {
                arr[j]->swap(arr[j+1]);

                count++;
                update(speed);
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

void SortAlgorithm::mergeSort(QVector<ArrayElement *> &arr, int &speed, int l, int h)
{
    if(l < h)
    {
        int mid = (l + h)/2;
        mergeSort(arr, speed, l, mid);
        mergeSort(arr, speed, mid + 1, h);
        merge(arr, speed, l, mid, h);
    }
}

void SortAlgorithm::quickSort(QVector<ArrayElement *> &arr, int &speed, int l, int h)
{
    int j;
    if(l < h)
    {
        j = partition(arr, speed, l, h);
        quickSort(arr, speed, l, j-1);
        quickSort(arr, speed, j+1, h);
    }
}

void SortAlgorithm::shellSort(QVector<ArrayElement *> &arr, int &speed)
{
    int N = arr.size();
    for(int gap = N/2; gap >= 1; gap = gap/2)					// for each pass
    {
        for(int i = 0, j = gap; i < N && j < N; i++, j++)		// for each element
        {
            while(i >= 0 && arr[i]->getHeight() > arr[j]->getHeight())
            {
                arr[i]->swap(arr[j]);
                i = i - gap;
                j = j - gap;

                count++;
                update(speed);
            }
        }
    }
}

int SortAlgorithm::getCount()
{
    return count;
}

void SortAlgorithm::merge(QVector<ArrayElement *> &A, int& speed, int l, int mid, int h)
{
    int N = A.size();

    QVector<int> C(N, 0);

    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;

    while(i <= mid && j <= h)
    {
        if(A[i]->getHeight() < A[j]->getHeight())
            C[k++] = A[i++]->getHeight();
        else
            C[k++] = A[j++]->getHeight();
    }

    while(i <= mid)
        C[k++] = A[i++]->getHeight();
    while(j <= h)
        C[k++] = A[j++]->getHeight();

    for(i = l; i <= h; i++)
    {
        A[i]->setHeight(C[i]);
        count++;
        update(speed);
    }
}

int SortAlgorithm::partition(QVector<ArrayElement *> &arr, int &speed, int l, int h)
{
    int pivot = arr[h]->getHeight();
    int i = (l-1);

    for (int j = l; j <= h-1; j++)
    {
        if(arr[j]->getHeight() < pivot)
        {
            i++;
            arr[i]->swap(arr[j]);
            count++;
        }
        update(speed);
    }

    arr[i+1]->swap(arr[h]);

    count++;
    update(speed);

    return (i+1);
}

void SortAlgorithm::update(int &speed)
{
    // update every 'x' milliseconds
    QEventLoop loop;
    QTimer::singleShot(speed, &loop, SLOT(quit()));
    loop.exec();
}
