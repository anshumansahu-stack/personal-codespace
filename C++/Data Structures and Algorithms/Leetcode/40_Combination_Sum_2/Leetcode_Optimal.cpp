// void merge(vector<int> &candidates, int first, int mid, int last)
// {
//     int first1 = first, last1 = mid, first2 = mid + 1, last2 = last;
//     vector<int> temp(last - first + 1, 0);
//     int index = 0;
//     while ((first1 <= last1) && (first2 <= last2))
//     {
//         if (candidates[first1] < candidates[first2])
//         {
//             temp[index] = candidates[first1];
//             index++;
//             first1++;
//         }
//         else if (candidates[first1] > candidates[first2])
//         {
//             temp[index] = candidates[first2];
//             index++;
//             first2++;
//         }
//         else
//         {
//             temp[index] = candidates[first1];
//             index++;
//             first1++;
//             temp[index] = candidates[first2];
//             index++;
//             first2++;
//         }
//     }
//     // adding remaining elements
//     while (first1 <= last1)
//     {
//         temp[index] = candidates[first1];
//         index++;
//         first1++;
//     }
//     while (first2 <= last2)
//     {
//         temp[index] = candidates[first2];
//         index++;
//         first2++;
//     }
//     // replacing entire nums array
//     for (int i = first, j = 0; i <= last; i++, j++)
//     {
//         candidates[i] = temp[j];
//     }
// }
// void mergesort(vector<int> &candidates, int start, int end)
// {
//     if (start < end)
//     {
//         int mid = start + (end - start) / 2;
//         mergesort(candidates, start, mid);
//         mergesort(candidates, mid + 1, end);
//         merge(candidates, start, mid, end);
//     }
// }