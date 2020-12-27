#include <stdio.h>
#include <stdlib.h>

// find minimal multiple element
int find_min_mal(int *array, int *fitted_array, int array_size) {
    int min_index = 0;
    int prev_min_index = 0;

    for(int i = 1; i < array_size; i++) {
        if(array[min_index] > array[i]) {
            int find_flag = 0;
            for(int j = 0; j < array_size-1; j++) {
                // skip fitted elements
                // use fitted_index_array
                if(fitted_array[j] == i)
                    find_flag = 1;
            }

            if(find_flag == 0) {
                prev_min_index = min_index;
                min_index = i;
            }

            else if(find_flag == 1) {
                min_index = prev_min_index;
            }
        }
    }

    return min_index;
}

int main() {
    freopen("input.txt", "r", stdin);

    int case_num = 0;
    scanf("%d", &case_num);

    for(int i = 0; i < case_num; i++) { // loop for case
        int index_max = 0;
        scanf("%d", &index_max); // input array max index

        int array[index_max][2];
        int mul_array[index_max]; // multiple result by two each elements
        
        for(int j = 0; j < index_max; j++) { // save elements
            scanf("%d %d", &array[j][0], &array[j][1]);
            mul_array[j] = array[j][0] * array[j][1];
        }

        int search_count = 0; // 
        int fitted_index_array[index_max-1]; //
        int fitted_index_array_count = 0; //
        
        for(int t = 0; t < index_max-1; t++) {
            fitted_index_array[t] = -1;
        }

        while(search_count < index_max){    
            // find minimum element
            int mul_min_index = find_min_mal(mul_array, fitted_index_array, index_max);
            // printf("%d\n", mul_min_index);
            int best_fit_index = -1;

            for(int j = 0; j < index_max; j++) {
                
                if((array[j][0] > array[mul_min_index][0])
                && (array[j][1] > array[mul_min_index][1])) {
                    if (best_fit_index < 0)
                        best_fit_index = j;

                    else if((array[best_fit_index][0] > array[j][0])
                    && (array[best_fit_index][1] > array[j][1])) {
                        best_fit_index = j;
                    }
                }

                printf("%d\n", best_fit_index);
            }

            if(best_fit_index > 0) {
                fitted_index_array[fitted_index_array_count] = best_fit_index;
                fitted_index_array_count++;
            }

            search_count++;
        }
        // print fitted index count
        // printf("%d\n", fitted_index_array_count);
    }
    return 0;
}
