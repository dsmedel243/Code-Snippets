if __name__ == '__main__':
    N = int(input())
    LIST = []
    for a in range(N):
        string = input()
        command = string.split(' ')

        #command[0]: command, command[1]: i, command[2]: e
        if command[0] == "insert":
            i = command[1]
            e = command[2]
            LIST.insert(int(i), int(e))
        elif command[0] == "print":
            print(LIST)
        elif command[0] == "remove":
            e = command[1]
            LIST.remove(int(e))
        elif command[0] == "append":
            e = command[1]
            LIST.append(int(e))
        elif command[0] == "sort":
            LIST = sorted(TUPLE)
        elif command[0] == "pop":
            LIST.pop()
        elif command[0] == "reverse":
            LIST.reverse()
        else:
            print("ERROR")

#insert i e: Insert integer e at position i.
#print: Print the list.
#remove e: Delete the first occurrence of integer e.
#append e: Insert integer e at the end of the list.
#sort: Sort the list.
#pop: Pop the last element from the list.
#reverse: Reverse the list.​

#input
#12
#insert 0 5
#insert 1 10
#insert 0 6
#print
#remove 6
#append 9
#append 1
#sort
#print
#pop
#reverse
#print
#output
#[6, 5, 10]
#[1, 5, 9, 10]
#[9, 5, 1]
