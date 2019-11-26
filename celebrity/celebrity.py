

graph1 = [
    [0, 1, 1, 1, 0],
    [1, 0, 0, 1, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0],
]


def find_celebrity(graph):
    stack = graph
    i = 0
    j = 1
    nnext = 2
    while nnext < len(graph) + 1:
        # import pdb; pdb.set_trace()
        if graph[i][j] == 1:
            i = nnext
        else:
            j = nnext
        
        nnext += 1

    candidate = -3
    if i == len(graph) + 1:
        candidate = i
    else:
        candidate = j

    for i in range(0, len(graph[candidate])):
        if graph[candidate][i] == 1:
            return None
    return candidate
        
    



if __name__ == "__main__":
    res = find_celebrity(graph1)
    if res != None:
        print("celebrity found at vertex: {}".format(res))
    else:
        print("celebrity not found")