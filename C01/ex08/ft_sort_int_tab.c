
void selectionSort(int arr[], int n){
    int i;
    int min;
    int j;
    int temp;
    i = 0;
    while(i < n - 1)
    {
        min = i;
        j = i + 1;
        while (j < n){
            if(arr[j] < arr[min])
            {
                min = j;
            }
            j++;
        }
        if(min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        i++;
    }
}

void ft_sort_tab(int *tab, int size){
    selectionSort(tab, size);
}
