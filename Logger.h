//
// Created by mimre on 10/25/17.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <csignal>

#define LOG_LINE_STEP 1000000

//#define LOG_LEVEL 0

#define STOP_ON_ERROR true


#define ERROR(s, ...) { fprintf(stderr,"Error: "); fprintf(stderr, s, ##__VA_ARGS__); fprintf(stderr,"\nIn %s line %d\n", __FILE__, __LINE__); if (STOP_ON_ERROR) { WTF; } }
#define WARN(s, ...) { fprintf(stderr, "WARNING: "); fprintf(stderr, s, ##__VA_ARGS__); fprintf(stderr,"\n");  }
#define REPORT(s, ...) { fprintf(stdout, "REPORT: "); fprintf(stdout, s, ##__VA_ARGS__); fprintf(stdout,"\n");  }
#define HIGHLIGHT(s, ...) { fprintf(stdout, "\n \033[0;36mHIGHLIGHT: "); fprintf(stdout, s, ##__VA_ARGS__); fprintf(stdout,"\033[0m\n\n");  }


#if LOG_LEVEL > 0
#define LOG(s, ...) {}
#else
#define LOG(s, ...) { fprintf (stdout, "LOG: "); fprintf(stdout, s, ##__VA_ARGS__); fprintf(stdout,"\n"); }
#endif
#if LOG_LEVEL > 1
#define LOG1(s, ...) {}
#else
#define LOG1(s, ...) { fprintf(stdout, "LOG: "); fprintf(stdout, s, ##__VA_ARGS__); fprintf(stdout,"\n"); }
#endif
#if LOG_LEVEL > 2
#define LOG2(s, ...) {}
#else
#define LOG2(s, ...) { fprintf(stdout, "LOG: "); fprintf(stdout, s, ##__VA_ARGS__); fprintf(stdout,"\n"); }
#endif


#define WTF printf("WTF\n"); std::raise(SIGINT)

#endif //LOGGER_H
