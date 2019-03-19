def main():
    x = 10
    x <<= 1
    return x

if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)