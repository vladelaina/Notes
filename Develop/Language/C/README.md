# （23~26）==24==



<progress value="24" max="239" style="width: 100%;">7.1%</progress>



> Interesting projects
>
> - [cmus](https://github.com/cmus/cmus?tab=readme-ov-file)

# A Totorial Intrduction



## Getting Started

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

##### Automation

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





##### \

- `\n` 	==n==ewline
- `\t`      ==t==ab<img src="./images/tab.png" alt="tab" style="zoom:5%;" />
- `\\`      backslash itself
- `\'`      single quote
- `\r`      carriage return<img src="./images/carriage return.png" alt="carriage return" style="zoom:5%;" />
- `\b`      ==b==ackspace

 



****



## Variables and Arithmetic Expressions

​     

### Variables



#### Declaration

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

#### %



##### d

> **decimal**
>
> If the number is **not specified**, the result will be displayed with the **<u>default width</u>.**



###### %(==number==)d

> Place the result in a field **<u>(==number==) digits wide</u>**.(**right**-justified)



###### printf

`printf("%d %d")` 

- The **space**<img src="./images/space bar.png" alt="space bar" style="zoom:15%;" /> in the middle is also print





##### f

> **floating-point**





###### Control the width and precision of the output



###### %3f 

> **Default** is ==6== digit after the decimal point

​	

###### %3.0f

> Floating-point number is to be printed at least ==3== characters wide, with no decimal point and fraction  digits.



###### %3.2f

> Printed **at least** ==6== characters wide, with ==2== digit after the decimal point





##### Omitted



###### %.2f

> Specifies ==2== characters after the decimal point, but the width is no constrained



###### %f

> Merely says to print the number as floating point(**Default** is ==6== digit after the decimal point)





##### o,x,c,%

> octal
>
> hexadecimal
>
> character
>
> itself(%) - `%d%%`



## Arithmetic Expressions

> If an arithmetic operator has one **<u>floating-point</u>** and one integer operand, the **<u>integer</u>** is converted to  a **<u>floating-point</u>** before the operation.



**<u>Floating-point numbers</u>** are recommended to be written as `1.0` instead of `1`

​	





## for

```c
for (initialization; condition; icrement){
	// loop body
}
```



## Symbolic Constants

`#define NAME replacement-list`



> Thereafter, any occurrence of name (not in quotes and not part of another name) will be replaced by the corresponding replacement text.

- `NAME` 

  A sequence of letters and digits that begins with a letter

  > Conventionally **==written in upper case==** so they can be readily **distinguished** from lower case variable names.

- `replacement-list`

  It's can be any sequence of characters; it is not limited to numbers.



- Notice 

   There is no semicolon(==;==) at the end of a `#define` line



## Character Input and Output

> **Stream**<img src="./images/stream.png" alt="stream" style="zoom:15%;" /> refers to a **<u>channel</u>**<img src="./images/channel.png" alt="channel" style="zoom: 5%;" /> for **data transmission**
>
> - Text input or output, regardless of where it originates or where it goed to, is dealt with as **streams**<img src="./images/stream.png" alt="stream" style="zoom:5%;" /> of characters

- A ==text stream==<img src="./images/stream.png" alt="stream" style="zoom:10%;" />is a sequence of characters divided into **<u>lines</u>**<img src="./images/lines.png" alt="lines" style="zoom:5%;" />; echo line consists of zero or more characters followed by a **newline character**.

- All data is a bit pattern

  > What appears to be a character on the keyboard or screen is of course, like everything else, stored internally just as a bit pattern.





##### getchar & putchar

> ==Reading== or ==wirting== one character at a time.



###### getchar()

```c
char c = getchat();
```

- Reads the next input character from a **<u>text stream</u>**<img src="./images/stream.png" alt="stream" style="zoom:5%;" />(normally come from the **<u>keyboard</u>**<img src="./images/keyboard.png" alt="keyboard" style="zoom:5%;" />) and returns that as its value.



###### puterchar()

> Prints a character each time it is called

```c
putchar(c);
```

- Prints the contents of the integer variable c as a character, usually on the **screen**<img src="./images/screen.png" alt="screen" style="zoom:8%;" />.

- Compare<img src="./images/compare.png" alt="compare" style="zoom:10%;" /> with `printf`

  - `putchar`

    No❎ buffer

    - Echo call **immediately** displays the character.

  - `printf` 

    Has a buffer

    - It first stores the content, and only when the conditions are met (shuch as encountering a newline character or the buffer being full)



### File Copying

```c
#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
```

- USE <img src="./images/ctrl+d.png" alt="ctrl+d" style="zoom:25%;" /> to indicate the end of iput.

  - Only use `Ctrl+c` when **necessary**

    Such as when the porgram is **<u>stuck</u>** of you want to **<u>forcefully terminate</u>**<img src="./images/stop.png" alt="stop" style="zoom:5%;" /> it.

- **<u>int</u>** c;

  > `char` can be **signed**(-128 ~ 127) or **unsigned**(0 ~ 255) on different platforms, using `int` avoids conflicts with `EOF`, hold any value taht getchat returns.

- `!=` > `=` (precendence)

- `EOF`(==E==nd-==O==f-==F==ile)

  > Usually ==-1==

- Declaration & assign

  - **Simple code**, assign at declaration
  - **Complex logic**, declare first, then assign



### Character Counting

###### use while

```c
#include <stdio.h>

int main() {
    long nc = 0; //long integers are at least 32 bits.
    int c; //temporary variable
    while ((c = getchar()) != EOF) {
            ++nc;
    }
    printf("%ld\n", nc);
    return 0;
}
```

- `long nc = 0`

  Setting `nc` to 0 ensures it returns 0 for empty input

- Press <img src="./images/ctrl+d.png" alt="ctrl+d" style="zoom:25%;" /> ==twice== to end the input

- `%ld` (long decimal)

  - `l`

    - Just a type modifier that indicates the data is of type `long`

    - The bit size of `long` is determined by the **system** and the **compiler**

  - `d`

    Indicates that this is a decimal integer

- `++nc` & `nc++`

  - `++nc`

    Increments the value first and then uses the incremented value

  - `nc++`

    User the value first and then increments it

  - Generally, `++c` is recommended



######  use for

```c
#include <stdio.h>

int main() {
    double nc;  
    for (nc = 0; getchar() != EOF; nc++)  
        ; //empty
        printf("%.0f\n", nc);      
    return 0;  
}
```

- `%.0f`
  - `%f` for both float and double
  - Suppresses the decimal point and the fractional part (if zero)

- The body of this `for` loop is **empty**
  - Called a **<u>null statement</u>**
  - Put it(**;**) on a separate line to make it **visible**



### Line Counting

```c
#include <stdio.h>

int main() {
    int c, nl;
    nl = 0;
    
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    
    printf("%d\n", nl);
    
    return 0;
}
```

- `==`

  Is equal to 

  - single`=` uses for assignment



- `'\n'`

  Is a ==character constant==; in the ASCLL character set its value is **10**, the internal representation of the character \n

  - Why use `'\n'`  instead of 10
    - They all represent the same `'\n'` across different **<u>encodings</u>**
  - sigle character & string constant
    - In expressions is just an **integer**(10)
    - The string constant containing **one character**(newline character)



#### expand

Use `putchar(' ')` to output a character.(more effeicient)



### Word Counting

```c
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() {
    int c, state, nc, nw, nl;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n') {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("nc: %d\n", nc);  
    printf("nw: %d\n", nw);  
    printf("nl: %d\n", nl); 

    return 0;
}
```

 ##### `IN` `OUT` (Symbolic constants)

  ```c
  #define IN 1  
  #define OUT 0 
  ```

  - It improves code **readability**, especially in complex programs, making **modifications easier**.



##### `if-else`

> One and only one of the two statements associated with an `if-else` is performed

```c
if (expression)
	statement1
else
	statement2
```




##### `||` - OR

###### precedence

> `&&` > `||` 

- `&&` - AND



##### conut word

 Every time the program encounters the first character of a word, it counts one more word(`++nw`)

  ```c
  if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
  } else if (state == OUT) {
      state = IN;
      ++nw;
  }
  ```





## Arrays

```c
#include <stdio.h>

int main() {
    int c, nwhite, nother;
    int ndigit[10] = {0}; 

    nwhite = nother = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits =");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
```

- Output is similat to: `digits = 9 3 0 0 0 0 0 0 0 1, white space = 123, other = 345`


##### Declares array

```c
int ndigit[10] = {0};
```

- Declares an array of 10 integers, with `ndigit[0]` initialized to **0**, and the **other elements** automatically initialized to **0**

- Subscripts[**?**] can be integers, including variables(e.g.,`i`) and constants



###### Count digits

```c
if (c >= '0' && c <= '9') {
    ++ndigit[c - '0'];
}
```

- `c >= '0' && c <= '9'`

  > Should use a range check based on **<u>char</u>**acters(`'0'` `'9'`)

  - Precedence

    - `&&` > `||`

      > ```c
      > a || b && c   ==  a || (b && c)
      > ```

- `++ndigit[c - '0']`  

  - `c` & `'0'` are characters, and subtracting(-) give the number represented by `c`
  - <img src="./images/ASCLL.png" alt="ASCLL" align = "left" style="zoom:10%;" />
  
    - '0' - 48
    - '1' - 49
    - '10' - 49 48(So recommended `<= 9`)
      - 'a' - 97     'z' - 122
      - 'A' - 65     'Z' - 90
  
  - Chars are essentially **small integers**
  
    > Therefore, they can be treated as integers in **<u>arithmetic operations</u>**

 

##### if - else if - else

```c
if (condition1)
    statement1
else if (condition2)
    statement2
...
else
    statementn
```

- To express a multi-way decision



##### Local Variable

```c
for (int i = 0; i < /* ending condition */; ++i) {
    
 }
```

- `int i = 0`

  > Restrict variables scope to the minimum required

- `++i` - Recommended style





处理剪切板的内容，然后将内容给chatgpt(包括要提起多少，然后自动复制到朗读网页，包括自动清空里面的内容)
