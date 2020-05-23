import os

a = os.popen("ls ./ast*.h*")
files = []
for l in a.readlines():
    files.append(l[:-1])
for file in files:
    f = open(file, "r")
    L = f.readlines()
    for l in L:
        if l.startswith("class") and (l.find(":") != -1 or l.find("{") != -1):
            index_mao = l.find(":")
            index_dak = l.find("{")
            if index_mao != -1:
                index = index_mao
            else:
                index = index_dak
            if index == -1:
                index = len(l)

            print(l[:index])