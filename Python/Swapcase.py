def swap_case(s):
    newstring = ''
    for a in s:
        if a.islower():
            newstring+=(a.upper()) 
        elif a.isupper():
            newstring+=(a.lower()) 
        elif not a.isalpha():
            newstring+=a
        else:
            pass
    return newstring

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)

#Swap the upper case and lower case letters
#input
#HackerRank.com presents "Pythonist 2".
#output
#hACKERrANK.COM PRESENTS "pYTHONIST 2".
