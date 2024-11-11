### 16 ~ 21(==18==)

<progress value="18" max="239" style="width: 100%;">7.1%</progress>

​	



# Started

> Every program must have a ==main== somewhere
>
> The `main` function (**clling** function) is essentially a regular function, and you can call other functions (**called** functions) within it to complete tasks.







```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");  
    return 0;  
}
```

- `stdio.h` (==st==and ==I==nput/==O==utput ==.== ==h==eader)

  > Tells the compiler to include information about the standard input/output library

  -  `stdio`

    **Libray**	-	like a **toolbox**

  - `h`

    Declatation and interface **linkage**

- `int`

  Specifies the funcation <u>return</u> an `int` **type**

- `printf` (print ==f==ormatted)

  **<u>Main</u>** calls a library function to output the result in a **predefined** format

- `\n` (==n==ew**line**)

##### Compile

`:! cc hello.c -o hello` 

- `:!` 

  Execute **<u>external</u>** command

- `cc`

  Is a **symlink** pointing to the **<u>gcc compiler</u>**

- `o` (==o==utput)



> Replenish
>
> > `:x` == `:wq`

###### Automation

Add to `init.lua`

```bash
vim.api.nvim_set_keymap('n', '<F5>', ':!gcc % -o %< && ./%< <CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<F5>', '<Esc>:!gcc % -o %< && ./%< <CR>', { noremap = true, silent = true })
```

- `n` (==n==ormal mode)

- `%` 

  Current file name

- `%<`

  Current file name without the extension

- `noremap`

  Ensure the mapping is not recursively remapped

- `silent`

  Suppress unnecessary output during command execution

- `<Esc>:` 

  Return to **<u>normal</u>** mode



## Function

> Is called by naming it, followed by a parenthesized list of **arguments**



### arguments

#### `printf` 

> (print ==f==ormatted)
>
> output the result in a **predefined** format



##### characters

> Between the quotes, is called a character string or string constant







###### \

- `\n` 	==n==ewline
- `\t`      ==t==ab<img src="./images/tab.png" alt="tab" style="zoom:5%;" />
- `\\`      backslash itself
- `\'`      single quote
- `\r`      carriage teturn<img src="./images/carriage return.png" alt="carriage return" style="zoom:5%;" />
- `\b`      ==b==ackspace

 



****



# Variables     	

​     

## Declaration

> Name and a list of variables	`int a, b, c;`



|        |                                                              | 1Byte = 8bit |
| ------ | ------------------------------------------------------------ | ------------ |
| int    | **int**egers                                                 | 4            |
| short  | short integer                                                | 2            |
| long   | long interger                                                | 4/8          |
|        |                                                              |              |
| float  | **float**ing point, i.e., numbers that may have a fractional part | 4            |
| double | double-precision floating point                              | 8            |
|        |                                                              |              |
| char   | A single byte                                                | 1            |

- `long`	

  > 4 bytes on a 32-bit system, 8 bytes on a 64-bit system

- `char`

  > Store a character (typicall form the ASCLL )
  >
  >  |    0 |  A   | a    |
  >  | ---: | :--: | :--- |
  >  |   48 |  64  | 97   |

 





​	

## %



### d

> **decimal**
>
> If the number is **not specified**, the result will be displayed with the **<u>default width</u>.**



##### %(==number==)d

> Place the result in a field **<u>(==number==) digits wide</u>**.(**right**-justified)



##### printf

`printf("%d %d")` 

- The **space**<img src="./images/space bar.png" alt="space bar" style="zoom:15%;" /> in the middle is also print





### f

> **floating-point**





#### Control the width and precision of the output



###### %3f 

> **Default** is ==6== digit after the decimal point

​	

###### %3.0f

> Floating-point number is to be printed at least ==3== characters wide, with no decimal point and fraction  digits.



###### %3.2f

> Printed at least ==6== characters wide, with ==2== digit after the decimal point





##### Omitted



###### %.2f

> Specifies ==2== characters after the decimal point, but the width is no constrained



###### %f

> Merely says to print the number as floating point(**Default** is ==6== digit after the decimal point)





### o,x,c,%

> octal
>
> hexadecimal
>
> character
>
> itself(%) - `%d%%`

# Arithmetic Expressions

> If an arithmetic operator has one **<u>floating-point</u>** and one integer operand, the **<u>integer</u>** is converted to  a **<u>floating-point</u>** before the operation.



**<u>Floating-point numbers</u>** are recommended to be written as `1.0` instead of `1`

​	





