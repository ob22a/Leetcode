class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        n = len(wordList)
        word_set = set(wordList)
        graph = defaultdict(list)

        def next_words(word)->list:
            if word in graph:
                return graph[word]

            words = []
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = word[:i] + c + word[i+1:]
                    if new_word in word_set:
                        words.append(new_word)

            graph[word]=words
            return words

        # for i in range(n):
        #     for j in range(i+1,n):
        #         if self.differ_by_one(wordList[i],wordList[j]):
        #             graph[wordList[i]].append(wordList[j])
        #             graph[wordList[j]].append(wordList[i])
        
        #print(graph)
        # Traverse graph and find cost (cost,word)

        visited = {beginWord}
        q = deque([(1,beginWord)])

        while q:
            #print(q)
            c,w = q.popleft()
            
            if w==endWord:
                return c

            for word in next_words(w):
                if word not in visited:
                    q.append((c+1,word))
                    visited.add(word)
            
        return 0


