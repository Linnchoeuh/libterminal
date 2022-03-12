# libterminal
> You have to include the file `terminal.h` in order to use this lib.

> You must add the -l printo flag at compilation.

**There's more info about each function in the .h files of the library** 

A little library to generate a terminal and manipulate input from STDIN.

## Usage

Use the makefile to compile the lib.

`make` will gives you a .a file

`make install` will install the library and the include in `/home/$LOGNAME/.froot/`

`make uninstall` will remove the library from your computer.

## Features

This lib has four major function :
- [**read_entry()**](#read_entry)
- [**get_entry()**](#get_entry)
- [**term_cd()**](#term_cd)
- [**term_execute()**](#term_execute)

It also have a set of function to [manage the environment variable](#the-env-set-of-function).

### read_entry()

**Prototype :**
```c
char *read_entry(bool block_sigint);
```
Read the STDIN of your terminal and returns a *char\** of what it read.
The function ends when you press enter. But you can stop it with CTRL+D, then the function will return NULL.

The parameter **block_sigint** let you choose if you want to ignore the CTRL+C key combination (SIGINT signal).



### get_entry()

**Prototype :**
```c
char **get_entry(char *entry_header, bool block_sigint);
```
Similar to [**read_entry()**](#read_entry) but return a *char\*\** instead of a *char\**.

> Same as read_entry(), you can stop the function with CTRL+D, then the function will return NULL.

The *char\*\** is splitted by the spaces get in the STDIN and has a NULL terminator at his end.

**Example :**
```
"    I  got this!"
```
Gives :
```
{"I", "got", "this!", NULL}
```
The parameter **entry_header** let you write a message before the entry reading.

**Example :**
```c
#include <terminal.h>

int main(void)
{
  char **split;
  
  split = get_entry("MyTerminal> ", true);
  term_plit_free(split);
  return (0);
}
```
Output : 
```
$> gcc main.c -lterminal
$> ./a.out
MyTerminal> 
```

The parameter **block_sigint** let you choose if you want to ignore the CTRL+C key combination (SIGINT signal).



### term_cd()

**Prototype :**
```c
bool term_cd(char *path, char **env);
```
Works the same way than cd in any terminal.

The parameter **path** is the path of where you want to go. It supports absolute and relative path.

The parameter **env** is optional you can put it at NULL if you want. 
If you don't then the cd function will try to update the environment variable if they exist.
- **PWD** path
- **OLDPWD** path



### term_execute()

**Prototype :**
```c
int term_execute(const char *cmd, char **env);
```
Let you execute programs installed (like ```ls```) or not (like ```./a.out```).

The parameter **cmd** is the program you want to launch.

The parameter **env** is just the environment variable.



## The env set of function
This will help you to manage the environment variable you get in a main like this :
```c
#include <terminal.h>

int main(int argc, char **argv, char **env)
{
  // And then here, use the env var in paramter
  return (0);
}
```
### Here's are the avaible function :
- **env_enable_modification()** *Necessary for some function.*
- **env_var_free()**
- **env_get_var()**
- **env_add_var()** *Needs env_enable_modification() to be called, to work properly.*
- **env_delete_var()** *Needs env_enable_modification() to be called, to work properly.*
- **env_set_var()** *Needs env_enable_modification() to be called, to work properly.*
- **env_get_var_pos()**
- **env_get_path()**


## Issues
No issues to deplore, nor than memory error or leak. But feel free to report bug :).
