### 12 ~ 17

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



###### escape characters

- `\n` 	==n==ewline
- `\t`      ==t==ab<img src="./images/tab.png" alt="tab" style="zoom:5%;" />
- `\\`      backslash itself
- `\'`      single quote
- `\r`      carriage teturn<img src="./images/carriage return.png" alt="carriage return" style="zoom:5%;" />
- `\b`      ==b==ackspace

 



****



# Variables and Arithmetic Expressions

  
