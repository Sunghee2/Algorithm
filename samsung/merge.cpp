int[] merge(int arr[], int l, int mid, int r) {
    int new_arr[arr.length()];
    int idx = 0;
    while(l <= mid || r < arr.length()) {
        if(arr[l] <= arr[r]) {
            new_arr[idx++] = arr[l++];
        } else {
            new_arr[idx++] = arr[r++];
        }
    }

    while(l <= mid) {
        new_arr[idx++] = arr[l++];
    }

    while(r <= arr.length()) {
        new_arr[idx++] = arr[r++];
    }
    return new_arr;
}