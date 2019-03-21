| IL Opcode | Example        | Meaning                              |
| --------- | -------------- | ------------------------------------ |
| mov       | mov x y        | x = y                                |
| movi      | movi x im      | x = im                               |
| add       | add x y z      | x = y - z                            |
| sub       | sub x y z      | x = y - z                            |
| mul       | mul x y z      | x = y * z                            |
| div       | div x y z      | x = y / z                            |
| mod       | mod x y z      | x = y % z                            |
| lsl       | lsl x y z      | x = y << z                           |
| lsr       | lsr x y z      | x = y >> z                           |
| lt        | lt x y z       | x = y < z                            |
| lte       | lte x y z      | x = y <= z                           |
| gt        | gt x y z       | x = y > z                            |
| gte       | gte x y z      | x = y >= z                           |
| eq        | eq x y z       | x = y == z                           |
| ne        | ne x y z       | x = y != z                           |
| and       | and x y z      | x = y & z                            |
| andl      | andl x y z     | x = y && z                           |
| or        | or x y z       | x = y \| z                           |
| orl       | orl x y z      | x = y \|\| z                         |
| xor       | xor x y z      | x = y ^ z                            |
| inc       | inc x          | x++                                  |
| dec       | dec x          | x--                                  |
| b         | b label        | branch to label                      |
| beq       | bgez label x y | branch to label if x == y            |
| bne       | bne label x y  | branch to label if x != y            |
| bez       | bez label x    | branch to label if x == 0            |
| bnez      | bnez label x   | branch to label if x != 0            |
| bgz       | bgz label x    | branch to label if x > 0             |
| bgez      | bgez label x   | branch to label if x >= 0            |
| blz       | blz label x    | branch to label if x < 0             |
| blez      | blez label x   | branch to label if x <= 0            |
| scu       | scu            | increases the scope depth            |
| scd       | scd            | decreases the scope depth            |
| nop       | nop            | do nothing                           |
| li        | li x im        | loads the immediate im into x        |
| retv      | retv x         | returns x and ends the function call |

