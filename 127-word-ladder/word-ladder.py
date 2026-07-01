class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        graph = defaultdict(list)
        if beginWord not in wordList:
            wordList.insert(0,beginWord)

        n = len(wordList)

        word_set = set(wordList)
        
        for word in wordList:
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = word[:i] + c + word[i+1:]
                    if new_word in word_set:
                        graph[word].append(new_word)
                        graph[new_word].append(word)

        # for i in range(n):
        #     for j in range(i+1,n):
        #         if self.differ_by_one(wordList[i],wordList[j]):
        #             graph[wordList[i]].append(wordList[j])
        #             graph[wordList[j]].append(wordList[i])
        
        #print(graph)
        # Traverse graph and find cost (cost,word)

        visited = set()
        q = deque([(1,beginWord)])

        while q:
            #print(q)
            c,w = q.popleft()
            
            if w in visited:
                continue
            
            if w==endWord:
                return c
            
            visited.add(w)

            for word in graph[w]:
                if word not in visited:
                    q.append((c+1,word))
            
        return 0


