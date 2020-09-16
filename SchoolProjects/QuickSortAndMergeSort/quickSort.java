public static <T> void quickSortRecursive(ArrayList<T> array, int start, int end, Comparator<? super T> comp){
        //base case
        if(end - start < 1){
        return;
        }

        //set the pivot using one of the three methods
//        int pivotIndex = start; // this takes the first index and makes it the pivot (could be good, could be bad)
        int pivotIndex = randomPivot(start, end);
//        int pivotIndex = medianOfSetThree(array, start, end, comp);
//        int pivotIndex = medianOfRandomThree(array, start, end, comp);

        //swap pivot with the end
        swap(array,pivotIndex, end);
        //keep track of where the pivot is
        pivotIndex = end;
        //set pointers
        int lPtr = start, rPtr = end - 1;

        //loop to know when to not swap the pointer
        while( lPtr <= rPtr){
        //if object at left pointer is less than pivot move pointer to next spot
        if(comp.compare(array.get(lPtr), array.get(pivotIndex)) < 1){
        lPtr++;
        continue;
        }
        //if object at right point is greater than pivot move pointer to next spot
        if(comp.compare(array.get(rPtr), array.get(pivotIndex)) > -1){
        rPtr--;
        continue;
        }

        //will only hit if the object at the left pointer is greater than the pivot and the object at the right pointer is less than the pivot, swap the two
        swap(array, lPtr, rPtr);
        lPtr++;
        rPtr--;
        }
        //swap the pivot back to it's original position (which is the left pointer
        swap(array, lPtr, pivotIndex);
        pivotIndex = lPtr;
        quickSortRecursive(array, start, pivotIndex - 1, comp);
        if((pivotIndex + 1) > end){
        pivotIndex -= 1;
        }
        quickSortRecursive(array, pivotIndex + 1, end, comp);




        }