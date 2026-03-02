class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        n = len(nums)

        largest = -float('inf')
        second_largest = -float('inf')
        third_largest = -float('inf')

        if n<3:
            return max(nums)

        for num in nums:
            if num>largest:
                third_largest=second_largest
                second_largest=largest
                largest=num
            elif num!=largest and num>second_largest:
                third_largest=second_largest
                second_largest=num
            elif num!=largest and num!=second_largest and num>=third_largest:
                third_largest=num
            # print(largest)
            # print(second_largest)
            # print(third_largest)

        return third_largest if third_largest!=-float('inf') else largest