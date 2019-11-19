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
