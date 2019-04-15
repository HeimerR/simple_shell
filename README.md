# 0x15. C - Simple Shell

## Description
command language interpreter that executes commands read from the standard input device (keyboard) or from a file.
 
## Usage
* ./hsh

### Example
##### Interactive mode
vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1*  ls
hsh main.c shell.c
*Ghost-in-the-shell-1*
*Ghost-in-the-shell-1* exit
vagrant@vagrant-ubuntu-trusty-64 

##### non-interactive mode:

vagrant@vagrant-ubuntu-trusty-64 echo "ls" | ./hsh
hsh main.c shell.c test_ls_2
vagrant@vagrant-ubuntu-trusty-64
vagrant@vagrant-ubuntu-trusty-64 cat test_ls_2
ls
ls
vagrant@vagrant-ubuntu-trusty-64
vagrant@vagrant-ubuntu-trusty-64 cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
vagrant@vagrant-ubuntu-trusty-64

### commands
##### ls
- list directory contents

vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1* ls
hsh main.c shell.c

##### cat
 - concatenate files and print on the standard output

vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1* cat README.md
0x15. C - Simple Shell

##### pwd
 - print name of current/working directory
 
vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1* pwd
/home/vagrant/simple_shell/

##### env
 - run a program in a modified environment
 
vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1* env
USER=vagrant
...

##### exit
 - cause normal process termination with last command status
 
vagrant@vagrant-ubuntu-trusty-64 ./hsh
*Ghost-in-the-shell-1* exit 98
vagrant@vagrant-ubuntu-trusty-64 echo $?
98
vagrant@vagrant-ubuntu-trusty-64

### Errors

vagrant@vagrant-ubuntu-trusty-64 echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
vagrant@vagrant-ubuntu-trusty-64 echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
vagrant@vagrant-ubuntu-trusty-64

 ---
### Author
* **JaiberS** - [JaiberS](https://github.com/JaiberS)
* **HeimerR** - [HeimerR](https://github.com/HeimerR)