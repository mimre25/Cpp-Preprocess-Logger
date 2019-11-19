# Cpp-Preprocessor-Logger
A simple C++ preprocessor logger that allows to set a log level and converts everything below the level to NOPs


##Usage
Just include the header and then use the macros as so:

```
LOG("This is a simple level 0 log");
LOG1("This is a simple level 1 log"); 
ERROR("This is an error message, it won't get 'NOPed' out");
```

Please note that every macro automatically adds its name and a ':' before the output and a '\n' at the end.
The code above with a LOG_LEVEL of 0 produces:

```
LOG: This is a simple level 0 log
LOG1: This is a simple level 1 log
ERROR: This is an error message, it won't get 'NOPed' out
In <filename> line <line number>
```

The `LOG_LEVEL` can be set in Logger.h, or during compilation by adding `-D LOG_LEVEL=<level>`
Another Handy variable is `STOP_ON_ERROR`, which can be set similarily to `LOG_LEVEL`, but to either true or false. If it is set to true, then the program will halt on an ERROR.

Other Macros inside `Logger.h`:

* `WARN` - Produces a warning that is never NOPed out
* `REPORT` - Similar to warning.
* `HIGHLIGHT` - For Highlighted outputs using a color.

##Example/Optimization

The file main.cpp shows an example. 

```
mimre@hpc-vis-1:~/tmp/Cpp-Preprocessor-Logger$ cat main.cpp 
#include "Logger.h"
#include "stdio.h"

int main()
{

  LOG("TEST");
  LOG1("TEST1");
  LOG2("TEST2");
  printf("Test\n");
  return 0;
}
```
Below the output of compilation with different LOG_LEVEL variables shows the different size of the assembly output, ie the NOPs not included.

```
mimre@hpc-vis-1:~/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=0 -O0 main.cpp -S && ls -lh main.s
-rwxrwxr-x 1 mimre mimre 1.4K Nov 19 09:12 main.s
mimre@hpc-vis-1:~/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=1 -O0 main.cpp -S && ls -lh main.s
-rwxrwxr-x 1 mimre mimre 1.1K Nov 19 09:12 main.s
mimre@hpc-vis-1:~/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=2 -O0 main.cpp -S && ls -lh main.s
-rwxrwxr-x 1 mimre mimre 769 Nov 19 09:12 main.s
mimre@hpc-vis-1:~/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=3 -O0 main.cpp -S && ls -lh main.s
-rwxrwxr-x 1 mimre mimre 447 Nov 19 09:12 main.s
```

Below the output depending on the LOG_LEVEL

```
mimre@hpc-vis-1:~/tmp/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=0 main.cpp -o main && ./main
LOG: TEST
LOG: TEST1
LOG: TEST2
Test
mimre@hpc-vis-1:~/tmp/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=1 main.cpp -o main && ./main
LOG: TEST1
LOG: TEST2
Test
mimre@hpc-vis-1:~/tmp/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=2 main.cpp -o main && ./main
LOG: TEST2
Test
mimre@hpc-vis-1:~/tmp/Cpp-Preprocessor-Logger$ g++ -D LOG_LEVEL=3 main.cpp -o main && ./main
Test
```


