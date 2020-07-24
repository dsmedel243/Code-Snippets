#String Sorter
c = input()

a =  sorted([i for i in c if str(i).isdigit()])
c = sorted([i for i in c if  str(i).islower()]) + sorted([i for i in c if str(i).isupper()]) 
odds=[]
even=[]
for i in a:
    if int(str(i))%2==1:
        odds+=[i]
    else:
        even+=[i]

listToStr = ''.join(map(str, c)) 
number = odds+even
number = ''.join(map(str, number))

print(listToStr+number)

#All sorted lowercase letters are ahead of uppercase letters.
#All sorted uppercase letters are ahead of digits.
#All sorted odd digits are ahead of sorted even digits.

#input
#Sorting1234
#output
#ginortS1324
