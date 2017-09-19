//
//  main.c
//  SortTest
//
//  Created by zhoutq on 2017/9/17.
//  Copyright © 2017年 zhoutq. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printfSort(int a[], int n) {
    
    for (int i = 0; i < n; i++) {
        
        printf("%d,",a[i]);
    }
    
    printf("\n");
}

// 冒泡排序：时间复杂度 -- O(n^2)
//         空间复杂度 -- O(1)
//         稳定性 -- 稳定
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
//         空间复杂度 -- O(1)
//         稳定性 -- 稳定
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

//折半插入：时间复杂度 -- O(n^2)
//         空间复杂度 -- O(1)
//         稳定性 -- 稳定
/*
 折半插入排序（binary insertion sort）是对插入排序算法的一种改进，由于排序算法过程中，就是不断的依次将元素插入前面已排好序的序列中。由于前半部分为已排好序的数列，这样我们不用按顺序依次寻找插入点，可以采用折半查找的方法来加快寻找插入点的速度。
 
 折半插入排序算法的具体操作为：在将一个新元素插入已排好序的数组的过程中，寻找插入点时，将待插入区域的首元素设置为a[low],末元素设置为a[high]，则轮比较时将待插入元素与a[m],其中m=(low+high)/2相比较,如果比参考元素小，则选择a[low]到a[m-1]为新的插入区域(即high=m-1)，否则选择a[m+1]到a[high]为新的插入区域（即low=m+1），如此直至low<=high不成立，即将此位置之后所有元素后移一位，并将新元素插入a[high+1]。
 
 折半插入排序算法是一种稳定的排序算法，比直接插入算法明显减少了关键字之间比较的次数，因此速度比直接插入排序算法快，但记录移动的次数没有变，所以折半插入排序算法的时间复杂度仍然为O(n^2)，与直接插入排序算法相同。
 */
void binaryInsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        
        int low = 0,high = i;
        
        int num = a[i];        //复制为哨兵，即存储待排序元素
        while (low <= high) {  //查找在 有序表 的插入位置  (遍历表)
            
            int m = (low + high) / 2; // 取有序表中间位置
            if (num < a[m]) { // 如果待插入值小于中间值，则继续在前半部分查找，即 high 为 m - 1;
                
                high = m - 1;
            }
            else { // 否则，在后半部分查找，即 low 为 m + 1
                
                low = m + 1;
            }
            
        }
        
        int j;
        // 待插位置之后的元素后移
        for (j = i - 1; j >= low; j--) { // j:有序表最后一位，i:无序表第一位。low:待插的位置。>= low 的都往后移动。最后插入到low的位置
            
            a[j + 1] = a[j];
        }
        
        a[j+1] = num;      //插入到正确位置， j + 1 是因为上个循环 j-- 了
    }
    
}
// 选择排序：时间复杂度 -- O(n^2)
//         空间复杂度 -- O(1)
//         稳定性 -- 不稳定
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
//         空间复杂度 -- O(nlogn)
//         稳定性 -- 不稳定
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



// 归并排序：时间复杂度 -- O(nlogn)
//         空间复杂度 -- O(n)
//         稳定性 -- 稳定
/*
归并排序（MERGE-SORT）是建立在归并操作上的一种有效的排序算法,该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
 */

void merge(int a[], int low, int mid, int high);

void mergeSort(int a[], int low, int high) {
    
    if (low < high) {
        
        int mid = (low + high) / 2;
        
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    
    int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int)); // 开辟对应大小的内存空间
    
    int k;
    // 两部分相互比较，按照升序将数据暂存入temp
    for (k = 0; start1 <= end1 && start2 <= end2; k++) {
        
        if (a[start1] < a[start2]) {
            temp[k] = a[start1++];
        } else {
            temp[k] = a[start2++];
        }
    }
    
    // 检测是否有剩余项，直接拷贝到temp
    while (start1 <= end1) temp[k++] = a[start1++];
    while (start2 <= end2) temp[k++] = a[start2++];
    
    // 将temp拷贝到原数组地址范围内
    for (int i = 0; i < high - low + 1; i++) {
        
        a[low + i] = temp[i];
    }
    
    free(temp);
}


int main(int argc, const char * argv[]) {
    
    int n = 10;
    int a[10] = {2,3,1,6,9,1,4,8,5,7};
//    int a[10] = {2,2,2,2,2,1,1,1,1,1};
    
    printfSort(a, n);
//    bubbleSort(a, n);
//    insertSort(a, n);
    binaryInsertSort(a, n);
//    selectSort(a, n);
//    quickSort(a, 0, n - 1);
//    mergeSort(a, 0, n - 1);
    printfSort(a, n);
    return 0;
}
