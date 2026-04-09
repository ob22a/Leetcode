class Solution:
    def simplifyPath(self, path: str) -> str:
        # If / on top don't push if / comes
        # push . and if non dot stuff comes if one . just remove if two dot then pop one back
        # At the end remove according to the rules

        n = len(path)
        stk = []
        i=0
        
        pathList = path.split("/")
        
        for p in pathList:
            if p:
                if p=="..":
                    if stk:
                        stk.pop()
                elif p!=".":
                    stk.append(p)
        
        return "/"+"/".join(stk) # start with /