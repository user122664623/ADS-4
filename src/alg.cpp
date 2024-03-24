// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int amount = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                amount++;
        }
    }
    return amount;
}

int countPairs2(int* arr, int len, int value) {
    int amount = 0, prevRight;
    for (int left = 0, right = len - 1; left <= right; left++) {
        while (arr[right] + arr[left] > value) {
            right--;
        }
        if (arr[left] + arr[right] == value) {
            prevRight = right;
            while (right != left && arr[right] + arr[left] == value) {
                right--;
                amount++;
            }
            right = prevRight;
        }
    }
    return amount;
}

int countPairs3(int* arr, int len, int value) {
    int amount = 0;
    int middleB, leftB, rightB;
    int prevAmount = 0, prev = -1;
    for (int left = 0, right = len - 1; left <= right; left++) {
        leftB = left;
        rightB = right;
        do {
            middleB = (leftB + rightB) / 2;
            if (arr[middleB] == value - arr[left]) {
                break;
            } else if (arr[middleB] > value - arr[left]) {
                rightB = middleB - 1;
            } else if (arr[middleB] < value - arr[left]) {
                leftB = middleB + 1;
            }
        } while (rightB >= leftB);
        if (prev != -1 && arr[left] == arr[prev] && arr[prev] * 2 != value) {
            amount += prevAmount;
            continue;
        }
        if (arr[left] + arr[middleB] == value) {
            prev = left;
            prevAmount = 0;
            while (middleB + 1 < len && arr[middleB + 1] + arr[left] == value) {
                middleB++;
            }
            while (middleB != left && arr[middleB] + arr[left] == value) {
                middleB--;
                amount++;
                prevAmount++;
            }
        }
    }
    return amount;
}
