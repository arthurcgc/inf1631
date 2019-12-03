
lookup = dict()

def knapsack_0_1(v, w, n, W):
    if W < 0:
        return -99999999
    if n < 0 or W == 0:
        return 0
    
    if (n, W) not in lookup:
        include = knapsack_0_1(v, w, n-1, W - w[n]) + v[n]
        exclude = knapsack_0_1(v, w, n-1, W)

        lookup[(n, W)] = max(include, exclude)
    
    return lookup[(n, W)]
    