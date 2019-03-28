vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum = 0, squereSum = 0, len = A.size();
    long long sumNum = 0, squereSumNum = 0;
    vector<int> result;
    
    for (int i = 1; i <= len; ++i)
    {
        sumNum += (long long)i;
        squereSumNum += (long long)i * (long long)i;
    }
    
    
    for (int i = 0; i < len; ++i)
    {
        sum += (long long)A[i];
        squereSum += (long long) A[i] * A[i];
    }
    
    long long diff = abs(sumNum - sum);
    long long squereDiff = abs(squereSumNum - squereSum);
    
    sum = squereDiff / diff;
    
    int oneNum = (int)((sum - diff) / 2);
    bool exist = false;
    
    for (int i = 0; i < len; ++i)
    {
        if (A[i] == oneNum)
        {    
            exist = true;
            break;
        }
    }
    
    if (exist)
        result.push_back(oneNum);
    
    result.push_back(oneNum + diff);
    
    if (!exist)
        result.push_back(oneNum);
        
    return result;
}