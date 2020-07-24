import numpy

A = []
N = int(input())
for a in range(N):
    A.append([])
    string = input()
    command = string.split(' ')
    for b in range(len(command)):
        d1 = float(command[b])
        A[a].append(d1)
    print(A)
print (round(numpy.linalg.det(A), 2))

#You are given a square matrix A with dimensions NXN. Your task is to find the determinant.

#input
#2
#1.1 1.1
#1.1 1.1
#output
#0.0
