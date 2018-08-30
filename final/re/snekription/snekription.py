#!/usr/bin/env python

s = raw_input("Kopi kembung tidak bikin luwak passwordnya?: ");

def encrypt(str):
    result = ""
    for i in str:
        c = ord(i);
        if c >= ord('a') and c <= ord('z'):
            if c > ord('m'):
                c -= 13
            else:
                c += 13
        elif c >= ord('A') and c <= ord('Z'):
            if c > ord('M'):
                c -= 13
            else:
                c += 13

        result += chr(c)

    return result

flag = encrypt("vGfnyErnQlEbGgRa")

if  encrypt(s) == "vGfnyErnQlEbGgRa":
    print "DUA JUTA RUPIAH!!!"
    print "flag: BeeFest{%s}" %(flag)
else:
    print "Silahkan dicoba kembali" 

