#!/usr/bin/python

from z3 import *

def is_valid(x):
    return Or(
        (x == ord('N')),
        (x == ord('D')),
        (x == ord('M')),
        (x == ord('S')),
        (x == ord('C')),
        (x == ord('R')),
        (x == ord('T')),
        (x == ord('H')),
        (x == ord('1')),
        (x == ord('2')),
        (x == ord('3')),
        (x == ord('4')),
        (x == ord('5')),
        (x == ord('6')),
        (x == ord('7')),
        (x == ord('8')),
        (x == ord('9')),
        (x == ord('0')),
        (x == ord('_'))
    )


def representsInt(s):
    try:
        int(s)
        return True
    except:
        return False

s = Solver()
vec = ""
for i in xrange(0, 21):
    vec += "pw[{}] ".format(i)
m = BitVecs(vec, 8)
for i in xrange(0, 21):
    s.add(is_valid(m[i]))

sum = 0
xor = 0
for i in xrange(0,21):
    sum += m[i]
    xor ^= m[i]

s.add(sum == 1432)
s.add(xor == 38)
s.add(m[11] == ord('T'))
s.add(m[0] == m[5])
s.add(m[3] == 48)
s.add(m[5] == m[8])
s.add(m[0]+m[5]+m[8] == 147)
s.add(m[6] == m[13])
s.add(m[16] == m[19])
s.add(m[19] == m[6])
s.add(m[11] == m[20])
s.add(m[20]-1 == m[15])
s.add(m[15]-1 == m[18])
s.add(m[1]-1 == m[4])
s.add(m[1] == ord('N'))
s.add(m[2] == ord('D'))
s.add(m[3] == ord('0'))
s.add(m[4] == ord('M'))
s.add(m[5] == ord('1'))
s.add(m[6] == ord('3'))
s.add(m[9] == ord('5'))
s.add(m[15] == ord('S'))
while s.check() == z3.sat:
    model = s.model()
    out = ""
    nope = []
    for i in m:
        if str(i) and model[i] is not None:
            out += chr(long(str(model[i])) & 0xff)
        nope.append(i != model[i])
    # prevent this solution to come up again
    s.add(Or(nope[:-1]))
    print out
