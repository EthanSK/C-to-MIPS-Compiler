a = 1
b = 2
c = 3
d = 4

def main():
    global a
    global b
    global c
    global d
    return a + b + c + d

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)