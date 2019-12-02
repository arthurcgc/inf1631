

def LCS_LEN(s1, s2):
    if len(s1) == 0 or len(s2) == 0:
        return 0
    
    c1 = s1[-1]
    c2 = s2[-1]

    if c1 == c2:
        return 1 + LCS_LEN(s1[:-1], s2[:-1])
    else:
       return max( LCS_LEN(s1, s2[:-1]), LCS_LEN(s1[:-1], s2) )


MAX = 20

# lookup[i][j] stores the length of LCS of substring X[0..i-1], Y[0..j-1]
lookup = [ [0 for _ in range(MAX)] for _ in range(MAX)]

def LCS(s1, s2, n, m, lcs = []):
    if n == 0 or m == 0:
        return lcs
    if s1[n-1] == s2[m-1]:
        lcs.insert(0, s1[n-1])
        return LCS(s1, s2, n-1, n-2)
    
if __name__ == "__main__":
    s1 = "AGGTAB"
    s2 = "GXTXAYB"
    S = []
    print(LCS_LEN(s1, s2))

