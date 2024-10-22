# encoding:utf-8
import os
commit_message = input("Enter commit message: ")
absolute_path = os.path.dirname(__file__)
print(absolute_path)
os.chdir(absolute_path)
os.system("python main.py")
os.chdir("..")
os.system("python .\-Delete.py")
os.system("git add .")
os.system("git commit -m \"" + commit_message + "\"")
os.system("git push")
