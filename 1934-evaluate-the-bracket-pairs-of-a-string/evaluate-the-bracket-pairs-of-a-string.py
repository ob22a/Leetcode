class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        knowledge_map = {x:y for x,y in knowledge}
        print(knowledge_map)
        stk = []

        for c in s:
            if c.isalpha() or c==" ":
                if not stk: stk.append("")
                stk[-1]+=c
            elif c=="(":
                stk.append("")
            elif c==")":
                key = stk.pop()
                stk.append(knowledge_map.get(key,"?"))
        
        return "".join(stk)