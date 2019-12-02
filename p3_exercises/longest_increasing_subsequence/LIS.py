

def find_all_sub(arr, d):
    res = []
    for i in range(0, len(arr)):
        sub = []
        sub.append(arr[i])
        sub_count = 0
        for j in range(i+1, len(arr)-1):
            if arr[j] >= sub[ sub_count ]:
                sub.append(arr[j])
                sub_count += 1
        
        if len(sub) == d:
            res.append(sub)
    return res
        
        

def lis_brute(arr):
    for i in range(len(arr)-1, -1, -1):
        subs = find_all_sub(arr, i)

        if len(subs) > 0:
            return subs

def shallow_copy(arr):
    res = []
    for n in arr:
        res.append(n)
    return res

def LIS(arr):
    LIS = [[arr[i]] for i in range(len(arr))]

    # print(LIS)
    # import pdb; pdb.set_trace()
    for i in range(0, len(arr)):
        maxLisSoFar = LIS[i]

        localMax = shallow_copy(LIS[i])
        for j in range(0, i):
            if arr[j] < arr[i]:
                # we update lis[j] in a temp variable
                if localMax[0] > arr[j]:
                    localMax.insert(0, arr[j])
                # check if local max is LISMAX
            if len(localMax) > len(maxLisSoFar):
                maxLisSoFar = shallow_copy(localMax)
        
        LIS[i] = maxLisSoFar
    
    return LIS



if __name__ == "__main__":
    # l = [3,17,9,12,35,6,27,8,21,26,23,11,19,13,15]
    # print(lis_brute(l))
    l = [3, 2, 6, 4, 5, 1]
    print(lis_brute(l))

    print(LIS(l))
        