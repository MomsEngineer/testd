#include <syslog.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

const std::string daemon_name = "testd";

void trace(std::string str, int level) {
	std::string message;
	switch(level) {
		case LOG_INFO:  message = "[INFO] : "; break;
		case LOG_DEBUG: message = "[DEBUG] : "; break;
		case LOG_ERR:   message = "[ERROR] : "; break;
		default: message = "[LEVEL] : "; break;
	}
	message += str;
	syslog(level, message.c_str());			
}


int main() {
	openlog(daemon_name.c_str(), LOG_CONS | LOG_PID | LOG_NDELAY, LOG_DAEMON);


	std::string mes = "Start '" + daemon_name + "' daemon";
	trace(mes, LOG_DEBUG);

	pid_t pid = fork();
	if (pid < 0) {
		trace("Exit with error.", LOG_ERR);
		exit(EXIT_FAILURE);
	} else if (pid > 0) {
		trace("Parent process succeeds.", LOG_DEBUG);
		exit(EXIT_SUCCESS);
	}

	trace("A new child process is created.", LOG_DEBUG);

	pid_t sid = setsid();
	if (sid < 0) {
		trace("The child exits with error.", LOG_ERR);
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	int i = 0;
	while(1) {
		mes = "[session " + std::to_string(sid) + "] " + "#" + std::to_string(i) +
			  " --> NIIT. UNIX Course. The task of configuring systemd.";
		trace(mes, LOG_INFO);
		sleep(30);
		++i;
	}

	closelog();
	exit(EXIT_SUCCESS);

	return 0;
}
