class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        sorted_chars = sorted(count.items(), key=lambda x: x[1], reverse=True)

        result = []
        for char, count in sorted_chars:
            result.append(char * count)
            
        return "".join(result)