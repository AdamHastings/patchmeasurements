#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

static void skeleton_daemon() {
    
    pid_t pid;

    // Fork off the parent process
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // If we get a good PID, then we can exit the parent process
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // On success: The child becomes session leader
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }

    // Catch, ignore, and handle signals
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    // Fork off for the second time
    pid = fork();

    // An error occurred...
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // Success! Let the parent terminate
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Change the file mode mask
    umask(0);

    // Close all file descriptors
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--) {
        close(x);
    }

    openlog("firstdaemon", LOG_PID, LOG_DAEMON);
}


int main() {
    skeleton_daemon();
    
    FILE *logfile;
    logfile = fopen("freqlogs.log", "a");

    int i=0;
    while(i < 10) {
        syslog(LOG_NOTICE, "First daemon running.");

        fprintf(logfile, "test\n");

        sleep(2);
        i++;
    }

    syslog(LOG_NOTICE, "First daemon terminated.");
    closelog();

    return EXIT_SUCCESS;
}
