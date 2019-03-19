a = 0

def set(b):
    global a
    a = b

def main():
    global a
    set(5)
    return a

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)