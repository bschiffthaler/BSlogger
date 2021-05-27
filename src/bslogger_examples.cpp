#include "../src/BSlogger.hpp"

#include <chrono> //milliseconds
#include <thread> //sleep_for

int main(int argc, char ** argv)
{

  // Initiate logger (default name is 'log')
  LOG_INIT_CERR();

  // Log some stuff. The initial loglevel is
  // INFO and lower (INFO, WARNING, ERROR)
  // so the debug info is not displayed
  log(LOG_DEBUG) << "Some text\n";
  log(LOG_INFO) << "Some text\n";
  log(LOG_WARN) << "Some text\n";
  log(LOG_ERR) << "Some text\n";

  // Change the log level
  log.set_log_level(LOG_DEBUG);

  // Now the debug info is displayed
  log(LOG_DEBUG) << "Some text\n";

  // Everything that has a operator<< method
  // for ostreams can be logged
  float x = 3.1415;

  log(LOG_DEBUG) << "The value of x is " << x
                 << ", the address is " << &x
                 << '\n';

  progbar_fancy<uint64_t> p(std::cout, 999999999);
  for (uint64_t i = 0; i < 999999999; i+=2)
  {
    p += 2;
  }
  p.finalize();

  // You can add time snapshots
  log.add_snapshot("before_sleep");
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  // Log the time since the last snap added
  log.time_since_last_snap();

  // Log the time since a particular snap was added
  log.time_since_snap("before_sleep");

  // Log the time since the log was initialized
  log.time_since_start();

  return 0;
}
