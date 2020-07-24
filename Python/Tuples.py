if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())
    t = tuple(integer_list)
    print(hash(t))

#Print the result of hash(t) wherein t is the tuple.

#input
#2
#1 2
#output
#3713081631934410656
