/*
Welcome to Facebook!

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

Enjoy your interview!
*/


// #######################################################################

// Return the column that contains the leftmost one in the matrix

// Examples:

// [00111]
// [00011]
// [00111] ---> returns 0,2 or 2,2


// [111]
// [001]   ---> returns 0


// #######################################################################

/**
 * Time complexity: O(mn)
 */
int leftmost_column_with_one (vector<vector<int>> matrix) {
    if (matrix.size() == 0)
        return -1;
    
    int col_num = 0;
    int row_count = matrix.size();
    int col_count = matrix[0].size();
    for (int curr_col = 0; curr_col < col_count; curr_col++) {
        for (int curr_row = 0; curr_row < row_count; curr_row++) {
            if (matrix[curr_row][curr_col] == 1)
                return curr_col;
        }
    }
    return -1;
}

/**
 * Time complexity: O(n logn)
 * For each row, find the index of left most 1 using binary search (Time: O(log n))
 * As there are n rows, total time: O(n logn)
 */
int left_most_col_with_one_bin_search (vector<vector<int>> matrix) {
    if (matrix.size() == 0)
        return -1;
    
    int min_col_index = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
        // find the index of 1st 1 in the ith row:
        int lo = 0, hi = matrix[i].size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // If we find a 1 following a 0, this is the index of the first 1 in the ith row
            if (matrix[i][mid] == 1 && (mid == 0 || (mid - 1 >= 0 && matrix[i][mid - 1] == 0))) {
                // store this index mid
                if (mid < min_col_index) {
                    min_col_index = mid;
                    break;
                } else {
                    break;
                }
            }
            else if (matrix[i][mid] == 1 && matrix[i][mid - 1] == 1) {
                hi = mid - 1;
            }
            else if (matrix[i][mid] == 0) {
                lo = mid + 1;
            }
        }
    }
    
    return min_col_index == INT_MAX ? -1 : min_col_index;
}

// [00111]
// [00011]
// [00001] ---> returns 2

/**
 * Time complexity: O(n logn)
 * For each row, find the index of left most 1 using binary search (Time: O(log n))
 * As there are n rows, total time: O(n logn)
 * 
 * Returns the row and col of the left most one randomly
 *
 * Ex:
// [00111]
// [00011]
// [00111] ---> returns <0,2> or <2,2>
 */
pair<int, int> random_indices_of_one (vector<vector<int>> matrix) {
    if (matrix.size() == 0)
        return -1;
    
    vector<pair<int, int>> all_possible_min_col_locs;
    int min_col_index = INT_MAX;
    
    for (int i = 0; i < matrix.size(); i++) {
        // find the index of 1st 1 in the ith row:
        int lo = 0, hi = matrix[i].size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // If we find a 1 following a 0, this is the index of the first 1 in the ith row
            if (matrix[i][mid] == 1 && (mid == 0 || (mid - 1 >= 0 && matrix[i][mid - 1] == 0))) {
                // store this index mid
                if (mid == min_col_index) {
                    all_possible_min_col_locs.push_back({i, mid});
                }
                else if (mid < min_col_index) {
                    min_col_index = mid;
                    // Delete all values stored till now as they do not correspond to the global min col number
                    all_possible_min_col_locs.clear();
                    break;
                } 
                else {
                    break;
                }
            }
            else if (matrix[i][mid] == 1 && matrix[i][mid - 1] == 1) {
                hi = mid - 1;
            }
            else if (matrix[i][mid] == 0) {
                lo = mid + 1;
            }
        }
    }
    
    // Randomly choose one index out of all the indices in the vector and return the element at that index:
    // choose an index randomly in 0 to all_possible_min_col_locs.size() - 1 which is all the possible set of indices
    int index_to_return = Random.getValue(0, all_possible_min_col_locs.size() - 1);
    return min_col_index == INT_MAX ? {-1, -1} : all_possible_min_col_locs[index_to_return];
}
