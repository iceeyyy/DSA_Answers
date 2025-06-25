class Solution {
public:
    long long findSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productsCount = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                if (midProduct >= 0) {
                    productsCount += n;
                }
                continue;
            }
            if (nums1[i] > 0) {
                // Binary search for the largest j such that nums1[i]*nums2[j] <= midProduct
                int l = 0, r = n - 1, m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                productsCount += (m + 1);
            } else {
                // nums1[i] < 0
                // Binary search for smallest j such that nums1[i]*nums2[j] <= midProduct
                int l = 0, r = n - 1, m = n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProduct) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                productsCount += (n - m);
            }
        }

        return productsCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long l = -1e10, r = 1e10;
        long long ans = 0;

        while (l <= r) {
            long long midProduct = l + (r - l) / 2;
            long long countSmallest = findSmallest(nums1, nums2, midProduct);

            if (countSmallest >= k) {
                ans = midProduct;
                r = midProduct - 1;
            } else {
                l = midProduct + 1;
            }
        }

        return ans;
    }
};
