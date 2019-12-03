

def edit_dist(s1, n, s2, m):
    if n == 0:
        return m
    if m == 0:
        return n
    
    cost = -1

    if s1[n-1] == s2[m-1]:
        cost = 0
    else:
        cost = 1
    
    return min( (edit_dist(s1, n-1, s2, m) + 1 ), (edit_dist(s1, n, s2, m-1) + 1 ), 
                (edit_dist(s1, n-1, s2, m-1) + cost) )


if __name__ == "__main__":
    s1 = "AC"
    s2 = "ACDA"
    print(edit_dist(s1, len(s1), s2, len(s2)))