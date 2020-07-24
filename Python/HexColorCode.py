import re
N = int(input())
start = 0
for a in range(N):
    string = input()
    if string == '}':
        start = 0
    if start == 1:
        match = re.findall(r'#[a-fA-F0-9]{3,6}', string)
        for b in range(len(match)):
            print(str(match[b]))
    new = re.findall(r'{', string)
    if len(new) != 0:
        if new[0] == '{':
            start = 1

#Find all the Valid Hex Colors in the CSS code

#input
#11
##BED
#{
#    color: #FfFdF8; background-color:#aef;
#    font-size: 123px;
#    background: -webkit-linear-gradient(top, #f9f9f9, #fff);
#}
##Cab
#{
#    background-color: #ABC;
#    border: 2px dashed #fff;
#}   

#output
#FfFdF8
#aef
#f9f9f9
#fff
#ABC
#fff
