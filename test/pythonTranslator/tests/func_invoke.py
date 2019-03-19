def func():
    pass

def main():
    func()
    return 23

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)