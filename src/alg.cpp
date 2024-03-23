// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] >=0 && arr[j] >= 0 && arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int rightborder = len - 1;
    while (arr[rightborder] > value) {
        rightborder--;
    }
    for (int i =0; i < rightborder; i++) {
        for (int j = rightborder; j > i; j--) {
            if (arr[i] >=0 && arr[j] >= 0 && arr[i] + arr[j] == value) {
                counter++;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int leftborder = 0;
    int rightborder = len - 1;
    int counter = 0;
    while (leftborder <= rightborder) {
        int middle = (leftborder + rightborder) / 2;
        if (arr[middle] == value) {
            counter++;
            int i = middle - 1;
            while (i >= 0 && arr[i] == value) {
                counter++;
                i--;
            }
            i = middle + 1;
            while (i < len && arr[i] == value) {
                i++;
                counter++;
            }
            break;
        } else if (arr[middle] < value) {
            leftborder = middle + 1;
        } else {
            rightborder = middle - 1;
        }
    }
    return counter;
}
