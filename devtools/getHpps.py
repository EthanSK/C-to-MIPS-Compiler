import os

path = "./"
files = os.walk("./")

print("#region includes")
for r, d, fs in files:
    for f in fs:
        if f.endswith(".hpp"):
            print("#include \"" + f + "\"")

print("#endregion")