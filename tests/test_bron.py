def printState(R,P,X):
    print('R:' + str(R))
    print('P:' + str(P))
    print('X:' + str(X))
    print('\n')

def bronk2(cliques, R, P, X, g):
    if not any((P, X)):
        cliques.append(R)
    for v in P[:]:
        R_v = R + [v]
        P_v = [v1 for v1 in P if v1 in g[v]]
        X_v = [v1 for v1 in X if v1 in g[v]]
        bronk2(cliques, R_v, P_v, X_v, g)
        P.remove(v)
        X.append(v)

graph = [[13,37],[16],[8, 11, 20],[35], [6,21,7,17,8,9,13,16,12],

        [], [4,7,8,9,12,16,17,21,10,13], [4,6,13,15,16,12,17,9,11,10], [4,6,2,10,11,12,13,15,17,9,16],

        [4,6,7,8,10,11,12,17,23,21,20],[8,9,6,7,11,12,13], [7,8,9,10,12,13,2], [6,7,8,9,10,11,4,17,21],

        [0,4,7,8,10,11,6,37], [], [7,8,31,35], [1,4,6,7,8,17],

        [4,6,7,8,9,12,16,21,22,23,25], [19,20], [18,20,36], [18,19,9,2,36],

        [4,6,9,12,17,23], [17,27,28,24], [9,17,21,24,28,27,25], [22,23,30,25,26,27,28],

        [17,23,24,27,30], [24,30], [22,23,24,25,28], [22,23,27,24],

        [32,34,33], [24,26,25], [15], [29,34],

        [29], [29,32], [15,3], [19,20],

        [0,13], []]

cliques = []
bronk2(cliques, [], list(range(39)) ,[],graph)
cliques.sort(key=len, reverse=True)
[print(i) for i in cliques if len(i) == 6]