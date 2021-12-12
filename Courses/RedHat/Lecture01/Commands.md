# Lecture 1

> Option: starts with (-) or (--)
>
> Parameter: doesn't start with (-) or (--)
>
> `September 2020` is a parameter in `cal September 2020`
>
> `-n` is an option in `uname -n`

## System info commands

#### Name of the system

    uname

#### User name

    uname -n

#### Print the network node hostname

    uname --nodename

#### Manual of `uname` command

    man uname

#### All information about the system

    uname --all

## Calendar

#### Print the calendar

    cal

#### Print the calendar of `September 2020`

    cal September 2020

#### Print the calendar of year `0005`

    cal 5

#### Print the calendar of year `2020`

    cal 2020

#### Print `Ms.Shereen`'s birth day `18-12-1979`

    cal 18 12 1979

> cal man
>
> `cal [options] [[[day] month] year]]`

## Accounts

#### Switch account

    su - username

#### Switch to the previous account

> logout of the system if there is no previous account

    logout

### Current logged in user info

#### Print effective username of the user who ran whoami

    whoami

#### Print username and date of the previous account

    who am i

## File system

> `root/sbin` Contains the administration commands super user `root` can use
>
> `root/bin` Contains the commands regural user can use
>
> `root/etc` Contains configration files
>
> `root/dev` Contains files of devices
>
> `root/var` Contains files to which the system writes data during the course of its operation
>
> `root/usr` Contains users files
>
> `root/tmp` Contains temporary files

> Note the difference between files, directories and shortcuts:
>
> `fileName`
>
> `directory/` has (/) after the directory name
>
> `shortcut@` has (@) after the name of shortcut

> Max file name length 255 character

#### `pwd` Print working directory

    pwd

#### `ls` List files and dirctories within the current working directory

    ls

#### `ls` List the contents of the /etc directory

    ls /etc

#### `ls -l` Print the long listing format

    ls -l /etc/hosts

> Output
>
> -rw-r--r-- 1 root root 337 Oct 4 11:31 /etc/hosts

#### `mkdir` Make dirctory

    mkdir dirName

#### `touch` Create a new file

    touch fileName

#### Print the full content of a file

    cat fileName

#### Print the content of a file from the beginning

    head fileName

#### Print the content of a file from the end

    tail fileName
