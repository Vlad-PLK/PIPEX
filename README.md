<p>
  <h1 align="center">PIPEX👷‍♂️</h1>
</p>
What is project Pipex ?
<br></br>
PIPEX is a C programming project where you discover for the first time how do processes work, how to interact with them, how to execute a simple shell command from
C, and of course how pipes work.
<br></br>
Here, I will not go too deep into processes, but I recommend you to instead read about it directly here : https://www.gnu.org/software/libc/manual/html_node/Processes.html.
<br></br>
To make it quick, each time you want to execute a shell command in C, it will automaticaly end your current process which is the file you are writting code in.
It means that if let's say you execute a simple "ls" command and then you want to make something else after it, it will not be considered.
That's why in this project we firstly learned fork() function.
<br></br>
<p align="center">
  <img width="50%" alt="fork_function" src="https://github.com/Vlad-PLK/PIPEX/assets/61476758/47720197-16c7-4519-8fe8-8bdf93ced0e0">
</p>
Once we've understand how fork works, what are processes and what are their utility, we can now dig into the real goal of this project.
In pipex we want to be able to recreate bash/shell pipe system which allows us to execute multiple commands in chain, as for example :
<br></br>
<p align="center">
  <img width="60%" alt="pipe_example" src="https://github.com/Vlad-PLK/PIPEX/assets/61476758/7b98bf7b-66ec-4842-828d-c7566f145550">
</p>
In the example above we execute the command "wc" (word count) with the infile named "text.txt" and we redirect it to another wc command with a pipe and finally to "text2.txt".
The pipe "|" redirects the output of one command into the input of another.
Once again here's a quick explanation from GeekforGeeks :
<br></br>
<p align="center">
  <img width="50%" alt="pipes_gfg" src="https://github.com/Vlad-PLK/PIPEX/assets/61476758/de76a4e1-1bf5-4fec-964e-aa0ffc5c4146">
</p>
Finally, we need to combine fork and pipe functions to create the program that will execute a command like I made above.
Here's a quick pseudocode of what it should be : 
```C
int  main(void)
{
      
}
```

