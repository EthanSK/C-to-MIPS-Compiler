import os

path = "./"
files = os.walk("./")

print("#ifndef test_hpp")
print("#define test_hpp")
for r, d, fs in files:
    for f in fs:
        if f.endswith(".hpp"):
            if "tab" not in f:
                print("#include \"" + f + "\"")

print("#endif")