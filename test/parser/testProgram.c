int or_check(){
    int op1 = 0xA, op2 = 0x5;
    return (op1 | op2) + (0 | 0);
}

int and_check(){
    int op1 = 0xff, op2 = 0xf;
    return (op1 & op2);
}

int xor_check(){
    int op1 = 0xff;
    return (op1^op1);
}