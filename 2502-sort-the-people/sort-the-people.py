class Solution:
    def sortPeople(self, names, heights):
        people = sorted(zip(heights, names), reverse=True)
        return [name for _, name in people]