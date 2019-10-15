import sys
import CPUtimer
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
            for newpaths in newpaths:
                paths.append(newpaths)
    return paths

def find_cycle(graph):
    cycles=[]
    for startnode in graph:
        for endnode in graph:
            newpaths= find_all_paths(graph,startnode,endnode)
            for path in newpaths:
                if(len(path)==len(graph)):
                    #print(path)
                    cycles.append(path)
    return cycles
    

graph = read_file(sys.argv)

timer = CPUtimer.CPUTimer()


print("")
print("Medindo codigo rápido repetido diversas vezes:")
timer.reset()
timer.start()
print ("Finding Hamiltonian Cycles----")
for i in range(0, 1):  
    a= find_cycle(graph)
    print ("Number of Hamiltonian Cycles=", len(a))
    print ("done!")
    timer.lap()
timer.stop()

print("Tempo Total: " + str( timer.get_time() ) +" s")
print("Tempo Medio: " + str( timer.get_time("average","micro") ) +" \u00B5s")
print("Ultima Chamada: " + str( timer.get_time("last","micro") ) +" \u00B5s")
print("Estampa 1 do total: " + str( timer.get_stamp("total","si") ) ) 
print("Estampa 2 do total: " + str( timer.get_stamp("total","clock") ) )