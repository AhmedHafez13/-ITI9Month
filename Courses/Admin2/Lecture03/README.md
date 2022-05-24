# Admin 2 - Lecture 3

- The /etc/passwd file
  username:x:uid:gid:comment:home-directory:login-shell

- The /etc/shadow file
  username:encrypted passwd:last changed:min:max:warn:??:expire:future-use

- The /etc/group file
  groupname:x:gid:comma-separated list of group members

---

### Adding a new user account

    $ useradd {username}

To view and modify default setting use

    $ useradd -D {username}

Change a user password

    $ passwd username

Adding multiple user accounts

    $ newusers filename

---

### Change a user's account information

#### Edit the /etc/passwd or /etc/shadow files manually

#### Use the chage command discussed later

#### Use the `usermod` command

    $ usermod [options] username

> `-l {login name}` changes the login name use
>
> `-L` lock the password use
>
> `-U` unlock the password use

---

### Delete a user account you can

#### Manually remove the user from

- /etc/passwd file
- /etc/shadow file
- /etc/group file
- remove the user's home directory (/home/username)
- and mail spool file (/var/spool/mail/username)

#### Use the userdel command.

    $ userdel [-r] username

> `-r` Files in the user's home directory will be removed along with the home directory itself and the user's mail spool.

---

### The chage command sets up password aging

    $ chage [options] username

> `-m` to change the min number of days between password changes
>
> `-M` to change the max number of days between password changes
>
> `-I {INACTIVE}` Set the number of days of inactivity after a password has expired before the account is locked. The `INACTIVE` option is the _number of days_ of inactivity. A user whose account is locked must contact the system administrator before being able to use the system again.
>
> `-E {EXPIRE_DATE}` change the expiration date for the account
>
> `-W` change the number of days to start warning before a password change will be required

---

### Creating New Group

    $ groupadd {groupName}

#### Modifying an Existing Group

    $ groupmod [options] {groupName}

#### Deleting a Certain Group

    $ groupdel {groupName}

#### List all file which are owned by groups not defined in `/etc/group` file

    $ find / -nogroup

#### `gpasswd` command

Usage: gpasswd [option] GROUP
options:

| option                             | description                              |
| ---------------------------------- | ---------------------------------------- |
| `-a`, `--add` USER                 | add USER to GROUP                        |
| `-d`, `--delete` USER              | remove USER from GROUP                   |
| `-Q`, `--root` CHROOT_DIR          | directory to chroot into                 |
| `-r`, `--delete-password`          | remove the GROUP's password              |
| `-R`, `--restrict`                 | restrict access to GROUP to its members  |
| `-M`, `--members` USER,...         | set the list of members of GROUP         |
| `-A`, `--administrators` ADMIN,... | set the list of administrators for GROUP |

---

### Login Shells vs Non-Login Shells

Initialize sequence

Login Shell

> `etc/profile` -> `/etc/profile.d/*.sh` -> `~/.bash_profile` -> `~/.bashrc` -> `/etc/bashrc`

Non-Login Shell

> `~/.bashrc` -> `/etc/bashrc` -> `/etc/profile.d/*.sh`

---

### Switching Accounts

`su` Command

    $ su [-] [username]
    $ su [-] [username] -c command

Option `-`, `-l` or `--login` Starts the shell as a login shell with an environment similar to a real login:

- clears all the environment variables except TERM
- initializes the environment variables HOME, SHELL, USER,LOGNAME, and PATH
- changes to the target user's home directory
- sets argv[0] of the shell to '-' in order to make the shell a login shell

---

### `sudo` Command

- `sudo` access is controlled by the `/etc/sudoers`.
- This file is edited by `visudo`, an editor and syntax checker.
- To give a specific group of users limited root privileges
  > User_Alias LIMITEDTRUST=st1,st2
  >
  > Cmnd_Alias MINIMUM=/etc/rc.d/init.d/httpd
  >
  > Cmnd_Alias SHELLS=/bin/sh,/bin/bash
  >
  > LIMITEDTRUST ALL=MININUM
  >
  > user5 ALL=ALL,!SHELLS
  >
  > %development station1=ALL, !SHELLS

---

### File Ownership and Permissions

Every file and directory has both user and group ownership. A newly-created file will be owned by:

- The user who creates it
- That user's primary group (unless the file is created in a set group ID `SGID` directory
- File ownership can be changed using `chown` command

#### Example

    $ chown {username} {file1}
    $ chown {username}:{group1} {file1}
    $ chown :{group1} {file1}

####Access level

- User (u)
- Group (g)
- Others (o)

#### Access mode

- Read (r)
- Write (w)
- Execute (x)

#### Example

    $ chmod u=rw file1
    $ chmod g+x file1
    $ chmod o-w file1
    $ chmod u+x,go-w file1
    $ chmod 742 file1

> `u` = user, `g` = group, `o` = others
>
> `r` read, `w` write, `x`

### Advanced Permissions

- `setuid` = `s`: a bit that makes an executable run with the privileges of the owner of the file
- `setgid` = `s`: a bit that makes an executable run with the privileges of the group of the file
- `sticky bit` = `t`: a bit set on directories that allows only the owner or root can delete files and subdirectories

#### `setuid` Set user id to a directory

    $ chmod u+s executable1
    $ ls –l
    -rwsr-xr-x ...

#### `setgid` Set group id to a file

    $ chmod g+s executable1
    $ ls –l
    -rwxr-sr-x ...

#### `setuid` Set group id to a directory

    $ chmod g+s directory1
    $ ls –l
    drwxr-sr-x ...

#### `sticky bit` Set sticky bit to a directory

    $ chmod o+t directory1
    $ ls –l
    drwxrwxrwt ...

### Default Permissions

The umask command sets the default permissions for files and directories

    $ umask 002
    $ umask 022

#### The ACL mask

- Mask limits the maximum permissions that both the group that owns the file and that supplementary users and groups in ACLs can have.
- getfacl command displays the current mask

> changing group permissions on a file with an ACL by using chmod, it actually changes the mask, which limits the max. permissions of all groups and supplementary users

#### Default ACLs (Inheritance)

A directory can have a default ACL entries
that are automatically set on new files
created in that directory

    $ setfacl -m d:u:ahmed:rw directory
    $ setfacl -m d:u:ahmed:rx directory

---

### Access Control Lists

- Use ACLs to generate customized permission sets
- To enable ACLs on a filesystem, the filesystem must be mounted with the acl option

#### `getfacl` get file access control lists

    $ getfacl /etc

    # file: etc
    # owner: root
    # group: root
    user::rwx
    group::r-x
    other::r-x

> `group::rw-` applies to file group
>
> `group::telecom:rwx` applies to telecom group
>
> `group::10:rw-` applies to group id 10
>
> `other::rwx` applies to everyone else

    $ setfacl –m u:user1:rw file1        # grants rw to user1
    $ setfacl –m g:group1:rx directory1  # grants rx to group group1
    $ setfacl –x u:user1 file1           # remove user1 acl entry

#### Permission Precedence

1. if owner, then the file's owner permission apply
2. if user has an acl entry, then the user acl applies as long as it is permitted by mask
3. if matches file's group or acl group entry then it applies
4. otherwise the file's other permissions apply.

---

### `chmod` Octal Mode Numbers

> 4 = r (Read)
>
> 2 = w (Write)
>
> 1 = x (eXecute)

> 1 = t (sticky bit)
>
> 2 = s (setgid)
>
> 4 = s (setuid)

| Octal | Description                                                               |
| ----- | ------------------------------------------------------------------------- |
| 0400  | Allows the owner to read                                                  |
| 0200  | Allows the owner to write                                                 |
| 0100  | Allows the owner to execute files and search in the directory             |
| 0040  | Allows group members to read                                              |
| 0020  | Allows group members to write                                             |
| 0010  | Allows group members to execute files and search in the directory         |
| 0004  | Allows everyone or the world to read                                      |
| 0002  | Allows everyone or the world to write                                     |
| 0001  | Allows everyone or the world to execute files and search in the directory |
| 1000  | Sets the sticky bit                                                       |
| 2000  | Sets the setgid bit                                                       |
| 4000  | Sets the setuid bit                                                       |
