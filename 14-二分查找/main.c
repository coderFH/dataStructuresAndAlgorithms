//
//  main.c
//  14-二分查找
//
//  Created by Ne on 2018/11/10.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>

#pragma mark --二分查找
int binSearch(int *arr,int low,int high,int find) {
    int mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (arr[mid] == find) {
            return mid;
        } else if (arr[mid] < find) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

#pragma mark --递归实现
int binSearchRecursion(int *arr,int low,int high,int find) {
    int mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (arr[mid] == find) {
            return mid;
        } else if (arr[mid] < find) {
            return binSearchRecursion(arr, mid+1, high, find);
        } else {
            return binSearchRecursion(arr, low, mid-1, find);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,3,5,7,9,11,34,66};
    int find = binSearch(arr, 0, 7, 34);
    int find1 = binSearchRecursion(arr, 0, 7, 6);
    printf("%d\t %d\n",find,find1);
    return 0;
}
