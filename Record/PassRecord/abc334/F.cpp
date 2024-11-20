class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& num){
        int n = num.size();
        int l = 0, r = n - 1;
        while (l + 1 < n && num[l + 1] > num[l]) l++;
        while (r - 1 >= 0 && num[r] > num[r - 1]) r--;
        if (l == n - 1) {
            return (long long)(n + 1) * n / 2;
        } else {
            long long ans = n - r;
            for (int i = 0; i <= l; ++i) {
                int k = num.end() - upper_bound(num.begin() + max(r, i + 1), num.end(), num[i]);
                ans += k + 1;
            }
            return ans + 1;
        }
    }
};
