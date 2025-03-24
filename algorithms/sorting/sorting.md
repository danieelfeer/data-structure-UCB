# Sorting Algorithms

## Bubble Sorting

- Bubble Sort repeatedly steps through the list, compares adjacent items, and swaps them if they are in the wrong order, until the list is sorted.
- ![Bubble Sort GIF](../../images/bubble_sort.gif)

## Selection Sorting

- Selection Sort divides the list into a sorted and unsorted part, repeatedly selecting the smallest element from the unsorted part and swapping it with the first unsorted element.
- ![Selection Sort GIF](../../images/selection_sort.gif) 

## Insertion Sorting

- Insertion Sort builds the sorted sequence one item at a time. It moves through the list from left to right, comparing each element with the ones before it and inserting it in the correct position. This is repeated until the entire list is sorted.
- ![Insertion Sort GIF](../../images/Insertion_sort.gif)

## Merge Sorting

- Merge Sort is a divide-and-conquer algorithm that splits the list into two halves, sorts each half recursively, and then merges the sorted halves back together. It is particularly efficient for large datasets due to its guaranteed performance of \( O(n \log n) \).
- ![Merge Sort GIF](../../images/mergesort.gif) 

## Quick Sorting

- Quick Sort is another divide-and-conquer algorithm. It selects a pivot element and partitions the list into two parts: elements less than the pivot and elements greater than or equal to the pivot. The process repeats recursively for both parts until the list is fully sorted. Like Merge Sort, Quick Sort also has a performance of \( O(n \log n) \) on average, but can degrade to \( O(n^2) \) in the worst case.
- ![Quick Sort GIF](../../images/quicksort.gif) 
