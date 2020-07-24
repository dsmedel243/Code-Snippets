import numpy
matrix = []
list1 = []
N, M = map(int, input().split())
a, b = (numpy.array([input().split() for _ in range(N)], dtype=int) for _ in range(2))

#Do multiple operations on a list of arrays

print(a+b)
print(a-b)
print(a*b)
print(a//b)
print(a%b)
print(a**b)

#You are given two integer arrays, A and B of dimensions NXM
#The first line contains two space separated integers, N and M.
#The next N lines contains M space separated integers of array .
#The following N lines contains M space separated integers of array .

#example
#2 4
#1 2 3 4
#1 2 3 4
#5 6 7 7
#5 6 7 7
#output
#[[ 6  8 10 11]
# [ 6  8 10 11]]
#[[-4 -4 -4 -3]
# [-4 -4 -4 -3]]
#[[ 5 12 21 28]
# [ 5 12 21 28]]
#[[0 0 0 0]
# [0 0 0 0]]
#[[1 2 3 4]
# [1 2 3 4]]
#[[    1    64  2187 16384]
# [    1    64  2187 16384]]
