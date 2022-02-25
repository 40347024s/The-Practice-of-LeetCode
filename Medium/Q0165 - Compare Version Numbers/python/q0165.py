class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split('.')
        version2 = version2.split('.')
        i = j = 0
        while i < len(version1) or j < len(version2):
            val1 = 0 if i >= len(version1) else int(version1[i])
            val2 = 0 if j >= len(version2) else int(version2[j])
            if val1 > val2:
                return 1
            elif val1 < val2:
                return -1
            i += 1
            j += 1
        return 0