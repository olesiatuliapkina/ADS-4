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
    int rightborder = len - 1;
    int counter = 0;
    while (arr[rightborder] > value) {
        rightborder = rightborder - 1;
    }
    for (int i = 0; i < rightborder; i++) {
        for (int j = rightborder; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len - 1; i++) {
        int leftborder = i + 1;
        int rightborder = len - 1;
        while (leftborder <= rightborder) {
            int middle = (leftborder + rightborder) / 2;
            int summ = arr[i] + arr[middle];
            if (summ == value) {
                counter++;
                break;
            } else if (summ < value) {
                leftborder = middle + 1;
            } else {
                rightborder = middle - 1;
            }
        }
    }
    return 0;
}
