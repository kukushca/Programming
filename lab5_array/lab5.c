#include <stdio.h>

int max(int arrSize, int scores[arrSize]) {
    int max = 0;
    for (int i = 1; i < arrSize; i++) {
        if (scores[max] < scores[i]) {
            max = i;
        }
    }
    return max;
}

int min(int arrSize, int scores[arrSize]) {
    int min = 0;
    for (int i = 1; i < arrSize; i++) {
        if (scores[min] > scores[i]) {
            min = i;
        }
    }
    return min;
}

float find(int arrSize, int scores[arrSize]) {
    int min_index = min(arrSize, scores);
    int max_index = max(arrSize, scores);
    
    int start;
    int end;
    if (min_index < max_index) {
        start = min_index;
        end = max_index;
    } else {
        start = max_index;
        end = min_index;
    }
    
    int sum = 0;
    int count = 0;
    
    for (int i = start + 1; i < end; i++) {
        sum += scores[i];
        count++;
    }
    return (float) sum / count; //Явное преобразование типов
}

int main() {
    int scores[] = {-1,10, -4,6 , 10000, 221, 1000};
    int arrSize = sizeof(scores) / sizeof(scores[0]);

    float s = find(arrSize, scores);
    printf("%.2f\n", s);

    return 0;
}