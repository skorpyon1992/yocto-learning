#include <string>
#include <syslog.h>
#include <sys/wait.h>

#include <boost/chrono.hpp>
#include <boost/random.hpp>
#include <boost/thread/thread.hpp> 


bool volatile done = false;
static const std::string app_name = "first-yocto-app";

static void SIGTERMhandler(int sig)
{
  done = true;
}

int main(int argc, char ** argv)
{
  signal(SIGTERM, SIGTERMhandler);
  openlog(app_name.c_str(), LOG_PID, LOG_DAEMON);
  syslog(LOG_DEBUG, "App is running \n");

  int delay = 0;
  boost::random::mt19937 rng;
  boost::random::uniform_int_distribution<> random_delay(100,600);
  
  while (!done) {
    syslog(LOG_DEBUG, "Random sleep %d \n", delay);
    delay = random_delay(rng);  
    boost::this_thread::sleep_for(boost::chrono::milliseconds(delay));
  }
  
  syslog(LOG_DEBUG, "App stopped \n");
  closelog();
  return 0;
}
