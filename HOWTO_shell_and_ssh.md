# HOWTO Use a Shell (aka Terminal) and SSH

By Michael Hahsler

A [shell](https://en.wikipedia.org/wiki/Shell_(computing)) is the user-exposed outside layer for the operating system. 
Often a command-line interface (CLI) is provided which can be accessed using a terminal emulation program. 
It provides a more powerful way to interact with the operating system using scripts. Your computer has a shell. 

* Linux: Popular shells are `sh` and [`bash`](https://www.gnu.org/software/bash/).
* Windows: Shells are the `Command Prompt` and a better version is [`PowerShell`](https://learn.microsoft.com/en-us/powershell/).
* MacOS: The app `Terminal` defaults to [`zsh`](https://zsh.sourceforge.io/).

Most shells understand similar commands and being able to use a shell is needed to work as a computer 
scientist with cloud-based servers. The commands that everyone needs to know are
`ls -lh`, `cd`, `rm`, `mkdir`, `cat`, and the meaning of `,`, `.`, `..` and `*`.
Here are a [brief introduction](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview) and
a short [Linux command cheat sheet.](https://files.fosswire.com/2007/08/fwunixref.pdf). 



To use a server remotely, you can securely log into a Unix/Linux server using the [secure shell protocol (SSH)](https://en.wikipedia.org/wiki/Secure_Shell). It opens a shell on the server that you can use from your computer. You need an ssh client. Linux, Windows Powershell, Mac and WSL2 contain a client called `ssh`.
It is often convenient to login automatically without using the password. This can be done by setting up a ssh key ([OpenSSH key management](https://en.wikipedia.org/wiki/Secure_Shell)).  


For SMU students: [Information on how to use SMU's Genuse servers](https://www.smu.edu/OIT/Services/genuse).


## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
