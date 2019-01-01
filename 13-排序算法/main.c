//
//  main.c
//  13-排序算法
//
//  Created by Ne on 2018/11/9.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
/*
 01-冒泡排序 稳定 慢，每次只能移动两个数据 O(n^2)
 02-插入排序 稳定 快 比较次数不一定，比较次数越少，插入点后的数据移动越多  O(n^2)
 03-希尔排序 不稳定    O(n^1.3)
 04-选择排序 不稳定    O(n^2)
 05-快速排序 不稳定    O(nlogn)
 06-归并排序 稳定      O(nlogn)
 07-堆
 */
#pragma mark --打印数据
void dis(int *p,int n) {
    for (int i = 0; i<n; i++) {
        printf("%d\t",p[i]);
    }
}

#pragma mark --01冒泡排序
void popSort(int *p,int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-1-i; j++) {
            if (p[j]>p[j+1]) {
                p[j]   ^= p[j+1];
                p[j+1] ^= p[j];
                p[j]  ^= p[j+1];
            }
        }
    }
}

#pragma mark --01冒泡排序(优化)
void popSortOptimize(int *p,int n) {
    int flage;
    for (int i=0; i<n-1; i++) {
        flage = 1;
        for (int j = 0; j<n-1-i; j++) {
            if (p[j]>p[j+1]) {
                p[j]   ^= p[j+1];
                p[j+1] ^= p[j];
                p[j]  ^= p[j+1];
                flage = 0;
            }
        }
        if (flage) {
            break;
        }
    }
}

#pragma mark --02-插入排序
//(理解为一个往左走,一个往右走)
void insertSort(int *arr,int n){
    int t,i,j;
    for (i=1; i<n; i++) {
        t = arr[i];
        for (j = i; j-1>=0 && t<arr[j-1]; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = t;
    }
}

#pragma mark --03-希尔排序
void shellSort(int *arr,int n) {
    int i,j,t;
    int gap = n/2;
    while (gap >= 1) {
        for (i=gap; i<n; i++) {
            t = arr[i];
            for (j = i; j-gap>=0 && t<arr[j-gap];  j = j - gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = t;
        }
        gap = gap/2;
    }
}

#pragma mark --04-选择排序
//(理解为两个都往前走)
void selectSort(int *arr,int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = i+1; j<n; j++) {
            if (arr[i]>arr[j]) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

#pragma mark --04-选择排序(优化)
//(比而不换,只记录下标)
void selectSortOptimize(int *arr,int n) {
    int idx;
    for (int i = 0; i<n-1; i++) {
        idx = i;
        for (int j = i+1; j<n; j++) {
            if (arr[idx]>arr[j]) {
                idx = j;
            }
        }
        if (idx != i) {
            arr[i] ^= arr[idx];
            arr[idx] ^= arr[i];
            arr[i] ^= arr[idx];
        }
    }
}

#pragma mark --05-快速排序
//分而治之   右边:大而移动,小而赋值  左边:小而移动,大而赋值
void quickSort(int *arr,int left,int right) {
    if (left < right) {
        int pivot=arr[left],l = left,h = right;
        while (l<h) {
            while (l<h && arr[h]>=pivot) {//大而移动,小而赋值
                h--;
            }
            arr[l] = arr[h];
            while (l<h && arr[l]<=pivot) {//小而移动,大而赋值
                l++;
            }
            arr[h] = arr[l];
        }
        arr[h] = pivot;
        quickSort(arr, left, h-1);
        quickSort(arr, h+1, right);
    }
}

#pragma mark --06-归并排序
void mergeArr(int *src,int *tmp,int start,int mid,int end) {
    int i = start;
    int j = mid+1;
    int k = start;
    while (i != mid+1 && j != end+1) {
        if (src[i]<src[j])
            tmp[k++] = src[i++];
        else
            tmp[k++] = src[j++];
    }
    if (i == mid + 1)
        while (j != end+1)
            tmp[k++] = src[j++];
    else
        while (i != mid +1)
            tmp[k++] = src[i++];
    while (start<=end) {
        src[start] = tmp[start];
        start++;
    }
}

void mergeSort(int *arr,int *tmp,int start,int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, tmp, start, mid);
        mergeSort(arr, tmp, mid +1, end);
        mergeArr(arr, tmp, start, mid, end);
    }
}

#pragma mark --主函数
int main(int argc, const char * argv[]) {
    printf("01-冒泡排序    ");
    int array[] = {1,4,2,9,5,6,3,8};
    popSort(array, sizeof(array)/sizeof(*array));
    dis(array, sizeof(array)/sizeof(*array));
    
    printf("\n01-冒泡排序优化 ");
    int array1[] = {1,4,2,9,5,6,3,8};
    popSortOptimize(array1, sizeof(array1)/sizeof(*array1));
    dis(array1, sizeof(array1)/sizeof(*array1));
    
    printf("\n02-插入排序    ");
    int array2[] = {1,4,2,9,5,6,3,8};
    insertSort(array2, sizeof(array2)/sizeof(*array2));
    dis(array2, sizeof(array2)/sizeof(*array2));
    
    printf("\n03-希尔排序    ");
    int array4[] = {1,4,2,9,5,6,3,8};
    shellSort(array4, sizeof(array4)/sizeof(*array4));
    dis(array4, sizeof(array4)/sizeof(*array4));
    
    printf("\n04-选择排序    ");
    int array5[] = {1,4,2,9,5,6,3,8};
    selectSort(array5, sizeof(array5)/sizeof(*array5));
    dis(array5, sizeof(array5)/sizeof(*array5));
    
    printf("\n04-选择排序优化 ");
    int array6[] = {1,4,2,9,5,6,3,8};
    selectSortOptimize(array6, sizeof(array6)/sizeof(*array6));
    dis(array6, sizeof(array6)/sizeof(*array6));
    
    printf("\n05-快速排序    ");
    int array7[] = {1,4,2,9,5,6,3,8};
    quickSort(array7, 0, 7);
    dis(array7, sizeof(array7)/sizeof(*array7));
    
    printf("\n将一个波峰的数组合并到另一个数组,保证数组顺序\n");
    int a[] = {1,3,5,7,2,4,6,8};
    int c[8];
    mergeArr(a, c, 0, 3, 7);
    dis(c, sizeof(c)/sizeof(*c));
    
    printf("\n06-归并排序    ");
    int array8[] = {1,4,2,9,5,6,3,8};
    int d[8];
    mergeSort(array8, d, 0, 7);
    dis(d, sizeof(d)/sizeof(*d));
    
    return 0;
}
