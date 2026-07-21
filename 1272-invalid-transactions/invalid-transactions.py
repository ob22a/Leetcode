class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        n = len(transactions)
        parsed = [t.split(",") for t in transactions]

        invalid = set()

        for i in range(n):
            name1, time1, amount1, city1 = parsed[i]

            if int(amount1) > 1000:
                invalid.add(i)

            for j in range(i + 1, n):
                name2, time2, amount2, city2 = parsed[j]

                if (name1 == name2 and city1 != city2 and abs(int(time1) - int(time2)) <= 60):
                    invalid.add(i)
                    invalid.add(j)

        return [transactions[i] for i in range(n) if i in invalid]