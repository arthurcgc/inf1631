

def LCS(s1, s2):
    if len(s1) == 0 or len(s2) == 0:
        return 0
    
    c1 = s1[-1]
    c2 = s2[-1]

    if c1 == c2:
        return 1 + LCS(s1[:-1], s2[:-1])
    else:
       return max( LCS(s1, s2[:-1]), LCS(s1[:-1], s2) )

if __name__ == "__main__":
    s1 = "AGGTAB"
    s2 = "GXTXAYB"
    S = []
    print(LCS(s1, s2))

