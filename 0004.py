# O(n)
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums = sorted(nums1)
        if len(nums) % 2 == 0:
            return (nums[len(nums) // 2] + nums[len(nums) // 2 - 1]) / 2
        else:
            return nums[len(nums) // 2]


# O(log (m+n)):
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        # To make sure j > 0
        if l1 > l2:
            nums1, nums2 = nums2, nums1
            l1, l2 = l2, l1
        if l1 == 0:
            if l2 % 2 != 0:
                return nums2[l2 // 2]
            return (nums2[l2 // 2] + nums2[l2 // 2 - 1]) / 2
        # 'mid' is right median
        mid = (l1 + l2) // 2
        l = 0
        r = l1
        while l <= r:
            i = (l + r) // 2
            j = mid - i
            if i < l1 and nums1[i] < nums2[j - 1]:
                l = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]:
                r = i - 1
            else:
                # check left median
                if i == 0:
                    left_mid = nums2[j - 1]
                elif j == 0:
                    left_mid = nums1[i - 1]
                else:
                    left_mid = max(nums1[i - 1], nums2[j - 1])
                # check right median
                if i == l1:
                    right_mid = nums2[j]
                elif j == l2:
                    right_mid = nums1[i]
                else:
                    right_mid = min(nums1[i], nums2[j])

                if (l1 + l2) % 2 != 0:
                    return right_mid
                return (left_mid + right_mid) / 2
