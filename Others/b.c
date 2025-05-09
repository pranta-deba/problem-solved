#include <stdio.h>
#define MAX 100

int isInFrame(int frame[], int capacity, int page) {
    for (int i = 0; i < capacity; i++) {
        if (frame[i] == page)
            return 1;
    }
    return 0;
}

int pageFaults(int pages[], int n, int capacity) {
    int frame[MAX];
    int front = 0, rear = 0, count = 0;
    int pageFaultCount = 0;

    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        if (!isInFrame(frame, capacity, pages[i])) {
            frame[rear] = pages[i];
            rear = (rear + 1) % capacity;
            if (count < capacity) count++;
            pageFaultCount++;
        }
    }

    return pageFaultCount;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    int faults = pageFaults(pages, n, capacity);
    printf("Total Page Faults: %d\n", faults);

    return 0;
}
