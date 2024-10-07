graph = {
    '1': ['2', '3', '4'],
    '2': ['5', '6'],
    '3': ['7', '8'],
    '4': ['9'],
    '5': ['10', '11'],
    '6': [],
    '7': ['12'],
    '8': [],
    '9': ['13'],
    '10': [],
    '11': ['14'],
    '12': [],
    '13': [],
    '14': []
}
def DFS(currentNode,destination,graph,maxDepth):
    print("Checking for destination",currentNode)
    if currentNode==destination:
        return True
    if maxDepth<=0:
       return False
    for node in graph[currentNode]:
        if DFS(node,destination,graph,maxDepth-1):
            return True
    return False

def IDDFS(currentNode,destination,graph,maxDepth):
    for i in range(maxDepth):
        if DFS(currentNode,destination,graph,i):
            return True
    return False

if not IDDFS('1','14',graph,5):
    print("Path is not available")
else:
    print("Path Exists")  
