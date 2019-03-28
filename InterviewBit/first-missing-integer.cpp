int Solution::firstMissingPositive(vector<int> &A) {
    int len = A.size();
    
    for (int i = 0; i < len; ++i)
        if (A[i] > 0 && A[i] <= len)
        {
            if (A[A[i] - 1] != A[i])
            {
                swap(A[i], A[A[i] - 1]);
                --i;
            }
        }
            
    for (int i = 0; i < len; ++i)
        if(A[i] != (i + 1)) 
            return i + 1;
    
    return len + 1;
}
