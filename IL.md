| IL Opcode | Example        | Meaning                   |
| --------- | -------------- | ------------------------- |
| add       | add x y z      | x = y + z                 |
| sub       | sub x y z      | x = y - z                 |
| mul       | mul x y z      | x = y * z                 |
| div       | div x y z      | x = y / z                 |
| mod       | mod x y z      | x = y % z                 |
| beq       | bgez label x y | branch to label if x == y |
| bne       | bne label x y  | branch to label if x != y |
| bez       | bez label x    | branch to label if x == 0 |
| bnez      | bnez label x   | branch to label if x != 0 |
| bgz       | bgz label x    | branch to label if x > 0  |
| bgez      | bgez label x   | branch to label if x >= 0 |
| blz       | blz label x    | branch to label if x < 0  |
| blez      | blez label x   | branch to label if x <= 0 |
| scu       | scu            | increases the scope depth |
| scd       | scd            | decreases the scope depth |
|           |                |                           |
|           |                |                           |
|           |                |                           |
|           |                |                           |

