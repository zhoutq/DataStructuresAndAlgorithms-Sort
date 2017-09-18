//
//  main.c
//  SortTest
//
//  Created by zhoutq on 2017/9/17.
//  Copyright © 2017年 zhoutq. All rights reserved.
//

#include <stdio.h>

void printfSort(int a[], int n) {
    
    for (int i = 0; i < n; i++) {
        
        printf("%d,",a[i]);
    }
    
    printf("\n");
}

// 冒泡排序：时间复杂度 -- O(n^2)
/*
 在冒泡排序过程中会将数组分成两部分，一部分是已经有序的数列，一部分是无序的数列。
 无序数列中不断的将其中最小的值往有序序列中冒泡，泡冒完后，我们的序列就创建好了。
 */
void bubbleSort(int a[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - 1 - i; j++) {
            
            // 如果前面的大于后面的，将大的放到后面
            if (a[j] > a[j + 1]) {
                
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            // 再用后面的和它后面的比较
        }
    }
}

// 插入排序：时间复杂度 -- O(n^2)
/*
 插入排序算是比较好理解的排序方式，插入排序也是将要排序的数列分为两部分，
 前半部分是已经排好序的，后半部分则是无序的。插入排序中的插入是指“取出无序数列中第一个值，
 插入到有序数列中相应的位置”。其实这个插入过程也是不断比较和交换的过程。
 */
void insertSort(int a[], int n) {
    
    for (int i = 1; i < n; i ++) {
        
        int j = i - 1; //有序数列end
        int num = a[i]; // 带插入数
        
        while (j >= 0 && a[j] > num) {
            // 如果num比有序比较数大，则将比较数往后移动 （从后往前查找，大的往后移动）
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = num;
    }
}

//折半插入
void binaryInsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        
        int low=0,high=i;
        
        int num = a[i];        //复制为哨兵，即存储待排序元素
        while (low <= high) {  //查找在有序表的插入位置  (遍历表)
            
            int m = (low + high) / 2;
            if(num<a[m]) {
                
                high = m - 1;
            }
            else {
                
                low = m + 1;
            }
            
        }
        
        int j = i-1;
        for (j = i-1; j >= high + 1; j--) {
            a[j + 1] = a[j];
        }
        a[j+1] = num;      //插入到正确位置
    }
    
}
// 选择排序：时间复杂度 -- O(n^2)
/* 在选择排序过程中，数组仍然被分作有序和无序两部分。而选择排序中的“选择”
 是指不断从无序序列中选择最小的值放入到有序序列的最后的位置，换句话说就是
 从现有的无序序列中找出那个最小的值，然后与无序序列的第一个值进行交换，然后
 缩小无序序列的范围即可。因为有序序列的最后一个值与无序序列的第一个值紧挨着，
 交换后，这个无序序列中的第一个值就成了有序序列的最后一个值。重复这个选择的过程，
 我们的数组就会变得有序。
 */
void selectSort(int a[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        int min = i;
        for (int j = i + 1; j < n; j++) {
            
            if (a[j] < a[min]) {
                
                min = j; //记录最小的数，继续查询
            }
        }
        
        if (min != i) {
            
            int temp;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    
}

// 快速排序：时间复杂度 -- O(nlogn)
/*
 快速排序的思想主要是取出无序序列中第一个值，然后通过比较将比该值小的元素放到该值的前方，将比该值大的元素放在该值的后方。
 这样一来该值前方的数据都要比该值小，该值后方的数据都要比该值大。然后再次对前半部分和后边半部分无序的数列进行上述操作，
 这样不断的操作，无序的序列的规模不断被缩小。等问题的规模被缩小到一定程度后，我们的序列就变的有序了
 */

void quickSort(int a[], int left, int right)
{
    if (left >= right) return;
    
    int i = left, j = right, k = a[left];
    
    // 当 i = j 时说明已经找到 k 的位置，停止查找
    while (i < j)
    {
        while(i < j && a[j] >= k) j--; // 从右向左找小于k的数

        if(i < j) a[i++] = a[j]; // 如果 i < j说明 j 已查到，则将其填入 a[i]( a[i] 已被暂存：k = a[left] 或者a[j--] = a[i])，i 后移
        
        while(i < j && a[i] <= k) i++; // 从左向右找大于k的数
            
        if(i < j) a[j--] = a[i]; // 如果 i < j说明 i 已查到，则将其填入 a[j]( a[j] 已被暂存：a[i++] = a[j])，j 前移
    }
    
    // 结束循环时 i = j 已经确定 k 的位置，将 k 填入。
    a[i] = k;
    // 递归调用
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {2,3,1,6,9,1,4,8,5,7};
//    int a[10] = {2,2,2,2,2,1,1,1,1,1};
    
    printfSort(a, 10);
//    bubbleSort(a, 10);
//    insertSort(a, 10);
//    binaryInsertSort(a, 10);
//    selectSort(a, 10);
    quickSort(a, 0, 9);
    printfSort(a, 10);
    return 0;
}
