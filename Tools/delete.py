import os
import shutil

def show(s):
    print('"' + s.replace("\\", "\\\\") + '"')


def Cmp(s, Suf, Sub):
    for l in Len:
        if s[-l:] in Suf:
            return True
    for ss in Sub:
        if ss in s:
            return True
    return False

Len = (3, 4)
Suf = (".in", ".out", ".exe", ".ans")
Sub = ("tmp", "Tmp", "temp")
## __path__之类的
mypath = os.path.dirname(__file__)
mypath = os.path.join(mypath, "..")
for root, dirs, files in os.walk(mypath):
    # 首先，删除以“.cph”结尾的文件夹
    for dir_name in dirs:
        if dir_name.endswith('.cph'):
            dir_path = os.path.join(root, dir_name)
            try:
                shutil.rmtree(dir_path)
                print(f"Deleted directory: {dir_path}")
            except OSError as e:
                print(f"Error: {dir_path} : {e.strerror}")
    # 接着，处理文件
    for name in files:
        if Cmp(name, Suf, Sub):
            file_path = os.path.join(root, name)
            show(file_path)
            os.remove(file_path)
