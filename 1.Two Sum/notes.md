returned array must be malloced，所以記住returned array如何宣告: int *ans = (int *)malloc(sizeof(int) *2); 2:return size(2個整數)
題目保證You may assume that each input would have exactly one solution.所以最後面*returnSize = 0;可忽略，但寫上去是良好習慣。
