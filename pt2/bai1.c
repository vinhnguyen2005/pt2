#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//function de sort list
void bubbleSort(int *arr, int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j]; // dịch phần tử nhỏ nhất về cuối
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n");
}
//function tim so lon thu 2
void secondLargest(int *arr, int n) {
    int max1 = 0, max2 = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > max1) { // check phàn tử hiện tại có lớn hơn giá trị lớn nhất hiện tại ko
            max2 = max1; // cập nhật giá trị max 2 thành giá trị lớn nhất max 1
            max1 = arr[i]; // max1 thành index hiện tại
        } else if (arr[i] > max2 && arr[i] != max1) { //check xem có lớn hơn max 2  và khác max 1
            max2 = arr[i];
        }
    }
    printf("The second largest element is: %d\n", max2);
}

//function tim so unique trong mang
int *uniquenumber(int *arr, int n, int *count) {
    int mark[1000] = {0};
    *count = 0;
    // Tính count để là size của mảng động chứa các số duy nhất (sao cho vừa đủ chứa các số unique)
    // Đếm số lượng phần tử duy nhất và đánh dấu chúng trong mảng mark.
    for (size_t i = 0; i < n; i++) {
        if (mark[arr[i]] == 0) { //để duyệt các số lặp lại sẽ ko đc lưu
            mark[arr[i]] = 1;
            (*count)++; // cứ duyệt qua đc 1 phần tử unique count sẽ tăng
        }
    }

    int *result = malloc((*count) * sizeof(int)); // Tạo mảng động để chứa các số duy nhất
    int num = 0; // Là số phần tử trong mảng result chứa unique

    // Lưu trữ các số duy nhất vào mảng
    for (size_t i = 0; i < n; i++) {
        if (mark[arr[i]] == 1) { //mark cac so vua duoc lay ra ben ngoai, luc nay ta phai lay bang 1 vi vua set o tren, nếu bằng 1 sẽ đc cho vào mảng result
            result[num++] = arr[i]; //cập nhât các phần tử trong mảng bằng các số unique tìm đc
            mark[arr[i]] = 2;// nếu phần tử nào xuất hiện lần nữa, mark lúc này là 2 nên sẽ ko đc cho vào mảng 
        }
    }

    return result;
}

int main() {
    int arr[16] = {1, 5, 4, 1, 4, 5, 7, 4, 2, 4, 5, 6, 5, 4, 6, 8};

    bubbleSort(arr, 16);
    printf("Sorted array in descending order is: \n");
    for (size_t i = 0; i < 16; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    secondLargest(arr, 16);
    printf("\n");

    int count;
    //tao mang doong tro vao function unique
    int *uniquearr = uniquenumber(arr, 16, &count);

    printf("Unique numbers of array: ");
    for (size_t i = 0; i < count; i++) { // chay den count do mang result chua cac so unique
        printf("%d ", uniquearr[i]);
    }
    printf("\n");

    free(uniquearr);

    return 0;
}
