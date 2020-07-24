def count_substring(string, sub_string):
    count = 0
    for a in range(0, len(string)):
        new = string.find(str(sub_string), int(a), int(a+len(sub_string)))
        if (a == 0) & (new == 0):
            count+=1
        if new > 0:
            count+=1
    return count

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)

#find the number of substrings found in string
#input:
#ABCDCDC
#CDC
#output:
#2
