import sys

def read_file(file):
    file_name=file[1]
    mynumbers=[]
    with open(file_name,"r") as f:
        for line in f:
            mynumbers.append([int(n) for n in line.strip().split(' ')])
    flag1=0
    edge=0
    vertice=0
    for pair in mynumbers:
        try:
            x,y=pair[0],pair[1]
            if flag1==0:
                edge=x
                vertice=y
                graph=[[0 for w in range(vertice)] for h in range(edge)]
                flag1=1
            else:
                graph[x-1][y-1]+=1
        except IndexError:
            print("Uma linha nao tem entradas o suficiente")
    return graph
    

def find_all_paths(graph, start,end, path=[]):
    path=path+[start]
    if start==end:
        return[path]
    if start not in graph:
        return None
    paths=[]
    for node in graph:
        if node not in path:
            newpaths=find_all_paths(graph,node,end,path)
            if newpaths in newpaths:
                if newpaths not in path:
                    paths.append(newpaths)
    return paths

def find_cycle(graph):
    cycles=[]
    for startnode in graph:
        for endnode in graph:
            newpaths= find_all_paths(graph,startnode,endnode)
            for path in newpaths:
                if(len(path)==len(graph)):
                   # print(path)
                    cycles.append(path)
    return cycles
    

graph = read_file(sys.argv)


print("")
print ("Ciclos")
a= find_cycle(graph)
print ("done!")
