public static <T> void mergeSortRecursive(ArrayList<T> arrayList, ArrayList<T> tempArrayList, int start, int end, Comparator<? super T> comparator){
        //threshold
        int threshold = 35;

        if((end - start) <= threshold){
        insertionSort(arrayList, comparator, start, end);
        return;
        }

        int mid = (start + end) / 2;
        mergeSortRecursive(arrayList, tempArrayList, start, mid, comparator);
        mergeSortRecursive(arrayList, tempArrayList, mid + 1, end, comparator);

        merge(arrayList, tempArrayList, start, mid, end, comparator);


        }