#include<stdio.h>
#include<stdlib.h>

// size of the demo array. must be >= 222 and < 555 for the test cases to work
// (feel free to change the test cases to try with even bigger numbers!)
#define SEARCH_ARRAY_SIZE 333

/**
 * find the index of a number using linear search
 */
int find_lin(int* array, int size, int value, int* comp_count) {
    // go through the array until the value is found
    for (int i = 0; i < size; i++) {
        // add the comparison count each time
        if (comp_count != NULL) {
            (*comp_count)++;
        }
        // if it is found, return the index
        if (value == array[i]) {
            return i;
        }
    }
    // if it wasn't found, return -1
    return -1;
}

/**
 * find the index of a number using binary search
 */
int find_bin(int* array, int start, int end, int value, int* comp_count) {
    // if the end and start indices match, check the only value:
    if (end == start) {
        //printf("bin: end and start are %d - array: %d", end, array[end]);
        // add the comparison count first
        if (comp_count != NULL) {
            (*comp_count)++;
        }

        if (array[end] == value) return end;
        else return -1;
    }

    // find the middle of the two provided indices
    int mid = (start + end) / 2;
    // increase the comparison count
    if (comp_count != NULL) {
        (*comp_count)++;
    }

    // if the value to find is at the middle, return the middle index
    if (array[mid] == value) {
        return mid;
    }

    // otherwise, recursively check a part of the array, depending on if
    // the value to find is bigger or smaller than the middle
    //printf("array[%d] (%d) vs value (%d) ", mid, array[mid], value);
    if (array[mid] > value) {
        //printf(">\n");
        return find_bin(array, start, mid - 1, value, comp_count);
    } else {
        //printf("<\n");
        return find_bin(array, mid + 1, end, value, comp_count);
    }
}

/**
 * find the index of a number using exponential search
 * (BONUS, this will not be on the exam)
 */
int find_exp(int* array, int size, int value, int* comp_count) {
    int upper_bound = 1; // upper limit (starts with 2^0)

    // find an upper limit for the number - that is, continue multiplying it by 2
    // until either the bound-th number is more than the value or it is out of bounds
    // for the array
    while (upper_bound < size && array[upper_bound - 1] < value) {
        // increment the comparison counter while this operation is going
        if (comp_count != NULL) {
            (*comp_count)++;
        }

        upper_bound = upper_bound * 2;
    }

    // once an upper bound is found, the corresponding lower bound is just that number over 2
    int lower_bound = upper_bound / 2 - 1;
    // normalize the upper boundary to be inside the array
    if (upper_bound > size) {
        upper_bound = size;
    }
    // and in that interval, perform a binary search
    return find_bin(array, lower_bound, upper_bound, value, comp_count);
}

void print_result(int idx, int comp_count) {
    // first, the found message
    if (idx == -1) {
        printf("not found");
    } else {
        printf("found at index %d", idx);
    }
    // then, the comparison message
    printf(", %d comparisons\n", comp_count);
}

int main() {
    int array[SEARCH_ARRAY_SIZE];
    // fill this array - this is just a demo for really large numbers of items
    for (int i = 0; i < SEARCH_ARRAY_SIZE; i++) {
        array[i] = i;
    }
    int comp_count = 0;

    // find the value 222 using all 3 searching methods
    printf("lin: ");
    int idx = find_lin(array, SEARCH_ARRAY_SIZE, 222, &comp_count);
    print_result(idx, comp_count);

    comp_count = 0;
    printf("bin: ");
    idx = find_bin(array, 0, SEARCH_ARRAY_SIZE - 1, 222, &comp_count);
    print_result(idx, comp_count);

    comp_count = 0;
    printf("exp: ");
    idx = find_exp(array, SEARCH_ARRAY_SIZE - 1, 222, &comp_count);
    print_result(idx, comp_count);

    // now find a value that doesn't exist, again using all 3 searching methods
    printf("\nvalue that doesn't exist\n");
    printf("lin: ");
    idx = find_lin(array, SEARCH_ARRAY_SIZE, 555, &comp_count);
    print_result(idx, comp_count);

    comp_count = 0;
    printf("bin: ");
    idx = find_bin(array, 0, SEARCH_ARRAY_SIZE, 555, &comp_count);
    print_result(idx, comp_count);

    comp_count = 0;
    printf("exp: ");
    idx = find_exp(array, SEARCH_ARRAY_SIZE, 555, &comp_count);
    print_result(idx, comp_count);
}
