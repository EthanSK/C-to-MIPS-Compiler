a = 10

def main():
    global a
    return a

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)