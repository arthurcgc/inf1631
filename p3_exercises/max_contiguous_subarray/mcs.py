

def shallow_copy(arr):
    r = []
    for n in arr:
        r.append(n)
    return r

def mcs_brute(arr):
    global_max = []
    for i in range(len(arr)):
        local_max = [arr[i]]
        tmp_arr = shallow_copy(local_max)
        for j in range(i+1, len(arr)):
            tmp_arr.append(arr[j])
            if sum(tmp_arr) > sum(local_max):
                local_max = shallow_copy(tmp_arr)
        if sum(local_max) > sum(global_max):
            global_max = shallow_copy(local_max)
    
    return global_max

def mcs_brute_with_cache(arr):
    global_max = []
    global_max_sum = -99999
    for i in range(len(arr)):
        local_max = [arr[i]]
        local_max_sum = arr[i]
        tmp_arr = [arr[i]]
        tmp_sum = arr[i]
        for j in range(i+1, len(arr)):
            tmp_arr.append(arr[j])
            tmp_sum += arr[j]
            if tmp_sum > local_max_sum:
                local_max = shallow_copy(tmp_arr)
                local_max_sum = tmp_sum
        if local_max_sum > global_max_sum:
            global_max = shallow_copy(local_max)
            global_max_sum = local_max_sum
    
    return global_max

def mcs(arr):
    S = [[arr[i]] for i in range(len(arr))]
    for i in range(1, len(arr)-1):
        if sum(S[i-1]) + arr[i] > arr[i]:
            S[i] = shallow_copy(S[i-1])
            S[i].append(arr[i])
    
    max_sum = -9999
    MCS = []
    for l in S:
        s = sum(l)
        if s > max_sum:
            max_sum = s
            MCS = l
    
    return MCS


if __name__ == "__main__":
    arr = [1, -0.5, 4, -5, 2]
    print("arr = {}".format(arr))
    print("pure brutality: {}".format(mcs_brute(arr)))
    print("brutality with cache: {}".format( mcs_brute_with_cache(arr)))
    print("dynamic programming: {}".format( mcs(arr)))