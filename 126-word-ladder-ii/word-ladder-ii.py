class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []

        word_set = set(wordList)
        n = len(wordList)
        graph=defaultdict(list)

        def next_words(word):
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

        def dfs(word):
            if word == beginWord:
                return [[beginWord]]

            ans = []

            for p in parents[word]:
                for path in dfs(p):
                    ans.append(path + [word])

            return ans
        
        # BFS expansion tracking the path with it 
        sol=[]
        q=deque([beginWord]) 
        seen=set([beginWord]) # in bfs if it is seen it was before and can't be shortest path
        found = False

        # Use parent storage and generate all solutions from there instead of storing nodes
        parents=defaultdict(set)


        while q and not found:
            level_set = set()
            level_len=len(q)

            for _ in range(level_len):
                node=q.popleft()

                for word in next_words(node):
                    if word not in seen:
                        if word == endWord:
                            found = True

                        if word not in level_set:
                            level_set.add(word)
                            q.append(word)

                        parents[word].add(node)
                    elif word in level_set:
                        parents[word].add(node)
                                   
            seen|=level_set
        
        return dfs(endWord)