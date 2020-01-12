Features Of terminal


    -Saves against the attack of adding multiple spaces at the beginning or in the middle of Commands
    -Colourfull Output
    -Can hide commands from history!
    -Does not crash with just an empty string!!
    -All External Commands Works
    -Just cd brings to home directory
    -All command Options for the external commands work
    -Can give multiple command options simultaneously!!
    -Creates a child process for external commands using fork, wait and execv!

Internal Commands: 


    -cd
        -Changes Directory
        -Special Features
            -Works with preceding spaces e.g "      cd" works!
            -works with spaces as well e.g "cd       /" is the same as "cd /"
            -Typing just "cd" brings to home directory!
    
    -echo
        -Prints message on the terminal
        -Special Features
            -Works with preceding spaces e.g "      echo " works!
            -Spaces don't matter e.g "echo     hi" is the same as "echo hi"
            -Spaces are taken into consideration with quotes e.g 'echo "   hi   hello"' will print all the spaces
            -Quotes are not printed!! e.g 'echo "hi"' prints hi without the quotes!
        -flags
            -"-n" - does not add the newline at the end
    
    -pwd
        -prints the current working directory
        -Special Features
            -Works with preceding spaces
        
    
    -history
        -Gives the history of Commands used so Features
        -Special Features
            -Adding a space before any command hides it from history!
            -Empty string is not entered in history!
            -Works with preceding spaces
    
    -exit
        -Exits the terminal
        -Special Features
            -Works with preceding spaces

External Commands:


    -ls
        -Lists the files and folders in the current directory
        -Special Features
            -
        -flags
            -"-a" - Shows the hidden files as well
            -"-l" - Shows Long format i.e detailed Information
            -"-h" - Human readable
            -rest all the flags work!!
    
    -cat
        -Displays the content of the files
        
        -flags
            -all flags work
    
    -date
        -displays the date
        -flags
            -all flags work

    -rm
        -removes files
        -flags
            -all flags work
    
    -mkdir
        -created directories
        -flags
            -All Flags Work!
    

