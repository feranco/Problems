int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
    const size_t listSize = D.size();
    unordered_map<int,int> cdSumFreq;
    int cnt = 0;

    for (int k = 0; k < listSize; ++k) {
       for (int l = 0; l < listSize; ++l) { 
           cdSumFreq[-(C[k]+D[l])]++;
       }
    }

    for (int i = 0; i < listSize; ++i) {
       for (int j = 0; j < listSize; ++j) {
           if (cdSumFreq.count(A[i]+B[j]))
            cnt += cdSumFreq[A[i]+B[j]];
       }
    }

    return cnt;
}

//O(n^2) time, O(n^2) space where n size of each lists
