
def kadanes(arr):
    global_max = []
    suffix_max = []
    gm = 0
    sm = 0

    for num in arr:
        # finding max suffix
        if (sm + num) > 0:
            suffix_max.append(num)
            sm += num
        else:
            suffix_max = []
            sm = 0
        
        # comparing to global maximum
        if gm < num or gm < sm:
            if num > sm:
                global_max = [num]
                gm = num
            else:
                global_max = suffix_max.copy()
                gm = sm
    
    return global_max


if __name__ == "__main__":
    print(kadanes([2, -3, 1.5, -1, 3, -2, -3, 3]))
    print(kadanes([2, -3, 1.5, -1, 3, -2, 15, -4, 3]))

        
        
        
        
        
