import os
def show(s):
    print('\"'+s.replace('\\','\\\\')+'\"')
def Cmp(s,Suf,Sub):
    for l in Len:
        if s[-l:] in Suf:
            return True
    for ss in Sub:
        if ss in s:
            return True
    return False
Len=(3,4)
Suf=(".in",".out",".exe",".ans")
Sub=("tmp","Tmp")
mypath=os.getcwd()
for root,dirs,files in os.walk(mypath):
    for name in files:
        if Cmp(name,Suf,Sub)==True:
            show(os.path.join(root,name))
            os.remove(os.path.join(root,name))
