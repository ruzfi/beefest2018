WAT = [14, 5, 20, 1, 21, 15, 0, 11, 4, 9, 10, 12, 18, 3, 6, 17, 16, 7, 22, 8, 19, 13, 2]
WKWK = "uS_3eNr5r_i_Ne1a_nzgdFv"
flag = ['=' for i in range(23)]
for w, c in zip(WAT, WKWK):
	flag[w] = c
print ''.join(flag) 
